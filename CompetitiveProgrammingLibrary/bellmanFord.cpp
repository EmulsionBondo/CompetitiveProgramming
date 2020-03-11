//ベルマンフォード O(|N|+|M|)
vector<ll> dist(NMAX);
REP(i,N) dist[i]=INF;
dist[0]=0;

for(int loop=0;loop<N;++loop){
    for(int i=0;i<M;++i){
        if(dist[a[i]-1]==INF) continue;

        if(dist[b[i]-1] > dist[a[i]-1]+c[i]) dist[b[i]-1] = dist[a[i]-1] + c[i];
    }
}

//負の閉路検出
vector<bool> negative(NMAX,0);

for(int loop=0;loop<N;++loop){
    for(int i=0;i<M;++i){
        if(dist[a[i]-1]==INF) continue;

        if(dist[b[i]-1] > dist[a[i]-1] + c[i]){
            dist[b[i]-1] = dist[a[i]-1] + c[i];
            negative[b[i]-1] = true;
        }

        if(negative[a[i]-1]==true) negative[b[i]-1]=true;
    }
}