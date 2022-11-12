#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits>
#include<set>

using namespace std;

#define INF numeric_limits<int>::max()

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen; 
    vector<int> roditelji;
    int time;
    vector<int> times;
    vector<int> lower_times;
    set<int> tacke;
};

void inicjalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.roditelji.resize(V, -1);
    g.time = 0;
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
}

void DFS(Graf &g, int u)
{
    g.posecen[u] = true;
    g.times[u] = g.lower_times[u] = g.time;
    g.time++;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    int deca = 0;

    while (begin != end) {
        if (!g.posecen[*begin]) {
            g.roditelji[*begin] = u;

            DFS(g, *begin);
            deca++;

            g.lower_times[u] = min(g.lower_times[u], g.lower_times[*begin]);

            if (g.roditelji[u] == -1 && deca > 1)
                g.tacke.insert(u);

            if (g.roditelji[u] != -1 && g.times[u] <= g.lower_times[*begin])
                g.tacke.insert(u);
        } else if (g.roditelji[u] != *begin)
            g.lower_times[u] = min(g.lower_times[u], g.times[*begin]);

        begin++;
    }
}

void artikulacione_tacke(Graf &g, int u)
{
    DFS(g, u);
    for (int x : g.tacke)
        cout << x << ' ';
    cout << endl;
}

int main()
{
    Graf g;

    inicjalizuj_graf(g, 8);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 4, 6);
    dodaj_granu(g, 5, 6);
    dodaj_granu(g, 5, 7);

    artikulacione_tacke(g, 3);


    return 0;
}