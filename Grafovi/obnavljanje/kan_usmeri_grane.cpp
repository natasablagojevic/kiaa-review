#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<numeric>
#include<limits>

#define INF numeric_limits<int>::max()

struct Graf 
{
    int V;
    std::vector<std::vector<int>> lista_susedstva;
    std::vector<bool> posecen;
    std::vector<int> topolosko;
    std::vector<int> ulazni_stepeni;
    std::vector<std::pair<int, int>> grane; // sve
    std::vector<std::pair<int, int>> dodate;
    std::vector<std::pair<int, int>> neusmerene;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.topolosko.resize(V, -1);
    g.ulazni_stepeni.resize(V, 0);
}

void dodaj_direktnu_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
    g.ulazni_stepeni[v]++;
    g.grane.push_back({u, v});
}

void dodaj_neusmerenu_granu(Graf &g, int u, int v)
{
    g.neusmerene.push_back({u, v});
}

void kan(Graf &g)
{
    std::queue<int> red;
    for (int i = 0; i < g.V; i++)
        if (g.ulazni_stepeni[i] == 0)
            red.push(i);

    int tmp;
    int pozicije = 0;

    while (!red.empty()) {
        tmp = red.front();
        red.pop();

        g.topolosko[tmp] = pozicije;
        pozicije++;

        for (int cvor : g.lista_susedstva[tmp]) {
            g.ulazni_stepeni[cvor]--;

            if (g.ulazni_stepeni[cvor] == 0)
                red.push(cvor);
        }
    }
}

void preusmeri_direkcije(Graf &g)
{
    kan(g);

    for (std::pair<int, int> u : g.lista_susedstva) {
        if (g.topolosko[u.first] < g.topolosko[u.second]) {
            g.grane.push_back({u.first, u.second});
            g.dodate.push_back({u.first, u.second});
        } else {
            g.grane.push_back({u.second, u.first});
            g.dodate.push_back({u.second, u.first});
        }
    }

    std::cout << "Dodate grane:" << std::endl;
    for (std::pair<int, int> it : g.dodate)
        std::cout << it.first << " -> " << it.second << std::endl;

    std::cout << "Sve grane:" << std::endl;
    for (std::pair<int, int> it: g.grane)
        std::cout << it.first << " -> " << it.second << std::endl; 
}

int main()
{


    return 0;
}