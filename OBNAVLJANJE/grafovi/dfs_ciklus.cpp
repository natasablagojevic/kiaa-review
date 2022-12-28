/* USMERENI */
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

bool DFS(Graf &g, int u)
{
    g.posecen[u]= true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (g.posecen[*begin])
            return true;

        if (DFS(g, *begin))
            return true;

        begin++;
    }

    g.posecen[u] = false;
    return false;
}

int main()
{
    Graf g;
    // inicijalizuj_graf(g, 3);
    // dodaj_granu(g, 0, 1);
    // dodaj_granu(g, 1, 2);
    // dodaj_granu(g, 0, 2);

    inicijalizuj_graf(g, 4);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 0);

    cout << boolalpha << DFS(g, 0) << endl;

    return 0;
}