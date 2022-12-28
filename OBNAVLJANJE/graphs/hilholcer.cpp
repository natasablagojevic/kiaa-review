#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
#include<stack>

using namespace std;

#define INF numeric_limits<int>::max()

struct Graf
{
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> put;
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

void hirholcer(Graf &g, int v)
{
    g.stek.push(v);
    int tmp;

    while (!g.stek.empty()) {
        if (g.lista_susedstva[v].size() > 0) {
            g.stek.push(v);

            tmp = g.lista_susedstva[v].back();
            g.lista_susedstva[v].pop_back();

            v = tmp;
        } else {
            g.put.push_back(v);
            
            v = g.stek.top();
            g.stek.pop();
        }
    }

    int i;
    for (i = g.put.size() - 1; i >= 1; i--)
        cout << g.put[i] << " -> ";
    cout << g.put[i] << endl;
}

int main()
{



    return 0;
}