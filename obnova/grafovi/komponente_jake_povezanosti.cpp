#include<iostream>
#include<vector>
#include<algorithm>
#include<numbers>
#include<stack>
#include<queue>

using namespace std;

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    int time = 0;
    vector<int> times;
    vector<int> lower_times;
    vector<int> u_steku;
    stack<int> stek;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void DFS(Graf &g, int u)
{
    g.posecen[u] = true;
    g.lower_times[u] = g.times[u] = g.time;
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

    if (g.lower_times[u] = g.times[u]) {
        while (true) {
            int v = g.stek.top();
            g.stek.pop();
            g.u_steku = false;

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



    return 0;
}