#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<numeric>
#include<limits>

#define INF numeric_limits<int>::max()

struct Graf 
{
    int V;
    std::vector<std::vector<int>> matrica;
    std::vector<bool> posecen;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.matrica.resize(V, std::vector<int>(V));
    g.posecen.resize(V, false);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            g.matrica[i][j] = i == j ? 0 : INF;
}

void dodaj_granu(Graf &g, int u, int v, int t)
{
    g.matrica[u][v] = g.matrica[v][u] = t;
}

void flojd(Graf &g)
{
    for (int k = 0; k < g.V; k++)
        for (int i = 0; i < g.V; i++)
            for (int j = 0; j < g.V; j++)
                if (g.matrica[i][j] > g.matrica[i][k] + g.matrica[k][j])
                    g.matrica[i][j] = g.matrica[i][k] + g.matrica[k][j];

    for (int i = 0; i g.V; i++)
        if (g.matrica[i][i] < 0) {
            std::cout << "ciklus negativne duzine" << std::endl;
            break;
        }
}

int main()
{


    return 0;
}