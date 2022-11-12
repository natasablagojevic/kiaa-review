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
    vector<vector<int>> udaljenost;
    vector<bool> posecen; 
};

void inicjalizuj_graf(Graf &g, int V)
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

void flojd_marsal(Graf &g)
{
    for (int k = 0; k < g.V; k++)
        for (int i = 0; i < g.V; i++)
            for (int j = 0; j < g.V; j++)
                if (g.udaljenost[i][j] > g.udaljenost[i][k] + g.udaljenost[k][j])
                    g.udaljenost[i][j] = g.udaljenost[i][k] + g.udaljenost[k][j];

    for (int i = 0; i < g.V; i++)
        if (g.udaljenost[i][i] < 0) {
            cout << "ciklus negativne duzine" << endl;
            return ;
        }

    cout << "nema ciklusa negativne duzine" << endl;
}

int main()
{
    Graf g;

    inicjalizuj_graf(g, 4);
    dodaj_granu(g, 0, 1, 1);
    dodaj_granu(g, 1, 2, -1);
    dodaj_granu(g, 2, 3, -1);
    dodaj_granu(g, 3, 0, -1);

    flojd_marsal(g);


    return 0;
}