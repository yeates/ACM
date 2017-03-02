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

int main()
{
    ios::sync_with_stdio(0);
    char num[15];
    int k;
    while(cin >> num >> k){
        int n = strlen(num);
        int x = atoi(num);
        int div = 1;
        REP(i, k)   div *= 10;
        if(x < div){
            cout << n-1 << endl;
            continue;
        }
        int tmin = 0;
        bool flag = true;
        FORD(i, n-1, 0){
            if(num[i] == '0'){
                x = atoi(num);
                if(x < div){
                    cout << n-1 << endl;
                    flag = false;
                    break;
                }
                if(x % div == 0)  {
                    cout << tmin << endl;
                    flag = false;
                    break;
                }
            }
            else{
                tmin++;
                FOR(j, i, n-1)
                    num[j] = num[j+1];
            }
        }
        if(flag)    cout << n-1 << endl;
    }
    return 0;
}
close
