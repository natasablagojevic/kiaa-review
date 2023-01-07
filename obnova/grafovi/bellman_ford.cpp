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
    vector<vector<pair<int, int>>> lista_susedstva;
    vector<bool> posecen;
    vector<int> udaljenost;
    vector<int> roditelji;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.udaljenost.resize(V, INF);
    g.roditelji.resize(V, -1);
}

void dodaj_granu(Graf &g, int u, int v, int t)
{
    g.lista_susedstva[u].push_back({v, t});
}

void bellman_ford(Graf &g, int u)
{
    int cena, sused;
    g.udaljenost[u] = 0;

    for (int k = 0; k < g.V - 1; k++) {
        for (int i = 0; i < g.V; i++)
            for (pair<int, int> sused : g.lista_susedstva[i]) {
                if (g.udaljenost[sused.first] > g.udaljenost[i] + sused.second) {
                    g.udaljenost[sused.first] = g.udaljenost[i] + sused.second;
                    g.roditelji[sused.first] = i;
                }
            }
    }

    for (int i = 0; i < g.V; i++)
        for (int j = 0; j < g.V; j++) {
            sused = g.lista_susedstva[i][j].first;
            cena = g.lista_susedstva[i][j].second;

            if (g.udaljenost[sused] > g.udaljenost[i] + cena){
                cout << "Graf sadrzi ciklus negativne duzine" << endl;
                return ;
            }
        }

    cout << "Graf ne sadrzi ciklus negativne duzine" << endl;
}

int main()
{
    Graf g;
    inicijalizuj_graf(g, 5);

    dodaj_granu(g, 0, 1, -1);
    dodaj_granu(g, 0, 2, 4);
    dodaj_granu(g, 1, 2, 3);
    dodaj_granu(g, 1, 3, 2);
    dodaj_granu(g, 1, 4, 2);
    dodaj_granu(g, 3, 2, 5);
    dodaj_granu(g, 4, 3, -1);

    bellman_ford(g, 0);

    // for (int i = 1; i < g.V; i++)
    //     cout << g.roditelji[i] << " - " << i << "\t" << g.udaljenost[i] << endl;

    return 0;
}