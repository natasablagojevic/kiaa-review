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
    std::vector<int> roditelji;
    std::vector<int> times;
    std::vector<int> lower_times;
    int time;
    std::set<int> tacke;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.roditelji.resize(V, -1);
    g.time = 0;
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
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
    int deca = 0;

    while (begin != end) {
        if (!g.posecen[*begin]) {
            g.roditelji[*begin] = u;

            DFS(g, *begin);
            deca++;

            g.lower_times[u] = min(g.lower_times[u], g.lower_times[*begin]);

            if (g.roditelji[u] == -1 && deca > 1)
                g.tacke.insert(u);

            if (g.roditelji[u] != -1 && g.times[u] <= g.lower_times[*begin])
                g.tacke.insert(u);
        } else if (g.roditelji[u] != *begin)
            g.lower_times[u] = min(g.lower_times[u], g.times[*begin]);

        begin++;
    }
}

void artikulacione_tacke(Graf &g, int u)
{
    DFS(g, u);

    for (int x : g.tacke)
        std::cout << x << ' ';
    std::cout << std::endl;
}

int main()
{


    return 0;
}