//レーベンシュタイン距離(編集距離)
int editDistance(string x,string y){
    int n = (int)x.size();
    int m = (int)y.size();
    vector<vector<int> > dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;++i) dp[i][0] = i;
    for(int i=0;i<=m;++i) dp[0][i] = i;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            dp[i][j] = min(dp[i-1][j]+1,
                     min(dp[i][j-1]+1,dp[i-1][j-1]+(x[i-1]!=y[j-1])));
        }
    }
    return dp[n][m];
}