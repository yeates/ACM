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
    int n;
    while(cin >> n){
        int a[MAX];
        int sum = 0;
        REP(i, n)   cin >> a[i];
        REP(i, n)   sum += a[i];
        int k = n-1;
        if(sum != 0){
            cout << "YES" << endl;
            cout << '1' << endl;
            cout << "1 " << k + 1 << endl;
            continue;
        }
        int tot = 0;
        bool flag = false;
        REP(i, n){
            tot += a[i];
            if(tot != 0){
                cout << "YES" << endl;
                cout << "2" << endl;
                cout << "1 " << i + 1 << endl;
                cout << i + 2 << " " << n<< endl;
                flag = true;
                break;
            }
        }
        if(!flag)   cout << "NO" << endl;
    }
    return 0;
}
