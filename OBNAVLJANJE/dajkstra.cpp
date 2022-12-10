#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<cmath>
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

void dajkstra(Graf &g, int u)
{
    g.udaljenost[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> heap;

    heap.push({g.udaljenost[u], u});

    pair<int, int> tmp;

    while (!heap.empty()) {
        tmp = heap.top();
        heap.pop();

        if (g.pronadjen_put[tmp.second]) 
            continue;

        for (pair<int, int> &sused : g.lista_susedstva[tmp.second])
            if (g.udaljenost[sused.first] > g.udaljenost[tmp.second] + sused.second) {
                g.udaljenost[sused.first] = g.udaljenost[tmp.second] + sused.second;
                heap.push({g.udaljenost[sused.first], sused.first});
            }
    }

    for (int i = 0; i < g.V; i++) {
        if (i == u)
            continue;
        cout << u << " -> " << i << " = " << g.udaljenost[i] << endl;
    }
}

int main()
{


    return 0;
}