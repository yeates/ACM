/*
推规律题
*/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
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
        int m, x;
        cin >> m;
        int a[6] = {1,2,2,1,0,0};
        int b[6] = {0,0,1,2,2,1};
        int c[6] = {2,1,0,0,1,2};
        if(a[(n-1)%6] == m) cout << "0" << endl;
        else if(b[(n-1)%6] == m)    cout << "1" << endl;
        else if(c[(n-1)%6] == m)   cout << "2" << endl;
    }
    return 0;
}
