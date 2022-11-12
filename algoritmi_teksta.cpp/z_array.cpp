#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> z_array(string &s)
{
    int n = s.length();
    vector<int> z(n);
    int l = 0, d = 0;

    for (int i = 1; i < n; i++) {
        if (i <= d) 
            z[i] = min(d-i+1, z[i-l]);

        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
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
    string s = "CDA#ACBACDACBACBACDA";
    vector<int> z = z_array(s);
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (z[i] == 3) 
            cout << i -4 << endl;
    }


    return 0;
}