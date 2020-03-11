//有向グラフでの閉路検出 O(V + E)
//status ~ 0:New, 1:Active(行きがけ), 2:Finished(帰りがけ)
//閉路がなければ isAcyclic は true，閉路があれば false を返す
const int NMAX = 5050;
const int MMAX = 5050;
vector<int> G[NMAX];
vector<int> status(NMAX);

bool isAcyclicDFS(int v){
    status[v] = 1;
    for(auto nv : G[v]){
        if(status[nv] == 1) return false;
        else if(status[nv] == 0) if(isAcyclicDFS(nv) == false) return false;
    }
    status[v] = 2;
    return true;
}

bool isAcyclic(){
    for(int i=0;i<NMAX;i++) status[i] = 0;
    for(int i=0;i<NMAX;i++){
        if(status[i] == 0){
            if(isAcyclicDFS(i) == false) return false;
        }
    }
    return true;
}