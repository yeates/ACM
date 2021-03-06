/*
题意：
1-n这n个数，会以乱序的输入，但是只有当最大的数输出之后，才能继续输出更小的数，不然就输出回车。比如：41523,输出/n/n5 4/n/n3 2 1
思路：
对题意分析化简，用模拟即可做出
*/

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 100005
#define MOD 1000000007
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans[MAX];
    int n;
    while(cin >> n){
        int tmax = n;
        memset(ans, 0, sizeof(ans));
        REP(i, n){
            int x;
            cin >> x;
            ans[x] = 1;
            while(ans[tmax] == 1){
                cout << tmax << " ";
                tmax--;
            }
            cout << endl;
        }
    }
    return 0;
}
