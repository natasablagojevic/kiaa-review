#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void prefix_table(string &pattern, vector<int> &table)
{
    int n = pattern.length();
    table[0] = 0;
    int i = 1, j = 0;

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

void kmp(string &text, string &pattern)
{
    int m = text.length();
    int n = pattern.length();

    vector<int> table(n);
    int i = 0, j = 0;

    while (i < m) {
        if (text[i] == pattern[j])
            i++, j++;

        if (j == n) {
            cout << "pattern found: " << i-j << " ";
            cout << text.substr(i-j, pattern.size()) << endl;
            j = table[j-1];
            // return ; 
        }

        if (i < m && text[i] != pattern[j]) {
            if (j != 0)
                j = table[j-1];
            else 
                i++;
        }
    }

    
}

int main()
{
    string text = "sahjdgfnatasaglhkjfnatasa";
    string pattern = "natasa";

    kmp(text, pattern);

    return 0;
}