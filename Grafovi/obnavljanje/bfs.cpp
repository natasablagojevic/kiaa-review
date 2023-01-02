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

void BFS(Graf &g, int u)
{
    std::queue<int> red;
    red.push(u);

    int tmp;

    while (!red.empty()) {
        tmp = red.front();
        red.pop();

        std::cout << tmp << ' ' << std::endl;

        auto begin = g.lista_susedstva[u].begin();
        auto end = g.lista_susedstva[u].end();

        while (begin != end) {
            if (!g.posecen[*begin]) {
                g.posecen[*begin] = true;
                red.push(*begin);
            }
        }
    }
}

int main()
{


    return 0;
}