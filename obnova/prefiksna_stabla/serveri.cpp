#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<numeric>
#include<limits>

#define INF numeric_limits<int>::max()

using namespace std;

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
    g.matrica[u][v] = t;
}

int min_grana_neuklhucena(Graf &g)
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
        cvor = min_grana_neuklhucena(g);
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

int main()
{
    int n, m;
    cin >> n >> m;

    int u;
    vector<pair<int, int>> parovi(m);
    vector<int> cene(m);

    for (int i = 0; i < m; i++) {
        cin >> parovi[i].first >> parovi[i].second;
    }

    for (int i = 0; i < m; i++)
        cin >> cene[i];

    cin >> u;

    Graf g;
    inicijalizuj_graf(g, n);
    for (int i = 0; i < m; i++) 
        dodaj_granu(g, parovi[i].first, parovi[i].second, cene[i]);

    prim(g, u);    


    return 0;
}