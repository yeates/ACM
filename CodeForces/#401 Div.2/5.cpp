#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
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

struct node{
    int a, b, c;
};

bool cmp(node a, node b){
    if(a.b == b.b)
        return a.a < b.a;
    return a.b < b.b;
}
int main(){
    //ios::sync_with_stdio(0);
    int n;
    while(scanf("%d", &n)!=EOF){
        node a[MAX];
        LL dp[MAX];
        int z=0;
        scanf("%d%d%d", &a[z].a, &a[z].b, &a[z].c);
        z++;
        REP(i, n-1){
            int x, b, c;
            scanf("%d%d%d", &x, &b, &c);
            if(b == a[z-1].b)
                a[z-1].c += c;
            else
                a[z].a = x, a[z].b = b, a[z].c = c, z++;
        }
        sort(a, a + z, cmp);
        LL tmax = -INF;
        REP(i, z){
            dp[i] = a[i].c;
            FORD(j, i-1, 0){
                if(a[i].a < a[j].b && a[i].b >= a[j].b){
                    if(dp[j] + a[i].c > dp[i])
                        dp[i] = dp[j] + a[i].c;
                }
            }
            tmax = Max(tmax, dp[i]);
        }
        cout << tmax << endl;
    }
    return 0;
}
