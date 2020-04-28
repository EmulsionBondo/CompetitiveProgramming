int LCS(string& X,string& Y){
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> c(max(m, n) + 1, vector<int>(max(m, n) + 1));
    int maxl = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    REP(i,m+1) c[i][0] = 0;
    for(int j=1;j<=n;j++) c[0][j] = 0;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(X[i] == Y[j]) c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = max(c[i-1][j],c[i][j-1]);
            maxl = max(maxl,c[i][j]);
        }
    }
    return maxl;
}