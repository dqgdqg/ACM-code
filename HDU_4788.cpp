#include <iostream>
#include <cmath>
using namespace std;
double B[9],_B[9];
int main () {
    int T,t,i,K;
    double Ans;
    char c;
    string temp;
    cin>>T;
    t=T;
    B[0]=_B[0]=1;
    for (i=1;i<=8;i++){
        B[i]=B[i-1]*1000;
        _B[i]=_B[i-1]*1024;
    }
    while (T--){
        temp="";
        while ((c=getchar())!='[');
        while ((c=getchar())!=']'){
            temp+=c;
        }
        if (temp=="B")K=0;
        else if (temp=="KB")K=1;
        else if (temp=="MB")K=2;
        else if (temp=="GB")K=3;
        else if (temp=="TB")K=4;
        else if (temp=="PB")K=5;
        else if (temp=="EB")K=6;
        else if (temp=="ZB")K=7;
        else if (temp=="YB")K=8;
        Ans=(1-B[K]/_B[K])*100;
        printf ("Case #%d: %.2lf%%\n",t-T,Ans);
    }
    return 0;
}
