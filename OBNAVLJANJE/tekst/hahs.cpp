#include<iostream>
#include<string>

int64_t hash_value(std::string &s)
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
    std::string s;
    std::cin >> s;

    std::cout << hash_value(s) << std::endl;

    return 0;
}