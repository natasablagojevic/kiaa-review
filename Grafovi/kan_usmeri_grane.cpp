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
    vector<pair<int, int>> grane;   // sve grane
    vector<pair<int, int>> dodate;
    vector<pair<int, int>> neusmerene;
    vector<int> ulazni_stepeni;
    vector<int> topolosko;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.ulazni_stepeni.resize(V, 0);
    g.topolosko.resize(V, -1);
}

void dodaj_direktnu_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
    g.grane.push_back({u, v});
    g.ulazni_stepeni[v]++;
}

void dodaj_neusmerenu_granu(Graf &g, int u, int v)
{
    g.neusmerene.push_back({u, v});
}

void kan(Graf &g)
{
    queue<int> red;
    for (int i = 0; i < g.V; i++)
        if (g.ulazni_stepeni[i] == 0)
            red.push(i);

    int tmp;
    int pozicija = 0;

    while (!red.empty()) {
        tmp = red.front();
        red.pop();

        g.topolosko[tmp] = pozicija;
        pozicija++;

        for (int cvor : g.lista_susedstva[tmp]) {
            g.ulazni_stepeni[cvor]--;

            if (g.ulazni_stepeni[cvor] == 0)
                red.push(cvor);
        }
    }
}

// 0 1 2 3 4 5 positions
// 0 2 3 4 5 1

bool DFS(Graf &g, int u)
{
    g.posecen[u] = true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    while (begin != end) {
        if (!g.posecen[*begin])
            return true;

        if (DFS(g, *begin))
            return true;

        begin++;
    }

    return false;
}

void preusmeri_direkcije(Graf &g)
{
    kan(g);

    for (pair<int, int> &u : g.neusmerene) {
        if (g.topolosko[u.first] < g.topolosko[u.second]) {
            g.grane.push_back({u.first, u.second});
            g.dodate.push_back({u.first, u.second});
        } else {
            g.grane.push_back({u.second, u.first});
            g.dodate.push_back({u.second, u.first});
        }
    }

    if (DFS(g, 0))
        cout << "postoji ciklus" << endl;
    else 
        cout << "ne postoji ciklus" << endl;

    cout << "Dodate grane:" << endl;
    for (pair<int, int> p : g.dodate)
        cout << p.first << " -> " << p.second << endl;

    cout << endl;
    cout << "Sve grane:" << endl;
    for (pair<int, int> p : g.grane)
        cout << p.first << " -> " << p.second << endl;
}

int main()
{
    Graf g;
    inicijalizuj_graf(g, 6);
    dodaj_direktnu_granu(g, 0, 1);
    dodaj_direktnu_granu(g, 0, 5);
    dodaj_direktnu_granu(g, 1, 2);
    dodaj_direktnu_granu(g, 1, 3);
    dodaj_direktnu_granu(g, 1, 4);
    dodaj_direktnu_granu(g, 2, 3);
    dodaj_direktnu_granu(g, 2, 4);
    dodaj_direktnu_granu(g, 3, 4);
    dodaj_direktnu_granu(g, 5, 1);
    dodaj_direktnu_granu(g, 5, 2);

    dodaj_neusmerenu_granu(g, 0, 2);
    dodaj_neusmerenu_granu(g, 0, 3);
    dodaj_neusmerenu_granu(g, 4, 5);

    // kan(g);

    // for (int x : g.topolosko)
    //     cout << x << ' ';
    // cout << endl;

    preusmeri_direkcije(g);

    return 0;
}