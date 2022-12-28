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
    bool pronadjen;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.pronadjen = false;
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void DFS(Graf &g, int u, int v, vector<int> &result)
{
    if (u == v) {
        result.push_back(v);
        g.pronadjen = true;
        return ;
    }

    g.posecen[u] = true;
    result.push_back(u);

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (!g.posecen[*begin] && !g.pronadjen) 
            DFS(g, *begin, v, result);

        if (g.pronadjen)
            return ;

        result.pop_back();
        begin++;
    }
}

int main()
{



    return 0;
}