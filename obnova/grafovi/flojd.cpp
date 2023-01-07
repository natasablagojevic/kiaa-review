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
    vector<vector<int>> udaljenost;
    vector<bool> posecen;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.udaljenost.resize(V, vector<int> (V));
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            g.udaljenost[i][j] = i == j ? 0 : INF;

    g.posecen.resize(V, false);
}

void dodaj_granu(Graf &g, int u, int v, int t)
{
    g.udaljenost[u][v] = g.udaljenost[v][u] = t;
}

void flojd(Graf &g)
{
    for (int k = 0; k < g.V; k++)
        for (int i = 0; i < g.V; i++)
            for (int j = 0; j < g.V; j++)
                if (g.udaljenost[i][j] > g.udaljenost[i][k] + g.udaljenost[k][j])
                    g.udaljenost[i][j] = g.udaljenost[i][k] + g.udaljenost[k][j];
}

int main()
{



    return 0;
}