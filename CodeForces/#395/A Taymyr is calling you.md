#\#395A : Taymyr is calling you [_link_](http://codeforces.com/contest/764/problem/A)

#Description
Comrade Dujikov is busy choosing artists for Timofey's birthday and is recieving calls from Taymyr from Ilia-alpinist.  

Ilia-alpinist calls every n minutes, i.e. in minutes n, 2n, 3n and so on. Artists come to the comrade every m minutes, i.e. in minutes m, 2m, 3m and so on. The day is z minutes long, i.e. the day consists of minutes 1, 2, ..., z. How many artists should be killed so that there are no artists in the room when Ilia calls? Consider that a call and a talk with an artist take exactly one minute.

#Input
The only string contains three integers — n, m and z (1 ≤ n, m, z ≤ 10^4).

#OutPut
Print single integer — the minimum number of artists that should be killed so that there are no artists in the room when Ilia calls.

#SampleInput
	1 1 10

#SampleOutput
	10

#Think
简单模拟

#Code
	#include <bits/stdc++.h>
	#define MAX 10050
	#define INF 0x3f3f3f3f
	#define LL long long
	#define Min(a, b) (a < b)? a: b
	#define Max(a, b) (a < b)? b: a
	using namespace std;
	
	int vis[MAX];
	
	int main(){
	    ios::sync_with_stdio(0);
	    cin.tie(0);
	    int x, y, n;
	    while(cin >> x >> y >> n){
	        memset(vis, 0, sizeof(vis));
	        int i = 1;
	        i *= x;
	        while(i <= n){
	            vis[i]++;
	            i += x;
	        }
	        i = y;
	        while(i <= n){
	            vis[i]++;
	            i += y;
	        }
	        int ans = 0;
	        for(i = 1; i <= n; i++){
	            if(vis[i] == 2) ans++;
	        }
	        cout << ans << endl;
	    }
	    return 0;
	}


