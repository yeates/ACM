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
    NODE(int a = 3, int b = 2, double c = 1.0):x(a), y(b), z(c){};      //����һ�ֳ�ʼ���ļ��д��
    /*������ԭʼ��д��
    NODE(int a = 3, int b = 2, double c = 1.0){
        x = a, y = b, z = c;
    }
    */
};
//����NODE�ṹ���+�����
NODE operator + (const NODE& A, const NODE& B){
    return NODE(A.x + B.x, A.y + B.y, A.z + B.z);
}
//����NODE�ṹ���е�<<�����
ostream& operator << (ostream& out, NODE A){
    out << "x=" << A.x << endl;
    out << "y=" << A.y << endl;
    out << "z=" << A.z << endl;
}

int main(){
    string line;
    while(getline(cin, line)){      //�������뵽line(string)��
        NODE nd;
        printf("%d %d %lf\n", nd.x, nd.y, nd.z);        //���Ĭ�ϵ�x,y,zֵ
        stringstream ss(line);      //stringstream������sstreamͷ�ļ��У����Զ�string�����ٴ���ע�����ĳ�ʼ����ʽ����Ч�ʱȽϵͣ�
        int no = 0, a, b;
        double c, x;
        while(ss >> x){     //�ո�Ϊ�ָ���
            if(0 == no) a = (int)x;
            else if(1 == no) b = (int)x;
            else c = x;
            no++;
        }
        NODE ned(a, b, c);
        cout << ned << endl;        //������NODE�ṹ���<<�����
    }
    return 0;
}
