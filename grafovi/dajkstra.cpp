#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits>

using namespace std;

#define INF numeric_limits<int>::max()

struct comparator
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
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

void inicjalizuj_graf(Graf &g, int V)
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> heap;

    g.udaljenost[u] = 0;
    heap.push({g.udaljenost[u], u});

    pair<int, int> tmp;
    while (!heap.empty()) {
        tmp = heap.top();
        heap.pop();

        if (g.pronadjen_put[tmp.second])
            continue;

        g.pronadjen_put[tmp.second] = true;

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
    Graf g;

    inicjalizuj_graf(g, 9);
    dodaj_granu(g, 0, 1, 4);
    dodaj_granu(g, 0, 7, 8);
    dodaj_granu(g, 1, 7, 11);
    dodaj_granu(g, 1, 2, 8);
    dodaj_granu(g, 2, 3, 7);
    dodaj_granu(g, 2, 5, 4);
    dodaj_granu(g, 2, 8, 3);
    dodaj_granu(g, 3, 4, 9);
    dodaj_granu(g, 3, 5, 14);
    dodaj_granu(g, 4, 5, 10);
    dodaj_granu(g, 5, 6, 2);
    dodaj_granu(g, 6, 8, 6);
    dodaj_granu(g, 7, 8, 7);

    dajkstra(g, 0);


    return 0;
}