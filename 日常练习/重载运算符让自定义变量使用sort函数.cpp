
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
    NODE(T a = 0, T b = 0): x(a), y(b){};       //���캯��
};

template<typename T>
bool operator < (const NODE<T>& A, const NODE<T>& B){       //�����<�ķ���ֵ�ǲ�������
    if(A.x > B.x)   return false;
    else    return true;
}

template<typename T>
ostream& operator << (ostream& out, const NODE<T>& A){
    out << "x=" << A.x << endl;
    out << "y=" << A.y << endl;
    return out;
}

int main(){
    int n;
    while(cin >> n){
        NODE<double> tp[MAX];
        REP(i, n)   cin >> tp[i].x >> tp[i].y;
        sort(tp, tp + n);       //�����Զ��������Ҫ����<���������ʹ��sort������
        REP(i, n)   cout << tp[i];
    }
    return 0;
}

