#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 10007
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
bool is_hw(char str[MAX]){
    int len = strlen(str);
    int ans =0 ;
    REP(i, len){
        if(i == len-1-i && str[i] == str[len-1-i])  continue;
        else if(str[i] != str[len-1-i])  ans++;
    }
    if(ans == 2 || (ans == 0 && len % 2 != 0))    return true;
    else return false;
}
int main(){
    char str[MAX];
    while(cin >>str){
        if(is_hw(str))  cout << "YES" << endl;
        else cout <<"NO" <<endl;
    }
}
