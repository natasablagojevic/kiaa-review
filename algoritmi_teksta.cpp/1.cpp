#include<iostream>
#include<vector>
#include<algorithm>
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

vector<int> z_array(string &s)
{
    int n = s.length();
    vector<int> z(n);
    int l = 0, d = 0;

    for (int i = 1 ; i < n; i++) {
        if (i <= d)
            z[i] = min(d-i+1, z[i-l]);

        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;

        if (i + z[i] - 1 > d) {
            l = i;
            d = i + z[i] - 1;
        }
    }

    return z;
}

void prefix_table(string &pattern, vector<int> &table)
{
    table[0] = 0;
    int i = 1, j = 0;
    int n = pattern.length();

    while (i < n) {
        if (pattern[i] == pattern[j]) {
            table[i] = j+1;
            i++, j++;
        } else {
            if (j != 0)
                j = table[j-1];
            else {
                table[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string &text, string &pattern)
{
    int m = text.length();
    int n = pattern.length();

    vector<int> table(n);
    prefix_table(pattern, table);

    int i = 0, j = 0;
    while (i < m) {
        if (text[i] == pattern[j])
            i++, j++;

        if (j == n) {
            cout << "Pattern found!" << endl;
            return ;
        }

        if (i < m && text[i] != pattern[j]) {
            if (j != 0) 
                j = table[j-1];
            else 
                i++;
        }
    }

    cout << "Pattern not found" << endl;
}

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

    int C = 1, R = 1;
    int mirror;
    vector<int> v(n);

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

    cout << res << ' ' << res.length() << endl;
}

int main()
{
    string s = "anavolimilovana";
    
    manacher(s);


    return 0;
}