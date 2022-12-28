#include<iostream>
#include<vector>
#include<algorithm>

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

    int result = determinanta(AB, AC);

    return result == 0 ? 0 : (result > 0 ? 1 : -1);
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

    auto it = prev(it);
    while (orjentacija(*prev(it), *it, t0) == 0)
        it = prev(it);

    reverse(it, tacke.end());
}

bool u_mnogouglu(vector<Tacka> &tacke, Tacka Q)
{
    int n = tacke.size();

    if (orjentacija(tacke[0], tacke[1], Q) != 0 && orjentacija(tacke[tacke.size() - 1], tacke[0], Q) != 0)
        return false;

    int i = 1;
    int j = n-1;

    while (j > i+1) {
        int m = (i+j)/2;

        if (sa_iste_strane_prave(tacke[0], tacke[m], Q, tacke[j]))
            i = m;
        else 
            j = m;
    }

    return u_trouglu(tacke[i], tacke[i+1], tacke[0], Q);
}

int main()
{


    return 0;
}