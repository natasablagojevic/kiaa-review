#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Cvor
{
    string rec;
    bool list;
    map<char, Cvor *> cvorovi;
};

Cvor *napravi_cvor()
{
    Cvor *novi = new Cvor();
    novi->list = false;

    return novi;
}

void build(Cvor *koren, string &rec, int i)
{
    if (i == (int)rec.length()) {
        koren->list = true;
        koren->rec = rec;
        return ;
    }

    auto it = koren->cvorovi.find(rec[i]);
    if (it == koren->cvorovi.end())
        koren->cvorovi[rec[i]] = napravi_cvor();

    build(koren->cvorovi[rec[i]], rec, i + 1);
}

bool find(Cvor *koren, string &rec, int i)
{
    if (i == (int)rec.length())
        return koren->list;

    auto it = koren->cvorovi.find(rec[i]);
    if (it == koren->cvorovi.end())
        return false;

    return find(koren->cvorovi[rec[i]], rec, i + 1);
}

void free(Cvor *koren)
{
    if (koren == nullptr)
        return;

    for (auto &cvor : koren->cvorovi)
        free(cvor.second);

    delete koren;
}

int main()
{
    int n;
    cin >> n;

    vector<string> reci(n);
    for (int i = 0; i < n; i++)
        cin >> reci[i];

    Cvor *koren = napravi_cvor();
    for (string s : reci)
        build(koren, s, 0);

    cout << "Unesite rec koju trazite: ";
    string s;
    cin >> s;

    cout << boolalpha << find(koren, s, 0) << endl;

    free(koren);

    return 0;
}