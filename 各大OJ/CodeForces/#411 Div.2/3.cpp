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
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        if(n % 2 == 0)   cout << (n / 2) - 1 <<endl;
        else cout << ((n + 1) / 2) - 1 <<endl;
    }
    return 0;
}
