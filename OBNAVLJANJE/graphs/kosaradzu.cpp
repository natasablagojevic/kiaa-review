#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
#include<stack>

using namespace std;

#define INF numeric_limits<int>::max()

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

Graf obrni_grane(Graf &g)
{
    Graf pom;
    inicijalizuj_graf(pom, g.V);

    for (int i = 0; i < g.V; i++)
        for (int u : g.lista_susedstva[i])
            dodaj_granu(pom, u, i);

    return pom;
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

int broj_neposecenih(Graf &g)
{
    int brojac = 0;
    for (int i = 0; i < g.V; i++)
        if (!g.posecen[i])
            brojac++;

    return brojac;
}

bool kosaradzu(Graf &g, int u)
{
    DFS(g, u);

    if (broj_neposecenih(g) > 0)
        return false;
    
    Graf pom = obrni_grane(g);
    DFS(pom, u);

    if (broj_neposecenih(pom) > 0)
        return fasle;

    return true;
}

int main()
{



    return 0;
}