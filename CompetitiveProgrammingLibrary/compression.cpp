//座圧 s:始点 e:終点 D:元の長さ
int compress(vector<int> &s, vector<int> &e, int D){
    vector<int> arr;
    int N = s.size();
    REP(i,N){
        for(int j=-1;j<=1;j++){
            int x1 = s[i] + j;
            int x2 = e[i] + j;
            if(x1 >= 0 && x1 < D) arr.push_back(x1);
            if(x2 >= 0 && x2 < D) arr.push_back(x2);
        }
    }
    arr.push_back(0);
    arr.push_back(D-1);
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    REP(i,N){
        s[i] = lower_bound(arr.begin(),arr.end(),s[i]) - arr.begin();
        e[i] = lower_bound(arr.begin(),arr.end(),e[i]) - arr.begin();
    }
    return arr.size();
}