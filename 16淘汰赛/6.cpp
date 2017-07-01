#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#define LL long long
#define Max(a, b) a > b? a: b
#define MAX 105
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, b, c;
    while(cin >> n >> b >> c){
        int a[MAX], ans = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(abs(a[i]-a[j])%b == c)   ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
