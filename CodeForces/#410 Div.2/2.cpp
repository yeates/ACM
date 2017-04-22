#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 105
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

void edit(char *str){
    int len = strlen(str);
    char key = str[0];
    REP(i, len-1){
        str[i] = str[i+1];
    }
    str[len-1] = key;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        char str[MAX][MAX];
        REP(i, n)   cin >> str[i];
        int ans = INF, t;
        bool flag = true;
        REP(i, n){
            t = 0;
            REP(j, n){
                int len = strlen(str[j]);
                int k = 0;
                char tmp[MAX];
                strcpy(tmp, str[j]);
                while(k < len && strcmp(tmp, str[i]) != 0){
                    edit(tmp);
                    k++, t++;
                }
                if(k >= len && strcmp(tmp, str[i]) != 0)    flag = false;
            }
            ans = Min(ans, t);
        }
        if(!flag)   cout << "-1" <<endl;
        else    cout << ans << endl;
    }
}
