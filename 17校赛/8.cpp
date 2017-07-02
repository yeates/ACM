#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define MAX 1005
using namespace std;

void o2b(char *s, char *a){
    memset(a, 0, sizeof(a));
    int n = strlen(s);
    char t[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    for(int i = 0; i < n; i++){
        int no = s[i] - '0';
        strcat(a, t[no]);
    }
}

int main(){
    char str[MAX];
    while(~scanf("%s", str)){
        char x[MAX];
        o2b(str, x);
        int n = strlen(x);
        int a, b, c;
        a = b = c = 0;
        char t[5];
        t[4] = 0;
        for(int i = n-1; i >= 0; i-=4){
            for(int j = 0; j < 4; j++){
                t[j] = x[i-j];
            }
            if(strcmp(t, "0101") == 0)  a++;
            else if(strcmp(t, "1101") == 0) b++;
            else if(strcmp(t, "0011") == 0) c++;
        }
        cout << a << " " << b << " " << c << "\r\n";
    }
    return 0;
}
