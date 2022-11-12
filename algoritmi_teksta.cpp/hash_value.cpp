#include<iostream>
#include<vector>
#include<string>

using namespace std;

int64_t hash_value(string &s)
{
    int p = 31;
    int n = s.length();
    int64_t m = 1e9 + 9;
    int64_t hash = 0;

    for (int i = n-1; i >= 0; i--)
        hash = (hash * p + (s[i] - 'a' + 1)) % m;

    return hash;
}

int main()
{
    string s;
    cin >> s;

    cout << hash_value(s) << endl;


    return 0;
}