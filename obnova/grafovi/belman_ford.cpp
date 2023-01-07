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

void belman_ford(Graf &g, int u)
{
    g.udaljenost[u] = 0;

    for (int k = 0; k < g.V - 1; k++)
        for (int i = 0; i < g.V; i++)
            for (pair<int> sused : g.lista_susedstva[i]) {
                if (g.udaljenost[sused.first] > g.udaljenost[i] + sused.second) {
                    g.udaljenost[sused.first] = g.udaljenost[i] + sused.second;
                    g.roditelji[sused.first] = i;
                }
            }
        

    for (int i = 0; i < g.V; i++)
        for (pair<int, int> sused : g.lista_susedstva[i])
            if (g.udaljenost[sused.first] > g.udaljenost[i] + sused.second) {
                cout << "postoji ciklus negativne duzine" << endl;
                return ;
            }

    cout << "ne postoji ciklus negativne duzine" << endl;
}

int main()
{



    return 0;
}