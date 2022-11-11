#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

void build(vector<int> &a, vector<int> &tree, int k, int x, int y)
{
    if (x == y) {
        tree[k] = a[x];
        return ;
    }

    int s = (x+y)/2;

    build(a, tree, 2*k, x, s);
    build(a, tree, 2*k + 1, s + 1, y);

    tree[k] = tree[2*k] + tree[2*k + 1];
}

int min_of_range(vector<int> &tree, int k, int x, int y, int a, int b)
{
    if (x > b || y < a)
        return INT_MAX;

    if (x >= a && y <= b)
        return tree[k];

    int s = (x+y)/2;

    return min(min_of_range(tree, 2*k, x, s, a, b), min_of_range(tree, 2*k + 1, s + 1, y, a, b));
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int h = (int)ceil(log2(n));
    int N = pow(2, h+1);

    vector<int> tree(N);

    build(a, tree, 1, 0, n-1);

    cout << "Unseite interval: ";
    int x, y;
    cin >> x >> y;

    cout << min_of_range(tree, 1, 0, n-1, x, y) << endl;

    return 0;
}