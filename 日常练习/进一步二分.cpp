#include <bits/stdc++.h>
using namespace std;
#define Max a > b ? a: b
#define Min a < b ? a: b
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define fcout(a, i, n)  i == n-1? cout << a << endl: cout << a << " "
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define pi acos(-1)
#define pb push_back
#define MAX 105
#define INF 0x3f3f3f3f

//几种二分查找(O(logn))，区别在于是否数组中含有多个相同的查找值
//lower_bound返回等于item的第一个位置
template<typename T>
int mine_lower_bound(T *a, T item, int n){
    int l = 0, r = n-1;
    while(l < r){
        int m = (r - l) / 2 + l;
        if(a[m] >= item)  r = m;
        else    l = m + 1;
    }
    if(a[l] == item)    return l;
    else return -1;
}

//upper_bound返回等于item的最后一个位置的下一个位置。。
template<typename T>
int mine_upper_bound(T *a, T item, int n){
    int l = 0, r = n-1;
    while(l < r){
        int m = (r - l) / 2 + l;
        if(a[m] > item)   r = m;
        else l = m + 1;
    }
    if(a[l-1] == item)   return l-1;
    else return -1;
}

template<typename T>
int mine_binary_search(T *a, T item, int n){
    int l = 0, r = n-1;
    while(l < r){
        int m = (r - l) / 2 + l;
        if(a[m] == item)  return m;
        else if(a[m] > item) r = m-1;
        else l = m+1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n){
        int _array[MAX];
        REP(i, n)   cin >> _array[i];
        sort(_array, _array + n);
        REP(i, n)   fcout(_array[i], i, n);
        int item;
        cin >> item;
        cout << "upper_bound:" << endl;
        cout << mine_upper_bound(_array, item, n) << endl << endl;
        cout << "lower_bound:" << endl;
        cout << mine_lower_bound(_array, item, n) << endl << endl;
        cout << "binary_search:" << endl;
        cout << mine_binary_search(_array, item, n) << endl << endl;
    }
    return 0;
}
