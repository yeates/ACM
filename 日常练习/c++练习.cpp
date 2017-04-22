#include <bits/stdc++.h>
using namespace std;
#define Max a > b ? a: b
#define Min a < b ? a: b
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define pi acos(-1)
#define pb push_back
#define MAX 105
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MS(vis) memset(vis, 0, sizeof(vis));
#define LL long long

struct NODE{
    int x, y;
    double z;
    NODE(int a = 3, int b = 2, double c = 1.0):x(a), y(b), z(c){};      //这是一种初始化的简便写法
    /*这是最原始的写法
    NODE(int a = 3, int b = 2, double c = 1.0){
        x = a, y = b, z = c;
    }
    */
};
//重载NODE结构体的+运算符
NODE operator + (const NODE& A, const NODE& B){
    return NODE(A.x + B.x, A.y + B.y, A.z + B.z);
}
//重载NODE结构体中的<<运算符
ostream& operator << (ostream& out, NODE A){
    out << "x=" << A.x << endl;
    out << "y=" << A.y << endl;
    out << "z=" << A.z << endl;
}

int main(){
    string line;
    while(getline(cin, line)){      //整行输入到line(string)中
        NODE nd;
        printf("%d %d %lf\n", nd.x, nd.y, nd.z);        //输出默认的x,y,z值
        stringstream ss(line);      //stringstream包含在sstream头文件中，可以对string进行再处理，注意他的初始化方式。（效率比较低）
        int no = 0, a, b;
        double c, x;
        while(ss >> x){     //空格为分隔符
            if(0 == no) a = (int)x;
            else if(1 == no) b = (int)x;
            else c = x;
            no++;
        }
        NODE ned(a, b, c);
        cout << ned << endl;        //重载了NODE结构体的<<运算符
    }
    return 0;
}
