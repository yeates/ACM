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

int gcd(int a, int b){
    int c = a % b;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int a[MAX];
int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        REP(i, n)   cin >> a[i];
        int key = gcd(a[0], a[1]);
        FOR(i, 2, n-1){
            key = gcd(key, a[i]);
        }
        if(key > 1){
            cout << "YES" << endl << "0" << endl;
            continue;
        }
        int ans = 0;
        FOR(i, 1, n-1){
            if(a[i] % 2 == 1 && a[i-1] % 2 == 1){
                a[i-1] *= 2;
                a[i] *= 2;
                ans++;
            }
            else if(i + 1 < n && a[i] % 2 == 1 && a[i+1] % 2 == 1){
                a[i] *= 2;
                a[i+1] *= 2;
                i++, ans++;
            }
            else if(a[i] % 2 == 1 && a[i-1] % 2 == 0){
                ans += 2;
                a[i] *= 2;
                a[i-1] *= 2;
            }
            else if(a[i] % 2 == 0 && a[i-1] % 2 == 1){
                ans += 2;
                a[i] *= 2;
                a[i-1] *= 2;
            }
        }
        cout << "YES" << endl << ans << endl;
    }
    return 0;
}
