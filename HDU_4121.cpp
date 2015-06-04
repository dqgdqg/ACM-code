#include <iostream>
#include <cstring>
using namespace std;

char map[11][11],C[8];
int X[8],Y[8],N;
int fx[5]={0,0,0,1,-1};
int fy[5]={0,1,-1,0,0};
int hx[9]={0,1,-1,1,-1,2,2,-2,-2};
int hy[9]={0,2,2,-2,-2,1,-1,1,-1};

int in () {
	int i,x,y;
	char ch;
	cin>>N>>x>>y;
	X[0]=x;
	Y[0]=y;
	//C[0]='g';
	if (N==0&&x==0&&y==0)return 0;
	memset (map,0,sizeof(map));
	//map[x][y]='g';
	for (i=1;i<=N;i++){
		cin>>ch>>x>>y;
		map[x][y]=ch;
		X[i]=x;
		Y[i]=y;
		C[i]=ch;
	}
	return 1;
}

int General (int bgx,int bgy,int k) {
	if (Y[k]!=bgy)return 1;
	int x,y;
	for (x=bgx+1;x<X[k];x++){
		if (map[x][bgy]!=0)break;
	}
	if (x<X[k]){
		return 1;
	}
	return 0;
}

int Chariot (int bgx,int bgy,int k) {
	if (X[k]==bgx&&Y[k]==bgy)return 1;
	if (X[k]!=bgx&&Y[k]!=bgy)return 1;
	int x,y;
	if (X[k]==bgx){
		for (y=min(bgy,Y[k])+1;y<max(bgy,Y[k]);y++){
			if (map[bgx][y]!=0)break;
		}
		if (y<max(bgy,Y[k])){
			return 1;
		}
		return 0;
	}
	else {
		for (x=min(bgx,X[k])+1;x<max(bgx,X[k]);x++){
			if (map[x][bgy]!=0)break;
		}
		if (x<max(bgx,X[k])){
			return 1;
		}
		return 0;
	}
}

int Horse (int bgx,int bgy,int k){
	if (X[k]==bgx&&Y[k]==bgy)return 1;
	int i,x,y;
	for (i=1;i<=4;i++){
		x=X[k]+fx[i];
		y=Y[k]+fy[i];
		if (map[x][y]!=0)continue;
		x=X[k]+hx[i*2-1];
		y=Y[k]+hy[i*2-1];
		if (x==bgx&&y==bgy)return 0;
		x=X[k]+hx[i*2];
		y=Y[k]+hy[i*2];
		if (x==bgx&&y==bgy)return 0;
	}
	return 1;
}

int Cannon (int bgx,int bgy,int k) {
	if (X[k]==bgx&&Y[k]==bgy)return 1;
	if (X[k]!=bgx&&Y[k]!=bgy)return 1;
	int x,y,sx,sy;
	sx=0;
	sy=0;
	if (X[k]==bgx){
		for (y=min(bgy,Y[k])+1;y<max(bgy,Y[k]);y++){
			if (map[bgx][y]!=0)sy++;
		}
		if (sy!=1){
			return 1;
		}
		return 0;
	}
	else {
		for (x=min(bgx,X[k])+1;x<max(bgx,X[k]);x++){
			if (map[x][bgy]!=0)sx++;
		}
		if (sx!=1){
			return 1;
		}
		return 0;
	}
}

int main () {
	int i,j,bgx,bgy;
	while (in()){
		for (i=1;i<=4;i++){
			bgx=X[0]+fx[i];
			bgy=Y[0]+fy[i];
			if (bgx>3||bgx<1||bgy>6||bgy<4)continue;
			for (j=1;j<=N;j++){
				if (C[j]=='G'&&!General(bgx,bgy,j)){
					break;
				}
				else if (C[j]=='R'&&!Chariot(bgx,bgy,j)){
					break;
				}
				else if (C[j]=='H'&&!Horse(bgx,bgy,j)){
					break;
				}
				else if (C[j]=='C'&&!Cannon(bgx,bgy,j)){
					break;
				}
			}
			if (j>N){
				cout<<"NO"<<endl;
				break;
			}
		}
		if (i>4){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
