#include<bits/stdc++.h>
#define Max(a, b) a > b? a: b
#define Min(a, b) a > b? b: a
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, n)   FOR(i, 0, n-1)
#define FORD(i, a, b)   for(int i = a; i >= b; i--)
#define PI acos(-1)
#define pb push_back
#define MS(a)   memset(a, 0, sizeof(a))
#define LL long long int
#define MAX 100005
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n, l, r;
    while(cin >> n >> l >> r){
        int a[MAX], b[MAX], c[MAX], z[MAX];
        REP(i, n)   cin >> a[i];
        REP(i, n){
            int tp;
            cin >> tp;
            z[tp-1] = i;
        }
        bool flag = true;
        REP(i, n){
            int x = z[i];
            if(i == 0){
                b[x] = l;
                c[x] = b[x] - a[x];
            }
            else{
                b[x] = c[z[i-1]] + a[x] + 1;
                if(b[x] > r)    flag = false;
                if(b[x] < l)    b[x] = l;
                c[x] = b[x] - a[x];
            }
        }
        if(flag){
            REP(i, n)
                i == n-1? cout << b[i] << endl: cout << b[i] << " ";
        }
        else    cout << "-1" << endl;

    }
    return 0;
}
