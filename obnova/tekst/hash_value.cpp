#include<iostream>
#include<string>

using namespace std;

int64_t hash_value(string &s)
{
    int n = s.length();
    int p = 31;
    int64_t m = 1e9 + 9;
    int64_t hash = 0;

    for (int i = n-1; i >= 0; i--)
        hash = (hash *p + (s[i] - 'a' + 1)) % m;

    return hash;
}

int main()
{


    return 0;
}