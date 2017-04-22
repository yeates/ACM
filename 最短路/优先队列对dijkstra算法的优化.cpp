#include <iostream>
#include <queue>
#include <string.h>
/*
priority_queueʵ�ֵ�dijkstra���·�㷨��ʱ�临�Ӷ�O(mlogn)
���ԭʼdijkstra��O(n^2)���Ӷȣ����㷨������ϡ��ͼ������´�����Ч�ʣ����ڳ���ͼ��Ҳ������������ԭʼ�㷨��
*/

using namespace std;
#define Max a > b ? a: b
#define Min a < b ? a: b
#define MAX 1005
#define INF 0x3f3f3f3f

struct Edge{
    int from, to, dist; //��㣬�յ㣬��Ȩ
    Edge(int f, int t, int d):from(f), to(t), dist(d){};
};

int n, m;       //n�ǽڵ�����m�Ǳ���
vector<Edge>edges;  //������
vector<int>G[MAX];   //�ڽ�ͼ���洢�ߵ���ţ�����ע��ڶ�ά�±겻�ٱ�ʾ���յ�!
int dis[MAX];         //ͼ��ÿ������뵥Դ���s����̾���

//��ӱߵ�edges�У�������G����ߵı��
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
    bool operator < (const Node& tp) const{     //�Զ������ȼ����ԣ���priority_queue��ʹ��
        return d > tp.d;        //d��dis[u]
    }
};

//core code
int dijkstra(int s, int d){
    int vis[MAX];
    priority_queue<Node>Q;
    //Ԥ������
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    Q.push((Node){0, s});
    while(!Q.empty()){
        Node tp = Q.top();
        Q.pop();
        int u = tp.u;       //��
        if(vis[u])  continue;
        vis[u] = 1;
        //�ɳڲ���,��ԭ�治һ����
        for(int i = 0; i < G[u].size(); i++){
            Edge& e = edges[G[u][i]];   //��
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

