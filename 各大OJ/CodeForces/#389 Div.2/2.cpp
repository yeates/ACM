#include<bits/stdc++.h>
#define Max(a, b) a > b? a : b
#define Min(a, b) a < b? a : b
#define PI acos(-1)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LL long long
#define FOR(i, a, b)    for(LL i = a; i <= b; i++)
#define FORD(i, a, b)   for(LL i = a; i >= b; i--)
#define REP(i, n)   FOR(i, 0, n-1)
using namespace std;
#define MAX 1050

int main(){
    ios::sync_with_stdio(false);
    char s[MAX], t[MAX];
    while(cin >> s >> t){
        int n = strlen(s);
        if(strlen(s) != strlen(t)){
            cout << "-1" << endl;
            continue;
        }
        else if(strcmp(s, t) == 0){
            cout << "0" << endl;
            continue;
        }
        map<char, char>mp;
        int vis[255];
        memset(vis, 0, sizeof(vis));
        bool flag = false;
        int ans = 0;
        REP(i, n){
            if(mp[s[i]] == '\0' && mp[t[i]] == '\0'){
                mp[s[i]] = t[i];
                mp[t[i]] = s[i];
                if(t[i] != s[i]) ans++;
            }
            else{
                if(mp[s[i]] != t[i] || mp[t[i]] != s[i]){
                    flag = true;
                    break;
                }
            }
            int a = s[i];
            int b = t[i];
            vis[a]++;
            vis[b]++;
        }
        if(flag){
            cout << "-1" << endl;
            continue;
        }
        flag = false;
        REP(i, 255){
            if(mp[i] == '\0')   continue;
            if((vis[i]+ vis[mp[i]])% 2 != 0){
                flag = true;
                break;
            }
        }
        map<char, int>v;
        if(flag)    cout << "-1" <<endl;
        else{
            cout << ans << endl;
            for(char i = 'a'; i <= 'z'; i++){
                if(v[i] != 0)   continue;
                if(mp[i] == '\0' || mp[i] == i) continue;
                cout << i << "  " << mp[i] << endl;
                v[mp[i]] = 1;
            }
        }
    }
    return 0;
}
