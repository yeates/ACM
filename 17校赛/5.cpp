#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 1005
using namespace std;

int mpt[MAX][MAX];
struct node{
    int x, y;
}a[4];
void add(node &a){
    a.x += 100;
    a.y += 100;
}
int main(){
    ios::sync_with_stdio(false);
    while(cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y){
        cin >> a[2].x >> a[2].y >> a[3].x >> a[3].y;
        memset(mpt, 0, sizeof(mpt));
        for(int i = 0; i < 4; i++)  add(a[i]);
        if(a[0].x > a[1].x) swap(a[0], a[1]);
        for(int i = a[0].x; i <= a[1].x; i++){
            mpt[i][a[0].y] = 1;
            mpt[i][a[1].y] = 1;
        }
        if(a[0].y > a[1].y) swap(a[0], a[1]);
        for(int i = a[0].y; i <= a[1].y; i++){
            mpt[a[0].x][i] = 1;
            mpt[a[1].x][i] = 1;
        }
        bool flag = true;
        if(a[2].x > a[3].x) swap(a[2], a[3]);
        for(int i = a[2].x; i <= a[3].x; i++){
            if(mpt[i][a[2].y] == 1) flag = false;
            if(mpt[i][a[3].y] == 1) flag = false;
        }
        if(a[2].y > a[3].y) swap(a[2], a[3]);
        for(int i = a[2].y; i <= a[3].y; i++){
            if(mpt[a[2].x][i] == 1) flag = false;
            if(mpt[a[3].x][i] == 1) flag = false;
        }
        if(flag)    cout << "NO" << "\r\n";
        else cout << "YES" << "\r\n";
    }
    return 0;
}
