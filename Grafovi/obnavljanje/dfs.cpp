#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<numeric>
#include<limits>

#define INF numeric_limits<int>::max()

struct Graf 
{
    int V;
    std::vector<std::vector<int>> lista_susedstva;
    std::vector<bool> posecen;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void DFS(Graf &g, int u)
{
    g.posecen[u] = true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    std::cout << u << ' ' << std::endl;

    while (begin != end) {
        if (!g.posecen[*begin])
            DFS(g, *begin);

        begin++;
    }
}

int main()
{


    return 0;
}