#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define Max(a, b)   (a > b ? a: b)
#define Min(a, b)   (a < b ? a: b)
#define MAX 1000050
#define INF 0x3f3f3f3f
using namespace std;
int a[MAX];
bool solve(int m, int n, int k){
    int sum = 0;
    int key = 0;
    for(int i = 0; i <= n; i++){    //���������ǰѡ��Ĵ�(mid)�������ܻ��ֳ����ٸ���
        sum += a[i];
        if(sum > m){
            key++;
            i--;
            sum = 0;
        }
    }
    if(key >= k)    return true;    //�����ǰѡ�Ĵ�(mid)���ֳ��Ŀ����������Ҫ��Ŀ���Ŀ��˵������ѡ��Ĵ�(mid)Ӧ�ø���һ�㣬Ҳ����lowӦ�õ���mid+1������������true
    else return false;
}

int main(){
    //ios::sync_with_stdio(false);
    int k, n = 0, tot = 0;
    scanf("%d", &k);
    getchar();      //ȥ�������ж���Ļس�
    memset(a, 0, sizeof(a));
    char t = getchar();     //���ַ�����
    while(t != '\n'){       //������س�ʱ˵�������Ѿ�����
        if(t == ' ' || t == '-'){   //������Ϊ�ո����-ʱ���������Ѿ���������һ������
            a[n]++; //ÿ�����ʵ��ַ���
            tot++;  //�ܹ����ٸ��ַ�����Ϊ���ֵ�high
            n++;    //���ʵĸ���
        }
        else    {a[n]++; tot++;}
        t = getchar();
    }
    int l = -INF, h = tot;
    for(int i = 0; i <= n; i++)
        l = l < a[i]? a[i]: l;  //n������������Ǹ�������Ϊ���ֵ�low

    while(l <= h){      //���ִ�
        int mid = (h - l) / 2 + l;
        if(solve(mid, n, k)){
            l = mid + 1;
        }
        else h = mid - 1;
    }
    cout << l << endl;
    return 0;
}
