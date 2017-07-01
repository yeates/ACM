#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define LL long long
#define Max(a, b) a > b? a: b
#define MAX 10005
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        vector<int>v;
        int vis[MAX];
        memset(vis, 0, sizeof(vis));
        int n, m;
        cin >> n;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            int len = v.size();
            for(int j = 0; j < len; j++){
                int a, b;
                a = abs(x - v[j]);
                b = x + v[j];
                if(vis[a] == 0) {vis[a] = 1; v.push_back(a);}
                if(vis[b] == 0) {vis[b] = 1; v.push_back(b);}
            }
            if(vis[x] == 0){
                vis[x] = 1;
                v.push_back(x);
            }
        }
        cin >> m;
        while(m--){
            int x;
            cin >> x;
            if(vis[x])  cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
