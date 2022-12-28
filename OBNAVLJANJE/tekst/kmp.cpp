#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

void prefix_table(std::string &pattern, std::vector<int> &table) 
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

void KMP(std::string &text, std::string &pattern)
{
    int m = text.length();
    int n = pattern.length();

    std::vector<int> table(n);
    int i = 0, j = 0;

    while (i < m) {
        if (text[i] == pattern[j])
            i++, j++;

        if (j == n) {
            std::cout << "pattern found" << std::endl;
            return ;
        }

        if (i < m && text[i] != pattern[j]) {
            if (j != 0)
                j = table[j-1];
            else 
                i++;
        }
    }

    std::cout << "pattern not found" << std::endl;
}

int main()
{   
    std::string s = "ajhsdgfakunatasaskgjeriuth";
    std::string pattern = "natasa";

    KMP(s, pattern);


    return 0;
}