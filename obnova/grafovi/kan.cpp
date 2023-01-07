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
    vector<int> ulazni_stepeni;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.ulazni_stepeni.resize(V, 0);
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
    g.ulazni_stepeni[v]++;
}

void kan(Graf &g)
{
    queue<int> red;
    for (int i = 0; i < g.V; i++)
        if (g.ulazni_stepeni[i] == 0)
            red.push(i);

    int tmp;

    while (!red.empty()) {
        tmp = red.front();
        red.pop();

        cout << tmp << ' ' ;

        for (int cvor : g.lista_susedstva[tmp]) {
            g.ulazni_stepeni[cvor]--;

            if (g.ulazni_stepeni[cvor] == 0)
                red.push(cvor);
        }
    }
}

int main()
{



    return 0;
}