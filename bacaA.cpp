//Karolina Kulas
#include <iostream>
using namespace std;
int main()
{
    int n; 
    cin>>n;
    n=n+1;
    float aw=0,bw=0,cw=0,dw=0,ew=0,ap=0,bp=0,cp=0,dp=0,ep=0,ar=0,br=0,cr=0,dr=0,er=0,as=0,bs=0,cs=0,ds=0,es=0;
    while(n=n-1)
    {
        char g1,g2;
        int q1,q2,q3,q4,w1,w2,w3,w4,r1=6,r2=6,s1=0,s2=0,s3=0,s4=0,m1=0,m2=0,m3=0,m4=0;
        cin>>g1>>q1>>q2>>q3>>q4>>g2>>w1>>w2>>w3>>w4;
        if(q1==1) s1=s1+1;
        if(q2==1) s1=s1+1;
        if(q3==1) s1=s1+1;
        if(q4==1) s1=s1+1;
        if(q1==2) s2=s2+1;
        if(q2==2) s2=s2+1;
        if(q3==2) s2=s2+1;
        if(q4==2) s2=s2+1;
        if(q1==3) s3=s3+1;
        if(q2==3) s3=s3+1;
        if(q3==3) s3=s3+1;
        if(q4==3) s3=s3+1;
        if(q1==4) s4=s4+1;
        if(q2==4) s4=s4+1;
        if(q3==4) s4=s4+1;
        if(q4==4) s4=s4+1;
        if(w1==1) m1=m1+1;
        if(w2==1) m1=m1+1;
        if(w3==1) m1=m1+1;
        if(w4==1) m1=m1+1;
        if(w1==2) m2=m2+1;
        if(w2==2) m2=m2+1;
        if(w3==2) m2=m2+1;
        if(w4==2) m2=m2+1;
        if(w1==3) m3=m3+1;
        if(w2==3) m3=m3+1;
        if(w3==3) m3=m3+1;
        if(w4==3) m3=m3+1;
        if(w1==4) m4=m4+1;
        if(w2==4) m4=m4+1;
        if(w3==4) m4=m4+1;
        if(w4==4) m4=m4+1;
        if(q1==q2||q2==q3||q3==q4||q1==q3||q1==q4||q2==q4) r1=5;
        if(w1==w2||w2==w3||w3==w4||w1==w3||w1==w4||w2==w4) r2=5;
        if((q1==q2&&q2==q3)||(q1==q2&&q2==q4)||(q4==q2&&q2==q3)||(q4==q1&&q1==q3)) r1=4;
        if((w1==w2&&w2==w3)||(w1==w2&&w2==w4)||(w4==w2&&w2==w3)||(w4==w1&&w1==w3)) r2=4;
        if((q1==q2&&q3==q4)||(q1==q3&&q2==q4)||(q1==q4&&q3==q2)) r1=3;
        if((w1==w2&&w3==w4)||(w1==w3&&w2==w4)||(w1==w4&&w3==w2)) r2=3;
        if((q1!=q2&&q2!=q3&&q3!=q4&&q1!=q3&&q1!=q4&&q2!=q4)) r1=2;
        if((w1!=w2&&w2!=w3&&w3!=w4&&w1!=w3&&w1!=w4&&w2!=w4)) r2=2;
        if((q1==q2&&q2==q3&&q3==q4&&q1==q3&&q1==q4&&q2==q4)) r1=1;
        if((w1==w2&&w2==w3&&w3==w4&&w1==w3&&w1==w4&&w2==w4)) r2=1;
        int top1=s1,best1=1,top2=m1,best2=1;
        if(r1==r2)
        {
            if(top1<=s2) {
                top1=s2;
                best1=2;
            }
            if(top1<=s3) {
                top1=s3;
                best1=3;
            }
            if(top1<=s4) {
                top1=s4;
                best1=4;
            }
            if(top2<=m2) {
                top2=m2;
                best2=2;
            }
            if(top2<=m3) {
                top2=m3;
                best2=3;
            }
            if(top2<=m4) {
                top2=m4;
                best2=4;
            }
            if(best1>best2) r1=r1-1;
            if(best1<best2) r2=r2-1;
            if(best1==best2){
                if(q1+q2+q3+q4>w1+w2+w3+w4) r1=r1-1;
                if(q1+q2+q3+q4<w1+w2+w3+w4) r2=r2-1;
            }
        }
        if(g1=='a'){
            if(r1<r2) aw=aw+1;
            if(r1==r2) ar=ar+1;
            if(r1>r2) ap=ap+1;
            as=as+1;
        }
        if(g2=='a'){
            if(r1>r2) aw=aw+1;
            if(r1==r2) ar=ar+1;
            if(r1<r2) ap=ap+1;
            as=as+1;
        }
        if(g1=='b'){
            if(r1<r2) bw=bw+1;
            if(r1==r2) br=br+1;
            if(r1>r2) bp=bp+1;
            bs=bs+1;
        }
        if(g2=='b'){
            if(r1>r2) bw=bw+1;
            if(r1==r2) br=br+1;
            if(r1<r2) bp=bp+1;
            bs=bs+1;
        }
        if(g1=='c'){
            if(r1<r2) cw=cw+1;
            if(r1==r2) cr=cr+1;
            if(r1>r2) cp=cp+1;
            cs=cs+1;
        }
        if(g2=='c'){
            if(r1>r2) cw=cw+1;
            if(r1==r2) cr=cr+1;
            if(r1<r2) cp=cp+1;
            cs=cs+1;
        }
        if(g1=='d'){
            if(r1<r2) dw=dw+1;
            if(r1==r2) dr=dr+1;
            if(r1>r2) dp=dp+1;
            ds=ds+1;
        }
        if(g2=='d'){
            if(r1>r2) dw=dw+1;
            if(r1==r2) dr=dr+1;
            if(r1<r2) dp=dp+1;
            ds=ds+1;
        }
        if(g1=='e'){
            if(r1<r2) ew=ew+1;
            if(r1==r2) er=er+1;
            if(r1>r2) ep=ep+1;
            es=es+1;
        }
        if(g2=='e'){
            if(r1>r2) ew=ew+1;
            if(r1==r2) er=er+1;
            if(r1<r2) ep=ep+1;
            es=es+1;
        }      
    }
    if(as>0){
            cout<<"gracz a"<<endl;
            if(aw!=0) cout<<"    wygrane: "<<aw*100/as<<"%"<<endl;
            if(ar!=0) cout<<"    remisy: "<<ar*100/as<<"%"<<endl;
            if(ap!=0) cout<<"    przegrane: "<<ap*100/as<<"%"<<endl;
            cout<<endl;
        }
        if(bs>0){
            cout<<"gracz b"<<endl;
            if(bw!=0) cout<<"    wygrane: "<<bw*100/bs<<"%"<<endl;
            if(br!=0) cout<<"    remisy: "<<br*100/bs<<"%"<<endl;
            if(bp!=0) cout<<"    przegrane: "<<bp*100/bs<<"%"<<endl;
            cout<<endl;
        }
        if(cs>0){
            cout<<"gracz c"<<endl;
            if(cw!=0) cout<<"    wygrane: "<<cw*100/cs<<"%"<<endl;
            if(cr!=0) cout<<"    remisy: "<<cr*100/cs<<"%"<<endl;
            if(cp!=0) cout<<"    przegrane: "<<cp*100/cs<<"%"<<endl;
            cout<<endl;
        }
        if(ds>0){
            cout<<"gracz d"<<endl;
            if(dw!=0) cout<<"    wygrane: "<<dw*100/ds<<"%"<<endl;
            if(dr!=0) cout<<"    remisy: "<<dr*100/ds<<"%"<<endl;
            if(dp!=0) cout<<"    przegrane: "<<dp*100/ds<<"%"<<endl;
            cout<<endl;
        }
        if(es>0){
            cout<<"gracz e"<<endl;
            if(ew!=0) cout<<"    wygrane: "<<ew*100/es<<"%"<<endl;
            if(er!=0) cout<<"    remisy: "<<er*100/es<<"%"<<endl;
            if(ep!=0) cout<<"    przegrane: "<<ep*100/es<<"%"<<endl;
            cout<<endl;
        }
}