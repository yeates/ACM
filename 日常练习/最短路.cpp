#include<bits/stdc++.h>
#define Max(a, b) a > b? a: b
#define MAX 10005
#define LL long long
#define INF 0x3f3f3f3f
#define Min(a, b) a < b? a: b
using namespace std;

int mpt[MAX][MAX];
int dis[MAX], vis[MAX];
int n;

void init(){
    dis[0] = INF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mpt[i][j] = i == j? 0: INF;
        }
        dis[i] = INF;
        vis[i] = 0;
    }
}

int dijkstra(int s, int d){
    int t;
    dis[s] = 0;
    for(int k = 0; k < n; k++){
        t = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i])  continue;
            t = dis[t] > dis[i]? i: t;
        }
        vis[t] = 1;
        for(int i = 1; i <= n; i++){
            if(vis[i] || mpt[t][i] == INF)  continue;
            dis[i] = Min(dis[i], dis[t] + mpt[t][i]);
        }
    }
    return dis[d];
}

int main(){
    int m;
    while(cin >> n >> m && (n !=0 || m != 0)){
        init();
        for(int i = 0; i < m; i++){
            int x, y, z;
            cin >> x >> y >> z;
            if(mpt[x][y] > z)
                mpt[x][y] = mpt[y][x] = z;
        }
        cout << dijkstra(1, n) << endl;
    }
    return 0;
}
