#include<bits/stdc++.h>
#define Max(a, b) a > b? a : b
#define Min(a, b) a < b? a : b
#define PI acos(-1)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LL long long
#define FOR(i, a, b)    for(LL i = a; i <= b; i++)
#define FORD(i, a, b)   for(LL i = a; i >= b; i--)
#define REP(i, n)   FOR(i, 0, n-1)
using namespace std;
#define MAX 105

char mpt[5][5];
int vis[5][5];
int n = 4;
int ca[8][2] = {1, 0, 0, -1, -1, 0, 0, 1, 1, 1, 1, -1, -1, 1, -1, -1};

struct node{
    int x, y;
    int prex, prey;
    int stp;
};


int bfs(int x, int y){
    memset(vis, 0, sizeof(vis));
    queue<node>q;
    node tp;
    tp.x = x, tp.y = y;
    tp.prex = tp.prey = -1;
    tp.stp = 1;
    q.push(tp);
    while(!q.empty()){
        tp = q.front();
        q.pop();
        vis[tp.x][tp.y] = 1;
        bool flag = false;
        if(tp.prex == -1 && tp.prex == tp.prey){
            REP(i, 8){
                int tx = tp.x + ca[i][0];
                int ty = tp.y + ca[i][1];
                if(tx >= 0 && ty >= 0 && tx < 4 && ty < 4 && mpt[tx][ty] == 'x' && vis[tx][ty] == 0){
                    node e;
                    e.x = tx, e.y = ty;
                    e.prex = tp.x, e.prey = tp.y;
                    e.stp = tp.stp + 1;
                    q.push(e);
                    flag = true;
                }
            }
        }
        else{
            int tx = tp.x * 2 - tp.prex;
            int ty = tp.y * 2 - tp.prey;
            if(tx >= 0 && ty >= 0 && tx < 4 && ty < 4 && mpt[tx][ty] == 'x' && vis[tx][ty] == 0){
                node e;
                e.x = tx, e.y = ty;
                e.prex = tp.x, e.prey = tp.y;
                e.stp = tp.stp + 1;
                q.push(e);
                flag = true;
            }
        }
        if(!flag && tp.stp >= 3){
            return 3;
        }
    }

    return 0;
}

bool BFS(){
    REP(i, 4){
        REP(j, 4){
            if(mpt[i][j] == 'x')
                if(3 == bfs(i, j))  return true;
        }
    }
    return false;
}



int main(){
    ios::sync_with_stdio(false);
    REP(i, 4){
        REP(j, 4){
            cin >> mpt[i][j];
        }
    }
    bool flag = false;
    REP(i, 4){
        REP(j, 4){
            if(mpt[i][j] == '.'){
                mpt[i][j] = 'x';
                flag = BFS();
                if(flag){
                    cout << "YES" << endl;
                    return 0;
                }
                mpt[i][j] = '.';
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
