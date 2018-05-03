#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 200050
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

double sum[MAX];
int main(){
    ios::sync_with_stdio(false);
    int n;
    double  a;
    while(cin >> n >> a){
        double angle = 180.0 / n;       //注意精度细节!
        double t_angle = angle;
        int i = 1;
        int t = i;
        double tmin = INF;
        while(i <= n-2){
            if(abs(angle-a) < tmin){
                t = i;
                tmin = abs(angle-a);
                //cout << t << " " << tmin << endl;
            }
            angle += t_angle;
            i++;
        }
        cout << "1 2 " << n - t + 1 << endl;
    }
    return 0;
}
