#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    vector<int>dp(n+1,0);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i],price[j-1]+dp[i-j]);
        }
    }
    cout<<dp[n]<<endl;
    
}