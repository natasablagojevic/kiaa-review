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
    int min_grana;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.min_grana = INF;
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void DFS(Graf &g, int u, int v, int trenutna)
{
    if (u == v) {
        if (trenutna < g.min_grana)
            g.min_grana = trenutna;
    }

    g.posecen[u] = true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (!g.posecen[*begin])
            DFS(g, *begin, v,trenutna + 1);

        begin++;
    }
}

int get_min_num_of_edges(Graf &g)
{
    return g.min_grana;
}

int main()
{
    Graf g;

    inicijalizuj_graf(g, 5);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 0);
    dodaj_granu(g, 0, 4);
    dodaj_granu(g, 4, 0);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 1);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 4, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 2);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 4, 3);

    // dodaj_granu(g, 0, 1);
    // dodaj_granu(g, 0, 4);
    // dodaj_granu(g, 1, 2);
    // dodaj_granu(g, 2, 4);
    // dodaj_granu(g, 2, 3);
    // dodaj_granu(g, 3, 4);

    DFS(g, 0, 4, 0);
    cout << get_min_num_of_edges(g) << endl;

    return 0;
}