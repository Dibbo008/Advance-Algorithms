#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int f[n];
    for(int i=0;i<n;i++){
        cin>>f[i];
    }

    int dp[n+2][n+2]={};

    for(int l=1;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){

            int j=i+l-1;
            dp[i][j]=INT_MAX;
            int sum=0;

            for(int k=i;k<=j;k++){
                sum+=f[k-1];
            }
            for(int k=i;k<=j;k++){
                int cost=dp[i][k-1]+dp[k+1][j]+sum;
                dp[i][j]=min(dp[i][j],cost);
            }
        }
    }
    cout<<dp[1][n]<<endl;
}