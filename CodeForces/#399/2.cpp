#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 100050
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    LL n;
    LL l, r;
    LL cf[64];
    cf[0] = 1;
    cf[1] = 2;
    FOR(i, 2, 60){
        cf[i] = cf[i-1] * 2;
    }
    while(scanf("%lld%lld%lld", &n, &l, &r)!=EOF){
        if(n == 0){
            printf("0\n");
            continue;
        }
        else if(n == 1){
            printf("1\n");
            continue;
        }
        int vis[64], t = 0;
        memset(vis, 0, sizeof(vis));
        while(n > 1){
            if(n % 2 == 0)  vis[t] = 1;
            n /= 2;
            t++;
        }
        LL ans = 0;
        for(LL i = l; i <= r; i++){
            if(i % 2 == 1)  ans++;
            else{
                int x = 1;
                LL k = i;
                while(k != 0){
                    x = 1;
                    while(cf[x] <= k){
                        x++;
                    }
                    x--;
                    k -= cf[x];
                }
                if(vis[t - x] == 0) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
