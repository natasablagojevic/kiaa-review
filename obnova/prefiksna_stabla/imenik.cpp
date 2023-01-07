#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

struct Cvor
{
    bool list;
    string rec;
    map<char, Cvor *> cvorovi;
    map<char, int> brojac;
};

Cvor *napravi_cvor()
{
    Cvor *novi = new Cvor();
    novi->list = false;

    return novi;
}

void dodaj_rec(Cvor *koren, string &rec)
{
    int n = rec.length();
    for (int i = 0; i < n; i++) {
        auto it = koren->cvorovi.find(rec[i]);
        
        if (it == koren->cvorovi.end()) {
            koren->cvorovi[rec[i]] = napravi_cvor();
            koren->brojac[rec[i]] = 1;
        } else {
            koren->brojac[rec[i]] += 1;
        }

        koren = koren->cvorovi[rec[i]];
    }

    koren->rec = rec;
    koren->list = true;
}

void oslobodi(Cvor *koren)
{
    if (koren == nullptr)
        return ;

    for (auto &cvor : koren->cvorovi)
        oslobodi(cvor.second);

    delete koren;
}

int prebroj(Cvor *koren, string &prefiks)
{
    int brojac = 0;
    int n = prefiks.length();

    for (int i = 0; i < n; i++) {
        if (koren->cvorovi.find(prefiks[i]) == koren->cvorovi.end()) {
            brojac = 0;
            break;
        }

        brojac = koren->brojac[prefiks[i]];
        koren = koren->cvorovi[prefiks[i]];
    }

    return brojac;
}

int main()
{
    int n;
    cin >> n;
    string command;
    string prefiks;
    Cvor *koren = napravi_cvor();

    while (n--) {
        cin >> command;
        if (command == "add") {
            cin >> prefiks;
            dodaj_rec(koren, prefiks);
        }

        if (command == "find") {
            cin >> prefiks;
            cout << prebroj(koren, prefiks) << endl;
        }
    }

    return 0;
}