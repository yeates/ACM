/*
简单分析+时间优化
scanf:374ms
优化cin:561ms
*/
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

vector<int>a[MAX];      //需要使用动态二维数组才能开那么(10^5)^2大的空间
vector<int>dp[MAX];

int main(){
    ios::sync_with_stdio(0);
    int n, m;
    while(cin >> n >> m){
        MS(dp);
        int ans[MAX];       //ans[i]表示第i行上，能满足题意条件的最大范围是 [r - ans[i] + 1, r]
        REP(i, n){
            int tmax = -INF;
            REP(j, m){
                int tp;
                //scanf("%d", &tp);
                cin >> tp;
                a[i].pb(tp);
                if(i == 0)  dp[i].pb(1);
                else{
                    if(a[i-1][j] <= a[i][j])    dp[i].pb(dp[i-1][j] + 1);
                    else dp[i].pb(1);
                }
                tmax = Max(tmax, dp[i][j]);
            }
            ans[i] = tmax;
        }
        int t;
        //scanf("%d", &t);
        cin >> t;
        while(t--){
            int l, r;
            //scanf("%d%d", &l, &r);
            cin >> l >> r;
            l--, r--;
            bool flag = false;
            if(r - ans[r] + 1 <= l){
                flag = true;
            }
            if(flag)    cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
