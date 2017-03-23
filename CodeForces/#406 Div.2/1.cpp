#include<bits/stdc++.h>
#define Max(a, b) a > b? a : b
#define Min(a, b) a < b? a : b
#define PI acos(-1)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LL long long
#define FOR(i, a, b)    for(int i = a; i <= b; i++)
#define FORD(i, a, b)   for(int i = a; i >= b; i--)
#define REP(i, n)   FOR(i, 0, n-1)
using namespace std;
#define MAX 1005

bool judge(int a, int b){
    if(b % 2 != 0){
        if(a % 2 == 0)  return true;
        else return false;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){
        if((judge(a, b) && !judge(c, d)) || (!judge(a, b) && judge(c, d))){
            cout << "-1" << endl;
            continue;
        }
        int ans = Min(b, d);
        while(b != d){
            if(b < d){
                b += a;
            }
            else d += c;
        }
        cout << b << endl;
    }
    return 0;
}
