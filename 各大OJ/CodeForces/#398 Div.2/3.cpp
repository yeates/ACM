/*
题意：一颗树，每个结点有可正可负的值，找到两条边，使得从这两条边剪掉之后分成的三部分，各自值的总和，能够相等
思路：
DFS+剪枝
学习：
一种二维数组结构——vector<int>mpt[]。优势：可以知道第二维的长度，且使第二维动态。适合用作树的数据结构！
清零方法:循环加clear()函数

要有剪枝的意识！
*/
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

vector<int>mpt[MAX];
int val[MAX];
int tmpVal[MAX];
int ans1, ans2, sum;

void DFS(int u, int v){
    tmpVal[u] = val[u];
    FOR(i, 0, mpt[u].size()-1){
        if(mpt[u][i] == v)  continue;       //如果是父亲结点就跳过，只搜索子节点
        DFS(mpt[u][i], u);
        tmpVal[u] += tmpVal[mpt[u][i]];
    }
    if(tmpVal[u] == sum / 3){
        if(v == -1) return;
        else if(ans1 == -1){
            ans1 = u;
            tmpVal[u] = 0;
        }
        else if(ans2 == -1){
            ans2 = u;
            tmpVal[u] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        REP(i, n+1)   mpt[i].clear();
        memset(tmpVal, 0, sizeof(tmpVal));
        sum = 0;
        int root;
        FOR(i, 1, n){
            int num;
            cin >> num >> val[i];
            sum += val[i];
            if(num == 0){
                root = i;
                continue;
            }
            mpt[i].pb(num);
            mpt[num].pb(i);
        }

        if(sum % 3 == 0){
            ans1 = ans2 = -1;
            DFS(root, -1);
            if(ans1 == -1 || ans2 == -1)    cout << "-1" << endl;
            else cout << ans1 << " " << ans2 << endl;
        }
        else    cout << "-1" << endl;
    }
    return 0;
}
