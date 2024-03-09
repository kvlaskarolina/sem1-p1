//Karolina Kulas
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        int tab[n];
        int k=0;
        while(k<n)
        {
            cin>>tab[k];
            k=k+1;
        }
        k=0;
        while(k<n)
        {
            cout<<tab[k]<<" ";
            k=k+1;
        }
        cout<<endl;
        char x='p';
        while(x!='F')
        {
            int a,b,c;
            cin>>x;
            if(x=='R')
            {
                cin>>a>>b;
                int j=0; 
                while(a<0) a=a+n;
                a=a%n;
                if(b!=0)
                {
                    while(j<n/b)
                    {
                    int p=(a+j*b)%n;
                    int d=0,pom;
                    while(d<b/2)
                    {
                        pom=tab[(p+d)%n];
                        tab[(p+d)%n]=tab[(p-d+b-1)%n];
                        tab[(p-d+b-1)%n]=pom;
                        d=d+1;
                    }
                    j=j+1;
                    }
                }
                
                
            }
            if(x=='C')
            {
                cin>>a>>b; 
                while(a<0) a=a+n;
                a=a%n;
                if(b!=0)
                {
                    int ilosc=0;
                    while(ilosc<n/b-1)
                    {
                        int p=(a+ilosc*b)%n;
                        int i=0;
                        while(i<b)
                        {
                            int pom=tab[(i+p)%n];
                                tab[(i+p)%n]=tab[(i+p+b)%n];
                                tab[(i+p+b)%n]=pom;
                            i=i+1;
                        }
                        ilosc=ilosc+2;
                    }
                }
            }
            if(x=='M')
            {
                cin>>a>>b>>c; 
                int j=0; 
                while(a<0) a=a+n;
                a=a%n;
                int c1=c;
                
                if(b!=0)
                {
                    c=c%b;
                while(c<0) c=c+b;
                    while(j<n/b)
                    {
                    int p=(a+j*b)%n,cc=0;
                    while(cc<b-c)
                    {
                        int pom=tab[p];
                        int bb=0;
                        while(bb<b-1)
                        {
                           tab[(p+bb)%n]=tab[(p+bb+1)%n];
                           bb=bb+1;
                        }
                        tab[(p+b-1)%n]=pom;
                        cc=cc+1;
                    }
                    j=j+1;
                    }
                    int p1=(a+j*b)%n;
                    int ile=n%b,cc=0;
                    if(ile!=0)
                    {
                        while(c1<0) c1=c1+ile;
                    c1=c1%ile;
                    while(cc<ile-c1)
                    {
                        int pom=tab[p1];
                        int bb=0;
                        while(bb<ile-1)
                        {
                           tab[(p1+bb)%n]=tab[(p1+bb+1)%n];
                           bb=bb+1;
                        }
                        tab[(p1+ile-1)%n]=pom;
                        cc=cc+1;
                    }
                    }
                }
            }
            if(x=='S')
            {
                cin>>a>>b;
                while(a<0) a=a+n;
                a=a%n;
                int j=0,flaga=0; 
                if(b<0)
                {
                    flaga=1;
                    b=b*(-1);
                }
                if(b>n) b=n;
                if(b!=0)
                {
                    while(j<n/b)
                    {
                    int p=(a+j*b)%n; 
                    if(flaga==0)
                    {
                        int i=p;
                        while(i<p+b)
                        {
                            int ii=p+1;
                            while(ii<p+b)
                            {
                                if(tab[(ii-1)%n]>tab[ii%n])
			                    {
                                int pom=tab[(ii-1)%n];
                                tab[(ii-1)%n]=tab[ii%n];
                                tab[ii%n]=pom;
                                }
                                ii=ii+1;
                            }
                        i=i+1;
                        }
                        
                    }                   
                    if(flaga==1)
                    {
                        int i=p;
                        while(i<p+b)
                        {
                            int ii=p+1;
                            while(ii<p+b)
                            {
                                if(tab[(ii-1)%n]<tab[ii%n])
			                    {
                                int pom=tab[(ii-1)%n];
                                tab[(ii-1)%n]=tab[ii%n];
                                tab[ii%n]=pom;
                                }
                                ii=ii+1;
                            }
                        i=i+1;
                        }
                    }                   
                    j=j+1;
                    }
                } 
                int reszta=n%b;
                if(reszta!=0)    
                {
                    int p=(a+j*b)%n; 
                    if(flaga==0)
                    {
                        int i=p;
                        while(i<p+reszta)
                        {
                            int ii=p+1;
                            while(ii<p+reszta)
                            {
                                if(tab[(ii-1)%n]>tab[ii%n])
			                    {
                                int pom=tab[(ii-1)%n];
                                tab[(ii-1)%n]=tab[ii%n];
                                tab[ii%n]=pom;
                                }
                                ii=ii+1;
                            }
                        i=i+1;
                        }
                        
                    }                   
                    if(flaga==1)
                    {
                        int i=p;
                        while(i<p+reszta)
                        {
                            int ii=p+1;
                            while(ii<p+reszta)
                            {
                                if(tab[(ii-1)%n]<tab[ii%n])
			                    {
                                int pom=tab[(ii-1)%n];
                                tab[(ii-1)%n]=tab[ii%n];
                                tab[ii%n]=pom;
                                }
                                ii=ii+1;
                            }
                        i=i+1;
                        }
                    }     
                }                         
            }
        }
        k=0;
        while(k<n)
        {
            cout<<tab[k]<<" ";
            k=k+1;
        }
        cout<<endl;
        t=t-1;
    }
}