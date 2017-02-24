#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 100005
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    int n, l, r;
    while(cin >> n >> l >> r){
        int a[MAX], b[MAX], c[MAX], p[MAX], z[MAX];
        REP(i, n)   cin >> a[i];
        REP(i, n){
            int tp;
            cin >> tp;
            p[i] = tp;
            z[tp-1] = i;
        }
        REP(i, n){
            int x = z[i];
            if(i == 0){
                b[x] = l;
                c[x] = b[x] - a[x];
            }
            else{
                b[x] = c[z[i-1]] + a[x] + 1;
                if(b[x] < l)    b[x] = l;
                c[x] = b[x] - a[x];
            }
        }
        if(b[n-1] > r)  cout << "-1" << endl;
        else{
            REP(i, n){
                i == n-1 ?cout << b[i] << endl: cout << b[i] << " ";
            }
        }
     }
    return 0;
}
