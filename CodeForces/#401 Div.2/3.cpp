#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 1005
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
char mpt[MAX][MAX];
int vis[3];
map<char, int>mp;
struct node{
    int vis[3];
    int st;
};

void BFS(){
    queue<node>q;
    int ans = 0;
    while(!q.empty()){
        node e = q.front();
        q.pop();
        bool flag = true;
        REP(i, 3){
            if(vis[i] == 0) flag = false;
        }
        if(flag){break; ans = q.st;}

    }
    return
}

int main(){
    ios::sync_with_stdio(0);
    REP(i, 10)  mp[char(i + '0')] = 0;
    REP(i, 26)  mp[char(i + 'a')] = 1;
    mp['#'] = mp['&'] = mp['*'] = 2;
    while(cin >> n >> m){
        MS(vis);
        REP(i, n)
            REP(j, m){
                cin >> mpt[i][j];
                if(j == 0){
                    int t = mp[mpt[i][j]];
                    vis[t] = 1;
                }
            }
        REP(i, 3)   cout << " " << vis[i];

    }
    return 0;
}
