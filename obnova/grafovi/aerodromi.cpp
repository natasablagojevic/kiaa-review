#include<iostream>
#include<vector>
#include<algorithm>
#include<numbers>
#include<stack>
#include<queue>

using namespace std;

#define INF numeric_limits<int>::max()

struct comparator 
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.first > p2.first;
    }
};

struct Graf
{
    int V;
    vector<vector<pair<int, int>>> lista_susedstva;
    vector<bool> posecen;
    vector<int> udaljenost;
    vector<bool> pronadjen_put;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.udaljenost.resize(V, INF);
    g.pronadjen_put.resize(V, false);
}

void dodaj_granu(Graf &g, int u, int v, int t)
{
    g.lista_susedstva[u].push_back({v, t});
    g.lista_susedstva[v].push_back({u, t});
}

int dajkstra(Graf &g, int u, int v, int avoid)
{
    g.udaljenost[u] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> heap;
    pair<int, int> tmp;

    heap.push({g.udaljenost[u], u});

    while (!heap.empty()) {
        tmp = heap.top();
        heap.pop();

        if (g.pronadjen_put[tmp.second])
            continue;

        g.pronadjen_put[tmp.second] = true;

        for (pair<int> sused : g.lista_susedstva[tmp.second]) {
            if (sused.first == avoid)
                continue;

            if (g.udaljenost[sused.first] > g.udaljenost[tmp.second] + sused.second) {
                g.udaljenost[sused.first] = g.udaljenost[tmp.second] + sused.second;
                heap.push({g.udaljenost[sused.firts], sused.first});
            }
        }
    }

    return g.udaljenost[v];
}

int preko_cvora(Graf &g, int u, int v, int middle)
{
    int res = dajkstra(g, u, middle, -1);
    fill(g.pronadjen_put.begin(), g.pronadjen_put.end(), false);
    fill(g.udaljenost.begin(), g.udaljenost.end(), INF);

    return res + dajkstra(g, middle, v, -1);
}

int zaobilazenje(Graf &g, int u, int v, int avoid)
{
    return dajkstra(g, u, v, avoid);
}

int main()
{



    return 0;
}