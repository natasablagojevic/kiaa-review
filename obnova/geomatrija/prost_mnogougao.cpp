#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

struct Tacka
{
    int x;
    int y;
};

int kvadratno_rastojanje(Tacka a, Tacka b)
{
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int determinanta(Tacka a, Tacka b)
{
    return a.x*b.y - a.y*b.x;
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

bool sa_iste_strane_prave(Tacka A, Tacka B, Tacka C, Tacka D)
{
    int ABC = orjentacija(A, B, C);
    int ABD = orjentacija(A, B, D);

    return ABC == ABD;
}

bool u_trouglu(Tacka A, Tacka B, Tacka C, Tacka M)
{
    int ABM = orjentacija(A, B, M);
    int BCM = orjentacija(B, C, M);
    int CAM = orjentacija(C, A, M);

    return ABM == BCM && ABM == CAM && BCM == CAM;
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

int main()
{



    return 0;
}