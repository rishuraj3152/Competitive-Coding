#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=100005;
vector<int> prime;

void simplesieve(){
	vector<bool> mark(N,true);
	for(int p=2;p<N;p++){
		if(mark[p]==true){
			for(int i=p;i<N;i+=p){
				mark[i]=false;
			}
		}
	}
	for(int i=2;i<N;i++){
		if(mark[i]==true){
			prime.push_back(i);
	    }
    }
}
void solve(int m,int n){
	int limit=floor(sqrt(n))+1;

	vector<bool> mark(n-m+1,true);
	for(int i=0;i<prime.size();i++){
		if(prime[i]*prime[i]>n)break;
		int nearest=floor(m/prime[i])*prime[i];
		if(prime[i]>=m && prime[i]<=n)nearest=prime[i]*2;
		for(int j=nearest;j<=n;j+=prime[i]){
			if(j>=m)
				mark[j-m]=false;
		}
	}
	for(int i=m;i<=n;i++){
		if(mark[i-m]==true && i!=1)cout<<i<<'\n';
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	simplesieve();
    int t;
    cin>>t;
    int m,n;
    while(t--){
        cin>>m>>n;
        solve(m,n);
        if(t>=1)cout<<'\n';
    }
    return 0;
}