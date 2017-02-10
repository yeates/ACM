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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        int a[MAX];
        FOR(i, 0, n-1)  cin >> a[i];
        sort(a, a + n);
        bool flag = false;
        FOR(i, 2, n-1){
            if(a[i-2] + a[i-1] > a[i]){
                if(a[i] - a[i-2] < a[i-1]){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)    cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
