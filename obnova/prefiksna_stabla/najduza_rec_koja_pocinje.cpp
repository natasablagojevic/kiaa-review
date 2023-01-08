#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<climits>

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
    novi->rec = "";

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

void nadji_max_rec(Cvor *koren, string &max_rec)
{
    if (koren->rec != "") {
        if (koren->rec.length() >= max_rec.length()) {
            max_rec = koren->rec;
        } 
    }

    auto begin = koren->cvororvi.begin();
    auto end = koren->cvororvi.end();

    while (begin != end) {
        // cout << "\t\t" << begin->first << endl;
        
        nadji_max_rec(begin->second, max_rec);

        // cout << "----------------" << endl;

        begin++;
    }
}

string max_rec = "";

void LCP(Cvor *koren, string &rec, string &lcp)
{
    // string result = "";

    int i = 0;
    int brojac = 1;
    auto it = koren->cvororvi.find(rec[i++]);
    int max = INT_MIN;

    if ((int)koren->cvororvi.size() > max)
        max = koren->cvororvi.size();

    while (koren != nullptr && it != koren->cvororvi.end()) {
        if ((int)koren->cvororvi.size() > max)
            max = koren->cvororvi.size();

        // result = koren->rec;

        lcp += it->first;
        koren = it->second;
        it = koren->cvororvi.find(rec[i++]);
        brojac++;

        // cout << "\t" << lcp << " " << it->first << " " << "maks: " << max << " size: " << koren->cvororvi.size() << endl;
    }

    nadji_max_rec(koren, max_rec);

/*     auto begin = koren->cvororvi.begin();
    auto end = koren->cvororvi.end();

    while ( koren->cvororvi.begin() != koren->cvororvi.end()) {
        cout << "\t" << begin->first  << " " << begin->second->cvororvi.size() << endl;

        if ((int)begin->second->cvororvi.size() > max) {
            max = begin->second->cvororvi.size();
            cout << "\t" << max << endl;
        }

        begin++;
    } */
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

    cin >> rec;
    string lcp = "";
    string result = "";
    
    LCP(koren, rec, lcp);
    // nadji_max_rec(koren, result, rec);


    if (lcp == "")
        cout << "-1" << endl;
    else 
        cout << max_rec << endl;

    // cout << lcp << endl;

    oslobodi(koren);
    return 0;
}