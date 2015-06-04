#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

string MON[13]={"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int _MON[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int H[2501],R[2501];
long long cost[100001];
int n,m,T,S;
long long Ans;
deque <int> Q,Q_i;

int _ (int y){
	if ((y%4==0&&y%100!=0)||(y%400==0))return 1;
	return 0;
}

int main () {
	string str;
	int i,j,mon,day,year,hour,s,y;
	while (cin>>n>>m,!(n==0&&m==0)) {
		for (i=1;i<=n;i++){
			cin>>str;
			for (j=1;j<=12;j++){
				if (str==MON[j]){
					mon=j;
				}
			}
			cin>>day>>year>>hour>>R[i];
			s=0;
			for (y=2001;y<=year;y++){
				s+=365;
				if (_(y-1)){
					s++;
				}
			}
			while (--mon){
				s+=_MON[mon];
				if (mon==2&&_(year)){
					s++;
				}
			}
			s+=day-1;
			s*=24;
			s+=hour+1;
			H[i]=s;
			//cout<<s<<endl;
		}
		cin>>T>>S;
		for (i=1;i<=m;i++){
			cin>>cost[i];
			cost[i]+=(m-i)*S;
		}
		Q.clear();
		Q_i.clear();
		Q.push_back(cost[1]);
		Q_i.push_back(1);
		j=1;
		Ans=0;
		for (i=1;i<=m;i++){
			while (!Q.empty()&&cost[i]<=Q.back()){
				Q.pop_back();
				Q_i.pop_back();
			}
			Q.push_back(cost[i]);
			Q_i.push_back(i);
			while (j<=n&&H[j]==i){
				while (Q_i.front()<i-T){
					Q.pop_front();
					Q_i.pop_front();
				}
				Ans+=(cost[Q_i.front()]+(i-m)*S)*R[j];
				j++;
			}
		}
		if (j<=n){
			for (;j<=n;j++){
				while (Q_i.front()<H[j]-T){
					Q.pop_front();
					Q_i.pop_front();
				}	
				Ans+=(cost[Q_i.front()]+(H[j]-m)*S)*R[j];
			}
		}
		cout<<Ans<<endl;
	}
	return 0;
}
