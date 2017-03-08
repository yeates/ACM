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

template <typename T>
struct NODE{
    T x, y;
    NODE(T a, T b): x(a), y(b){};       //构造函数
};

template <typename T>       //每段使用模版函数的函数前都应该加上模版函数的声明
//重载+运算符
NODE<T> operator + (const NODE<T>& A, const NODE<T>& B){        //注意每个使用到模版函数的都要修改保留字格式:后面加上<typename>
    return NODE<T>(A.x + B.x, A.y + B.y);
}

//重载<<运算符
template <typename T>
ostream& operator << (ostream& out, const NODE<T>& A){
    out << "x=" << A.x << endl;
    out << "y=" << A.y << endl;
}

int main(){
    double _1, _2, _3, _4;      //下划线_不能作为变量的后缀
    while(cin >> _1 >> _2 >> _3 >> _4){
        NODE<double> m(_1, _2), n(_3, _4);
        cout << m << endl;
        cout << n << endl;
        cout << m + n << endl;
    }
    return 0;
}

