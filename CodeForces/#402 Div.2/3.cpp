#include <bits/stdc++.h>
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
using namespace std;

struct node{
    int a, b;
}a[MAX];

bool cmp(node a, node b){
    return a.a - a.b < b.a - b.b;
}

int main()
{
    //ios::sync_with_stdio(0);
    int n;
    int k;
    while(~scanf("%d%d", &n, &k)){
        REP(i, n)   scanf("%d", &a[i].a);
        REP(i, n)   scanf("%d", &a[i].b);
        int tpk = 0;
        REP(i, n){
            if(a[i].a - a[i].b < 0) tpk++;
        }
        if(tpk > k) k = tpk;
        sort(a, a + n, cmp);
        int ans = 0;
        REP(i, k)   ans += a[i].a;
        FOR(i, k, n-1)  ans += a[i].b;
        printf("%d\n", ans);
    }
    return 0;
}
