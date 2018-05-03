#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define Max(a, b)   (a > b ? a: b)
#define Min(a, b)   (a < b ? a: b)
#define MAX 200050
using namespace std;
int a[MAX];
int main(){
    //ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        memset(a, 0, sizeof(a));
        int m = 0;
        for(int i = 0; i < n; i++){
            int tp;
            cin >> tp;
            if(tp == 0)
                a[m++] = i;
        }
        int j = 0;
        for(int i = 0; i < n; i++){
            if(i == a[j]){
                i == n - 1?cout << "0" << endl: cout << "0 ";
                j++;
                continue;
            }
            if(i < a[j] && j == 0){
                i == n - 1? cout << a[j] - i << endl: cout << a[j] - i << " ";
            }
            else if(i > a[j] && j == m){
                i == n - 1? cout << i - a[j-1] << endl: cout << i - a[j-1] << " ";
            }
            else{
                i == n - 1? cout << Min(a[j] - i, i - a[j-1]) << endl: cout << Min(a[j] - i, i - a[j-1]) << " ";
            }
        }
    }
    return 0;
}
