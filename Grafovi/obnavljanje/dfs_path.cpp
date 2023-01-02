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
    bool pronadjen;
};

void inicijalizuj_graf(Graf &g, int V)
{
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.pronadjen = false;
}

void dodaj_granu(Graf &g, int u, int v)
{
    g.lista_susedstva[u].push_back(v);
}

void DFS(Graf &g, int u, int v, std::vector<int> &result)
{
    if (u == v) {
        result.push_back(v);
        g.pronadjen = true;
        int i, n = result.size();
        for (i = 0; i < n-1; i++)
            std::cout << result[i] << " -> ";
        std::cout << result[i] << std::endl;
        return ;
    }

    g.posecen[u] = true;

    auto begin = g.lista_susedstva[u].begin();
    auto end = g.lista_susedstva[u].end();

    result.push_back(u);

    while (begin != end) {
        if (!g.posecen[*begin] && !g.pronadjen)
            DFS(g, *begin, v, result);

        if (g.posecen)
            return ;

        result.pop_back();
        begin++;
    }
}

int main()
{


    return 0;
}