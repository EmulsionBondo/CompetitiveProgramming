//二部グラフ判定
bool dfs(int v, int cur=0){
    color[v] = cur;
    for(auto nv:G[v]){
        if(color[nv]!=-1){
            if(color[nv]==cur) return false;
            continue;
        }
        if(!dfs(nv,1-cur)) return false;
    }
    return true;
}
color.assign(N,-1);
bool bipartite =true;
REP(v,N){
    if(color[v]!=-1) continue;
    if(!dfs(v)) bipartite = false;
}