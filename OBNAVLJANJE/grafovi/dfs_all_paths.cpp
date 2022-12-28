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

void DFS(Graf &g, int u, int v, vector<int> result)
{
    if (u == v) {
        result.push_back(v);
        int i;
        for (i = 0; i < result.size() - 1; i++)
            cout << result[i] << " -> ";
        cout << result[i] << endl;
        return ;
    }

    g.posecen[u] = true;
    result.push_back(u);

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (!g.posecen[*begin])
            DFS(g, *begin, v, result);

        begin++;
    }

    g.posecen[u] = false;
}

int main()
{

    Graf g;
    inicijalizuj_graf(g, 4);

    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 0, 3);
    dodaj_granu(g, 2, 0);
    dodaj_granu(g, 2, 1);
    dodaj_granu(g, 1, 3);

    vector<int> rezultat;
    DFS(g, 0, 3, rezultat);

    return 0;
}