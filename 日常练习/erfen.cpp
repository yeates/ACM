#include<bits/stdc++.h>
#define Max(a, b) a > b? a: b
#define MAX 10005
#define LL long long
#define INF 0x3f3f3f3f
#define Min(a, b) a < b? a: b
using namespace std;

int erfen(int a[], int n, int item){
    int l = 0, r = n-1;
    while(l <= r){
        //int mid = (l + r) / 2;
        int mid = (r - l) / 2 + l;
        if(a[mid] == item)  return mid;
        if(a[mid] < item)   l = mid + 1;
        else r = mid - 1;
    }
    return -2;
}

int main(){
    int n, a[MAX];
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> a[i];
    int item;
    sort(a, a + n);
    cin >> item;
    cout << erfen(a, n, item) + 1 << endl;
    return 0;
}
