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
    for(int i = 0; i <= n; i++){    //计算出按当前选择的答案(mid)，至少能划分出多少个块
        sum += a[i];
        if(sum > m){
            key++;
            i--;
            sum = 0;
        }
    }
    if(key >= k)    return true;    //如果当前选的答案(mid)划分出的块比我们输入要求的块数目大，说明我们选择的答案(mid)应该更大一点，也就是low应该等于mid+1，本函数返回true
    else return false;
}

int main(){
    //ios::sync_with_stdio(false);
    int k, n = 0, tot = 0;
    scanf("%d", &k);
    getchar();      //去掉输入中多余的回车
    memset(a, 0, sizeof(a));
    char t = getchar();     //按字符输入
    while(t != '\n'){       //当输入回车时说明输入已经结束
        if(t == ' ' || t == '-'){   //当输入为空格或者-时，都代表已经进入了下一个单词
            a[n]++; //每个单词的字符数
            tot++;  //总共多少个字符，作为二分的high
            n++;    //单词的个数
        }
        else    {a[n]++; tot++;}
        t = getchar();
    }
    int l = -INF, h = tot;
    for(int i = 0; i <= n; i++)
        l = l < a[i]? a[i]: l;  //n个单词中最长的那个单词作为二分的low

    while(l <= h){      //二分答案
        int mid = (h - l) / 2 + l;
        if(solve(mid, n, k)){
            l = mid + 1;
        }
        else h = mid - 1;
    }
    cout << l << endl;
    return 0;
}
