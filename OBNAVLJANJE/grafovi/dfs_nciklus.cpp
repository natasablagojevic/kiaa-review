/* NEUSMEREN */
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
    g.lista_susedstva[v].push_back(u);
}

bool DFS(Graf &g, int u, int parent)
{
    g.posecen[u] = true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (g.posecen[*begin]) {
            if (*begin != parent)
                return true;
        } else if (DFS(g, *begin, u))
            return true;

        begin++;
    }

    return false;
}

int main()
{
    Graf g;
    // inicijalizuj_graf(g, 4);
    // dodaj_granu(g, 0, 1);
    // dodaj_granu(g, 0, 2);
    // dodaj_granu(g, 1, 2);
    // dodaj_granu(g, 2, 3);
    // dodaj_granu(g, 3, 0);

    inicijalizuj_graf(g, 3);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);

    cout << boolalpha << DFS(g, 0, -1) << endl;

    return 0;
}