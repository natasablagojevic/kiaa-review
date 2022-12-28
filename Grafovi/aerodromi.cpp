#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<numeric>
#include<limits>

#define INF numeric_limits<int>::max()

using namespace std;

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
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> heap;

    g.udaljenost[u] = 0;
    heap.push({g.udaljenost[u], u});

    pair<int, int> tmp;

    while (!heap.empty()) {
        tmp = heap.top();
        heap.pop();

        if (g.pronadjen_put[tmp.second])
            continue;

        for (pair<int, int> &sused : g.lista_susedstva[tmp.second]) {
            if (sused.first == avoid)
                continue;

            if (g.udaljenost[sused.first] > g.udaljenost[tmp.second] + sused.second) {
                g.udaljenost[sused.first] = g.udaljenost[tmp.second] + sused.second;
                heap.push({g.udaljenost[sused.first], sused.first});
            }
        }
    }

    return g.udaljenost[v];
}

int udaljenost_preko_zaobilaska(Graf &g, int u, int v, int middle)
{
    return dajkstra(g, u, v, middle);
}

int udaljenost_bez_zaobilazenja(Graf &g, int u, int v, int middle)
{
    int res = dajkstra(g, u, middle, -1);
    fill(g.udaljenost.begin(), g.udaljenost.end(), INF);
    fill(g.pronadjen_put.begin(), g.pronadjen_put.end(), false);

    return res + dajkstra(g, middle, v, -1);
}

int main()
{

    Graf g;
    inicijalizuj_graf(g, 5);
    dodaj_granu(g, 0, 1, 10);
    dodaj_granu(g, 0, 2, 2);
    dodaj_granu(g, 1, 3, 9);
    dodaj_granu(g, 2, 3, 7);
    dodaj_granu(g, 2, 4, 5);
    dodaj_granu(g, 3, 4, 6);

    cout << udaljenost_bez_zaobilazenja(g, 0, 1, 4) << endl;
    cout << udaljenost_preko_zaobilaska(g, 0, 3, 2) << endl;


    return 0;
}