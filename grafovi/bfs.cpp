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

void BFS(Graf &g, int u)
{
    queue<int> red;

    red.push(u);
    g.posecen[u] = true;

    int tmp;

    while (!red.empty()) {
        tmp = red.front();
        red.pop();

        cout << tmp << ' ';

        auto begin = g.lista_susedstva[tmp].begin();
        auto end = g.lista_susedstva[tmp].end();

        while (begin != end) {
            if (!g.posecen[*begin]) {
                g.posecen[*begin] = true;
                red.push(*begin);
            }

            begin++;
        }
    }

    cout << endl;
}

int main()
{
    Graf g;

    inicjalizuj_graf(g, 4);
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 2, 0);
    dodaj_granu(g, 2, 3);
    dodaj_granu(g, 3, 3);

    BFS(g, 0);


    return 0;
}