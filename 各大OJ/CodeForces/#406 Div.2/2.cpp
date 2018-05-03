#include<bits/stdc++.h>
#define Max(a, b) a > b? a : b
#define Min(a, b) a < b? a : b
#define PI acos(-1)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LL long long
#define FOR(i, a, b)    for(int i = a; i <= b; i++)
#define FORD(i, a, b)   for(int i = a; i >= b; i--)
#define REP(i, n)   FOR(i, 0, n-1)
using namespace std;
#define MAX 1005

vector<int>vis;

void init(int n){
    vis.clear();
    n++;
    while(n--)
     vis.push_back(0);
}

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m){
        bool flag;
        bool swi = true;
        for(int i = 0; i < m; i++){
            int k;
            cin >> k;
            flag = false;
            init(n);
            while(k--){
                int tp, p;
                cin >> tp;
                p = abs(tp);
                if(vis[p] == 0 && tp < 0)    vis[p] = -1;
                else if(vis[p] == 0 && tp > 0) vis[p] = 1;
                else if(vis[p] == 1 && tp < 0){vis[p] = 2;flag = true;}
                else if(vis[p] == -1 && tp > 0){vis[p] = 2;flag = true;}
            }
            if(!flag)   swi = false;
        }
        if(swi)    cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
