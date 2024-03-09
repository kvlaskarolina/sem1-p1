//Karolina Kulas
#include <iostream>
using namespace std;
void Cardinality(int tab[], int *moc)
{
    int n=0;
    while(tab[n]!=-1) n++;
    *moc=n;
}
bool Element(int a, int tab[])
{
    int n=0;
    while(tab[n]!=-1)
    {
        if (tab[n]==a) return true;
        n++;
    }
    return false;
}
bool Subset(int tab2[],int tab1[])
{
    int m1=0,m2=0;
    while(tab1[m1]!=-1) m1++;
    while(tab2[m2]!=-1) m2++;
    if(m2>m1) return false;
    int k=0;
    while(k<m2)
    {
        if(!Element(tab2[k],tab1)) return false;
        k++;
    }
    return true;
}
bool Equal(int tab1[], int  tab2[])
{
    
    if(Subset(tab1,tab2)&&Subset(tab2,tab1)) return true;
    return false;
    
}
bool Empty(int tab[])
{
    if(tab[0]==-1) return true;
    return false;
}
bool Nonempty(int tab[])
{
    if(tab[0]!=-1) return true;
    return false;
}
void Add(int a, int tab [])
{
    int n=0;
    while(tab[n]!=-1) n++;
    if(a>0 && a<4096)
    {
        if(Element(a,tab)==false)
        {
            tab[n] = a;
            tab[n+1] = -1;
            for(int i=0;i<=n;i++)
		    for(int j=1;j<=n-i;j++)
		    if(tab[j-1]>tab[j])
            {
                int pom=tab[j];
                tab[j]=tab[j-1];
                tab[j-1]=pom;
            }
        }  
    }
}
void Create(int n, int tab[],int tat[])
{  
    tat[0]=-1;
    for(int i=0;i<n;i++) 
    {
        if(!Element(tab[i],tat)) Add(tab[i],tat);
    }
}
void Complement(int tab1[], int tab2[])
{
    int n=0;
    for(int i=1;i<4096;i++)
    {
        if(!Element(i,tab1))
        {
            tab2[n]=i;
            tab2[n+1]=-1;
            n++;
        }
    }
}
void Union(int tab1[],int tab2[],int tab[])
{
    int n=0;
    tab[0]=-1;
    for(int i=1;i<4096;i++)
    {
        if(Element(i,tab1)||Element(i,tab2))
        {
            tab[n]=i;
            tab[n+1]=-1;
            n++;
        }
    }
}
void Intersection(int tab1[],int tab2[],int tab[])
{
    int n=0;
    tab[0]=-1;
    for(int i=1;i<4096;i++)
    {
        if(Element(i,tab1)&&Element(i,tab2))
        {
            tab[n]=i;
            tab[n+1]=-1;
            n++;
        }
    }
}
void Difference(int tab1[],int tab2[],int tab[])
{
    int n=0;
    tab[0]=-1;
    for(int i=1;i<4096;i++)
    {
        if(Element(i,tab1)&&!Element(i,tab2))
        {
            tab[n]=i;
            tab[n+1]=-1;
            n++;
        }
    }
}
void Symmetric(int tab1[],int tab2[],int tab[])
{
    int n=0;
    tab[0]=-1;
    for(int i=1;i<4096;i++)
    {
        if((Element(i,tab1)&&!Element(i,tab2))||(!Element(i,tab1)&&Element(i,tab2)))
        {
            tab[n]=i;
            tab[n+1]=-1;
            n++;
        }
    }
}
double Arithmetic(int tab[])
{
    if(Empty(tab)) return 0;
    int n=0;
    double suma=0;
    while(tab[n]!=-1)
    {
        suma+=tab[n];
        n++;
    }
    return suma/n;
}
double Harmonic(int tab[])
{
    if(Empty(tab)) return 1;
    int n=0;
    double suma=0;
    while(tab[n]!=-1)
    {
        suma=suma+(1.0)/tab[n];
        n++;
    }
    double a=n/suma;
    return a;
}
void MinMax(int tab[], int *mini, int &maxi)
{
    if(Nonempty(tab))
    {
        *mini=tab[0];
        maxi=tab[0];
        int n=1;
        while(tab[n]!=-1)
        {
            if(tab[n]<*mini) *mini=tab[n];
            if(tab[n]>maxi) maxi=tab[n];
            n++;
        }
    }   
}
void Properties(int tab[], char s[], double &sa, double *sh, int &mini, int *maxi, int &moc)
{
    int i=0;
    while(s[i]!=0)
    {   
        if(s[i]=='a') sa=Arithmetic(tab);
        if(s[i]=='h') *sh=Harmonic(tab);
        if(s[i]=='m') MinMax(tab,&mini,*maxi);
        if(s[i]=='c') Cardinality(tab,&moc);
        i++;
    }
}



