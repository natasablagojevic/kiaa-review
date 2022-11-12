#include<iostream>
#include<vector>
#include<algorithm>

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

int main()
{


    return 0;
}