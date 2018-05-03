#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#define LL long long
#define Max(a, b) a > b? a: b
#define MAX 150
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m){
        int a[MAX];
        int vis[MAX];
        int dd[MAX];
        memset(dd, 0, sizeof(dd));
        memset(vis, 0, sizeof(vis));
        int x, y;
        bool flag = false;
        cin >> x;
        for(int i = 1; i < m; i++){
            cin >> y;
            if(x >= y){
                a[x] = y - x + n;
                if(a[x] == 0)   a[x] = x;
            }
            else a[x] = y - x;
            if(vis[x] == 0){
                if(dd[a[x]])    flag = true;
                vis[x] = 1;
            }
            dd[a[x]] = 1;
            x = y;
        }
        if(flag) {cout << -1 << endl; continue;}
        int k = 1;
        for(int i = 1; i <= n; i++){
            int ans;
            if(vis[i] == 0){
                while(dd[k])    k++;
                ans = k;
                k++;
            }
            else ans = a[i];
            i == n? cout << ans << endl: cout << ans << " ";
        }
    }
    return 0;
}
