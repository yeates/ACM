#客户调查(0478)  [_link_](http://acm.swust.edu.cn/problem/0478/)

##Problem Description
公司派你去和几位客户面谈，以了解他们对公司产品的意见。你逐个打电话与客户联系，得知他们一般都很忙，不过他们还是可以为你抽出一点时间。现在的问题是有些客户的时间有冲突，你无法在一天内联系所有客户。所以你需要一个程序来帮助你安排第一天的工作，使得你能尽可能地和更多的客户进行联系。注意，客户不愿意你打乱他们的计划。如果你和某个客户约定见面，必须按时到达并且充分利用这段时间和他交谈，这样才不至于让他产生不满。你可以假设从一个客户处到另一个客户处的时间短得忽略不计。 

##Input
输入包括了多个测试数据，每个测试数据开头是一个整数n（1<=n<=1000），表示客户总数。接下来n行每行包括两个正整数s、t，分别表示该客户的空闲时间段的起始时间和终止时间。

##Output
对于每个测试数据，在单独一行内输出你所能接触到的最多客户数。

##Sample Input
	3
	1 15
	2 19
	15 17  

##Sample Output
	2


##Think
这道题是算法导论考试的时候抽到的一道题，那时还不怎么会用动归，所以只有用稍微暴力点的方法——记忆化搜索。  
对题建模相当于是求最大的不重叠子集的集合的元素个数。先排序再搜索即可得到答案。

##Code
    #include <bits/stdc++.h>
    #define MAX 1010
    #define INF 0x3f3f3f3f
    #define LL long long
    #define Min(a, b) (a < b)? a: b
    #define Max(a, b) (a < b)? b: a
    using namespace std;

    int a[MAX], b[MAX];
    int dp[MAX];
    int n;

    struct node{
        int x, y;
    }c[MAX];

    int DFS(int x){
       if(dp[x] > 1)    return dp[x];
       for(int i = x + 1; i < n; i++){
            if(a[i] < b[x])  continue;      //如果后一个客户的开始小于了当前这个客户结束时间，说明时间重合。
            dp[x] = Max(dp[x], DFS(i) + 1);
       }
       return dp[x];
    }

    bool cmp(node a, node b){
        return a.x < b.x;
    }

    int main(){
        while(cin >> n){
            for(int i = 0; i < n; i++)
                dp[i] = 1;     //最少都有一个客户
            for(int i = 0 ; i < n; i++)
                cin >> c[i].x >> c[i].y;
            sort(c, c + n, cmp);        //以开始时间进行排序
            for(int i = 0; i < n; i++)
                a[i] = c[i].x, b[i] = c[i].y;
            int ans = 0;
            for(int i =0 ; i <n ;i++){  //虽然进行排序，但第一个客户并不肯定就是答案集合中的元素。所以要遍历数组。
                ans = Max(DFS(i), ans);
            }
            cout << ans << endl;
        }
        return 0;
    }
