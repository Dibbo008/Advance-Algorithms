#include <bits/stdc++.h>
using namespace std;

int root[100][100];
void printTree(int i, int j){
    if(i>j){
        return;
    }
    int rt=root[i][j];
    cout<<rt<<endl;
    if (i<rt){
        cout<<"Left child of root : "<<rt<<endl;
        printTree(i, rt-1);
    }
    if(rt<j){
          cout<<"Right child of root : "<<rt<< endl;
        printTree(rt+1, j);
    }
}

int main(){
    int n;
    cin>>n;

    int f[n];
    for (int i=0;i<n;i++){
        cin>>f[i];
    }
    int dp[n+2][n+2]={};

    for (int l=1;l<=n;l++){
        for (int i=1;i<=n-l+1;i++){

            int j=i+l-1;
            dp[i][j]=INT_MAX;
            int sum=0;

            for(int k=i;k<=j;k++){
                sum+=f[k-1];
            }
            for (int k=i;k<=j;k++){
                int cost=dp[i][k-1]+dp[k+1][j]+sum;
                if (cost < dp[i][j]){
                    dp[i][j]=cost;
                    root[i][j]=k;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    printTree(1, n);
}
