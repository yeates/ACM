#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define MS(vis) memset(vis, 0, sizeof(vis));
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 60005
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
double v[MAX], x[MAX];
int n;
const double eps = 0.0000001;

bool solve(double t)
{
    double up = 0, down = 0;
    REP(i, n){
        if(x[i] >= t){
            up = Max(up, (x[i] - t) / v[i]);
        }
        else{
            down = Max(down, (t - x[i]) / v[i]);
        }
    }
    if(up > down)   return true;
    return false;
}
double bsearch(double l,double r)
{
    while(l<=r)
    {
        double mid=(l+r)/2;
        bool key = solve(mid);
        if(key)
        {
            l = mid+eps;
        }
        else r = mid-eps;
    }
    double ans = 0;
    REP(i, n){
        ans = Max(ans, abs(l - x[i]) / v[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    while(cin >> n) {
        double l = INF, r = 0;
        REP(i, n){
            cin >> x[i];
            l = Min(l, x[i]);
            r = Max(r, x[i]);
        }
        REP(i, n)   cin >> v[i];
        printf("%.12lf\n", bsearch(l, r));
        //cout << eps << endl;
    }
    return 0;
}
