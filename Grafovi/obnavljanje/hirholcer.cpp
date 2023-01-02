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
    std::stack<int> stek;
    std::vector<bool> u_steku;
    std::vector<int> put;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.u_steku.resize(V, false);
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void hirholcer(Graf &g)
{
    int v = 0;
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

    int n = g.put.size();
    int i;
    for (i = n-1; i >= 1; i--)
        std::cout << g.put[i] << " -> ";
    std::cout << g.put[i] << std::endl;
}

int main()
{


    return 0;
}