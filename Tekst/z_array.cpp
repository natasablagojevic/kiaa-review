#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> z_array(std::string &s)
{
    int n = s.length();
    std::vector<int> z(n);

    int l = 0, d = 0;

    for (int i = 1; i < n; i++) {
        if (i <= d)
            z[i] = std::min(d-i+1, z[i-l]);

        while (i+z[i] < n && s[s[i]] == s[i+z[i]])
            z[i]++;

        if (i + z[i] - 1 > d) {
            l = i;
            d = i + z[i] - 1;
        }
    }

    return z;
}

int main()
{


    return 0;
}