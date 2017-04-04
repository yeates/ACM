#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 200005
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f

vector<int>vec[MAX];
int color[MAX];

struct node{
    int pre1, pre2;
    int v;
};

void BFS(int tp){
    int tmax = 1;       //颜色计数器
    queue<node>q;
    node tmp;
    tmp.v = 1, tmp.pre1 = 1, tmp.pre2 = 0;
    q.push(tmp);
    color[1] = tmax++;
    while(!q.empty()){
        node k = q.front();
        int e = k.v;
        q.pop();
        REP(i, vec[e].size()){
            if(color[vec[e][i]] != 0)  continue;
            int y = vec[e][i];
            if(tmax == k.pre1 || tmax == k.pre2)   tmax++;
            if(tmax == tp+1)   tmax = 1;
            if(tmax == k.pre1 || tmax == k.pre2)   tmax++;
            if(tmax == tp+1)   tmax = 1;
            color[y] = tmax;
            tmp.pre1 = tmax++;
            if(tmax == tp+1)   tmax = 1;
            tmp.pre2 = k.pre1;
            tmp.v = y;
            q.push(tmp);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        MS(color);
        int tmax = 0;
        REP(i, n-1){
            int u, v;
            cin >> u >> v;
            vec[u].pb(v);
            vec[v].pb(u);
        }
        FOR(i, 1, n){
            tmax = Max(tmax, vec[i].size());
        }
        tmax++;
        cout << tmax << endl;

        BFS(tmax);

        FOR(i, 1, n)
            i == n ?cout << color[i] << endl: cout << color[i] << " ";

        FOR(i, 1, n){
            vec[i].clear();
        }
    }
    return 0;
}
