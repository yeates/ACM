#include<bits/stdc++.h>
#define MAX 150000
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;

int f[MAX];
int find(int x){
    if(x == f[x])   return f[x];
    else{
        return f[x] = find(f[x]);
    }
}
int a[MAX];
int num[MAX];

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m){
        memset(a, 0, sizeof(a));
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++) f[i] = i;
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            a[x]++;
            a[y]++;
            x = find(x), y= find(y);
            if(x != y)  f[x] = y;
        }
        for(int i = 1; i <= n; i++){
            find(i);
        }
        for(int i = 1; i <= n; i++){
            num[f[i]]++;
        }
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(a[i] != num[f[i]]-1){
                flag = false;
                break;
            }
        }
        if(flag)  cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
