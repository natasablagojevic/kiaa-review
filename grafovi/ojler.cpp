#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits>

using namespace std;

#define INF numeric_limits<int>::max()

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen; 
    vector<int> stepeni;
};

void inicjalizuj_graf(Graf &g, int V)
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

int broj_cvorova_neparnog_stepena(Graf &g)
{
    int broajc = 0;
    for (int i = 0; i < g.V; i++)
        if (g.stepeni[i] % 2 != 0)
            broajc++;

    return broajc;
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
        if (!g.posecen[i] && g.stepeni[i] > 0)
            return false;

    return true;
}

/* 
    0 -> nije
    1 -> put
    2 -> ciklus
 */
int ojler(Graf &g)
{
    int br_nep = broj_cvorova_neparnog_stepena(g);
    if (br_nep > 2)
        return 0;

    if (!je_povezan(g))
        return 0;

    return br_nep == 0 ? 2 : 1;
}

int main()
{
    Graf g;
    
    /* 
    //  ciklus:
    inicjalizuj_graf(g, 3);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 0); 
    */
    
    /* 
    //  put:
    inicjalizuj_graf(g, 5);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 0, 3);
    dodaj_granu(g, 1, 3);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 3, 4);
    */

    //  nije:
    inicjalizuj_graf(g, 5);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 1, 4);
    dodaj_granu(g, 2, 3);


    cout << (ojler(g) == 0 ? "nije ojler" : (ojler(g) == 1 ? "put" : "ciklus")) << endl;


    return 0;
}