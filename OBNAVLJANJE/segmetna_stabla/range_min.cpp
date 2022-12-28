#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

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

    tree[k] = min(tree[2*k], tree[2*k + 1]);
}

int min_of_range(vector<int> &tree, int k, int x, int y, int a, int b)\
{
    if (x > b || y < a)
        return numeric_limits<int>::max();

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

    vector<int> tree(N, numeric_limits<int>::max());
    build(a, tree, 1, 0, n-1);

    // for (int x : tree)
    //     cout << x << ' ';
    // cout << endl;

    cout << min_of_range(tree, 1, 0, n-1, 2, 3) << endl;

    return 0;
}