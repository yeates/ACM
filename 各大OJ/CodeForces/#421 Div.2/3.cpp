#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 200050
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int a, b, l, r;
    while(cin >> a >> b >> l >> r){
        int x = (a + b) * 2;
        char ar[50];
        memset(ar, 0, sizeof(ar));
        for(int i = 0; i < a; i++)
            ar[i] = 'a' + i;
        for(int i = 0; i < b; i++)
            ar[i + a] = ar[a-1];
        int tp;
        if(b >= a)  tp = 1;
        else tp = a - b;
        for(int i = 0; i < a - tp; i++)
            ar[i + a + b] = 'a' + i;
        for(int i = 0; i < tp; i++)
            ar[i + 2 * a + b - tp] = i + 'm';
        for(int i = 0; i < b; i++)
            ar[i + 2 * a + b] = ar[2 * a + b - 1];
        //cout << ar << endl;
        if(r - l >= x){
            cout << tp + a << endl;
        }
        else{
            if(r - l + 1 == x - 1 && l % x == a + 1){
                cout << tp + a - 1 << endl;
                continue;
            }
            l = (l - 1) % x;
            r = (r - 1) % x;
            int i = l;
            int vis[300];
            memset(vis, 0, sizeof(vis));
            int res = 0;
            while(i != r){
                if(vis[ar[i]] == 0){
                    res++;
                    vis[ar[i]] = 1;
                }
                i++;
                if(i >= x){
                    i = 0;
                }
            }
            if(vis[ar[i]] == 0){
                res++;
                vis[ar[i]] = 1;
            }
            cout << res << endl;
        }
    }
    return 0;
}
