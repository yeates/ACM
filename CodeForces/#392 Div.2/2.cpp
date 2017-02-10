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

int main(){
    char str[MAX];
    while(~scanf("%s", str)){
        int n = strlen(str);
        int kr, kb, ky, kg;
        kr = kb = ky = kg = 0;
        char test[5];
        memset(test, '\0', sizeof(test));
        int testNum = 0;
        for(int i = 0; i < n; i++){
            if(str[i] != '!' && test[i % 4] != str[i]){
                test[i % 4] = str[i];
                if(testNum >= 4)    break;
                else testNum++;
            }
        }
        for(int i = 0; i < n; i++){
            if(str[i] == '!'){
                if(test[i % 4] == 'R')  kr++;
                else if(test[i % 4] == 'B') kb++;
                else if(test[i % 4] == 'Y') ky++;
                else if(test[i % 4] == 'G') kg++;
            }
        }
        printf("%d %d %d %d\n", kr, kb, ky, kg);
        memset(str, '\0', sizeof(str));
    }
    return 0;
}
