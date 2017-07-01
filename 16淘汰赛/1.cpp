#include <iostream>
#include <stdio.h>
#include <map>
#define Max(a, b) a > b? a: b
using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        map<int, int>mp;
        int tmax = 0;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            mp[x]++;
            tmax = Max(tmax, mp[x]);
        }
        printf("%d\n", tmax);
    }
    return 0;
}
