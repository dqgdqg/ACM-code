#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

deque <int> Q,Q_i;

int n,k;
int num[1000001];

int minAns () {
	int i;
	Q.clear();
	Q_i.clear();
	Q.push_back(num[1]);
	Q_i.push_back(1);
	for (i=1;i<k;i++){
		while (!Q.empty()&&num[i]<=Q.back()){
			Q.pop_back();
			Q_i.pop_back();
		}
		Q.push_back(num[i]);
		Q_i.push_back(i);
	}
	for (i=k;i<=n;i++){
		while (!Q.empty()&&num[i]<=Q.back()){
			Q.pop_back();
			Q_i.pop_back();
		}
		Q.push_back(num[i]);
		Q_i.push_back(i);
		while (Q_i.front()<i-k+1){
			Q_i.pop_front();
			Q.pop_front();
		}
		printf ("%d ",Q.front());
	}
	printf ("\n");
	return 0;
}

int maxAns () {
	int i;
	Q.clear();
	Q_i.clear();
	Q.push_back(num[1]);
	Q_i.push_back(1);
	for (i=1;i<k;i++){
		while (!Q.empty()&&num[i]>=Q.back()){
			Q.pop_back();
			Q_i.pop_back();
		}
		Q.push_back(num[i]);
		Q_i.push_back(i);
	}
	for (i=k;i<=n;i++){
		while (!Q.empty()&&num[i]>=Q.back()){
			Q.pop_back();
			Q_i.pop_back();
		}
		Q.push_back(num[i]);
		Q_i.push_back(i);
		while (Q_i.front()<i-k+1){
			Q_i.pop_front();
			Q.pop_front();
		}
		printf ("%d ",Q.front());
	}
	printf ("\n");
	return 0;
}

int main () {
	int i;
	scanf ("%d%d",&n,&k);
	for (i=1;i<=n;i++){
		scanf ("%d",&num[i]);
	}
	minAns ();
	maxAns ();
	return 0;
}
