#\#395 C : Timofey and a tree [_link_](http://codeforces.com/contest/764/problem/C)

#Description
Each New Year Timofey and his friends cut down a tree of n vertices and bring it home. After that they paint all the n its vertices, so that the i-th vertex gets color ci.  

Now it's time for Timofey birthday, and his mother asked him to remove the tree. Timofey removes the tree in the following way: he takes some vertex in hands, while all the other vertices move down so that the tree becomes rooted at the chosen vertex. After that Timofey brings the tree to a trash can.  

Timofey doesn't like it when many colors are mixing together. A subtree annoys him if there are vertices of different color in it. Timofey wants to find a vertex which he should take in hands so that there are no subtrees that annoy him. He doesn't consider the whole tree as a subtree since he can't see the color of the root vertex.  

A subtree of some vertex is a subgraph containing that vertex and all its descendants.  

Your task is to determine if there is a vertex, taking which in hands Timofey wouldn't be annoyed.

#Input
The first line contains single integer n (2 ≤ n ≤ 10^5) — the number of vertices in the tree.  

Each of the next n - 1 lines contains two integers u and v (1 ≤ u, v ≤ n, u ≠ v), denoting there is an edge between vertices u and v. It is guaranteed that the given graph is a tree.  

The next line contains n integers c1, c2, ..., cn (1 ≤ ci ≤ 10^5), denoting the colors of the vertices.

#OutPut
Print "NO" in a single line, if Timofey can't take the tree in such a way that it doesn't annoy him.  

Otherwise print "YES" in the first line. In the second line print the index of the vertex which Timofey should take in hands. If there are multiple answers, print any of them.

#SampleInput
	4
	1 2
	2 3
	3 4
	1 2 1 1
	3
	1 2
	2 3
	1 2 3
	4
	1 2
	2 3
	3 4
	1 2 1 2

#SampleOutput
	YES
	2
	YES
	2
	NO

#Think
当时已经有50+人做出来这道题的时候我才读懂题意。。  
题意：大意就是给出一颗**树**，并且无论哪个结点作为根节点仍然是一颗数，树的每个结点都有一个值（颜色），然后让我找出一个结点作为树的根节点，**使得这个结点的左子树的所有子结点的值(颜色)全部相同，右子树的所有子结点的值也全部相同**，根节点不作计算。  

<br>
一开始想到了线段树。。也想到了并查集。。也试过正难则反的推规律，但是似乎都不能下手，尤其在后两者想了很久，实在走投无路了还真想过用数据结构模拟，但是觉得等到写出来黄花菜都凉了。在比赛结束前的半个小时，头脑就好像处于一种放空推规律的状态了，当晚睡的时候还真没想起来我是怎么想到下面的方法。。。但是一切都迟了。。最后5秒绝杀，并没有AC。。写错了一点WA了。。所以思路和经验一样重要啊，要是能快速确定题型的话，绝对是事半功倍   
<br>
首先每个边肯定是要遍历一遍的，至少得知道边的两个结点值是不是相同，而且不能嵌套循环，嵌套绝对会超时，所以就要注意这一遍循环究竟要做什么。然后再进一步分析题意，如果树上每个结点的值都相同，那么哪个点都能做为根节点，皆大欢喜。但如果，有哪个点的值会和其他的不一样，那么那个点肯定就是根节点，如果有一些点和其他的不一样，那么这些点就都有可能是根节点，就可以称之为**嫌疑点**。继续，因为每条边的两个结点其实是有两种类型的，一种是两个点抱团（值相同），一种就是出现嫌疑点（两结点值不同，两者之一就有可能是最后的答案）。  
所以，先找到所有出现了嫌疑点的边，最后的答案结点肯定染指了这每一条边（就是出现）了。  
这里用times[i]记录第i个结点出现过的可疑边的条数，tot就是所有可疑边的条数，如果相等，那么就找到了这个最终点。


#Code
	#include <bits/stdc++.h>
	#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
	#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
	#define REP(i, a)   FOR(i, 0, (int)(a) - 1)
	#define pb push_back
	#define MAX 100050
	#define INF 0x3f3f3f3f
	using namespace std;
	
	vector<int>vec[MAX];
	int color[MAX];
	int tot, times[MAX];
	
	int main(){
	    ios::sync_with_stdio(0);
	    cin.tie(0);
	    int n;
	    while(cin >> n){
	        //输入
	        REP(i, n-1){
	            int u, v;
	            cin >> u >> v;
	            vec[u].pb(v);
	            vec[v].pb(u);
	        }
	        FOR(i, 1, n)   cin >> color[i];
			
			//计算
	        FOR(i, 1, n){
	            for(int j = 0; j < vec[i].size(); j++){
	                int tmp = vec[i][j];
	                if(color[i] != color[tmp]){
	                    times[i]++, times[tmp]++;
	                    tot++;
	                }
	            }
	        }
	        int ans = -1;
	        FOR(i, 1, n){
	            if(tot == times[i]){
	                ans = i;
	                break;
	            }
	        }
	
	        ans == -1? cout << "NO": cout << "YES" << endl << ans;
	        cout << endl;
	    }
	    return 0;
	}
