// verify : https://codeforces.com/contest/1406/submission/92651628
struct Centroid{
    int N;  // 木のサイズ
    vector<vector<int>> G;
    vector<int> sz; // 頂点vを根とする部分木のサイズ
    vector<int> centroids;  // 重心を列挙したもの

    Centroid(const int& N) : N(N), sz(N, 0), G(N){}

    void add_edge(int u, int v){
        G[u].emplace_back(v);
    }

    void SubFindCentroids(int v, int par = -1){
        sz[v] = 1;
        bool isCentroid = true;
        for(auto nv : G[v]){
            if(nv == par) continue;
            SubFindCentroids(nv, v);
            if(sz[nv] > N / 2) isCentroid = false;
            sz[v] += sz[nv];
        }
        if(N - sz[v] > N / 2) isCentroid = false;
        if(isCentroid) centroids.emplace_back(v);
    }

    void build(int root){
        centroids.clear();
        SubFindCentroids(root, N);
    }
};