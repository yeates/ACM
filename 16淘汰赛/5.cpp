#include <iostream>
#include <algorithm>
#include <string.h>
#define LL long long
#define Max(a, b) a > b? a: b
#define MAX 100005
using namespace std;

int a[MAX], b[MAX];
int main(){
    int n;
    while(cin >> n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            b[i] = ((1890*a[i] + 143) % 10007) - a[i];
        }
        int tmax = 0, t = 0;
        for(int i = 0; i < n; i++){
            if(t + b[i] >= t){
                t += b[i];
            }
            else{
                if(t + b[i] <= 0){
                    t = 0;
                }
                else{
                    t += b[i];
                }
            }
            tmax = Max(tmax, t);
        }
        cout << sum + tmax << endl;
    }
    return 0;
}
