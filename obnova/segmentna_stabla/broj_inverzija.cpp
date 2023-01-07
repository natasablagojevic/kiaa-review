#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

void dodaj_1(vector<int> &tree, int k, int x, int y, int index)
{
    if (x == y) {
        tree[k] = 1;
        return ;
    }

    int s = (x+y)/2;

    if (index <= s)
        dodaj_1(tree, 2*k, x, s, index);
    else
        dodaj_1(tree, 2*k + 1, s + 1, y, index);

    tree[k] = tree[2*k] + tree[2*k + 1];
}

int inverzije(vector<int> &tree, int k, int x, int y, int a, int b)
{
    if (x > b || y < a)
        return 0;

    if (x >= a && y <= b)
        return tree[k];

    int s = (x+y)/2;

    return inverzije(tree, 2*k, x, s, a, b) + inverzije(tree, 2*k + 1, s + 1, y, a, b);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int max = *max_element(a.begin(), a.end());
    int h = (int)ceil(log2(max));
    int N = pow(2, h+1);

    vector<int> tree(N);
    int result = 0;

    for (int i = 0; i < n; i++) {
        result += inverzije(tree, 1, 1, max, a[i], max);
        dodaj_1(tree, 1, 1, max, a[i]);
    }

    cout << result << endl;

    return 0;
}