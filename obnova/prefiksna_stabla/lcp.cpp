#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

struct Cvor
{
    bool list;
    string rec;
    map<char, Cvor *> cvororvi;
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

    auto it = koren->cvororvi.find(rec[i]);
    if (it == koren->cvororvi.end())
        koren->cvororvi[rec[i]] = napravi_cvor();

    dodaj_rec(koren->cvororvi[rec[i]], rec, i + 1);
}

void dodaj_rec(Cvor *koren, string &rec)
{
    int n = rec.length();

    for (int i = 0; i < n; i++) {
        if (koren->cvororvi.find(rec[i]) == koren->cvororvi.end()) 
            koren->cvororvi[rec[i]] = napravi_cvor();

        koren = koren->cvororvi[rec[i]];
    }

    koren->list = true;
    koren->rec = rec;
}

void oslobodi(Cvor *koren)
{
    if (koren == nullptr)
        return ;

    for (auto &cvor : koren->cvororvi)
        oslobodi(cvor.second);

    delete koren;
}

void ispisi_leksikografski(Cvor *koren)
{
    if (koren->rec != "") 
        cout << koren->rec << endl;

    auto begin = koren->cvororvi.begin();
    auto end = koren->cvororvi.end();

    while (begin != end) {
        ispisi_leksikografski(begin->second);
        begin++;
    }
}

void LCP(Cvor *koren, string &lcp)
{
    while (koren != nullptr && !koren->list && koren->cvororvi.size() == 1) {
        auto element = koren->cvororvi.begin();
        lcp += element->first;
        koren = element->second;
    }
}

int main()
{
    int n;
    cin >> n;

    string rec;
    Cvor *koren = napravi_cvor();

    for (int i = 0; i < n; i++) {
        cin >> rec;
        dodaj_rec(koren, rec);
    }

    string lcp = "";

    LCP(koren, lcp);

    cout << lcp << endl;

    oslobodi(koren);
    return 0;
}