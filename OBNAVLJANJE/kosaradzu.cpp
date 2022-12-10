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

void DFS(Graf &g, int u)
{
    g.posecen[u] = true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (!g.posecen[*begin])
            DFS(g, *begin);

        begin++;
    }
}

int broj_ne_posecenih(Graf &g)
{
    int brojac = 0;
    for (int i = 0; i < g.V; i++)
        if (!g.posecen[i])
            brojac++;

    return brojac;
}

Graf obrni_grane(Graf &g)
{
    Graf pom;
    inicijalizuj_graf(pom, g.V);

    for (int i = 0; i < g.V; i++)
        for (int u : g.lista_susedstva[i])
            dodaj_granu(pom, u, i);

    return pom;
}

bool kosaradzu(Graf &g, int u)
{
    DFS(g, u);

    if (broj_ne_posecenih(g) > 0)
        return false;

    Graf pom = obrni_grane(g);
    DFS(pom, u);

    if (broj_ne_posecenih(pom) > 0)
        return false;

    return true;
}

int main()
{


    return 0;
}