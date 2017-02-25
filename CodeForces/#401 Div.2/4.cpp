/*
一次ac。
题意分析，模拟，剪枝优化
优化cin:1310ms
*/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
#define pb push_back
#define pi acos(-1)
#define Max(a, b) a > b ? a: b
#define Min(a, b) a < b ? a: b
#define MAX 500005
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

vector<int>a[MAX];

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n){
        string tp;
        REP(i, n){
            cin >> tp;
            FOR(j, 1, tp.size()-1){
                a[i].pb(tp.at(j)-'a');
            }
            a[i].pb(-1);
        }
        FORD(i, n-2, 0){
            bool flag = true;
            REP(j, a[i].size()-1){
                if(a[i+1][j] < a[i][j] && a[i+1][j] != -1){
                    a[i][j] = -1;
                    break;
                }
                else if(a[i+1][j] > a[i][j])    break;
                else if(a[i+1][j] == -1){
                    if(flag){
                        a[i][j] = -1;
                        break;
                    }
                    else break;
                }
            }
        }
        REP(i, n){
            cout << "#";
            int j = 0;
            while(a[i][j] != -1){
                cout << char(a[i][j] + 'a');
                j++;
            }
            cout << endl;
        }
        REP(i, n)   a[i].clear();
    }
    return 0;
}
