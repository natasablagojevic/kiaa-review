#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> z_array(string &s)
{
    int n = s.length();
    int l = 0, d  = 0;
    vector<int> z(n);

    for (int i = 1; i < n; i++) {
        if (i <= d) 
            z[i] = min(d-i+1, z[i-l]);

        while (i+z[i] < n && s[z[i]] == s[z[i] + i])
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