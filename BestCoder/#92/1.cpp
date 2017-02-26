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

struct node{
    int v[MAX];
    int time;
};

int main(){
    ios::sync_with_stdio(0);
    int T;
    cin >>T;
    while(T--){
        int n;
        cin >> n;
        map<string, int>mp;
        int z=1;
        node mpt[MAX];
        MS(mpt);
        REP(i, n){
            string tp;
            int v;
            cin >> tp >> v;
            int xx = mp[tp];
            if(xx != 0){
                mpt[xx].v[mpt[xx].time++] = v;
            }
            else{
                mpt[z].v[mpt[z].time++] = v;
                z++;
                mp[tp] = z-1;
            }
        }
        FOR(i, 1, z-1){
            sort(mpt[i].v, mpt[i].v + mpt[i].time);
        }
        int ans= 0;
        FOR(i, 1, z-1){
            if(mpt[i].time <= 2){
                REP(j, mpt[i].time){
                    ans += mpt[i].v[j];
                }
            }
            else{
                FORD(j, mpt[i].time-1, mpt[i].time-2)
                    ans += mpt[i].v[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
