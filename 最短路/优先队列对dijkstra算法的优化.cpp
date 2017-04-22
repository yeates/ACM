#include <iostream>
#include <queue>
#include <string.h>
/*
priority_queue实现的dijkstra最短路算法，时间复杂度O(mlogn)
相比原始dijkstra的O(n^2)复杂度，该算法不仅在稀疏图的情况下大大提高效率，且在稠密图下也常常不会慢于原始算法。
*/

using namespace std;
#define Max a > b ? a: b
#define Min a < b ? a: b
#define MAX 1005
#define INF 0x3f3f3f3f

struct Edge{
    int from, to, dist; //起点，终点，边权
    Edge(int f, int t, int d):from(f), to(t), dist(d){};
};

int n, m;       //n是节点数，m是边数
vector<Edge>edges;  //边数组
vector<int>G[MAX];   //邻接图，存储边的序号，不过注意第二维下标不再表示边终点!
int dis[MAX];         //图中每个点距离单源起点s的最短距离

//添加边到edges中，并且用G保存边的编号
void AddEdge(int s, int d, int w){
    edges.push_back(Edge(s, d, w));
    int no = edges.size() - 1;
    G[s].push_back(no);
}

void init(){
    for(int i = 0; i < MAX; i++){
        dis[i] = INF;
        G[i].clear();
    }
    edges.clear();
}

struct Node{
    int d, u;
    bool operator < (const Node& tp) const{     //自定义优先级策略，在priority_queue会使用
        return d > tp.d;        //d即dis[u]
    }
};

//core code
int dijkstra(int s, int d){
    int vis[MAX];
    priority_queue<Node>Q;
    //预处理部分
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    Q.push((Node){0, s});
    while(!Q.empty()){
        Node tp = Q.top();
        Q.pop();
        int u = tp.u;       //简化
        if(vis[u])  continue;
        vis[u] = 1;
        //松弛操作,和原版不一样了
        for(int i = 0; i < G[u].size(); i++){
            Edge& e = edges[G[u][i]];   //简化
            if(vis[e.to] == 0 && dis[e.to] > dis[u] + e.dist){
                dis[e.to] = dis[u] + e.dist;
                Q.push((Node){dis[e.to], e.to});
            }
        }
    }
    return dis[d];
}

int main(){
    ios::sync_with_stdio(0);
    while(cin >> m >> n){
        init();
        for(int i = 0; i < m; i++){
            int s, d, w;
            cin >> s >> d >> w;
            AddEdge(s, d, w);
            AddEdge(d, s, w);
        }
        cout << dijkstra(1, n) << endl;
    }
    return 0;
}

