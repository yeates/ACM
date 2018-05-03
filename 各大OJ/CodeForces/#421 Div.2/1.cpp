
 #include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 200050
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, v, m, a, l;
    while(cin >> n >> v >> m >> a >> l){
        int k = v;
        int res = 0;
        while(n > 0){
            n -= k;
            if(res != 0) n += l;
            k += a;
            k = Min(m, k);
            res++;
        }
        cout << res << endl;
    }
    return 0;
}
