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
    vector<int> put;
    stack<int> stek;
};

void inicjalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void hilholcer(Graf &g)
{
    int v = 0;
    g.stek.push(v);

    int tmp;
    while (!g.stek.empty()) {
        if (g.lista_susedstva[v].size()) {
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

    int n = g.put.size();
    int i;
    for (int i = n-1; i >= 1; i--)
        cout << g.put[i] << " -> ";
    cout << g.put[i] << endl;
    cout << i << endl;
}

int main()
{
    Graf g;

    inicjalizuj_graf(g, 6);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 1);
    dodaj_granu(g, 1, 3);
    dodaj_granu(g, 2, 0);
    dodaj_granu(g, 2, 1);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 3, 2);
    dodaj_granu(g, 3, 5);
    dodaj_granu(g, 4, 5);
    dodaj_granu(g, 5, 2);

    hilholcer(g);


    return 0;
}