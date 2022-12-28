#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<numeric>
#include<limits>

#define INF numeric_limits<int>::max()

using namespace std;

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    int time;
    vector<int> lower_times;
    vector<int> times;
    vector<bool> u_steku;
    stack<int> stek;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.time = 0;
    g.lower_times.resize(V, -1);
    g.times.resize(V, -1);
    g.u_steku.resize(V, false);
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

    g.stek.push(u);
    g.u_steku[u] = true;

    while (begin != end) {
        if (!g.posecen[*begin]) {
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
    inicijalizuj_graf(g, 8);

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