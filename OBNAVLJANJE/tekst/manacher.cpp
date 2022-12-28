#include<iostream>
#include<vector>
#include<algorithm>

void manacher(std::string &s)
{
    int n = s.length();
    std::string pom = "$";
    for (int i = 0; i < n; i++) {
        pom += "#";
        pom += s[i];
    }

    pom += "#@";

    n = pom.length();
    std::vector<int> v(n);
    int C = 1, R = 1;
    int mirror;

    for (int i = 1; i < n-1; i++) {
        mirror = 2*C - 1;

        if (i < R)
            v[i] = std::min(R-i, v[mirror]);

        while (pom[i + (v[i] + 1)] == pom[i - (v[i] + 1)])
            v[i]++;

        if (i + v[i] > R) {
            C = i;
            R = i + v[i];
        }
    }

    int max_p = std::max_element(v.begin(), v.end()) - v.begin();
    int max = v[max_p];
    int start = max_p - max + 1;
    int end = start + 2*max;
    std::string res = "";

    for (int i = start; i < end; i += 2)
        res += pom[i];

    std::cout << res << " " << res.length() << std::endl;
}

int main()
{
    std::string s = "uasgfanaopuerfg";

    manacher(s);



    return 0;
}