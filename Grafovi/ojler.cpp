#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<numeric>
#include<limits>

#define INF numeric_limits<int>::max()

using namespace std;

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> stepeni;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.stepeni.resize(V, 0);
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
    g.stepeni[u]++;
    g.stepeni[v]++;
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

bool je_povezan(Graf &g)
{
    int start;
    for (int i = 0; i < g.V; i++)
        if (g.lista_susedstva[i].size() > 0)
            start = i;

    DFS(g, start);

    for (int i = 0; i < g.V; i++)
        if (g.lista_susedstva[i].size() > 0 && !g.posecen[i])
            return false;
    
    return true;
}

int broj_neparnih(Graf &g)
{
    int brojac = 0;
    for (int i = 0; i < g.V; i++)
        if (g.stepeni[i] % 2 != 0)
            brojac++;

    return brojac;
}

/* 
    0 - nije ojler
    1 - ojlerov put
    2 - ojlerov ciklus
 */
int ojler(Graf &g)
{
    int br_nep = broj_neparnih(g);

    if (br_nep > 2)
        return 0;

    if (!je_povezan(g))
        return 0;

    return br_nep == 0 ? 2 : 1;
}

int main()
{
    Graf g;
    inicijalizuj_graf(g, 5);

    // ciklus:
    // dodaj_granu(g, 0, 1);
    // dodaj_granu(g, 1, 2);
    // dodaj_granu(g, 2, 0);

    // nije ojlerov:
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 1, 4);
    dodaj_granu(g, 2, 3);


    // put
    // dodaj_granu(g, 0, 1);
    // dodaj_granu(g, 0, 2);
    // dodaj_granu(g, 0, 3);
    // dodaj_granu(g, 1, 2);
    // dodaj_granu(g, 1, 3);
    // dodaj_granu(g, 2, 3);
    // dodaj_granu(g, 2, 4);
    // dodaj_granu(g, 3, 4);

    int o = ojler(g);

    cout << (o == 0 ? "Graf nije Ojlerov" : (o == 1 ? "Graf ima Ojlerov put" : "Graf ima Olerov ciklus")) << endl;


    return 0;
}