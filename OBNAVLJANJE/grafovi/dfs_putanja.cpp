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
    Graf g;
    inicijalizuj_graf(g, 5);

    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 1, 3);
    dodaj_granu(g, 3, 4);

    vector<int> result;
    DFS(g, 0, 3, result);

    if (!g.pronadjen) 
        cerr << "ne postoji put" << endl;
    else {
        int n = result.size();
        int i;
        for (i = 0; i < n-1; i++) 
            cout << result[i] << " -> ";
        cout << result.back() << endl;
    }

    return 0;
}