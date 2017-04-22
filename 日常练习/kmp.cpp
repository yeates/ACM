#include<bits/stdc++.h>
#define Max(a, b) a > b? a: b
#define MAX 10005
#define LL long long
#define INF 0x3f3f3f3f
#define Min(a, b) a < b? a: b
using namespace std;

int Next[MAX];

void makeNext(char t[], int m){
    Next[0] = -1;
    int i = 0, j = -1;
    while(i < m){
        if(j == -1 || t[i] == t[j]) {
            i++, j++;
            Next[i] = Next[j];
        }
        else j = Next[j];
    }
}

int kmp(char s[], int n, char t[], int m){
    makeNext(t, m);
    int i = 0, j = -1;
    while(i < n && j < m){
        if(j == -1 || t[j] == s[i]){
            i++, j++;
        }
        else j = Next[j];
    }
    if(i >= n && j < m) return -1;
    else return i - m + 1;
}

int main(){
    char s[MAX], t[MAX];
    while(cin >> s >> t){
        int n = strlen(s), m = strlen(t);
        cout << kmp(s, n, t, m) << endl;
    }
    return 0;
}
