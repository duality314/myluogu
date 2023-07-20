#include<iostream>
#include<cstdio>

using namespace std;

bool f[25][25];
long long dp[25][25];
short dx[8]={2,2,1,1,-1,-1,-2,-2};
short dy[8]={1,-1,2,-2,2,-2,1,-1};
int bx,by,mx,my;
int main(){
	cin>>bx>>by>>mx>>my;
	bx+=2;	by+=2;	mx+=2;	my+=2;
	f[mx][my]=1;
	dp[2][1]=1;
	for(int i=0;i<=7;i++)
		for(int j=0;j<=7;j++)	f[mx+dx[i]][my+dy[i]]=1;
	for(int i=2;i<=bx;i++)
		for(int j=2;j<=by;j++){
			if(f[i][j])	continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	cout<<dp[bx][by];
	
	
	return 0;
}