#\#395 B : Timofey and cubes [_link_](http://codeforces.com/contest/764/problem/B)

#Description
Young Timofey has a birthday today! He got kit of n cubes as a birthday present from his parents. Every cube has a number ai, which is written on it. Timofey put all the cubes in a row and went to unpack other presents.  

In this time, Timofey's elder brother, Dima reordered the cubes using the following rule. Suppose the cubes are numbered from 1 to n in their order. Dima performs several steps, on step i he reverses the segment of cubes from i-th to (n - i + 1)-th. He does this while i ≤ n - i + 1.  

After performing the operations Dima went away, being very proud of himself. When Timofey returned to his cubes, he understood that their order was changed. Help Timofey as fast as you can and save the holiday — restore the initial order of the cubes using information of their current location.

#Input
The first line contains single integer n (1 ≤ n ≤ 2·10^5) — the number of cubes.  

The second line contains n integers a1, a2, ..., an ( - 10^9 ≤ ai ≤ 10^9), where ai is the number written on the i-th cube after Dima has changed their order.

#OutPut
Print n integers, separated by spaces — the numbers written on the cubes in their initial order.  

It can be shown that the answer is unique.

#SampleInput
	7
	4 3 7 6 9 1 2
	8
	6 1 4 2 5 6 9 2

#SampleOutput
	2 3 9 6 7 1 4
	2 1 6 2 5 4 9 6

#Think
找规律

#Code
	#include <bits/stdc++.h>
	#define MAX 200500
	#define INF 0x3f3f3f3f
	#define LL long long
	#define Min(a, b) (a < b)? a: b
	#define Max(a, b) (a < b)? b: a
	using namespace std;
	
	int a[MAX];
	
	int main(){
	    ios::sync_with_stdio(0);
	    cin.tie(0);
	    int n;
	    while(cin >> n){
	        for(int i = 1; i <= n; i++)
	            cin >> a[i];
	
	        for(int i = 1; i <= n / 2; i++){
	            if(i % 2 == 1)  swap(a[i], a[n - i + 1]);
	        }
	        for(int i = 1; i <= n; i++){
	            if(i != n)
	                cout << a[i] << " ";
	            else cout << a[i] << endl;
	        }
	    }
	    return 0;
	}


