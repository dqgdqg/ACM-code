#include <iostream>
#include <cstdio>
using namespace std;
int u[100001],v[100001],w[100001],fa[100001],r[100001];
int F[31]={0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025};
int find (int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int Kru1 (int n,int m){
	int i,s,S;
	for (i=1;i<=n;i++){
		fa[i]=i;
	}
	s=S=0;
	for (i=1;i<=m;i++){
		int e=r[i];
		int fu=find(u[e]),fv=find(v[e]);
		if (fu==fv)continue;
		s+=w[e];
		S++;
		fa[fu]=fv;
	}
	if (S!=n-1)s=-1;
	return s;
}
int Kru2 (int n,int m){
	int i,s;
	for (i=1;i<=n;i++){
		fa[i]=i;
	}
	s=0;
	for (i=m;i>=1;i--){
		int e=r[i];
		int fu=find(u[e]),fv=find(v[e]);
		if (fu==fv)continue;
		s+=w[e];
		fa[fu]=fv;
	}
	return s;
}
int main () {
	int T,t,n,m,front,rear,Min,Max,i;
	scanf ("%d",&T);
	t=T;
	while (T--){
		printf ("Case #%d: ",t-T);
		scanf ("%d%d",&n,&m);
		front=1;
		rear=m;
		for (i=1;i<=m;i++){
			scanf ("%d%d%d",&u[i],&v[i],&w[i]);
			if (w[i]==1){
				r[rear--]=i;
			}
			else {
				r[front++]=i;
			}
		}
		Min=Kru1(n,m);
		if (Min==-1){
			printf ("No\n");
			continue;
		}
		Max=Kru2(n,m);
		for (i=1;i<=24;i++){
			if (F[i]>=Min&&F[i]<=Max){
				printf ("Yes\n");
				break;
			}
		}
		if (i==25){
			printf ("No\n");
		}
	}
	return 0;
}
