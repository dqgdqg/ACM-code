#include <iostream>
#include <cstring>
using namespace std;
const int INF=2147483647;
struct Point {
    int x,y;
};
Point start,precious[5],queue[20001];
int map[101][101],visit[101][101],dist[5][5],_visit[5],Q[20001];
int fx[5]={0,1,-1,0,0};
int fy[5]={0,0,0,1,-1};
int n,m,k,Ans;
int _dist (int p,int q){
    int i,j,x,y,ex,ey,front,rear;
    front=rear=1;
    queue[front].x=precious[p].x;
    queue[front].y=precious[p].y;
    Q[front]=0;
    memset (visit,0,sizeof(visit));
    visit[queue[front].x][queue[front].y]=1;
    while (front<=rear){
        x=queue[front].x;
        y=queue[front].y;
        for (i=1;i<=4;i++){
            ex=x+fx[i];
            ey=y+fy[i];
            if (ex<1||ex>n||ey<1||ey>m||visit[ex][ey]||!map[ex][ey])continue;
            rear++;
            visit[ex][ey]=1;
            queue[rear].x=ex;
            queue[rear].y=ey;
            Q[rear]=Q[front]+1;
            if (ex==precious[q].x&&ey==precious[q].y){
                return Q[rear];
            }
        }
        front++;
    }
    return -1;
}
int dfs (int s,int t,int e){
    int i;
    if (t==k){
        if (s<Ans){
            Ans=s;
        }
        return 0;
    }
    for (i=1;i<=k;i++){
        if (!_visit[i]){
            _visit[i]=1;
            dfs (s+dist[e][i],t+1,i);
            _visit[i]=0;
        }
    }
    return 0;
}
int main () {
    int i,j;
    char ch;
    while (cin>>n>>m,n!=0&&m!=0){
        memset (map,0,sizeof(map));
        for (i=1;i<=n;i++){
            for (j=1;j<=m;j++){
                cin>>ch;
                if (ch=='.')map[i][j]=1;
                else if (ch=='@'){
                    start.x=i;
                    start.y=j;
                }
            }
        }
        precious[0].x=start.x;
        precious[0].y=start.y;
        cin>>k;
        for (i=1;i<=k;i++){
            cin>>precious[i].x>>precious[i].y;
        }
        for (i=0;i<k;i++){
            for (j=i+1;j<=k;j++){
                dist[i][j]=dist[j][i]=_dist(i,j);
                if (dist[i][j]==-1)break;
            }
            if (j<=k)break;
        }
        if (i<k){
            cout<<-1<<endl;
            continue;
        }
        memset (_visit,0,sizeof(_visit));
        Ans=INF;
        for (i=1;i<=k;i++){
            _visit[i]=1;
            dfs (dist[0][i],1,i);
            _visit[i]=0;
        }
        cout<<Ans<<endl;
    }
    return 0;
}
