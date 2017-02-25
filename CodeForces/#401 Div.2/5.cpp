/*
scanf时间为62ms
优化cin时间为202ms
*/
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
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        node a[MAX];
        LL dp[MAX];
        REP(i, n){
            cin >> a[i].a >> a[i].b >> a[i].c;
        }
        sort(a, a + n, cmp);
        LL tmax = -INF, t=0;
        REP(i, n){
            dp[i] = a[i].c;
            FORD(j, i-1, t){
                if(a[i].a < a[j].b){
                    if(dp[j] + a[i].c > dp[i]){
                        dp[i] = dp[j] + a[i].c;
                    }
                }
                else break;
            }
            if(dp[i] > tmax){
                tmax = dp[i];
                t = i;
            }
        }
        cout << tmax << endl;
    }
    return 0;
}
