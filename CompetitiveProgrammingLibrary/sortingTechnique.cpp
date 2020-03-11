//元のインデックスを保持したままの複数比較のソート
//<S,P> で要素Sが同一のとき、要素Pでソート(以下はSは昇順、Pは降順)
vector<int> idx(v.size());
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),
         [&](int x, int y){return S[x] == S[y] ? P[x] > P[y] : S[x] < S[y];}
         );
//-------------------------------------------------------------------------
//上と同じソートを構造体でやる場合
struct guide{
    string city;
    int point;
    
    guide(string s, int p){
        city = s;
        point = p;
    }
    bool operator<(const guide &another) const
    {
        return city==another.city ? point<another.point : city>another.city;
    };
};