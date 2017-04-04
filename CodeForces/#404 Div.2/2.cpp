#include<bits/stdc++.h>
#define MAX 1005
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        int tr, tl, zr, zl;
        tr = zr = INF;
        tl = zl = -1;
        for(int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;
            if(l > tl)  tl = l;
            if(r < tr)  tr = r;
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            if(l > zl)  zl = l;
            if(r < zr)  zr = r;
        }
        int ans = 0;
        if(tr < zl) ans = zl - tr;
        if(zr < tl) ans = max(ans, tl - zr);
        cout << ans << endl;
    }
    return 0;
}
