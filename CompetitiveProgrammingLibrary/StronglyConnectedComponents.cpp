class StronglyConnectedComponents{
    int nodeNum;
    int size;
public:
    vector<vector<int>> edge,revEdge;
    vector<vector<int>> graph;
    vector<int> label,visited,order;
    // 帰りがけ順に番号を振っていく
    void dfs(int cur){
        visited[cur] = 1;
        for(int next:edge[cur]) if(!visited[next]) dfs(next);
        order.push_back(cur);
    }
    // 通ることが出来た頂点に番号を振っていく
    void revDfs(int cur,int labelId){
        visited[cur] = 1;
        label[cur] = labelId;
        for(int next:revEdge[cur]) if(!visited[next]) revDfs(next,labelId);
    }

	StronglyConnectedComponents(const int& nodeNum) :
    nodeNum(nodeNum), edge(nodeNum), revEdge(nodeNum), label(nodeNum), visited(nodeNum) {}

    void make_edge(const int from,const int to) {
        edge[from].push_back(to);
        revEdge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        for(int i = 0; i < nodeNum; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int labelId = 0;
        for(int i:order) if(!visited[i]) revDfs(i,labelId++);
        size = labelId;
        make_graph();
    }

    // 強連結成分で縮約したグラフを作る
    void make_graph(){
        graph.resize(size);
        for(int i = 0; i < edge.size(); i++){
            for(auto to : edge[i]){
                if(getLabel(i) == getLabel(to)) continue;
                graph[getLabel(i)].push_back(getLabel(to));
            }
        }
    }

    vector<vector<int>> topological_sort(void){
        vector<vector<int>> ret(size);
        for(int i = 0; i < nodeNum; i++) ret[label[i]].emplace_back(i);
        return ret;
    }

    void print(void) {
        for(auto labelId:label) cout << labelId << " ";
        cout << endl;
    }
    // vが属している強連結成分のラベル（トポロジカル順序）
    int getLabel(int v){
        return label[v];
    }

    int getSize(){
        return size;
    }
};