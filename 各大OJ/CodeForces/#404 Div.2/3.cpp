#include<bits/stdc++.h>
#define MAX 1005
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    LL n, m;
    while(cin >> n >> m){
        if(n <= m){
            cout << n << endl;
            continue;
        }
        LL low = 0, high = 1e10;
        LL tp = 0;
        while(low <= high){
            LL mid = (high - low) / 2 + low;
            if((1 + mid)*mid/2 + mid + 1 >= n - m){
                tp = mid + 1;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        cout << tp + m << endl;
    }
    return 0;
}
