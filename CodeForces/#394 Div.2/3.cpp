#include<bits/stdc++.h>
#define Max(a, b) a > b? a: b
#define Min(a, b) a > b? b: a
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, n)   FOR(i, 0, n-1)
#define FORD(i, a, b)   for(int i = a; i >= b; i--)
#define PI acos(-1)
#define pb push_back
#define MS(a)   memset(a, 0, sizeof(a))
#define LL long long int
#define MAX 100
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int mpt[MAX][MAX];
struct node{
    int st;
    int pro[MAX];
};

bool judge(int pro[]){
    int vis[3];
    MS(vis);
    REP(i, n){
        int y = pro[i];
        int val = mpt[i][y];
        vis[val] = 1;
    }
    REP(i, 3)
        if(vis[i] == 0) return false;
    return true;
}

int BFS(){
    queue<node>q;
    node tp;
    tp.st = 0;
    REP(i, n)   tp.pro[i] = 0;
    if(judge(tp.pro))   return 0;
    q.push(tp);
    int ans = INF;
    while(!q.empty()){
        node e = q.front();
        q.pop();
        if(judge(e.pro)){
            ans = Min(ans, e.st);
        }
        e.st++;
        REP(i, n){
            if(e.pro[i] + 1 >= m)   continue;
            e.pro[i]++;
            q.push(e);
            e.pro[i]--;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    while(cin >> n >> m){
        char tp;
        REP(i, n)
            REP(j, m){
                cin >> tp;
                if(tp >= '0' && tp <= '9')    mpt[i][j] = 0;
                else if(tp >= 'a' && tp <= 'z') mpt[i][j] = 1;
                else if(tp == '&' || tp == '#' || tp == '*')    mpt[i][j] = 2;
            }
        int pro[MAX];
        MS(pro);
        int ans = 0;
        REP(i, n){
            if(judge(pro))  break;

        }
    }
    return 0;
}
