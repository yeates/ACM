#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 100050
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

int a[MAX], b[MAX], c[MAX];
int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        LL sa, sb;
        sa = sb = 0;
        REP(i, n){
            cin >> a[i];
            c[i] = i;
            sa += a[i];
        }
        REP(i, n){
            cin >> b[i];
            sb += b[i];
        }
        int k = n / 2 + 1;
        while(1){
            LL ka, kb;
            ka = kb = 0;
            REP(i, k)   ka += a[c[i]], kb += b[c[i]];
            if(ka * 2 > sa && kb * 2 > sb){
                cout << k << endl;
                REP(i, k)   cout << c[i] + 1 << " ";
                cout << endl;
                break;
            }
            else    random_shuffle(c, c + n);
        }
    }
    return 0;
}
