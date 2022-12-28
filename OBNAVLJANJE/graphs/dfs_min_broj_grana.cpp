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
    int min_broj_grana;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.min_broj_grana = numeric_limits<int>::max();
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void DFS(Graf &g, int u, int v, int trenutni_min) 
{   
    if (u == v) {
        if (trenutni_min < g.min_broj_grana)
            g.min_broj_grana = trenutni_min;
        
        return ;
    }
    g.posecen[u] = true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (!g.posecen[*begin])
            DFS(g, *begin, v, trenutni_min + 1);

        begin++;
    }

    g.posecen[u] = false;
}

int main()
{



    return 0;
}