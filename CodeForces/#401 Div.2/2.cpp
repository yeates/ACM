/*
简单分析加贪心
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
#define MAX 1005
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        string x, y;
        cin >> x >> y;
        int a[MAX], b[MAX];
        REP(i, x.size())    a[i] = int(x.at(i)-'0');
        REP(i, x.size())    b[i] = int(y.at(i)-'0');
        sort(a, a + n);
        sort(b, b + n);
        int ans1=0, j=0;
        REP(i, n){
            while(j < n && b[j] < a[i])    j++;
            if(j >= n)  break;
            j++;
            ans1++;
        }
        ans1 = n - ans1;
        int ans2=0; j=0;
        REP(i, n){
            while(j < n && b[j] <= a[i])    j++;
            if(j >= n)  break;
            j++;
            ans2++;
        }
        cout << ans1 << endl;
        cout << ans2 << endl;
    }
    return 0;
}
