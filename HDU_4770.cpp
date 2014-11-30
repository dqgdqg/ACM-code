#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int INF=2147483647;
struct CNM {
	int x,y;
}G[16];
int fx[4]={-1,0,1,0};
int fy[4]={0,1,0,-1}; 
int map[210][210],_map[210][210];
int _ (int k,int p){
	return (k>>(p-1))&1;
}
int main () {
	freopen ("A.in","r",stdin);
	freopen ("A.out","w",stdout);
	int i,j,k,n,m,N,tx,ty,p,q,Ans,tmp,S;
	char ch;
	while ((cin>>n>>m,!(n==0&&m==0))){
		memset (map,0,sizeof(map));
		N=0;
		for (i=1;i<=n;i++){
			for (j=1;j<=m;j++){
				map[i][j]=(cin>>ch,ch)=='#'?0:(G[N+1].x=i,G[N+1].y=j,++N);
			}
		}
		for (i=1;i<=n;i++){
			map[i][0]=map[i][m+1]=N+1;
		}
		for (j=1;j<=m;j++){
			map[0][j]=map[n+1][j]=N+1;
		}
		if (N==0){
			cout<<0<<endl;
			continue;
		}
		k=(int)pow((double)2,N);
		Ans=INF;
		for (i=0;i<k;i++){
			for (p=1;p<=N;p++){
				if (_(i,p)){
					tx=G[p].x;
					ty=G[p].y;
					if (!(map[tx-1][ty]&&map[tx][ty+1])){
						break;
					}
				}
			}
			if (p<=N)continue;
			for (j=1;j<=N;j++){//j is special
				if (_(i,j))continue;
				for (q=0;q<4;q++){
					tx=G[j].x;
					ty=G[j].y;
					if (!(map[tx+fx[q]][ty+fy[q]]&&map[tx+fx[(q+1)%4]][ty+fy[(q+1)%4]])){
						continue;
					}
					for (p=1;p<=N;p++){
						tx=G[p].x;
						ty=G[p].y;
						if (_(i,map[tx][ty]))continue;
						if (map[tx+1][ty]&&_(i,map[tx+1][ty]))continue;
						if (map[tx][ty-1]&&_(i,map[tx][ty-1]))continue;
						if (G[j].x==tx&&G[j].y==ty)continue;
						if (G[j].x+fx[q]==tx&&G[j].y+fy[q]==ty)continue;
						if (G[j].x+fx[(q+1)%4]==tx&&G[j].y+fy[(q+1)%4]==ty)continue;
						break;
					}
					if (p>N){
						tmp=i;
						S=1;
						while (tmp){
							S+=(tmp&1);
							tmp>>=1;
						}
						if (S<Ans)Ans=S;
						break;
					}
				}
			}
		}
		if (Ans==INF)cout<<-1<<endl;
		else cout<<Ans<<endl;
	}
	return 0;
}
