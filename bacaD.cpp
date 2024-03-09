//Karolina Kulas
#include <iostream>
using namespace std;
long long int macierz[32][32];
long long int dett(int long long n) 
{
    int znak = 1;
    for(int k = 0; k < n - 1; k++) {
        if(macierz[k][k] == 0) {
            int m = 0;
            for(m = k + 1; m < n; m++) {
                if(macierz[m][k] != 0) { 
                    for(int j=0;j<n;j++) 
                    {
                        long long int pom=macierz[m][j];
                        macierz[m][j]=macierz[k][j];
                        macierz[k][j]=pom;
                    }     
                    znak = -znak;
                    break;
                }
            }
            if(m == n) 
                return 0;
        }
        for (int i = k + 1; i < n; i++) {
            for (int j = k + 1; j < n; j++) {
                macierz[i][j] = macierz[k][k] * macierz[i][j] - macierz[i][k] * macierz[k][j];
                if(k != 0) {
                    macierz[i][j] /= macierz[k-1][k-1];
                }
            }
        }
    }

    return znak * macierz[n-1][n-1];
}
int main()
{
    int n;
    cin>>n; 
    long long int tab[n][n][n]; 
    char s='1';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
                cin>>tab[j][k][i];
        }
    }
    while(s!='E')
    {
        cin>>s;
        if(s=='C')
        {
            int l,v,p,h,w,d; 
            cin>>l>>v>>p>>h>>w>>d;
            int wynik=0;
            if(l<n/2&&v<n/2&&p<n/2)
            {
                for(int i=l;i<l+h+1;i++)
                {
                for(int j=v;j<v+1+w;j++)

                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&j<n&&i<n&&k>=0&&j>=0&&i>=0) wynik+=tab[i][j][k];
                        }
                    }
                }
            }
            if(l<n/2&&v<n/2&&p>=n/2)
            {
                for(int i=l;i<l+h+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=0;k<d+1;k++)
                        {
                            if(p-k<n&&j<n&&i<n&&p-k>=0&&j>=0&&i>=0) wynik+=tab[i][j][p-k];
                        }
                    }
                }
            }
            if(l<n/2&&v>=n/2&&p<n/2)
            {
                for(int i=l;i<l+h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&v-j<n&&i<n&&k>=0&&v-j>=0&&i>=0) wynik+=tab[i][v-j][k];
                        }
                    }
                }
            }
            if(l<n/2&&v>=n/2&&p>=n/2)
            {
                for(int i=l;i<l+h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=0;k<d+1;k++)
                        {
                            if(p-k<n&&v-j<n&&i<n&&p-k>=0&&v-j>=0&&i>=0)  wynik+=tab[i][v-j][p-k];
                        }
                    }
                }
                

            }
            if(l>=n/2&&v<n/2&&p<n/2)
            {
                for(int i=0;i<0+h+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&j<n&&l-i<n&&k>=0&&j>=0&&l-i>=0) wynik+=tab[l-i][j][k];
                        }
                    }
                }
            }
            if(l>=n/2&&v<n/2&&p>=n/2)
            {
                for(int i=0;i<0+h+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=0;k<1+d;k++)
                        {
                            if(p-k<n&&j<n&&l-i<n&&p-k>=0&&j>=0&&l-i>=0) wynik+=tab[l-i][j][p-k];
                        }
                    }
                }
            }
            if(l>=n/2&&v>=n/2&&p<n/2)
            {
                for(int i=0;i<h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&v-j<n&&l-i<n&&k>=0&&v-j>=0&&l-i>=0) wynik+=tab[l-i][v-j][k];
                        }
                    }
                }
            }
            if(l>=n/2&&v>=n/2&&p>=n/2)
            {
                for(int i=0;i<h+1;i++)
                {
                for(int j=0;j<1+w;j++)
                    {
                    for(int k=0;k<1+d;k++)
                        {
                            if(p-k<n&&v-j<n&&l-i<n&&p-k>=0&&v-j>=0&&l-i>=0) wynik+=tab[l-i][v-j][p-k];
                        }
                    }
                }
            }
            cout<<wynik<<endl;
        }
        if(s=='T')
        {
           int l,v,p,r;
            cin>>l>>v>>p>>r;
            int wynik=0;
            int h=r,w=r,d=r;
            if(l<n/2&&v<n/2&&p<n/2)
            {
                for(int i=l;i<l+r+1;i++)
                {
                for(int j=v;j<v+1+r;j++)

                    {
                    for(int k=p;k<p+1+r;k++)
                        {
                            if(k<n&&j<n&&i<n&&k>=0&&j>=0&&i>=0) 
                            {
                                if((i-l)+(j-v)+(k-p)<=r)
                                wynik+=tab[i][j][k];
                            }
                        }
                    }
                }
            }
            if(l<n/2&&v<n/2&&p>=n/2)
            {
                for(int i=l;i<l+r+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=0;k<d+1;k++)
                        {
                            if(p-k<n&&j<n&&i<n&&p-k>=0&&j>=0&&i>=0)
                            {
                                if((i-l)+(j-v)+(k)<=r)
                                 wynik+=tab[i][j][p-k];
                            }
                        }
                    }
                }
            }
            if(l<n/2&&v>=n/2&&p<n/2)
            {
                for(int i=l;i<l+h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&v-j<n&&i<n&&k>=0&&v-j>=0&&i>=0)
                            {
                                if((i-l)+(j)+(k-p)<=r)
                                 wynik+=tab[i][v-j][k];
                            }
                        }
                    }
                }
            }
            if(l<n/2&&v>=n/2&&p>=n/2)
            {
                for(int i=l;i<l+h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=0;k<d+1;k++)
                        {
                            if(p-k<n&&v-j<n&&i<n&&p-k>=0&&v-j>=0&&i>=0) 
                            {
                                if((i-l)+(j)+(k)<=r)
                                wynik+=tab[i][v-j][p-k];
                            }
                        }
                    }
                }
                

            }
            if(l>=n/2&&v<n/2&&p<n/2)
            {
                for(int i=0;i<0+h+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&j<n&&l-i<n&&k>=0&&j>=0&&l-i>=0) 
                            {
                                if((i)+(j-v)+(k-p)<=r)
                                wynik+=tab[l-i][j][k];
                            }
                        }
                    }
                }
            }
            if(l>=n/2&&v<n/2&&p>=n/2)
            {
                for(int i=0;i<0+h+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=0;k<1+d;k++)
                        {
                            if(p-k<n&&j<n&&l-i<n&&p-k>=0&&j>=0&&l-i>=0) 
                            {
                                if((i)+(j-v)+(k)<=r)
                                wynik+=tab[l-i][j][p-k];
                            }
                        }
                    }
                }
            }
            if(l>=n/2&&v>=n/2&&p<n/2)
            {
                for(int i=0;i<h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&v-j<n&&l-i<n&&k>=0&&v-j>=0&&l-i>=0) 
                            {
                                if((i)+(j)+(k-p)<=r)
                                wynik+=tab[l-i][v-j][k];
                            }
                        }
                    }
                }
            }
            if(l>=n/2&&v>=n/2&&p>=n/2)
            {
                for(int i=0;i<h+1;i++)
                {
                for(int j=0;j<1+w;j++)
                    {
                    for(int k=0;k<1+d;k++)
                        {
                            if(p-k<n&&v-j<n&&l-i<n&&p-k>=0&&v-j>=0&&l-i>=0) 
                            {
                                if((i)+(j)+(k)<=r)
                                wynik+=tab[l-i][v-j][p-k];
                            }
                        }
                    }
                }
            }
            cout<<wynik<<endl; 
        }
        if(s=='O')
        {
           int l,v,p,r;
            cin>>l>>v>>p>>r;
            int wynik=0;
            int h=r,w=r,d=r;
            if(l<n/2&&v<n/2&&p<n/2)
            {
                for(int i=l;i<l+r+1;i++)
                {
                for(int j=v;j<v+1+r;j++)

                    {
                    for(int k=p;k<p+1+r;k++)
                        {
                            if(k<n&&j<n&&i<n&&k>=0&&j>=0&&i>=0) 
                            {
                                if((i-l)*(i-l)+(j-v)*(j-v)+(k-p)*(k-p)<=r*r)
                                wynik+=tab[i][j][k];
                            }
                        }
                    }
                }
            }
            if(l<n/2&&v<n/2&&p>=n/2)
            {
                for(int i=l;i<l+r+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=0;k<d+1;k++)
                        {
                            if(p-k<n&&j<n&&i<n&&p-k>=0&&j>=0&&i>=0)
                            {
                                if((i-l)*(i-l)+(j-v)*(j-v)+(k)*(k)<=r*r)
                                 wynik+=tab[i][j][p-k];
                            }
                        }
                    }
                }
            }
            if(l<n/2&&v>=n/2&&p<n/2)
            {
                for(int i=l;i<l+h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&v-j<n&&i<n&&k>=0&&v-j>=0&&i>=0)
                            {
                                if((i-l)*(i-l)+(j)*(j)+(k-p)*(k-p)<=r*r)
                                 wynik+=tab[i][v-j][k];
                            }
                        }
                    }
                }
            }
            if(l<n/2&&v>=n/2&&p>=n/2)
            {
                for(int i=l;i<l+h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=0;k<d+1;k++)
                        {
                            if(p-k<n&&v-j<n&&i<n&&p-k>=0&&v-j>=0&&i>=0) 
                            {
                                if((i-l)*(i-l)+(j)*(j)+(k)*(k)<=r*r)
                                wynik+=tab[i][v-j][p-k];
                            }
                        }
                    }
                }
                

            }
            if(l>=n/2&&v<n/2&&p<n/2)
            {
                for(int i=0;i<0+h+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&j<n&&l-i<n&&k>=0&&j>=0&&l-i>=0) 
                            {
                                if((i)*(i)+(j-v)*(j-v)+(k-p)*(k-p)<=r*r)
                                wynik+=tab[l-i][j][k];
                            }
                        }
                    }
                }
            }
            if(l>=n/2&&v<n/2&&p>=n/2)
            {
                for(int i=0;i<0+h+1;i++)
                {
                for(int j=v;j<v+1+w;j++)
                    {
                    for(int k=0;k<1+d;k++)
                        {
                            if(p-k<n&&j<n&&l-i<n&&p-k>=0&&j>=0&&l-i>=0) 
                            {
                                if((i)*(i)+(j-v)*(j-v)+(k)*(k)<=r*r)
                                wynik+=tab[l-i][j][p-k];
                            }
                        }
                    }
                }
            }
            if(l>=n/2&&v>=n/2&&p<n/2)
            {
                for(int i=0;i<h+1;i++)
                {
                for(int j=0;j<w+1;j++)
                    {
                    for(int k=p;k<p+1+d;k++)
                        {
                            if(k<n&&v-j<n&&l-i<n&&k>=0&&v-j>=0&&l-i>=0) 
                            {
                                if((i)*(i)+(j)*(j)+(k-p)*(k-p)<=r*r)
                                wynik+=tab[l-i][v-j][k];
                            }
                        }
                    }
                }
            }
            if(l>=n/2&&v>=n/2&&p>=n/2)
            {
                for(int i=0;i<h+1;i++)
                {
                for(int j=0;j<1+w;j++)
                    {
                    for(int k=0;k<1+d;k++)
                        {
                            if(p-k<n&&v-j<n&&l-i<n&&p-k>=0&&v-j>=0&&l-i>=0) 
                            {
                                if((i)*(i)+(j)*(j)+(k)*(k)<=r*r)
                                wynik+=tab[l-i][v-j][p-k];
                            }
                        }
                    }
                }
            }
            cout<<wynik<<endl; 
        }
        if(s=='D')
        {
            char ss;
            long long int a;
            cin>>ss>>a;
            long long int det=1;
            if(ss=='l')
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    macierz[i][j]=tab[a][i][j];
                }
            }
            if(ss=='v')
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    macierz[i][j]=tab[i][a][j];
                }
            }
            if(ss=='p')
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    macierz[i][j]=tab[i][j][a];
                }
            }
            cout<<dett(n)<<endl;
        }
    }
}