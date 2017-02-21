#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 1000005
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    int q;
    while(cin >> k >> q){
        REP(i, q){
            double p;
            cin >> p;
            double key = p / 2000.0;
            double fan = (1.0 - (1.0 / k)), tfan = (1.0 - (1.0 / k));
            double ans;
            int day = k;
            REP(j, day-1)   tfan *= fan;
            ans = 1 - tfan;
            REP(j, k-1) ans *= (1-tfan);
            while(ans < key){
                day++;
                tfan = fan;
                REP(j, day-1)   tfan *= fan;
                ans = 1 - tfan;
                REP(j, k-1) ans *= (1-tfan);
            }
            cout << day << endl;
        }
    }
    return 0;
}
