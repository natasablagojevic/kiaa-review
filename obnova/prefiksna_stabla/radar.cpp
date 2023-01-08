#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Tacka
{
    int x;
    int y;
};

int kvadrat_rastojanja(Tacka A, Tacka B)
{
    return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
}

int determinanta(Tacka A, Tacka B)
{
    return A.x*B.y - A.y*B.x;
}

/* 
    0 - kolinearne
    1 - pozitivna
    -1 - negativna
 */
int orjentacija(Tacka A, Tacka B, Tacka C)
{
    Tacka AB;
    AB.x = B.x - A.x, AB.y = B.y - A.y;

    Tacka AC;
    AC.x = C.x - A.x, AC.y = C.y - A.y;

    int res = determinanta(AB, AC);

    return res == 0 ? 0 : (res > 0 ? 1 : -1);
}

void prost_mnogougao(vector<Tacka> &tacke)
{
    auto max = max_element(tacke.begin(), tacke.end(), [](Tacka &t1, Tacka &t2) {
        return t1.x < t2.x || (t1.x == t2.x && t1.y > t2.y);
    });

    swap(*tacke.begin(), *max);

    const Tacka &t0 = {0, 0};

    sort(tacke.begin(), tacke.end(), [t0](Tacka &t1, Tacka &t2) {
        int orj = orjentacija(t0, t1, t2);

        if (orj == 0)
            return kvadrat_rastojanja(t0, t1) <= kvadrat_rastojanja(t0, t2);

        return orj == 1;
    });

    auto it = prev(tacke.end());
    while (orjentacija(*prev(it), *it, t0) == 0)
        it = prev(it);

    reverse(it, tacke.end());
}

void print_points(vector<Tacka> &tacke)
{
    prost_mnogougao(tacke);
    cout << endl;

    for (Tacka t : tacke)
        cout << t.x << " " << t.y << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<Tacka> tacke(n);
    for (int i = 0; i < n; i++)
        cin >> tacke[i].x >> tacke[i].y;

    print_points(tacke);


    return 0;
}