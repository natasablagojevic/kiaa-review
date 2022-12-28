#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
#include<stack>

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

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    g.posecen[u] = true;
    result.push_back(u);

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