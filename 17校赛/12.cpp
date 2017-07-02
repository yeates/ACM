#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;
int a[MAX], b[MAX];
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int i, j;
        i = 0, j = n-1;
        while(i < n && a[i] == b[i]) i++;
        if(i == n){
            cout << 0 << "\r\n";
            continue;
        }
        while(a[j] == b[j]) j--;
        cout << j - i + 1 << "\r\n";
    }
    return 0;
}
