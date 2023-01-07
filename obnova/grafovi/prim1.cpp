#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>
#include<stack>
#include<queue>

using namespace std;

#define INF numeric_limits<int>::max()

struct Graf
{
    int V;
    vector<vector<int>> matrica;
    vector<bool> posecen;
    vector<bool> MST;
    vector<int> grane;
    vector<int> roditelji;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.matrica.resize(V, vector<int> (V));
    g.posecen.resize(V, false);
    g.MST.resize(V, false);
    g.grane.resize(V, INF);
    g.roditelji.resize(V, -1);
}

void dodaj_granu(Graf &g, int u, int v, int t)
{
    g.matrica[u][v] = g.matrica[v][u] = t;
}

int min_grana_neukljucena(Graf &g)
{
    int min = INF;
    int min_index = -1;

    for (int i = 0; i < g.V; i++) 
        if (!g.MST[i] && g.grane[i] < min) {
            min = g.grane[i];
            min_index = i;
        }

    return min_index;
}

void prim(Graf &g, int u) 
{
    g.grane[u] = 0;
    int cvor;

    for (int i = 0; i < g.V - 1; i++) {
        cvor = min_grana_neukljucena(g);
        g.MST[cvor] = true;

        for (int v = 0; v < g.V; v++) 
            if (!g.MST[v] && g.matrica[cvor][v] && g.matrica[cvor][v] < g.grane[v]) {
                g.roditelji[v] = cvor;
                g.grane[v] = g.matrica[cvor][v];
            }
    }

    int cena = 0;
    for (int i = 0; i < g.V; i++) {
        if (i == u)
            continue;

        cena += g.grane[i];
    }

    cout << cena << endl;
}

void print_prim(Graf &g, int u)
{
    for (int i = 0; i < g.V; i++) {
        if (i == u)
            continue;

        cout << g.roditelji[i] << " - " << i << "\t" << g.matrica[g.roditelji[i]][i] << endl; 
    }
}

int main()
{
    Graf g;
    inicijalizuj_graf(g, 5);

    dodaj_granu(g, 0, 1, 1);
    dodaj_granu(g, 0, 2, 5);
    dodaj_granu(g, 0, 3, 10);
    dodaj_granu(g, 0, 4, 4);
    dodaj_granu(g, 1, 2, 2);
    dodaj_granu(g, 1, 4, 1);
    dodaj_granu(g, 2, 3, 4);

    prim(g, 0);
    print_prim(g, 0);

    return 0;
}