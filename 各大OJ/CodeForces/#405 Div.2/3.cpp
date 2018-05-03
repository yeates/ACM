#include<bits/stdc++.h>
#define MAX 1005
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k;
    while(cin >> n >> k){
        int num[MAX];
        for(int i = 1; i < k; i++)  num[i] = i;
        int key = k;
        int tp = n - k + 1;
        for(int i = 1; i <= tp; i++){
            string str;
            cin >> str;
            int m = k+i-1;
            if(str == "YES"){
                num[m] = key;
                key++;
            }
            else if(str == "NO"){
                num[m] = num[m-k+1];
            }
        }
        for(int i = 1; i <= n; i++){
            cout << "A";
            if(num[i] < 26){
                cout << 'a' << char('a' + num[i] - 1);
            }
            else{
                cout << 'b' << char(num[i] - 26 + 'a');
            }
            i == n ? cout << endl: cout << " ";
        }
    }
    return 0;
}
