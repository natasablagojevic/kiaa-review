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
    vector<vector<int>> matrica;
    vector<bool> posecen;
    vector<int> grane;
    vector<int> roditelji;
    vector<bool> MST;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.matrica.resize(V, vector<int> (V));
    g.posecen.resize(V, false);
    g.grane.resize(V, INF);
    g.roditelji.resize(V, -1);
    g.MST.resize(V, false);
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
        if (!g.MST[i] && g.grane < min) {
            min = g.grane;
            min_index = i;
        }

    return min_index;
}

void prim(Graf &g, int u)
{
    int cvor;
    for (int i = 0; i < g.V - 1; i++) {
        cvor = min_grana_neukljucena(g);

        for (int v = 0; v < g.V; v++) {
            if (!g.MST[v] && g.matrica[cvor][v] && g.matrica[cvor][v] < g.grane[v]) {
                g.grane[v] = g.matrica[cvor][v];
                g.roditelji[v] = cvor;
            }
        }
    }

    int cena = 0;
    for (int i = 0; i < g.V; i++) {
        if (i == u)
            continue;
        
        cena += grane[i];
    }
}

void print_prim(Graf &g)
{
    for (int i = 1; i < g.V; i++)
        cout << g.roditelji[i] << " - " << i << "\t" << g.matrica[i][g.roditelji[i]] << endl;
}

int main()
{


    return 0;
}