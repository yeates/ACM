#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 100050
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char str1[MAX], str2[MAX];
    while(cin >> str1 >> str2){
        int n = strlen(str1), m = strlen(str2);
        if(strcmp(str1, str2) == 0){
            cout << "-1" << endl;
        }
        else cout << max(n, m) << endl;
    }
    return 0;
}
