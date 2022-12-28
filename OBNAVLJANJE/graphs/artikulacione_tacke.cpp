#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
#include<stack>
#include<set>

using namespace std;

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    int time;
    vector<int> times;
    vector<int> lower_times;
    vector<int> roditelji;
    set<int> tacke;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.time = 0;
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
    g.roditelji.resize(V, -1);
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
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
        } else if (g.roditelji[*begin] != u)
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



    return 0;
}