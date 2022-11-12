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
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen; 
    vector<int> times;
    vector<int> lower_times;
    int time;
    vector<int> roditelji;
    vector<bool> u_steku;
    stack<int> stek;
};

void inicjalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.time = 0;
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
    g.roditelji.resize(V, -1);
    g.u_steku.resize(V, false);
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

    g.stek.push(u);
    g.u_steku[u] = true;

    while (begin != end) {
        if (g.times[*begin] == -1) {
            DFS(g, *begin);

            g.lower_times[u] = min(g.lower_times[u], g.lower_times[*begin]);
        } else if (g.u_steku[*begin])
            g.lower_times[u] = min(g.lower_times[u], g.times[*begin]);

        begin++;
    }

    if (g.lower_times[u] == g.times[u]) {
        while (true) {
            int v = g.stek.top();
            g.stek.pop();
            g.u_steku[v] = false;

            cout << v << ' ';

            if (u == v) {
                cout << endl;
                break;
            }
        }
    }
}

int main()
{
    Graf g;

    inicjalizuj_graf(g, 8);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 0);
    dodaj_granu(g, 1, 3);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 4);
    dodaj_granu(g, 3, 5);
    dodaj_granu(g, 4, 2);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 4, 6);
    dodaj_granu(g, 5, 7);
    dodaj_granu(g, 6, 5);
    dodaj_granu(g, 7, 6);

    DFS(g, 0);

    return 0;
}