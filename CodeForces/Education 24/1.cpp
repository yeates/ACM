#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#define LL long long
#define Max(a, b) a > b? a: b
#define MAX 1000005
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    LL n, k;
    while(cin >> n >> k){
        LL tot = n / 2;
        LL a = tot / (k + 1);
        LL b = a * k;
        tot = n - a - b;
        cout << a << " " << b << " " << tot << endl;
    }
    return 0;
}
