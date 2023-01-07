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

void DFS(Graf &g, int u, int v, vector<int> result)
{
    if (u == v) {
        result.push_back(v);
        int i, n = result.size();
        for (i = 0; i < n-1; i++)
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



    return 0;
}