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

int main(){
    ios::sync_with_stdio(0);
    int n, m;
    while(cin >> n >> m){
        int a[MAX], b[MAX], x[MAX], y[MAX];
        REP(i, n)   cin >> a[i];
        REP(i, n)   cin >> b[i];
        REP(i, n){
            if(i != n-1)
                x[i] = a[i+1] - a[i];
            else
                x[i] = m - a[i] + a[0];
        }
        REP(i, n){
            if(i != n-1)
                y[i] = b[i+1] - b[i];
            else
                y[i] = m - b[i] + b[0];
        }
        bool flag;
        REP(i, n){
            flag = true;
            REP(j, n){
                int z = (i + j) % n;
                if(x[z] != y[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)    break;
        }
        if(flag)    cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
