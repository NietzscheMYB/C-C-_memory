#include<stdio.h> 
#pragma warning(disable:4996)
#define Max(a,b) (a>b?a:b) 
#define Min(a,b) (a<b?a:b)
int dp[1005][50]; 
int main(int argc, char* argv[]) { int n,m; scanf("%d%d",&n,&m); for (int i=1;i<=n;i++) { dp[i][1]=i; } for (int cnt=2;cnt<=m;cnt++) { for (int ind=1;ind<=n;ind++) { dp[ind][cnt]=1+dp[ind-1][cnt]; for (int k=2;k<=ind;k++) dp[ind][cnt]=Min(dp[ind][cnt],1+Max(dp[k-1][cnt-1],dp[ind-k][cnt])); } } printf("%d\n",dp[n][m]); return 0; }
