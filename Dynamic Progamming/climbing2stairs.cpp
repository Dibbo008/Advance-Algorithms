
#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& v){
    if(n==0){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    if(n>=1){
        v.push_back(1);
        solve(n-1,v);
        v.pop_back();
    }
    if(n>=2){
        v.push_back(2);
        solve(n-2,v);
        v.pop_back();
    }
}

int main(){
    int n;
    cin>>n;

    vector<int>dp(n+1,0);
    dp[0]=1;

    if(n>=1){
        dp[1]=1;
    }

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<"Total Ways: "<<dp[n]<<endl;

    vector<int>v;
    solve(n,v);

    return 0;
}
