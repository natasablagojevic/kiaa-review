#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<numeric>
#include<limits>

#define INF numeric_limits<int>::max()

struct comparator
{
    bool operator()(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
        return p1.first > p2.first;
    }
};

struct Graf 
{
    int V;
    std::vector<std::vector<std::pair<int, int>>> lista_susedstva;
    std::vector<bool> posecen;
    std::vector<int> udaljenost;
    std::vector<bool> pronadjen_put;
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

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comparator> heap;
    heap.push({g.udaljenost[u], u});

    std::pair<int, int> tmp;

    while (!heap.empty()) {
        tmp = heap.top();
        heap.pop();

        if (g.pronadjen_put[tmp.second])
            continue;

        g.pronadjen_put[tmp.second] = true;

        for (std::pair<int, int> sused : g.lista_susedstva[tmp.second]) 
            if (g.udaljenost[sused.first] > g.udaljenost[tmp.second] + sused.secont) {
                g.udaljenost[sused.first] = g.udaljenost[tmp.second] + sused.second;
                heap.push({g.udaljenost[sused.first], sused.first});
            }
    }

    for (int i = 0; i < g.V; i++) {
        if (i == u)
            continue;

        std::cout << i << " -> " << u << " = " << g.udaljenost[i] << std::endl;
    }
}

int main()
{


    return 0;
}