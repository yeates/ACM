#include<bits/stdc++.h>
#define MAX 1005
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    map<string, int>mp;
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    while(cin >> n){
        string tp;
        LL ans = 0;
        for(int i = 0; i < n; i++){
            cin >> tp;
            ans += mp[tp];
        }
        cout << ans << endl;
    }
    return 0;
}
