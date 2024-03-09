// Karolina Kulas
#include <iostream>
using namespace std;
struct Miejsce
{
    unsigned short int towar;
    char etykieta[2];
};
struct Polka
{
    Miejsce miejsce[128];
    unsigned short int rozmiar;
};
struct Regal
{
    Polka polka[128];
    unsigned short int rozmiar;
    unsigned long long s;
};
struct Magazyn
{
    Regal regal[128];
    unsigned short int rozmiar;
    unsigned short int s;
    Polka podreczna_polka;
};
struct Sklad
{
    Magazyn magazyn[128];
    unsigned short int rozmiar;
    Regal podreczny_regal;
    Polka podreczna_polka;
};
Sklad sklad;
long long sumasumasuma = 0;
long long sumasuma()
{
    long long sumka = 0;
    for (int i = 0; i < sklad.rozmiar; i++)
    {
        for (int j = 0; j < sklad.magazyn[i].rozmiar; j++)
        {
            for (int k = 0; k < sklad.magazyn[i].regal[j].rozmiar; k++)
            {
                for (int l = 0; l < sklad.magazyn[i].regal[j].polka[k].rozmiar; l++)
                    sumka += sklad.magazyn[i].regal[j].polka[k].miejsce[l].towar;
            }
        }
        for (int n = 0; n < sklad.magazyn[i].podreczna_polka.rozmiar; n++)
            sumka += sklad.magazyn[i].podreczna_polka.miejsce[n].towar;
    }
    for (int i = 0; i < sklad.podreczna_polka.rozmiar; i++)
        sumka += sklad.podreczna_polka.miejsce[i].towar;
    for (int i = 0; i < sklad.podreczny_regal.rozmiar; i++)
    {
        for (int j = 0; j < sklad.podreczny_regal.polka[i].rozmiar; j++)
            sumka += sklad.podreczny_regal.polka[i].miejsce[j].towar;
    }
    return sumka;
}
void SETAP(int w, int r, int s, int p)
{
    if ( w >= 0 && sklad.rozmiar > w  && r >= 0 && s >= 0 && sklad.magazyn[w].rozmiar > r && p <= 128 && p >= 0 && sklad.magazyn[w].regal[r].rozmiar > s)
    {
        int rozmiar0 = sklad.magazyn[w].regal[r].polka[s].rozmiar;
        sklad.magazyn[w].regal[r].polka[s].rozmiar = p;
        if (rozmiar0 > p)
        {
            for (int i = p; i < rozmiar0; i++)
            {
                sklad.magazyn[w].regal[r].polka[s].miejsce[i].etykieta[0] = 0;
                sklad.magazyn[w].regal[r].polka[s].miejsce[i].etykieta[1] = 0;
                sklad.magazyn[w].regal[r].polka[s].miejsce[i].towar = 0;
            }
        }
        else
        {
            for (int i = rozmiar0; i < p; i++)
            {
                sklad.magazyn[w].regal[r].polka[s].miejsce[i].etykieta[0] = 0;
                sklad.magazyn[w].regal[r].polka[s].miejsce[i].etykieta[1] = 0;
                sklad.magazyn[w].regal[r].polka[s].miejsce[i].towar = 0;
            }
        }
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void SETAS(int w, int r, int s, int p)
{
    if (w <= 128 && w >= 0 && r <= 128 && r >= 0 && s <= 128 && s >= 0 && p <= 128 && p >= 0 && sklad.magazyn[w].rozmiar > r && sklad.rozmiar > w)
    {
        int rozmiar0 = sklad.magazyn[w].regal[r].rozmiar;
        sklad.magazyn[w].regal[r].rozmiar = s;
        if (rozmiar0 < s)
        {
            for (int i = rozmiar0; i < s; i++)
            {
                for (int j = 0; j < sklad.magazyn[w].regal[r].polka[i].rozmiar; j++)
                {
                    sklad.magazyn[w].regal[r].polka[i].miejsce[j].etykieta[0] = 0;
                    sklad.magazyn[w].regal[r].polka[i].miejsce[j].etykieta[1] = 0;
                    sklad.magazyn[w].regal[r].polka[i].miejsce[j].towar = 0;
                }
                sklad.magazyn[w].regal[r].polka[i].rozmiar = p;
            }
            for (int i = 0; i < rozmiar0; i++)
            {
                SETAP(w, r, i, p);
            }
        }
        else
        {
            for (int i = 0; i < s; i++)
            {
                SETAP(w, r, i, p);
            }
            for (int i = s; i < rozmiar0; i++)
            {
                for (int j = 0; j < sklad.magazyn[w].regal[r].polka[i].rozmiar; j++)
                {
                    sklad.magazyn[w].regal[r].polka[i].miejsce[j].etykieta[0] = 0;
                    sklad.magazyn[w].regal[r].polka[i].miejsce[j].etykieta[1] = 0;
                    sklad.magazyn[w].regal[r].polka[i].miejsce[j].towar = 0;
                }
                sklad.magazyn[w].regal[r].polka[i].rozmiar = 0;
            }
        }
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void SETAR(int w, int r, int s, int p)
{
    if (w <= 128 && w >= 0 && r <= 128 && r >= 0 && s <= 128 && s >= 0 && p <= 128 && p >= 0 && sklad.rozmiar > w)
    {
        int rozmiar0 = sklad.magazyn[w].rozmiar;
        sklad.magazyn[w].rozmiar = r;
        if (rozmiar0 < r)
        {
            for (int i = rozmiar0; i < r; i++)
            {
                sklad.magazyn[w].regal[i].rozmiar = s;
                for (int j = 0; j < s; j++)
                {
                    sklad.magazyn[w].regal[i].polka[j].rozmiar = p;
                    for (int k = 0; k < p; k++)
                    {
                        sklad.magazyn[w].regal[i].polka[j].miejsce[k].towar = 0;
                        sklad.magazyn[w].regal[i].polka[j].miejsce[k].etykieta[0] = 0;
                        sklad.magazyn[w].regal[i].polka[j].miejsce[k].etykieta[1] = 0;
                    }
                }
            }
            for (int i = 0; i < rozmiar0; i++)
            {
                SETAS(w, i, s, p);
            }
        }
        else
        {
            for (int i = 0; i < r; i++)
            {
                SETAS(w, i, s, p);
            }
            for (int i = r; i < rozmiar0; i++)
            {
                for (int j = 0; j < sklad.magazyn[w].regal[i].rozmiar; j++)
                {
                    for (int k = 0; k < sklad.magazyn[w].regal[i].polka[j].rozmiar; k++)
                    {
                        sklad.magazyn[w].regal[i].polka[j].miejsce[k].towar = 0;
                        sklad.magazyn[w].regal[i].polka[j].miejsce[k].etykieta[0] = 0;
                        sklad.magazyn[w].regal[i].polka[j].miejsce[k].etykieta[1] = 0;
                    }
                    sklad.magazyn[w].regal[i].polka[j].rozmiar = 0;
                }
                sklad.magazyn[w].regal[i].rozmiar = 0;
            }
        }
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void SETAW(int w, int r, int s, int p)
{
    if (w <= 128 && w >= 0 && r <= 128 && r >= 0 && s <= 128 && s >= 0 && p <= 128 && p >= 0)
    {
        if (sklad.rozmiar > w)
        {
            for (int i = w; i < sklad.rozmiar; i++)
            {
                for (int j = 0; j < sklad.magazyn[i].rozmiar; j++)
                {
                    for (int k = 0; k < sklad.magazyn[i].regal[j].rozmiar; k++)
                    {
                        for (int l = 0; l < sklad.magazyn[i].regal[j].polka[k].rozmiar; l++)
                        {
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].towar = 0;
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].etykieta[0] = 0;
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].etykieta[1] = 0;
                        }
                        sklad.magazyn[i].regal[j].polka[k].rozmiar = 0;
                    }
                    sklad.magazyn[i].regal[j].rozmiar = 0;
                }
                sklad.magazyn[i].rozmiar = 0;
            }
            for(int i=w;i<sklad.rozmiar;i++)
            {
                for(int j=0;j<sklad.magazyn[i].podreczna_polka.rozmiar;j++)
                {
                    sklad.magazyn[i].podreczna_polka.miejsce[j].towar=0;
                    sklad.magazyn[i].podreczna_polka.miejsce[j].etykieta[0]=0;
                    sklad.magazyn[i].podreczna_polka.miejsce[j].etykieta[1]=0;
                }
                sklad.magazyn[i].podreczna_polka.rozmiar=0;
            }
            for (int i = 0; i < w; i++)
                SETAR(i, r, s, p);
        }
        else
        {
            for (int i = sklad.rozmiar; i < w; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    for (int k = 0; k < s; k++)
                    {
                        for (int l = 0; l < p; l++)
                        {
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].towar = 0;
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].etykieta[0] = 0;
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].etykieta[1] = 0;
                        }
                        sklad.magazyn[i].regal[j].polka[k].rozmiar = p;
                    }
                    sklad.magazyn[i].regal[j].rozmiar = s;
                }
                sklad.magazyn[i].rozmiar = r;
            }
            for(int i=sklad.rozmiar;i<w;i++)
            {
                for(int j=0;j<sklad.magazyn[i].podreczna_polka.rozmiar;j++)
                {
                    sklad.magazyn[i].podreczna_polka.miejsce[j].towar=0;
                    sklad.magazyn[i].podreczna_polka.miejsce[j].etykieta[0]=0;
                    sklad.magazyn[i].podreczna_polka.miejsce[j].etykieta[1]=0;
                }
                sklad.magazyn[i].podreczna_polka.rozmiar=p;
            }
            for (int i = 0; i < sklad.rozmiar; i++)
                SETAR(i, r, s, p);
        }
        sklad.rozmiar = w;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void SETHW(int w, int p)
{
    if (sklad.rozmiar > w && w >= 0 && 128 > p && p >= 0)
    {
        int pom = sklad.magazyn[w].podreczna_polka.rozmiar;
        sklad.magazyn[w].podreczna_polka.rozmiar = p;
        if (pom > p)
        {
            for (int i = p; i < pom; i++)
            {
                sklad.magazyn[w].podreczna_polka.miejsce[i].etykieta[0] = 0;
                sklad.magazyn[w].podreczna_polka.miejsce[i].etykieta[1] = 0;
                sklad.magazyn[w].podreczna_polka.miejsce[i].towar = 0;
            }
        }
        else
        {
            for (int i = pom; i < p; i++)
            {
                sklad.magazyn[w].podreczna_polka.miejsce[i].etykieta[0] = 0;
                sklad.magazyn[w].podreczna_polka.miejsce[i].etykieta[1] = 0;
                sklad.magazyn[w].podreczna_polka.miejsce[i].towar = 0;
            }
        }
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void SETHR(int s, int p)
{
    if (128 >= s && s >= 0 && 128 >= p && p >= 0)
    {
        int som = sklad.podreczny_regal.rozmiar;
        sklad.podreczny_regal.rozmiar = s;
        if (som > s)
        {
            for (int i = s; i < som; i++)
            {
                for (int j = 0; j < sklad.podreczny_regal.polka[i].rozmiar; j++)
                {
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[0] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[1] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].towar = 0;
                }
                sklad.podreczny_regal.polka[i].rozmiar = 0;
            }
            for (int i = 0; i < s; i++)
            {
                for (int j = sklad.podreczny_regal.polka[i].rozmiar; j < p; j++)
                {
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[0] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[1] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].towar = 0;
                }
                for (int j = p; j < sklad.podreczny_regal.polka[i].rozmiar; j++)
                {
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[0] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[1] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].towar = 0;
                }
                sklad.podreczny_regal.polka[i].rozmiar = p;
            }
        }
        else
        {
            for (int i = 0; i < s; i++)
            {
                for (int j = sklad.podreczny_regal.polka[i].rozmiar; j < p; j++)
                {
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[0] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[1] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].towar = 0;
                }
                for (int j = p; j < sklad.podreczny_regal.polka[i].rozmiar; j++)
                {
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[0] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].etykieta[1] = 0;
                    sklad.podreczny_regal.polka[i].miejsce[j].towar = 0;
                }
                sklad.podreczny_regal.polka[i].rozmiar = p;
            }
        }
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void SETHS(int p)
{
    if (128 >= p && p >= 0)
    {
        int pom = sklad.podreczna_polka.rozmiar;
        sklad.podreczna_polka.rozmiar = p;
        if (pom < p)
        {
            for (int i = pom; i < p; i++)
            {
                sklad.podreczna_polka.miejsce[i].towar = 0;
                sklad.podreczna_polka.miejsce[i].etykieta[0] = 0;
                sklad.podreczna_polka.miejsce[i].etykieta[1] = 0;
            }
        }
        else
        {
            for (int i = p; i < pom; i++)
            {
                sklad.podreczna_polka.miejsce[i].towar = 0;
                sklad.podreczna_polka.miejsce[i].etykieta[0] = 0;
                sklad.podreczna_polka.miejsce[i].etykieta[1] = 0;
            }
        }
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void FILL(long long w, long long r, long long s, long long p, long long a)
{
    if (128 >= w && w >= 0 && 128 >= r && r >= 0 && 128 >= s && s >= 0 && 128 >= p && p >= 0 && a >= 0 && a <= 65535)
    {
        sumasumasuma = w * r * s * p * a + w * p * a + s * p * a + p * a;
        for (int l = p; l < 128; l++)
        {
            sklad.podreczna_polka.miejsce[l].towar = 0;
            sklad.podreczna_polka.miejsce[l].etykieta[0] = 0;
            sklad.podreczna_polka.miejsce[l].etykieta[1] = 0;
        }
        for (int k = s; k < 128; k++)
        {
            sklad.podreczny_regal.polka[k].rozmiar = 0;
            for (int l = p; l < 128; l++)
            {
                sklad.podreczny_regal.polka[k].miejsce[l].towar = 0;
                sklad.podreczny_regal.polka[k].miejsce[l].etykieta[0] = 0;
                sklad.podreczny_regal.polka[k].miejsce[l].etykieta[1] = 0;
            }
        }
        for (int i = w; i < 128; i++)
        {
            sklad.magazyn[i].rozmiar = 0;
            sklad.magazyn[i].podreczna_polka.rozmiar = 0;
            for (int l = p; l < 128; l++)
            {
                sklad.magazyn[i].podreczna_polka.miejsce[l].towar = 0;
                sklad.magazyn[i].podreczna_polka.miejsce[l].etykieta[0] = 0;
                sklad.magazyn[i].podreczna_polka.miejsce[l].etykieta[1] = 0;
            }
            for (int j = r; j < 128; j++)
            {
                sklad.magazyn[i].regal[j].rozmiar = 0;
                for (int k = s; k < 128; k++)
                {
                    sklad.magazyn[i].regal[j].polka[k].rozmiar = 0;
                    for (int l = p; l < 128; l++)
                    {
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].towar = 0;
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].etykieta[0] = 0;
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].etykieta[1] = 0;
                    }
                }
            }
        }
        sklad.rozmiar = w;
        sklad.podreczna_polka.rozmiar = p;
        for (int l = 0; l < p; l++)
        {
            sklad.podreczna_polka.miejsce[l].towar = a;
            sklad.podreczna_polka.miejsce[l].etykieta[0] = 0;
            sklad.podreczna_polka.miejsce[l].etykieta[1] = 0;
        }
        sklad.podreczny_regal.rozmiar = s;
        for (int k = 0; k < s; k++)
        {
            sklad.podreczny_regal.polka[k].rozmiar = p;
            for (int l = 0; l < p; l++)
            {
                sklad.podreczny_regal.polka[k].miejsce[l].towar = a;
                sklad.podreczny_regal.polka[k].miejsce[l].etykieta[0] = 0;
                sklad.podreczny_regal.polka[k].miejsce[l].etykieta[1] = 0;
            }
        }
        for (int i = 0; i < w; i++)
        {
            sklad.magazyn[i].rozmiar = r;
            sklad.magazyn[i].podreczna_polka.rozmiar = p;
            for (int l = 0; l < p; l++)
            {
                sklad.magazyn[i].podreczna_polka.miejsce[l].towar = a;
                sklad.magazyn[i].podreczna_polka.miejsce[l].etykieta[0] = 0;
                sklad.magazyn[i].podreczna_polka.miejsce[l].etykieta[1] = 0;
            }
            for (int j = 0; j < r; j++)
            {
                sklad.magazyn[i].regal[j].rozmiar = s;
                for (int k = 0; k < s; k++)
                {
                    sklad.magazyn[i].regal[j].polka[k].rozmiar = p;
                    for (int l = 0; l < p; l++)
                    {
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].towar = a;
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].etykieta[0] = 0;
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].etykieta[1] = 0;
                    }
                }
            }
        }
    }
}
void POPW(int w, int r, int s, int p, long long a)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0 && sklad.magazyn[w].regal[r].rozmiar > s && s >= 0 && sklad.magazyn[w].regal[r].polka[s].rozmiar > p && p >= 0 && a >= 0 && a <= 65535)
    {
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar > a ? sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar -= a : sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar = 0;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void POPH(int w, int p, long long a)
{
    if (sklad.rozmiar > w && w >= 0 && a >= 0 && a <= 65535 && sklad.magazyn[w].podreczna_polka.rozmiar > p && p >= 0)
    {
        sklad.magazyn[w].podreczna_polka.miejsce[p].towar > a ? sklad.magazyn[w].podreczna_polka.miejsce[p].towar -= a : sklad.magazyn[w].podreczna_polka.miejsce[p].towar = 0;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void POPR(int s, int p, long long a)
{
    if (sklad.podreczny_regal.rozmiar > s && s >= 0 && sklad.podreczny_regal.polka[s].rozmiar > p && p >= 0 && a >= 0 && a <= 65535)
    {
        sklad.podreczny_regal.polka[s].miejsce[p].towar > a ? sklad.podreczny_regal.polka[s].miejsce[p].towar -= a : sklad.podreczny_regal.polka[s].miejsce[p].towar = 0;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void POPS(int p, long long a)
{
    if (sklad.podreczna_polka.rozmiar > p && p >= 0 && a >= 0 && a <= 65535)
    {
        sklad.podreczna_polka.miejsce[p].towar > a ? sklad.podreczna_polka.miejsce[p].towar -= a : sklad.podreczna_polka.miejsce[p].towar = 0;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void PUTW(int w, int r, int s, int p, long long a)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0 && sklad.magazyn[w].regal[r].rozmiar > s && s >= 0 && sklad.magazyn[w].regal[r].polka[s].rozmiar > p && p >= 0 && a >= 0 && a <= 65535)
    {
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar <= 65535 - a ? sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar += a : sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar = 65535;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void PUTH(int w, int p, long long a)
{
    if (sklad.rozmiar > w && w >= 0 && a >= 0 && a <= 65535 && sklad.magazyn[w].podreczna_polka.rozmiar > p && p >= 0)
    {
        sklad.magazyn[w].podreczna_polka.miejsce[p].towar <= 65535 - a ? sklad.magazyn[w].podreczna_polka.miejsce[p].towar += a : sklad.magazyn[w].podreczna_polka.miejsce[p].towar = 65535;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void PUTR(int s, int p, long long a)
{
    if (sklad.podreczny_regal.rozmiar > s && s >= 0 && sklad.podreczny_regal.polka[s].rozmiar > p && p >= 0 && a >= 0 && a <= 65535)
    {
        sklad.podreczny_regal.polka[s].miejsce[p].towar <= 65535 - a ? sklad.podreczny_regal.polka[s].miejsce[p].towar += a : sklad.podreczny_regal.polka[s].miejsce[p].towar = 65535;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void PUTS(int p, long long a)
{
    if (sklad.podreczna_polka.rozmiar > p && p >= 0 && a >= 0 && a <= 65535)
    {
        sklad.podreczna_polka.miejsce[p].towar <= 65535 - a ? sklad.podreczna_polka.miejsce[p].towar += a : sklad.podreczna_polka.miejsce[p].towar = 65535;
    }
    else
        cout << "error" << endl;
    sumasumasuma = sumasuma();
}
void MOVW(int w, int r, int s, int w1, int r1, int s1, int p, long long a)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0 && sklad.magazyn[w].regal[r].rozmiar > s && s >= 0 && sklad.magazyn[w].regal[r].polka[s].rozmiar > p && p >= 0 && sklad.rozmiar > w1 && w1 >= 0 && sklad.magazyn[w1].rozmiar > r1 && r1 >= 0 && sklad.magazyn[w1].regal[r1].rozmiar > s1 && s1 >= 0 && sklad.magazyn[w1].regal[r1].polka[s1].rozmiar > p && 65535 >= a && a >= 0)
    {
        if (a > sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar)
            a = sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar;
        if (sklad.magazyn[w1].regal[r1].polka[s1].miejsce[p].towar + a > 65535)
            a = 65535 - sklad.magazyn[w1].regal[r1].polka[s1].miejsce[p].towar;
        POPW(w, r, s, p, a);
        PUTW(w1, r1, s1, p, a);
    }
    else
        cout << "error" << endl;
}
void MOVH(int w, int r, int s, int p, long long a)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0 && sklad.magazyn[w].regal[r].rozmiar > s && s >= 0 && sklad.magazyn[w].regal[r].polka[s].rozmiar > p && p >= 0 && 65535 >= a && a >= 0 && sklad.magazyn[w].podreczna_polka.rozmiar > p)
    {
        if (a > sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar)
            a = sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar;
        if (sklad.magazyn[w].podreczna_polka.miejsce[p].towar + a > 65535)
            a = 65535 - sklad.magazyn[w].podreczna_polka.miejsce[p].towar;
        POPW(w, r, s, p, a);
        PUTH(w, p, a);
    }
    else
        cout << "error" << endl;
}
void MOVR(int w, int r, int s, int s1, int p, int a)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0 && sklad.magazyn[w].regal[r].rozmiar > s && s >= 0 && sklad.magazyn[w].regal[r].polka[s].rozmiar > p && p >= 0 && 65535 >= a && a >= 0 && sklad.podreczny_regal.rozmiar>s1 &&  s1>=0 && sklad.podreczny_regal.polka[s1].rozmiar > p)
    {
        if (a > sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar)
            a = sklad.magazyn[w].regal[r].polka[s].miejsce[p].towar;
        if (sklad.podreczny_regal.polka[s1].miejsce[p].towar  > 65535-a)
            a = 65535 - sklad.podreczny_regal.polka[s1].miejsce[p].towar;
        POPW(w, r, s, p, a);
        PUTR(s1, p, a);
    }
    else
        cout << "error" << endl;
}
void MOVS(int s, int p, int a)
{
    if (sklad.podreczny_regal.rozmiar > s && s >= 0 && sklad.podreczny_regal.polka[s].rozmiar > p && p >= 0 && sklad.podreczna_polka.rozmiar > p && a >= 0)
    {
        if (a > sklad.podreczny_regal.polka[s].miejsce[p].towar)
            a = sklad.podreczny_regal.polka[s].miejsce[p].towar;
        if (sklad.podreczna_polka.miejsce[p].towar > 65535-a)
            a = 65535 - sklad.podreczna_polka.miejsce[p].towar;
        POPR(s, p, a);
        PUTS(p, a);
    }
    else
        cout << "error" << endl;
}
long long GETS()
{
    long long suma = 0;
    for (int i = 0; i < sklad.podreczna_polka.rozmiar; i++)
        suma += sklad.podreczna_polka.miejsce[i].towar;
    return suma;
}
long long GETSR(long long s)
{
    long long suma = 0;
    for (int i = 0; i < sklad.podreczny_regal.polka[s].rozmiar; i++)
        suma += sklad.podreczny_regal.polka[s].miejsce[i].towar;
    return suma;
}
long long GETSH(long long w)
{
    long long suma = 0;
    for (int i = 0; i < sklad.magazyn[w].podreczna_polka.rozmiar; i++)
        suma += sklad.magazyn[w].podreczna_polka.miejsce[i].towar;
    return suma;
}
long long GETSW(long long w, long long r, long long s)
{
    long long suma = 0;
    for (int i = 0; i < sklad.magazyn[w].regal[r].polka[s].rozmiar; i++)
        suma += sklad.magazyn[w].regal[r].polka[s].miejsce[i].towar;
    return suma;
}
long long GETRH()
{
    long long suma = 0;
    for (int i = 0; i < sklad.podreczny_regal.rozmiar; i++)
    {
        for (int j = 0; j < sklad.podreczny_regal.polka[i].rozmiar; j++)
        {
            suma += sklad.podreczny_regal.polka[i].miejsce[j].towar;
        }
    }
    return suma;
}
long long GETRW(long long w, long long r)
{
    long long suma = 0;
    for (int i = 0; i < sklad.magazyn[w].regal[r].rozmiar; i++)
        suma += GETSW(w, r, i);
    return suma;
}
long long GETW(long long w)
{
    long long suma = 0;
    for (int i = 0; i < sklad.magazyn[w].rozmiar; i++)
        suma += GETRW(w, i);
    suma += GETSH(w);
    return suma;
}
long long GETE()
{
    return sumasumasuma;
}
void GETLW(int w, int r, int s, int p)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0 && sklad.magazyn[w].regal[r].rozmiar > s && s >= 0 && sklad.magazyn[w].regal[r].polka[s].rozmiar > p && p >= 0)
    {
        if(sklad.magazyn[w].regal[r].polka[s].miejsce[p].etykieta[0]!=0&&sklad.magazyn[w].regal[r].polka[s].miejsce[p].etykieta[1]!=0)
        cout << sklad.magazyn[w].regal[r].polka[s].miejsce[p].etykieta[0] << sklad.magazyn[w].regal[r].polka[s].miejsce[p].etykieta[1] << endl;
        else cout<<"--"<<endl;
    }
    else
        cout << "error" << endl;
}
void GETLH(int w, int p)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].podreczna_polka.rozmiar > p && p >= 0)
    {
        if(sklad.magazyn[w].podreczna_polka.miejsce[p].etykieta[0]!=0&&sklad.magazyn[w].podreczna_polka.miejsce[p].etykieta[1]!=0)
        cout << sklad.magazyn[w].podreczna_polka.miejsce[p].etykieta[0] << sklad.magazyn[w].podreczna_polka.miejsce[p].etykieta[1] << endl;
        else cout<<"--"<<endl;
    }
    else
        cout << "error" << endl;
}
void GETLR(int s, int p)
{
    if (sklad.podreczny_regal.rozmiar > s && s >= 0 && sklad.podreczny_regal.polka[s].rozmiar > p && p >= 0)
    {
        if(sklad.podreczny_regal.polka[s].miejsce[p].etykieta[0]!=0&&sklad.podreczny_regal.polka[s].miejsce[p].etykieta[1]!=0)
        cout << sklad.podreczny_regal.polka[s].miejsce[p].etykieta[0] << sklad.podreczny_regal.polka[s].miejsce[p].etykieta[0] << endl;
        else cout<<"--"<<endl;
    }
    else
        cout << "error" << endl;
}
void GETLS(int p)
{
    if (sklad.podreczna_polka.rozmiar > p && p >= 0)
    {
        if(sklad.podreczna_polka.miejsce[p].etykieta[0]!=0&&sklad.podreczna_polka.miejsce[p].etykieta[1]!=0)
        cout << sklad.podreczna_polka.miejsce[p].etykieta[0] << sklad.podreczna_polka.miejsce[p].etykieta[1] << endl;
        else cout<<"--"<<endl;
    }
    else
        cout << "error" << endl;
}
void SETLW(int w, int r, int s, int p, char d0, char d1)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0 && sklad.magazyn[w].regal[r].rozmiar > s && s >= 0 && sklad.magazyn[w].regal[r].polka[s].rozmiar > p && p >= 0&& d0<='9'&&d0>='0'&&d1<='9'&&d1>='0')
    {
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].etykieta[0] = d0;
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].etykieta[1] = d1;
    }
    else
        cout << "error" << endl;
}
void SETLH(int w, int p, char d0, char d1)
{
    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].podreczna_polka.rozmiar > p && p >= 0&& d0<='9'&&d0>='0'&&d1<='9'&&d1>='0')
    {
        sklad.magazyn[w].podreczna_polka.miejsce[p].etykieta[0] = d0;
        sklad.magazyn[w].podreczna_polka.miejsce[p].etykieta[1] = d1;
    }
    else
        cout << "error" << endl;
}
void SETLR(int s, int p, char d0, char d1)
{
    if (sklad.podreczny_regal.rozmiar > s && s >= 0 && sklad.podreczny_regal.polka[s].rozmiar > p && p >= 0&& d0<='9'&&d0>='0'&&d1<='9'&&d1>='0')
    {
        sklad.podreczny_regal.polka[s].miejsce[p].etykieta[0] = d0;
        sklad.podreczny_regal.polka[s].miejsce[p].etykieta[1] = d1;
    }
    else
        cout << "error" << endl;
}
void SETLS(int p, char d0, char d1)
{
    if (sklad.podreczna_polka.rozmiar > p && p >= 0 && d0<='9'&&d0>='0'&&d1<='9'&&d1>='0')
    {
        sklad.podreczna_polka.miejsce[p].etykieta[0] = d0;
        sklad.podreczna_polka.miejsce[p].etykieta[1] = d1;
    }
    else
        cout << "error" << endl;
}
int main()
{
    char polecenie[7];
    int w, r, s, p, a;
    polecenie[0] = '0';
    while (polecenie[0] != 'E')
    {
        cin >> polecenie;
        if (polecenie[0] == 'S')
        {
            if (polecenie[4] == 'A')
            {
                if (polecenie[5] == 'P')
                {
                    cin >> w >> r >> s >> p;
                    SETAP(w, r, s, p);
                }
                if (polecenie[5] == 'S')
                {
                    cin >> w >> r >> s >> p;
                    SETAS(w, r, s, p);
                }
                if (polecenie[5] == 'R')
                {
                    cin >> w >> r >> s >> p;
                    SETAR(w, r, s, p);
                }
                if (polecenie[5] == 'W')
                {
                    cin >> w >> r >> s >> p;
                    SETAW(w, r, s, p);
                }
            }
            if (polecenie[4] == 'L')
            {
                char d0, d1;
                if (polecenie[5] == 'H')
                {
                    cin >> w >> p;
                    cin >> d0 >> d1;
                    SETLH(w, p, d0, d1);
                }
                if (polecenie[5] == 'S')
                {
                    cin >> p;
                    cin >> d0 >> d1;
                    SETLS(p, d0, d1);
                }
                if (polecenie[5] == 'R')
                {
                    cin >> s >> p;
                    cin >> d0 >> d1;
                    SETLR(s, p, d0, d1);
                }
                if (polecenie[5] == 'W')
                {
                    cin >> w >> r >> s >> p;
                    cin >> d0 >> d1;
                    SETLW(w, r, s, p, d0, d1);
                }
            }
            else if (polecenie[4] == 'H')
            {
                if (polecenie[5] == 'W')
                {
                    cin >> w >> p;
                    SETHW(w, p);
                }
                if (polecenie[5] == 'R')
                {
                    cin >> s >> p;
                    SETHR(s, p);
                }
                if (polecenie[5] == 'S')
                {
                    cin >> p;
                    SETHS(p);
                }
            }
        }
        if (polecenie[0] == 'P')
        {
            if (polecenie[1] == 'U')
            {
                if (polecenie[4] == 'W')
                {
                    cin >> w >> r >> s >> p >> a;
                    PUTW(w, r, s, p, a);
                }
                if (polecenie[4] == 'H')
                {
                    cin >> w >> p >> a;
                    PUTH(w, p, a);
                }
                if (polecenie[4] == 'R')
                {
                    cin >> s >> p >> a;
                    PUTR(s, p, a);
                }
                if (polecenie[4] == 'S')
                {
                    cin >> p >> a;
                    PUTS(p, a);
                }
            }
            if (polecenie[1] == 'O')
            {
                if (polecenie[4] == 'W')
                {
                    cin >> w >> r >> s >> p >> a;
                    POPW(w, r, s, p, a);
                }
                if (polecenie[4] == 'H')
                {
                    cin >> w >> p >> a;
                    POPH(w, p, a);
                }
                if (polecenie[4] == 'R')
                {
                    cin >> s >> p >> a;
                    POPR(s, p, a);
                }
                if (polecenie[4] == 'S')
                {
                    cin >> p >> a;
                    POPS(p, a);
                }
            }
        }
        if (polecenie[0] == 'F')
        {
            cin >> w >> r >> s >> p >> a;
            FILL(w, r, s, p, a);
        }
        if (polecenie[0] == 'M')
        {
            int w1, r1, s1;
            if (polecenie[4] == 'W')
            {
                cin >> w >> r >> s >> w1 >> r1 >> s1 >> p >> a;
                MOVW(w, r, s, w1, r1, s1, p, a);
            }
            if (polecenie[4] == 'H')
            {
                cin >> w >> r >> s >> p >> a;
                MOVH(w, r, s, p, a);
            }
            if (polecenie[4] == 'R')
            {
                cin >> w >> r >> s >> s1 >> p >> a;
                MOVR(w, r, s, s1, p, a);
            }
            if (polecenie[4] == 'S')
            {
                cin >> s >> p >> a;
                MOVS(s, p, a);
            }
        }
        if (polecenie[0] == 'G')
        {
            if (polecenie[4] == 'E')
            {
                cout << GETE() << endl;
            }
            if (polecenie[4] == 'W')
            {
                cin >> w;
                if (sklad.rozmiar > w && w >= 0)
                    cout << GETW(w) << endl;
                else
                    cout << "error" << endl;
            }
            if (polecenie[4] == 'R')
            {
                if (polecenie[5] == 'W')
                {
                    cin >> w >> r;
                    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0)
                        cout << GETRW(w, r) << endl;
                    else
                        cout << "error" << endl;
                }
                else
                    cout << GETRH() << endl;
            }
            if (polecenie[4] == 'S')
            {
                if (polecenie[5] == 'W')
                {
                    cin >> w >> r >> s;
                    if (sklad.rozmiar > w && w >= 0 && sklad.magazyn[w].rozmiar > r && r >= 0 && sklad.magazyn[w].regal[r].rozmiar > s && s >= 0)
                        cout << GETSW(w, r, s) << endl;
                    else
                        cout << "error" << endl;
                }
                else
                {
                    if (polecenie[5] == 'H')
                    {
                        cin >> w;
                        if (sklad.rozmiar > w && w >= 0)
                            cout << GETSH(w) << endl;
                        else
                            cout << "error" << endl;
                    }
                    else
                    {
                        if (polecenie[5] == 'R')
                        {
                            cin >> s;
                            if (sklad.podreczny_regal.rozmiar > s && s >= 0)
                                cout << GETSR(s) << endl;
                            else
                                cout << "error" << endl;
                        }
                        else
                            cout << GETS() << endl;
                    }
                }
            }
            if (polecenie[4] == 'L')
            {
                if (polecenie[5] == 'W')
                {
                    cin >> w >> r >> s >> p;
                    GETLW(w, r, s, p);
                }
                if (polecenie[5] == 'H')
                {
                    cin >> w >> p;
                    GETLH(w, p);
                }
                if (polecenie[5] == 'R')
                {
                    cin >> s >> p;
                    GETLR(s, p);
                }
                if (polecenie[5] == 'S')
                {
                    cin >> p;
                    GETLS(p);
                }
            }
        }
    }
}