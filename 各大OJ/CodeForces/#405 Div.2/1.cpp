#include<bits/stdc++.h>
#define MAX 1005
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m){
        int i = 0;
        while(n <= m){
            n*=3;
            m*=2;
            i++;
        }
        cout << i << endl;
    }
    return 0;
}
