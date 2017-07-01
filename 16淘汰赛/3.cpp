#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 400005
using namespace std;

struct node{
    int l, r;
    int sum;
    int mark;
}a[MAX * 4];

void pushdown(int x){
    if(a[x].mark != 0){
        a[x].sum += a[x].mark;
        a[x * 2].mark += a[x].mark;
        a[x * 2 + 1].mark += a[x].mark;
        a[x].mark = 0;
    }
}

void pushup(int x){
    a[x].sum = a[x * 2].sum + a[x * 2 + 1].sum;
}

void build(int x, int l, int r){
    a[x].l = l, a[x].r = r;
    if(l == r){
        a[x].sum = 0;
        a[x].mark = 0;
        return;
    }
    int mid = (r - l) / 2 + l;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    pushup(x);
}

void update(int x, int l, int r){
    if(a[x].l == l && a[x].r == r){
        a[x].mark++;
        return;
    }
    int mid = (a[x].r - a[x].l) / 2 + a[x].l;
    if(r <= mid){
        update(x * 2, l, r);
    }
    else if(l > mid){
        update(x * 2 + 1, l, r);
    }
    else if(l <= mid && mid <= r){
        update(x * 2, l, mid);
        update(x * 2 + 1, mid + 1, r);
    }
}

int query(int x, int l, int r){
    pushdown(x);
    if(a[x].l == l && a[x].r == r){
        return a[x].sum;
    }
    int mid = (a[x].r - a[x].l) / 2 + a[x].l;
    if(r <= mid){
        return query(x * 2, l, r);
    }
    else if(l > mid){
        return query(x * 2 + 1, l, r);
    }
    else if(l <= mid && mid <= r){
        int ans = 0;
        ans += query(x * 2, l, mid);
        ans += query(x * 2 + 1, mid + 1, r);
        return ans;
    }
}

int main(){
    //ios::sync_with_stdio(false);
    int n;
    while(scanf("%d", &n) && n){
        memset(a, 0, sizeof(a));
        build(1, 1, n);
        for(int i = 0; i < n; i++){
            int l, r;
            scanf("%d%d", &l, &r);
            //l = r = n;
            update(1, l, r);
        }
        for(int i = 1; i <= n; i++){
            i == n? printf("%d\n", query(1, i, i)): printf("%d ", query(1, i, i));
        }
    }
    return 0;
}
