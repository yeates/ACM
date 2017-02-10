#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define MAX 105
#define INF 0x3f3f3f3f
#define LL long long
#define Min(a, b) (a < b)? a: b
#define Max(a, b) (a < b)? b: a
using namespace std;

LL mpt[MAX][MAX];

int main(){
    LL n, m, k, x, y;
    while(~scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &x, &y)){
        LL max, min, ser;
        if(n == 1){
            LL t,p;
            t = k / (n*m);
            p = k % (n * m);
            max = min = t;
            if(p != 0) max++;
            if(x * y <= p)  ser = max;
            else ser = min;
            printf("%lld %lld %lld\n", max, min, ser);
            continue;
        }
        memset(mpt, 0, sizeof(mpt));
        LL t, p, q, z;
        t = k - n * m;
        if(t > 0){
            p = t / ((n - 1) * m);
            q = t % (n - 1) * m;
            if(p >= 0){
                if(q != 0) max = 1 + p + 1;
                else max = 1 + p;
                min = p / 2 + 1;
                if(p % 2 == 0){
                    int i = n - 2, j = 0;
                    while(q > 0){
                        mpt[i][j] = 1;
                        j++;
                        if(j >= m){
                            j = 0;
                            i--;
                        }
                        q--;
                    }
                    for(i = 0; i < n; i++){
                        for(j = 0; j < m; j++){
                            if(i == n - 1 || i == 0){
                                mpt[i][j] += 1 + p / 2;
                            }
                            else    mpt[i][j] += 1 + p;
                        }
                    }
                }
                else{
                    int i = 1, j = 0;
                    while(q > 0){
                        mpt[i][j] = 1;
                        j++;
                        if(j >= m){
                            j = 0;
                            i++;
                        }
                        q--;
                    }
                    for(i = 0; i < n; i++){
                        for(j = 0; j < m; j++){
                            if(i == n - 1)  mpt[i][j] += 1 + p / 2;
                            else if(i == 0) mpt[i][j] += 2 + p / 2;
                            else    mpt[i][j] += 1 + p;
                        }
                    }
                }
            }
        }
        else{
            max = 1;
            min = t == 0 ? 1: 0;
            if(x * y <= k)   ser = 1;
            else ser = 0;
            printf("%lld %lld %lld\n", max, min, ser);
            continue;
        }
        printf("%lld %lld %lld\n", max, min, mpt[x - 1][y - 1]);
    }
    return 0;
}
