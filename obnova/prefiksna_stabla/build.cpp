#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct Cvor
{
    string rec;
    bool list;
    map<char, Cvor *> cvorovi;
};

Cvor *napravi_cvor()
{
    Cvor *novi_cvor = new Cvor();
    novi_cvor->list = false;
    
    return novi_cvor;
}

void dodaj_rec(Cvor *koren, string &rec, int i)
{
    if (i == (int)rec.length()) {
        koren->rec = rec;
        koren->list = true;
        return ;
    }

    auto it = koren->cvorovi.find(rec[i]);

    if (it == koren->cvorovi.end())
        koren->cvorovi[rec[i]] = napravi_cvor();

    dodaj_rec(koren->cvorovi[rec[i]], rec, i + 1);
}

bool nadji_rec(Cvor *koren, string &rec, int i)
{
    if (i == (int)rec.length()) {
        return koren->list;
    }

    auto it = koren->cvorovi.find(rec[i]);

    if (it == koren->cvorovi.end())
        return false;

    return nadji_rec(koren->cvorovi[rec[i]], rec, i + 1);
}

void oslobodi(Cvor *koren)
{
    if (koren == nullptr)
        return ;

    for (auto &cvor : koren->cvorovi)
        oslobodi(cvor.second);

    delete koren;
}

int main()
{
    vector<string> s = {"cod", "coder", "codecs", "coding"};

    Cvor *koren = napravi_cvor();

    for (string pom : s)
        dodaj_rec(koren, pom, 0);


    string pom = "coder";
    cout << boolalpha << nadji_rec(koren, pom, 0) << endl;


    oslobodi(koren);

    return 0;
}