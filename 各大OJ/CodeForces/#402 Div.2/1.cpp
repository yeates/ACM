#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 105
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        int a[MAX];
        int b[MAX];
        int vis[MAX];
        int vis1[MAX];
        memset(vis, 0, sizeof(vis));
        MS(vis1);
        REP(i, n){
            cin >> a[i];
            vis1[a[i]]++;
            vis[a[i]]++;
        }
        REP(i, n){
            cin >> b[i];
            vis1[b[i]]++;
        }
        int num = 0;
        bool flag = true;
        FOR(i, 1, 5){
            if(vis1[i] % 2 == 0){
                num += vis1[i] / 2;
            }
            else{
                flag = false;
                break;
            }
        }
        if(num != n)    flag = false;
        if(flag == false)   cout << "-1" << endl;
        else{
            int ans = 0;
            FOR(i, 1, 5){
                int tp = vis1[i];
                if(tp / 2 < vis[i]){
                    ans += vis[i] - tp / 2;
                }
            }
            cout << ans << endl;
        }

    }
    return 0;
}
