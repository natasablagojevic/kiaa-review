#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Tacka
{
    int x;
    int y;
};

int kvadratno_rastojanje(Tacka A, Tacka B)
{
    return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
}

int determinanta(Tacka A, Tacka B)
{
    return A.x*B.y - A.y*B.x;
}

int orjentacija(Tacka A, Tacka B, Tacka C)
{
    Tacka AB;
    AB.x = B.x - A.x, AB.y = B.y - A.y;

    Tacka AC;
    AC.x = C.x - A.x, AC.y = C.y - A.y;

    int res = determinanta(AB, AC);
    
    return res == 0 ? 0 : (res > 0 ? 1 : -1);
}

bool u_trouglu(Tacka A, Tacka B, Tacka C, Tacka M)
{
    int ABM = orjentacija(A, B, M);
    int BCM = orjentacija(B, C, M);
    int CAM = orjentacija(C, A, M);

    return ABM == BCM && ABM == CAM && BCM == CAM;
}

bool sa_iste_strane_prave(Tacka A, Tacka B, Tacka C, Tacka D)
{
    int ABC = orjentacija(A, B, C);
    int ABD = orjentacija(A, B, D);

    return ABC == ABD;
}

void prost_mnogougao(vector<Tacka> &tacke)
{
    auto max = max_element(tacke.begin(), tacke.end(), [](Tacka &t1, Tacka &t2) {
        return t1.x < t2.x || (t1.x == t2.x && t1.y > t2.y);
    });

    swap(*tacke.begin(), *max);

    const Tacka &t0 = tacke[0];

    sort(tacke.begin() + 1, tacke.end(), [t0](Tacka &t1, Tacka &t2) {
        int orj = orjentacija(t0, t1, t2);

        if (orj == 0)
            return kvadratno_rastojanje(t0, t1) <= kvadratno_rastojanje(t0, t2);

        return orj == 1;
    });

    auto it = prev(tacke.end());
    while (orjentacija(*prev(it), *it, t0) == 0)
        it = prev(it);

    reverse(it, tacke.end());
}

vector<Tacka> konveksan_omotac(vector<Tacka> &tacke)
{
    prost_mnogougao(tacke);

    int n = tacke.size();
    vector<Tacka> omotac;

    omotac.push_back(tacke[0]);
    omotac.push_back(tacke[1]);

    for (int i = 2; i < n; i++) {
        while (omotac.size() >= 2 && orjentacija(omotac[omotac.size() - 2], omotac[omotac.size() - 1], tacke[i]) != 1)
            omotac.pop_back();

        omotac.push_back(tacke[i]);
    }

    return omotac;
}

int main()
{


    return 0;
}