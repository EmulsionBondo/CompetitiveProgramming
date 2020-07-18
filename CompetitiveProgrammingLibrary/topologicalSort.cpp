vector<int> topologicalSort(vector<vector<int>> & G){
    vector<int> order; //トポロジカル順序
    int N = G.size();
    vector<int> deg(N);
    for(int i=0;i<N;i++) for(auto nv : G[i]) deg[nv]++;
    queue<int> q;
    for(int i=0;i<N;i++){
        if(deg[i] == 0){
            q.emplace(i);
            order.emplace_back(i);
        }
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nv : G[cur]){
            deg[nv]--;
            if(deg[nv] == 0){
                q.emplace(nv);
                order.emplace_back(nv);
            }
        }
    }
    return order;
}