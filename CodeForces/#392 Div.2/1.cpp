#include <bits/stdc++.h>
#define MAX 50005
#define INF 0x3f3f3f3f
#define LL long long
#define Min(a, b) (a < b)? a: b
#define Max(a, b) (a < b)? b: a
using namespace std;

struct node{
    int l,r;
    int x, y,c;
    int ml, mr;
    int sum;
};
node a[4*50005];
void build(int i,int l,int r){
    a[i].l = l;
    a[i].r = r;
    int mid = (l + r)/2;
    if(l == r){
        scanf("%d%d%d%d%d",&a[i].ml, &a[i].mr, &a[i].x, &a[i].y, &a[i].z);
        a[i].sum = Max(a[i].x, a[i].y, a[i].z);
        return;
    }
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    if(a[i * 2].ml >= )
    a[i].sum = a[i*2].sum + a[i*2+1].sum;
}
void updata(int i,int index,int data){
    if(a[i].l == a[i].r){
        a[i].sum+=data;
        return;
    }
    int mid = (a[i].l+a[i].r)/2;
    if(index<=mid)  updata(i*2,index,data);
    else    updata(i*2+1,index,data);
    a[i].sum = a[i*2].sum + a[i*2+1].sum;
}
int query(int i,int l,int r){
    int mid = (a[i].l + a[i].r)/2;
    int sum=0;
    if(a[i].l == l&&a[i].r == r)    return a[i].sum;
    if(r <= mid)    return query(i*2,l,r);
    else if(l > mid)   return query(i*2+1,l,r);
    else{
        sum+=query(i*2,l,mid);
        sum+=query(i*2+1,mid+1,r);
        return sum;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        build(1, 1, n);
        cout << query(1, n) << endl;
    }
    return 0;
}
