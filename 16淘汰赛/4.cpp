#include <iostream>
#include <string.h>
#include <stdio.h>
#define Max(a, b) a > b? a: b
#define Min(a, b) a < b? a: b
#define MAX 10005
#define eps 1e-10
using namespace std;
double a[MAX];
int n, m;
bool solve(double x){
    int key = 0;
    for(int i = 0; i < n; i++){
        key += (int)(a[i] / x);
    }
    if(m <= key)    return true;
    return false;
}
int main(){
    while(scanf("%d%d", &n, &m) && (n || m)){
        double sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%lf", &a[i]);
            sum += a[i];
        }
        double l, h, ans;
        l = 0, h = sum / (double)m;
        while(h - l >= 0){
            double mid = (h + l) / 2.0;
            if(solve(mid))  l = mid + eps;
            else h = mid - eps;
        }
        if(l <= 0.01) l = 0.00;
        printf("%.2lf\n", l);
    }
    return 0;
}
