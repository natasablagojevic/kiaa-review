#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void manacher(string &s)
{
    int n = s.length();
    string pom = "$";
    for (int i = 0; i < n; i++) {
        pom += "#";
        pom += s[i];
    }

    pom += "#@";
    n = pom.length();

    vector<int> v(n);
    int C = 1, R = 1;
    int mirror;

    for (int i = 1; i < n-1; i++) {
        mirror = 2*C - 1;

        if (i < R)
            v[i] = min(R-i, v[mirror]);

        while (pom[i + (v[i] + 1)] == pom[i - (v[i] + 1)])
            v[i]++;

        if (i + v[i] > R) {
            C = i;
            R = i + v[i];
        }
    }

    int max_p = max_element(v.begin(), v.end()) - v.begin();
    int max = v[max_p];
    int start = max_p - max + 1;
    int end = start + 2*max;
    string res = "";

    for (int i = start; i < end; i += 2)
        res += pom[i];

    cout << res << " " << res.length() << endl;
}

int main()
{
    string s = "anavolimilovana";

    manacher(s);

    return 0;
}