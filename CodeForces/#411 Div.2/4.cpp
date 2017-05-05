#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 1000050
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
LL POW(LL a, LL n){
    LL ans = 1, tmp = a;
    while(n != 0){
        if(n % 2 == 1){
            ans = (ans * tmp) % MOD;
        }
        tmp = (tmp * tmp) % MOD;
        n/=2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    char str[MAX];
    while(cin >> str){
        LL ans = 0, icount;
        int n = strlen(str);
        FOR(i, 0, n-1){
            if(str[i] == 'a')   icount++;
            else{
                ans = (ans + POW(2, icount)-1) %MOD;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
