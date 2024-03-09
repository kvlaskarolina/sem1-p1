// Karolina Kulas
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct podskladowa
{
    bool b;
    unsigned int c;
    float f;
};
struct skladowe
{
    int i;
    string s;
    string c;
    podskladowa p1;
    podskladowa p2;
    podskladowa p3;
    podskladowa p4;
};
skladowe DANE, TEMP;
bool wystepuje(skladowe DANE, string dane1)
{
    std::fstream dane1_in;
    dane1_in.open(dane1.c_str(), fstream::in);
    while (dane1_in >> TEMP.i)
    {
        getline(dane1_in, TEMP.s);
        getline(dane1_in, TEMP.s);
        getline(dane1_in, TEMP.c);
        dane1_in >> TEMP.p1.b >> TEMP.p1.c >> TEMP.p1.f;
        dane1_in >> TEMP.p2.b >> TEMP.p2.c >> TEMP.p2.f;
        dane1_in >> TEMP.p3.b >> TEMP.p3.c >> TEMP.p3.f;
        dane1_in >> TEMP.p4.b >> TEMP.p4.c >> TEMP.p4.f;
        if (TEMP.i == DANE.i && TEMP.c == DANE.c && TEMP.s == DANE.s)
        {
            if (TEMP.p1.b == DANE.p1.b && TEMP.p1.c == DANE.p1.c && TEMP.p1.f == DANE.p1.f && TEMP.p2.b == DANE.p2.b && TEMP.p2.c == DANE.p2.c && TEMP.p2.f == DANE.p2.f && TEMP.p3.b == DANE.p3.b && TEMP.p3.c == DANE.p3.c && TEMP.p3.f == DANE.p3.f && TEMP.p4.b == DANE.p4.b && TEMP.p4.c == DANE.p4.c && TEMP.p4.f == DANE.p4.f)
            {
                dane1_in.close();
                return true;
            }
        }
    }
    dane1_in.close();
    return false;
}
void SymmetricDifference(string dane1, string dane2, string pomocniczy)
{
    fstream dane2_in;
    dane2_in.open(dane2.c_str(), fstream::in);
    fstream pom_out;
    pom_out.open(pomocniczy.c_str(), fstream::out);
    while (dane2_in >> DANE.i)
    {
        getline(dane2_in, DANE.s);
        getline(dane2_in, DANE.s);
        getline(dane2_in, DANE.c);
        dane2_in >> DANE.p1.b >> DANE.p1.c >> DANE.p1.f;
        dane2_in >> DANE.p2.b >> DANE.p2.c >> DANE.p2.f;
        dane2_in >> DANE.p3.b >> DANE.p3.c >> DANE.p3.f;
        dane2_in >> DANE.p4.b >> DANE.p4.c >> DANE.p4.f;
        if (wystepuje(DANE, dane1))
        {
            pom_out << DANE.i << endl;
            pom_out << DANE.s << endl;
            pom_out << DANE.c << endl;
            pom_out << DANE.p1.b << " " << DANE.p1.c << " " << DANE.p1.f << endl;
            pom_out << DANE.p2.b << " " << DANE.p2.c << " " << DANE.p2.f << endl;
            pom_out << DANE.p3.b << " " << DANE.p3.c << " " << DANE.p3.f << endl;
            pom_out << DANE.p4.b << " " << DANE.p4.c << " " << DANE.p4.f << endl;
        }
        else
        {
            fstream dane1_out;
            dane1_out.open(dane1.c_str(), fstream::app | fstream::out);
            dane1_out << DANE.i << endl;
            dane1_out << DANE.s << endl;
            dane1_out << DANE.c << endl;
            dane1_out << DANE.p1.b << " " << DANE.p1.c << " " << DANE.p1.f << endl;
            dane1_out << DANE.p2.b << " " << DANE.p2.c << " " << DANE.p2.f << endl;
            dane1_out << DANE.p3.b << " " << DANE.p3.c << " " << DANE.p3.f << endl;
            dane1_out << DANE.p4.b << " " << DANE.p4.c << " " << DANE.p4.f << endl;
            dane1_out.close();
        }
    }
    dane2_in.close();
    pom_out.close();
    fstream pom_in;
    pom_in.open(pomocniczy.c_str(), fstream::in);
    fstream dane2_out;
    dane2_out.open(dane2.c_str(), fstream::out);
    std::string temp;
    while (std::getline(pom_in, temp))
    {
        dane2_out << temp << endl;
    }
    dane2_out.close();
    pom_in.close();
}
int ile_danych(string dane)
{
    int i = 0;
    fstream dane_in;
    dane_in.open(dane.c_str(), fstream::in);
    string s;
    while (getline(dane_in, s))
        i++;
    dane_in.close();
    return i / 7;
}
void SortInt(string dane, string pomocniczy1, string pomocniczy2)
{
    int INT, minimum = 2147483648, n = ile_danych(dane), pos;
    string S;
    fstream dane_in;
    fstream dane_out;
    fstream pom1_in;
    fstream pom1_out;
    fstream pom2_in;
    fstream pom2_out;
    int m = n;
    while (n--)
    {
        minimum = 21474836;
        dane_in.open(dane.c_str(), fstream::in);
        for (int i = 0; i < n + 1; i++)
        {
            dane_in >> INT;
            int a = 7;
            while (a--)
            {
                getline(dane_in, S);
            }
            if (INT < minimum)
            {
                minimum = INT;
                pos = i;
            }
        }
        dane_in.close();
        dane_in.open(dane.c_str(), fstream::in);
        pom1_out.open(pomocniczy1.c_str(), fstream::out);
        pom2_out.open(pomocniczy2.c_str(), fstream::app | fstream::out);
        for (int i = 0; i < n + 1; i++)
        {
            string s;
            int a = 7;
            if (i == pos)
            {
                while (a--)
                {
                    getline(dane_in, s);
                    pom2_out << s << endl;
                }
            }
            else
            {
                while (a--)
                {
                    getline(dane_in, s);
                    pom1_out << s << endl;
                }
            }
        }
        dane_in.close();
        pom1_out.close();
        pom2_out.close();
        pom1_in.open(pomocniczy1.c_str(), fstream::in);
        dane_out.open(dane.c_str(), fstream::out);
        while (getline(pom1_in, S))
        {
            dane_out << S << endl;
        }
        dane_out.close();
        pom1_in.close();
    }
    pom2_in.open(pomocniczy2.c_str(), fstream::in);
    dane_out.open(dane.c_str(), fstream::out);
    while (getline(pom2_in, S))
    {
        dane_out << S << endl;
    }
    dane_out.close();
    pom2_in.close();
}
void SortIntReverse(string dane, string pomocniczy1, string pomocniczy2)
{
    int INT, maksimum = -2147483648, n = ile_danych(dane), pos;
    string S;
    fstream dane_in;
    fstream dane_out;
    fstream pom1_in;
    fstream pom1_out;
    fstream pom2_in;
    fstream pom2_out;
    pom2_out.open(pomocniczy2.c_str(), fstream::out);
    pom2_out.close();
    int m = n;
    while (n--)
    {
        maksimum = -21474836;
        dane_in.open(dane.c_str(), fstream::in);
        for (int i = 0; i < n + 1; i++)
        {
            dane_in >> INT;
            int a = 7;
            while (a--)
            {
                getline(dane_in, S);
            }
            if (INT > maksimum)
            {
                maksimum = INT;
                pos = i;
            }
        }
        dane_in.close();
        dane_in.open(dane.c_str(), fstream::in);
        pom1_out.open(pomocniczy1.c_str(), fstream::out);
        pom2_out.open(pomocniczy2.c_str(), fstream::app | fstream::out);
        for (int i = 0; i < n + 1; i++)
        {
            string s;
            int a = 7;
            if (i == pos)
            {
                while (a--)
                {
                    getline(dane_in, s);
                    pom2_out << s << endl;
                }
            }
            else
            {
                while (a--)
                {
                    getline(dane_in, s);
                    pom1_out << s << endl;
                }
            }
        }
        dane_in.close();
        pom1_out.close();
        pom2_out.close();
        pom1_in.open(pomocniczy1.c_str(), fstream::in);
        dane_out.open(dane.c_str(), fstream::out);
        while (getline(pom1_in, S))
        {
            dane_out << S << endl;
        }
        dane_out.close();
        pom1_in.close();
    }
    pom2_in.open(pomocniczy2.c_str(), fstream::in);
    dane_out.open(dane.c_str(), fstream::out);
    while (getline(pom2_in, S))
    {
        dane_out << S << endl;
    }
    dane_out.close();
    pom2_in.close();
    pom2_out.open(pomocniczy2.c_str(),fstream::out);
    pom2_out.close();
    pom1_out.open(pomocniczy1.c_str(),fstream::out);
    pom1_out.close();
}
void SortString(string dane, string pomocniczy1, string pomocniczy2)
{
    int INT, n = ile_danych(dane), pos;
    string minimum = "zzzzzzzzzzzzz";
    string S, STRING;
    fstream dane_in;
    fstream dane_out;
    fstream pom1_in;
    fstream pom1_out;
    fstream pom2_in;
    fstream pom2_out;
    int m = n;
    while (n--)
    {
        minimum = "zzzzzzzzzzzzz";
        dane_in.open(dane.c_str(), fstream::in);
        for (int i = 0; i < n + 1; i++)
        {
            getline(dane_in, S);
            getline(dane_in, STRING);
            int a = 5;
            while (a--)
            {
                getline(dane_in, S);
            }
            if (STRING < minimum)
            {
                minimum = STRING;
                pos = i;
            }
        }
        dane_in.close();
        dane_in.open(dane.c_str(), fstream::in);
        pom1_out.open(pomocniczy1.c_str(), fstream::out);
        pom2_out.open(pomocniczy2.c_str(), fstream::app | fstream::out);
        for (int i = 0; i < n + 1; i++)
        {
            string s;
            int a = 7;
            if (i == pos)
            {
                while (a--)
                {
                    getline(dane_in, s);
                    pom2_out << s << endl;
                }
            }
            else
            {
                while (a--)
                {
                    getline(dane_in, s);
                    pom1_out << s << endl;
                }
            }
        }
        dane_in.close();
        pom1_out.close();
        pom2_out.close();
        pom1_in.open(pomocniczy1.c_str(), fstream::in);
        dane_out.open(dane.c_str(), fstream::out);
        while (getline(pom1_in, S))
        {
            dane_out << S << endl;
        }
        dane_out.close();
        pom1_in.close();
    }
    pom2_in.open(pomocniczy2.c_str(), fstream::in);
    dane_out.open(dane.c_str(), fstream::out);
    while (getline(pom2_in, S))
    {
        dane_out << S << endl;
    }
    dane_out.close();
    pom2_in.close();
}
void SortSumChar(string dane, string pomocniczy1, string pomocniczy2)
{
    int  n = ile_danych(dane), pos;
    unsigned int maksimum = 0, INT;
    string S;
    fstream dane_in;
    fstream dane_out;
    fstream pom1_in;
    fstream pom1_out;
    fstream pom2_in;
    fstream pom2_out;
    int m = n;
    while (n--)
    {
        INT=0;
        maksimum = 0;
        dane_in.open(dane.c_str(), fstream::in);
        for (int i = 0; i < n + 1; i++)
        {
            INT = 0;
            int a = 3;
            while (a--)
            {
                getline(dane_in, S);
            }
            dane_in >> DANE.p1.b >> DANE.p1.c >> DANE.p1.f;
            dane_in >> DANE.p2.b >> DANE.p2.c >> DANE.p2.f;
            dane_in >> DANE.p3.b >> DANE.p3.c >> DANE.p3.f;
            dane_in >> DANE.p4.b >> DANE.p4.c >> DANE.p4.f;
            getline(dane_in, S);
            INT = DANE.p1.c % 256;
            INT += DANE.p2.c ;
            INT %= 256;
            INT += DANE.p3.c ;
            INT %= 256;
            INT += DANE.p4.c ;
            INT %= 256;
            if (INT > maksimum)
            {
                maksimum = INT;
                pos = i;
            }
        }
        dane_in.close();
        dane_in.open(dane.c_str(), fstream::in);
        pom1_out.open(pomocniczy1.c_str(), fstream::out);
        pom2_out.open(pomocniczy2.c_str(), fstream::app | fstream::out);
        for (int i = 0; i < n + 1; i++)
        {
            string s;
            int a = 7;
            if (i == pos)
            {
                while (a--)
                {
                    getline(dane_in, s);
                    pom2_out << s << endl;
                }
            }
            else
            {
                while (a--)
                {
                    getline(dane_in, s);
                    pom1_out << s << endl;
                }
            }
        }
        dane_in.close();
        pom1_out.close();
        pom2_out.close();
        pom1_in.open(pomocniczy1.c_str(), fstream::in);
        dane_out.open(dane.c_str(), fstream::out);
        while (getline(pom1_in, S))
        {
            dane_out << S << endl;
        }
        dane_out.close();
        pom1_in.close();
    }
    pom2_in.open(pomocniczy2.c_str(), fstream::in);
    dane_out.open(dane.c_str(), fstream::out);
    while (getline(pom2_in, S))
    {
        dane_out << S << endl;
    }
    dane_out.close();
    pom2_in.close();
    pom1_out.open(pomocniczy1.c_str(),fstream::out);
    pom1_out.close();
    pom2_out.open(pomocniczy2.c_str(),fstream::out);
    pom2_out.close();
}
int IleRazy(string dane,int INT)
{
    fstream licznik;
    licznik.open(dane.c_str(),fstream::in);
    int i,wynik=0;
    while(licznik>>i)
    {
        if(i==INT) wynik++;
    }
    licznik.close();
    return wynik;
}
void Count(string dane, string pomocniczy1, string pomocniczy2)
{
    int INT, n = ile_danych(dane), pos;
    string S;
    fstream dane_in;
    fstream dane_out;
    fstream pom1_in;
    fstream pom1_out;
    fstream pom2_in;
    fstream pom2_out;
    int m = n;
    dane_in.open(dane.c_str(), fstream::in);
    pom2_out.open(pomocniczy2.c_str(),fstream::out);
    while(dane_in>>DANE.i)
    {
        int a=7;
        while (a--)
        {
            getline(dane_in, S);
        }
        pom2_out<<DANE.i<<endl;
    }
    dane_in.close();
    pom2_out.close();
    dane_in.open(dane.c_str(), fstream::in);
    pom1_out.open(pomocniczy1.c_str(),fstream::out);
    while (n--)
    {
        dane_in >> INT;
        pom1_out<<INT<<" "<<IleRazy(pomocniczy2,INT)<<endl;
        getline(dane_in, S);
        int a = 6;
        while (a--)
        {
            getline(dane_in, S);
            pom1_out<<S<<endl;
        }
    }
    dane_in.close();
    pom1_out.close();
    pom1_in.open(pomocniczy1.c_str(), fstream::in);
    dane_out.open(dane.c_str(), fstream::out);
    while (getline(pom1_in, S))
    {
        dane_out << S << endl;
    }
    dane_out.close();
    pom1_in.close();
    pom1_out.open(pomocniczy1.c_str(),fstream::out);
    pom1_out.close();
    pom2_out.open(pomocniczy2.c_str(),fstream::out);
    pom2_out.close();
}
void SortCountInt(string dane, string pomocniczy1, string pomocniczy2)
{
    Count(dane, pomocniczy1, pomocniczy2);
    //w dane1 znajduje sie  int spacja ilosc ich wystapien, a nasteonie pozostale dane
    int INT, maksimum = -2147483648, n = ile_danych(dane), pos;
    string S;
    fstream dane_in;
    fstream dane_out;
    fstream pom1_in;
    fstream pom1_out;
    fstream pom2_in;
    fstream pom2_out;
    int m = n;
    while (n--)
    {
        maksimum = -21474836;
        dane_in.open(dane.c_str(), fstream::in);
        for (int i = 0; i < n + 1; i++)
        {
            dane_in >> DANE.i>>INT;
            int a = 7;
            while (a--)
            {
                getline(dane_in, S);
            }
            if (INT > maksimum)
            {
                maksimum = INT;
                pos = i;
            }
        }
        dane_in.close();
        dane_in.open(dane.c_str(), fstream::in);
        pom1_out.open(pomocniczy1.c_str(), fstream::out);
        pom2_out.open(pomocniczy2.c_str(), fstream::app | fstream::out);
        for (int i = 0; i < n + 1; i++)
        {
            string s;
            int a = 7,b;
            if (i == pos)
            {
                dane_in>>DANE.i>>b;
                pom2_out<<DANE.i;
                while (a--)
                {
                    getline(dane_in, s);
                    pom2_out << s << endl;
                }
            }
            else
            {
                dane_in>>DANE.i>>b;
                pom1_out<<DANE.i<<" "<<b;
                while (a--)
                {
                    getline(dane_in, s);
                    pom1_out << s << endl;
                }
            }
        }
        dane_in.close();
        pom1_out.close();
        pom2_out.close();
        pom1_in.open(pomocniczy1.c_str(), fstream::in);
        dane_out.open(dane.c_str(), fstream::out);
        while (getline(pom1_in, S))
        {
            dane_out << S << endl;
        }
        dane_out.close();
        pom1_in.close();
    }
    pom2_in.open(pomocniczy2.c_str(), fstream::in);
    dane_out.open(dane.c_str(), fstream::out);
    while (getline(pom2_in, S))
    {
        dane_out << S << endl;
    }
    dane_out.close();
    pom2_in.close();
    pom1_out.open(pomocniczy1.c_str(),fstream::out);
    pom1_out.close();
    pom2_out.open(pomocniczy2.c_str(),fstream::out);
    pom2_out.close();

}
void SortCount(string dane, string pomocniczy1, string pomocniczy2)
{
    SortSumChar(dane, pomocniczy1, pomocniczy2);
    SortIntReverse(dane, pomocniczy1, pomocniczy2);
    SortCountInt(dane, pomocniczy1, pomocniczy2);
}
/*int main()
{
    //Count("f1.txt","f2.txt","f3.txt");  
    //SortSumChar("f1.txt","f2.txt","f3.txt");
    //SortIntReverse("f1.txt","f2.txt","f3.txt"); dziala ladniusio
    //SortCount("f1.txt","f2.txt","f3.txt");
}*/
