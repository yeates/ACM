#include<bits/stdc++.h>
#define Max(a, b) a > b? a : b
#define Min(a, b) a < b? a : b
#define PI acos(-1)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LL long long
#define FOR(i, a, b)    for(LL i = a; i <= b; i++)
#define FORD(i, a, b)   for(LL i = a; i >= b; i--)
#define REP(i, n)   FOR(i, 0, n-1)
using namespace std;
#define MAX 105

int main(){
    ios::sync_with_stdio(false);
    int n, m, k;
    while(cin >> n >> m >> k){
        int a, b, tp;
        a = (k / (m * 2));
        char c;
        if(k % (m * 2) != 0){
            a++;
            tp = k % (m * 2);
            b = tp / 2;
            if(tp % 2 != 0){
                b++;
                c = 'L';
            }
            else c = 'R';
        }
        else{
            b = m;
            c = 'R';
        }
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
