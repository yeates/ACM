#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 100005
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    while(cin >> n >> d){
        int a[20] = {0, 31, 28,31,30,31,30,31,31,30,31,30,31};
        double key = a[n];
        key -= (7-d+1);
        double ans = key / 7 + 1;
        if(ans != (int)ans)    ans = (int)ans + 1;
        cout << (int)ans << endl;
    }
    return 0;
}
