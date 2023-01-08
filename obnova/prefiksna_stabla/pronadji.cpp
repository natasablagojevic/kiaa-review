#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Cvor
{
    bool list;
    string rec;
    map<char, Cvor *> cvorovi;
};

Cvor *napravi_cvor()
{
    Cvor *novi = new Cvor();
    novi->list = false;

    return novi;
}

void dodaj_rec(Cvor *koren, string &rec, int i)
{
    if (i == (int)rec.length()) {
        koren->list = true;
        koren->rec = rec;
        return ;
    }

    auto it = koren->cvorovi.find(rec[i]);
    if (it == koren->cvorovi.end())
        koren->cvorovi[rec[i]] = napravi_cvor();

    dodaj_rec(koren->cvorovi[rec[i]], rec, i + 1);
}

void oslobodi(Cvor *koren)
{
    if (koren == nullptr)
        return ;

    for (auto &cvor : koren->cvorovi)
        oslobodi(cvor.second);

    delete koren;
}

bool pronadji(Cvor *koren, string &rec, int i)
{
    if (i == (int)rec.length())
        return koren->list;

    auto it = koren->cvorovi.find(rec[i]);
    if (it == koren->cvorovi.end())
        return false;

    return pronadji(koren->cvorovi[rec[i]], rec, i + 1);
}

int main()
{
    int n;
    cin >> n;

    string rec;
    Cvor *koren = napravi_cvor();

    for (int i = 0; i < n; i++) {
        cin >> rec;
        dodaj_rec(koren, rec, 0);
    }
    cin >> rec;

    cout << boolalpha << pronadji(koren, rec, 0) << endl;

    oslobodi(koren);

    return 0;
}