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

void oslobodi(Cvor *koren)
{
    if (koren == nullptr)
        return ;

    for (auto &cvor : koren->cvorovi)
        oslobodi(cvor.second);

    delete koren;
}

void LCP(Cvor *koren, string &lcp)
{
    while (koren != nullptr && !koren->list && koren->cvorovi.size() == 1) {
        auto element = koren->cvorovi.begin();
        lcp += element->first;
        koren = element->second;
    }
}

int main()
{
    // vector<string> reci = {"cod", "coder", "coding", "codecs"};
    vector<string> reci = {"ana", "anastasija", "anastasijin"};
    Cvor *koren = napravi_cvor();
    string lcp = "";

    for (string &rec : reci)
        build(koren, rec, 0);

    LCP(koren, lcp);

    cout << lcp;

    // string s = "coder";

    // boolalpha nam omogucava da pisemo true i false, a ne 0 ili 1;
    // cout << boolalpha << nadji_rec(koren, s, 0);

    oslobodi(koren);

    return 0;
}