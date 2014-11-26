#include <iostream>
#include <cstring>
using namespace std;
int map[81][81],visit[81],Sum[81][81],U[5050],V[5050];
int hash[3]={0,2,0};
int _ (int n,int s,int x,int y){
    if (x==y){
        return s;
    }
    int i;
    for (i=1;i<=n;i++){
        if (map[x][i]){
            return _ (n,s+map[x][i],i,y);
        }
    }
    return 0;
}    
int init (int n,int m) {
    int i,j;
    for (i=1;i<n;i++){
        map[i][i+1]=i;
        visit[i]=true;
        U[i]=i;
        V[i]=i+1;
    }
    map[n][1]=n+hash[n%3];
    visit[n+hash[n%3]]=true;
    U[n+hash[n%3]]=n;
    V[n+hash[n%3]]=1;
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            Sum[i][j]=_ (n,0,i,j);
        }
    }
    return 0;
}
int find (int n,int m){
    int i,j,u,v;
    for (i=n;i<=m;i++){
        if (visit[i])continue;
        for (u=1;u<=n;u++){
            for (v=1;v<=n;v++){
                if (u==v||map[u][v]||map[v][u])continue;
                if (i%3==Sum[u][v]%3){
                    map[u][v]=i;
                    visit[i]=true;
                    U[i]=u;
                    V[i]=v;
                    break;
                }
            }
            if (v<=n)break;
        }
    }
    return 0;
}
int out (int n,int m,int t){
    int i;
    cout<<"Case #"<<t<<":"<<endl;
    for (i=n;i<=m;i++){
        if (!visit[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for (i=1;i<=m;i++){
        cout<<U[i]<<' '<<V[i]<<' '<<i<<endl;
    }
    return 0;
}
int main () {
    int T,t,n,m;
    cin>>T;
    t=T;
    while (T--){
        cin>>n>>m;
        memset (map,0,sizeof(map));
        memset (visit,0,sizeof(visit));
        memset (U,0,sizeof(U));
        memset (V,0,sizeof(V));
        memset (Sum,0,sizeof(Sum));
        init (n,m);
        find (n,m);
        out (n,m,t-T);
    }
    return 0;
}
