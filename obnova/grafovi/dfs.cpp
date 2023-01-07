#include<iostream>
#include<vector>
#include<algorithm>
#include<numbers>
#include<stack>
#include<queue>

using namespace std;

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
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

void dfs(Graf &g, int u)
{
    g.posecen[u] = true;

    cout << u << ' ';

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (!g.posecen[*begin])
            dfs(g, *begin);

        begin++;
    }
}

int main()
{



    return 0;
}