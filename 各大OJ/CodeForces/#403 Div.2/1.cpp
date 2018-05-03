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

int main(){
    int n;
    while(cin >> n){
        int a[MAX];
        REP(i, 2 * n)   cin >> a[i];
        int vis[MAX];
        MS(vis);
        int tot = 0, ans = 0;
        REP(i, 2 * n){
            int x = a[i];
            if(vis[x] == 1){
                tot--;
            }
            else{
                vis[x] = 1;
                tot++;
                ans = Max(ans, tot);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
