#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Q = (1e9)+7LL;
const int N = 126000;
int n;
ll dp[N+3],przep[N+3];

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n%4 != 0 && n%4 != 3){
		cout<<0;return 0;
	} 
	dp[1]=1LL;
	int mx = n*(n+1);
	mx /= 4;
	for(int i = 2;i<=n;i++){
		for(int sum = i;sum<=mx;sum++){
			przep[sum] = (dp[sum]+dp[sum-i])%Q;
		}
		for(int sum = i;sum<=mx;sum++){
			dp[sum]=przep[sum];
		}
	}
	cout<<dp[mx];
	
	return 0;
}

