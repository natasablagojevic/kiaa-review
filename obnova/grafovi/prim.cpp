#include<iostream>
#include<vector>
#include<algorithm>
#include<numbers>
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

    for (int i = 0; i < g.V; i++) {
        if (!g.MST[i] && g.grane[i] < min) {
            min = g.grane[i];
            min_index = i;
        }
    }

    return min_index;
}

void prim(Graf &g, int u)
{
    int cvor;
    g.grane[u] = 0;

    for (int i = 0; i < g.V - 1; i++) {
        cvor = min_grana_neukljucena(g);
        g.MST[cvor] = true;

        for (int v = 0; v < g.V; v++) {
            if (!g.MST[v] && g.matrica[v][cvor] && g.grane[i] > g.matrica[v][cvor]) {
                g.grane[v] = g.matrica[v][cvor];
                g.roditelji[v] = cvor;
            }
        }
    }
}

int main()
{



    return 0;
}