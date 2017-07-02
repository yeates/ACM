#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m){
        int ans = 0;
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            if(y == 1){
                ans = max(n - x, ans);
            }
            else{
                ans = max(ans, x);
            }
        }
        cout << ans << "\r\n";
    }
    return 0;
}
