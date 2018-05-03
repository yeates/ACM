#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 1050
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    while(cin >> n >> k){
        if(k > n * n){
            cout << "-1" << endl;
            continue;
        }
        int a[105][105];
        memset(a, 0, sizeof(a));
        int i = n;
        int z = 1;
        while(k > 0){
            if(k >= i*i - (i-1)*(i-1)){
                k -= i*i - (i-1)*(i-1);
                for(int x = z; x <= n; x++)  a[x][z] = 1;
                for(int y = z; y <= n; y++)  a[z][y] = 1;
                z++;
                i--;
            }
            else{
                k++;
                for(int x = z; x < z + k / 2; x++)  a[x][z] = 1;
                for(int y = z; y < z + k / 2; y++)  a[z][y] = 1;
                if(k % 2 != 0){
                    a[z + 1][z + 1] = 1;
                }
                k = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                j == n? cout << a[i][j] << endl: cout << a[i][j] << " ";
            }
        }
    }
    return 0;
}
