#include <iostream>
#define LL long long
#define Max(a, b) a > b? a: b
#define MAX 105
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a[MAX];
        cin >> n;
        int k;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == n)   k = i;
        }
        int i = k;
        k = n;
        while(i >= 0){
            if(k == a[i])   k--;
            i--;
        }
        int key = n - k;
        cout << n - key << endl;
    }
    return 0;
}
