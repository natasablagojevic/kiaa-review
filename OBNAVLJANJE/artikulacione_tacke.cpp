#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<cmath>
#include<numeric>
#include<limits>
#include<set>

#define INF numeric_limits<int>::max()

using namespace std;

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> roditelji;
    vector<int> times;
    vector<int> lower_times;
    int time;
    set<int> tacke;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.roditelji.resize(V, -1);
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
    g.time = 0;
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void DFS(Graf &g, int u)
{
    g.times[u] = g.lower_times[u] = g.time;
    g.time++;
    g.posecen[u] = true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();
    int deca = 0;

    while (begin != end) {
        if (!g.posecen[*begin]) {
            g.roditelji[v] = u;

            DFS(g, *begin);
            deca++;

            g.lower_times[u] = min(g.lower_times[u], g.lower_times[*begin]);

            if (g.roditelji[u] == -1 && deca > 1)
                g.tacke.insert(u);

            if (g.roditelji[u] != -1 && g.lower_times[u] <= g.times[*begin])
                g.tacke.insert(u); 
        } else if (g.roditelji[v] != u)
            g.lower_times[u] = min(g.times[u], g.lower_times[*begin]);

        begin++;
    }
}

void ptint_points(Graf &g)
{
    for (int x : g.tacke)
        cout << x << ' ';
    cout << endl;
}

int get_points(Graf &g)
{
    return g.tacke.size();
}

int main()
{


    return 0;
}