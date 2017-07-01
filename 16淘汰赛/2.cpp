#include <stdio.h>

int res[25];
void hanoi(){
    res[0] = 0;
    for(int i = 1; i < 25; i++){
        res[i] += 2 + 3 * res[i-1];
    }
}

int main(){
    int T;
    scanf("%d", &T);
    hanoi();
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%d\n", res[n-1] + 2);
    }
    return 0;
}
