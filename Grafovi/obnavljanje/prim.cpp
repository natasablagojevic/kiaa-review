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
    std::vector<bool> MST;
    std::vector<int> grane;
    std::vector<int> roditelji;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.matrica.resize(V, std::vector<int> (V));
    g.posecen.resize(V, false);

    for (int i = 0; i < g.V; i++)
        for (int j = 0; j < g.V; j++)
            g.matrica[i][j] = INF;

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
        if (!g.MST[i] && min > g.grane[i]) {
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

        for (int v = 0; v < g.V; v++) {
            if (!g.MST[v] && g.matrica[cvor][v] && g.grane[i] > g.matrica[cvor][v]) {
                g.grane[v] = g.matrica[cvor][v];
                g.roditelji[v] = cvor;
            }
        }
    }

    int cena = 0;
    for (int i = 0; i < g.V; i++) {
        if (i == u)
            continue;
        cena += g.grane[i];
    }

    std::cout << cena << std::endl;
} 

void print_prim(Graf &g) 
{
    for (int i = 0; i < g.V; i++)
        stc::cout << g.roditelji[i] << " - " << i << "\t" << g.matrica[g.roditelji[i]][i] << std::endl;
}

int main()
{


    return 0;
}