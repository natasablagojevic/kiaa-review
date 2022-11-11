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
    vector<int> ulazni_stepeni;
};

void inicjalizuj_graf(Graf &g, int V)
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

        cout << tmp << ' ';

        for (int cvor : g.lista_susedstva[tmp]) {
            g.ulazni_stepeni[cvor]--;

            if (g.ulazni_stepeni[cvor] == 0)
                red.push(cvor);
        }
    }

    cout << endl;
}

int main()
{
    Graf g;

    inicjalizuj_graf(g, 6);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 4);
    dodaj_granu(g, 2, 4);
    dodaj_granu(g, 3, 0);
    dodaj_granu(g, 3, 2);
    dodaj_granu(g, 5, 2);
    dodaj_granu(g, 5, 4);

    kan(g);


    return 0;
}