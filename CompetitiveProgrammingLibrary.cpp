//辺の構造体
//costの低い順にソートしてくれる
//costの高い順は-wにすればok
struct edge{
    ll from, to, cost;
    edge(ll s, ll d, ll w) : from(s), to(d), cost(w){}
    
    bool operator < (const edge& x) const {
        return cost < x.cost;
    }
};

//最大公約数を求める(ユークリッド互除法)
//O(log max(x,y))
ll gcd(ll x, ll y){
  return y ? gcd(y, x%y) : x;
}

ll lcm( ll m, ll n ){
	if ( ( 0 == m ) || ( 0 == n ) ) return 0;
    return ((m / gcd(m, n)) * n);// lcm = m * n / gcd(m,n)
}

//拡張ユークリッド互助法
//ax+by=1の解を求める
//ax+by=gcd(a,b)の整数解(x,y)は常に存在する
int extgcd(int a, int b, int& x, int& y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x)
        y -= (a/b) * x;
    }
    else{
        x = 1; y = 0;
    }
    return d;//戻り値はgcd(a,b)
}

//入力はすべて正
//素数判定O(√n)
bool is_prime(int n){
    for(int i = 2;i * i <=n;i++){
        if(n % i == 0) return false;
    }
    return n != 1; //1の場合は例外
}

//約数の列挙 O(√n)
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=1; i*i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

//素因数分解
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));//p^num
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}
//----------------------------------------------------------------
//エラトステネスの篩
//n以下の素数を列挙
int prime[MAX_N];//i番目の素数
bool is_prime[MAX_N + 1];//is_prime[i]がtrueならiは素数

//n以下の素数の数を返す
int sieve(int n){
    int p=0;
    for(int i=0; i<=n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j= 2*i; j<= n; j+=i) is_prime[j] = false;
        }
    }
    return p;
}
//O(n log log n)
//だいたいnの線形時間と考えて問題ない
//----------------------------------------------------------------


//----------------------------------------------------------------
//二項係数を求める
//nCk mod.p(pは素数)の求め方(1<=k<=n<=10^7程度)
const int MOD = 1000000007;
const int MAX = 1110000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//----------------------------------------------------------------

//文字列sに patがあるかどうか，あればtrue
bool isfind(string s, string pat){
    if(s.find(pat) != string::npos) return true;
    else return false;
}

//繰り返し二乗法 O(logN)
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;//最下位ビットが立っているときにx^(2^i)をかける
        x = x * x % mod; //xを順次二乗していく
        n >>= 1;
    }
    return res;
}

//逆元を求める(フェルマーの小定理)X^(p-1)≡1 <=> X^(-1) ≡ X^(p-2) p:素数
ll mod_inv(ll x) {
    return mod_pow(x,MOD-2,MOD);
}

//-------------------------------------------------------------------------
typedef vector<unsigned int>vec;
typedef vector<vec> mat;

//行列の積(XOR,ANDバージョン)
mat mul(mat& A,mat& B){
  mat C(A.size(),vec(B[0].size()));
  for(int i=0;i<A.size();i++){
    for(int j=0;j<B[0].size();j++){
      for(int k=0;k<A[0].size();k++){
        C[i][j] ^= A[i][k] & B[k][j];//ANDしたものをXORする(かけたものを足していく)
      }
    }
  }
  return C;
}

//行列の繰り返し二乗法
mat pow(mat A, int n){
  mat B(A.size(),vec(A.size()));
  for(int i=0;i<A.size();i++){
    B[i][i]=1;
  }
  while(n>0){
    if(n&1) B=mul(B,A);
    A = mul(A,A);
    n >>= 1;
  }
  return B;
}
//-------------------------------------------------------------------------

// string s全体を小/大文字化
transform(s.begin(),s.end(),s.begin(),::tolower);
//string 1文字を小/大文字化
s[0] = toupper(s[0]);

//-------------------------------------------------------------------------
//パスカルの三角形
long double  nCr[1001][1001];
nCr[0][0] = 1;
REP(i, 1000) REP(j, i + 1) {
    nCr[i + 1][j] += nCr[i][j];
    nCr[i + 1][j + 1] += nCr[i][j];
}

//-------------------------------------------------------------------------
//しゃくとり法
vector<int> fnum(M, 0); // 区間に種類 i が何個あるか
vector<int> L(N+1, 0); // 各 i に対するしゃくとり法の区間
int left = 0;
for (int right = 0; right < N; ++right) {
    fnum[f[right]]++;
    while (left < right && fnum[f[right]] > 1) {
        --fnum[f[left]];
        ++left;
    }
    L[right+1] = left;
}

//-------------------------------------------------------------------------
//しゃくとり法の汎用的な形式
int right = 0;
for (int left = 0; left < n; ++left) {
    while (right < n && (right を 1 個進めたときに条件を満たす)) {
        /* 実際に right を 1 進める */
        // ex: sum += a[right];
        ++right;
    }

    /* break した状態で right は条件を満たす最大なので、何かする */
    // ex: res += (right - left);

    /* left をインクリメントする準備 */
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];
}

//-------------------------------------------------------------------------
//グラフのノードの構造体
struct Node{
  ll id, dist;
  Node(ll a, ll b){
    id = a;
    dist = b;
  }
  bool operator <(const Node& another) const
  {
    return dist < another.dist;
  }
};
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//ミニマックス法のテンプレ
char Board[H][W]; // ゲームの状態を持つ

// 盤面を評価する関数。自分の得点を求める。
int value() {
    // 中身を書く
}

int MIN_MAX(int turn) {
    // 終局したら盤面の値を返す
    if (turn == END) return value();

    if (/*自分の局面*/) {
        int Max = -INF;
        for () {
            // 今の盤面で自分が打てるすべての状態を列挙
            Max = max(Max, MIN_MAX(turn + 1));
        }
        return Max;
    } else { // 相手の局面
        int Min = INF;
        for () {
            // 今の盤面で相手が打てるすべての状態を列挙
            Min = min(Min, MIN_MAX(turn + 1));
        }
        return Min;
    }
}

int main() {
    // こんな感じで呼び出せば自分の得点の最大値を知ることができる。
    int myPoint = MIN_MAX(0);
}
//-------------------------------------------------------------------------

// vector v において、x の前方と後方の index を求める
template<class T> int former(const vector<T> &v, T x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}
template<class T> int latter(const vector<T> &v, T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

//-------------------------------------------------------------------------
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
//-------------------------------------------------------------------------
//UnionFind
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
//-------------------------------------------------------------------------

//サイズ付きUnionFind
class UnionFind{
public:
    //親の番号，親の場合-(その集合のサイズ)
    vector<int> Parent;
    
    UnionFind(int N){
        Parent = vector<int>(N,-1);
    }
    
    //Aがどのグループに属しているか調べる
    int root(int A){
        if(Parent[A]<0) return A;
        return Parent[A] = root(Parent[A]);
    }

    //自分のいるグループの頂点数を調べる
    int size(int A){
        return -Parent[root(A)];
    }

    bool connect(int A, int B){
        //root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if(A==B) return false;//すでにくっついてる

        //大きい方に小さい方をくっつける
        if(size(A) < size(B)) swap(A, B);

        Parent[A] += Parent[B];
        Parent[B] = A;

        return true;
    }
};
//-------------------------------------------------------------------------
//ダイクストラ O(|M|)
struct edge{ll to, cost;};
vector<vector<edge>> G;

vector<ll> dijkstra(ll s,ll n,vector<vector<edge>> G){
    vector<ll> d={};
    d.resize(n);
    REP(i,n) d[i]=LINF;
    // 最短距離firstが小さい順に取り出せるようにする
    priority_queue<LP, vector<LP>, greater<LP>> que;
    d[s] = 0;// スタート地点を0で初期化
    que.push(LP(0,s));// キューに初期位置のコスト、初期位置をpush

    while(que.size()){
        LP p = que.top();que.pop(); // p: 今の{最短距離、頂点番号}
        ll v = p.second;//今の頂点番号
        if(d[v] < p.first) continue;// 今見ている頂点の歴代最小距離 < 今見ている頂点の最短距離
        for(int i=0; i < G[v].size();i++){// 今の頂点に隣接する頂点を調べる
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){// 遷移先の頂点の歴代最小距離 > 今の距離 + 遷移コスト
                d[e.to] = d[v] + e.cost;// 歴代最小距離の更新
                que.push(P(d[e.to],e.to));// 更新した遷移先の頂点をキューに突っ込む
            }
        }
    }
    return d;
}
//-------------------------------------------------------------------------
//ダイクストラのテンプレート（くるさんのやつ）
//https://atcoder.jp/contests/gigacode-2019/submissions/8651446
template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost;
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf),cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for(int i = 0; i < N; ++i) cost[i] = inf;

		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			T v = pq.top().first;
			int from = pq.top().second;
			pq.pop();
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};

//-------------------------------------------------------------------------
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
//-------------------------------------------------------------------------
//二部最大マッチング
struct BipartiteMatching {
    vector<vector<int>> E; int n, m; vector<int> match, dist;
    void init(int _n,int _m){n=_n,m=_m;E.resize(n+m+2);match.resize(n+m+2);dist.resize(n+m+2);}
    bool bfs() {
        queue<int> que;
        for(int i=1;i<n+1;i++) {
            if (!match[i]) dist[i] = 0, que.push(i);
            else dist[i] = INF;
        }
        dist[0] = INF;
        while (!que.empty()) {
            int u = que.front(); que.pop();
            if (u) for(auto v:E[u]) if (dist[match[v]] == INF) {
                dist[match[v]] = dist[u] + 1;
                que.push(match[v]);
            }
        }
        return (dist[0] != INF);
    }
    bool dfs(int u) {
        if (u) {
            for(auto v:E[u]) if (dist[match[v]] == dist[u] + 1) if (dfs(match[v])) {
                match[v] = u; match[u] = v;
                return true;
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
    void add(int a, int b) { b += n; E[a + 1].push_back(b + 1); E[b + 1].push_back(a + 1); }
    int whois(int x) { return match[x + 1] - 1; }
    int solve() {
        for(int i=0;i<n+m+1;i++) match[i] = 0;
        int res = 0;
        while (bfs()) for(int i=1;i<n+1;i++) if (!match[i] && dfs(i)) res++;
        return res;
    }
};
//使い方
BipartiteMatching bm;
bm.init(N, N);
rep(i, 0, N) rep(j, 0, N) {
    if (A[i] < C[j] and B[i] < D[j]) bm.add(i, j);//条件を満たすとき追加する(iとjを結ぶ辺をグラフに追加)
}
cout << bm.solve() << endl;
//-------------------------------------------------------------------------
//BIT(Binary Indexed Tree)
//O(logN)でa_iにxを加算，Σ(i,k=0)a_kを求める事ができる
//BITで転倒数を求める O(NlogN)
template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;
    
    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }
    
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }
    
    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};
//-------------------------------------------------------------------------
// セグメントツリー
// 区間[l,r)の和をO(log N)で求めることができる
template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;
    
    SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) { init(n); }
    void init(int n) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY);
    }
    
    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k*2], dat[k*2+1]);
    }
    
    /* update a, a is 0-indexed */
    void update(int a, const Monoid &v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k*2], dat[k*2+1]);
    }
    
    /* get [a, b), a and b are 0-indexed */
    Monoid get(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

    /* debug */
    void print() {
        for (int i = 0; i < SIZE_R; ++i) {
            cout << (*this)[i];
            if (i != SIZE_R-1) cout << ",";
        }
        cout << endl;
    }
};

//使うとき
// セグツリーの構築
SegTree<long long> seg(N, [](long long a, long long b) {
        return gcd(a, b);
    },
    0);
vector<long long> A(N);
for (int i = 0; i < N; ++i) {
    cin >> A[i];
    seg.set(i, A[i]);
}
seg.build();
//-------------------------------------------------------------------------
// Lazy Segment Tree(抽象化)
template<class Monoid, class Action> struct LazySegTree {
    using FuncMonoid = function< Monoid(Monoid, Monoid) >;
    using FuncAction = function< void(Monoid&, Action) >;
    using FuncLazy = function< void(Action&, Action) >;
    FuncMonoid FM;
    FuncAction FA;
    FuncLazy FL;
    Monoid UNITY_MONOID;
    Action UNITY_LAZY;
    int SIZE, HEIGHT;
    vector<Monoid> dat;
    vector<Action> lazy;
    
    LazySegTree() { }
    LazySegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy)
    : FM(fm), FA(fa), FL(fl), UNITY_MONOID(unity_monoid), UNITY_LAZY(unity_lazy) {
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }
    void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
              const Monoid &unity_monoid, const Action &unity_lazy) {
        FM = fm; FA = fa; FL = fl;
        UNITY_MONOID = unity_monoid; UNITY_LAZY = unity_lazy;
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }
    
    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE] = v; }
    void build() {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = FM(dat[k*2], dat[k*2+1]);
    }
    
    /* update [a, b) */
    inline void evaluate(int k) {
        if (lazy[k] == UNITY_LAZY) return;
        if (k < SIZE) FL(lazy[k*2], lazy[k]), FL(lazy[k*2+1], lazy[k]);
        FA(dat[k], lazy[k]);
        lazy[k] = UNITY_LAZY;
    }
    inline void update(int a, int b, const Action &v, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)  FL(lazy[k], v), evaluate(k);
        else if (a < r && l < b) {
            update(a, b, v, k*2, l, (l+r)>>1), update(a, b, v, k*2+1, (l+r)>>1, r);
            dat[k] = FM(dat[k*2], dat[k*2+1]);
        }
    }
    inline void update(int a, int b, const Action &v) { update(a, b, v, 1, 0, SIZE); }
    
    /* get [a, b) */
    inline Monoid get(int a, int b, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return FM(get(a, b, k*2, l, (l+r)>>1), get(a, b, k*2+1, (l+r)>>1, r));
        else
            return UNITY_MONOID;
    }
    inline Monoid get(int a, int b) { return get(a, b, 1, 0, SIZE); }
    inline Monoid operator [] (int a) { return get(a, a+1); }
    
    /* debug */
    void print() {
        for (int i = 0; i < SIZE; ++i) { cout << (*this)[i]; if (i != SIZE) cout << ","; }
        cout << endl;
    }
};

//モノイド同士の演算 fm
//モノイドへの作用 fa
//作用の合成 fl
auto fm = [](long long a, long long b) { return max(a, b); };
auto fa = [](long long &a, long long d) { a = max(a, d); };
auto fl = [](long long &d, long long e) { d = max(d, e); };
LazySegTree<long long, long long> seg(N+1, fm, fa, fl, 0, 0);
//-------------------------------------------------------------------------
//遅延評価セグ木（区間加算・区間和）
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};
//-------------------------------------------------------------------------
//LIS and LDS
//A+B<=N+1 , AB>=N are necessarily and sufficient
//0~N-1の順列で、LISの長さA、LDSの長さBとなる数列を求める
vector<long long> LISLDS(long long N, long long A, long long B) {
    vector<long long> res;
    for (long long i = B-1; i >= 0; --i) res.push_back(i);
    
    if (A == 1) return res;
    
    long long rem = N - B;
    long long p = rem / (A-1);
    long long r = rem % (A-1);
    
    long long b = r;
    long long c = A-1-r;
    
    for (int i = 0; i < b; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p+1; ++j) {
            res.push_back(size + p - j);
        }
    }
    for (int i = 0; i < c; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p; ++j) {
            res.push_back(size + p-1 - j);
        }
    }
    
    return res;
}
//-------------------------------------------------------------------------
//LISの長さを返す
//strict == trueなら狭義，strict == falseなら広義
template< typename T >
size_t LIS(const vector< T > &a, bool strict) {
  vector< T > lis;
  for(auto &p : a) {
    typename vector< T >::iterator it;
    if(strict) it = lower_bound(begin(lis), end(lis), p);
    else it = upper_bound(begin(lis), end(lis), p);
    if(end(lis) == it) lis.emplace_back(p);
    else *it = p;
  }
  return lis.size();
}
//-------------------------------------------------------------------------
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
//-------------------------------------------------------------------------
// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

// 二項係数ライブラリ
template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int MOD = fact_[0].getmod();
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[MOD%i] * (MOD/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};

const int MOD = 1000000007;
using mint = Fp<MOD>;
BiCoef<mint> bc;

//使い方
int main() {
    long long N, M, K; cin >> N >> M >> K;
    bc.init(510000);
    mint sum = 0;
    for (int i = 0; i <= N-1; ++i) {
        for (int j = 0; j <= M-1; ++j) {
            mint tmp = mint(N - i) * mint(M - j) * mint(i + j);
            if (i != 0 && j != 0) tmp *= 2;
            sum += tmp;
        }
    }
    cout << sum * bc.com(N*M-2, K-2) << endl;
}
//-------------------------------------------------------------------------
//実行時にMODを受け取るmodint
vector<int> MODS = {1000000007};
template<int IND = 0> struct Fp{
    long long val;
    int MOD = MODS[IND];
    constexpr Fp(long long v = 0) noexcept : val(v % MODS[IND]) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<IND>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<IND> modpow(const Fp<IND> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
cin >> MODS[0];
using mint = Fp<>;
//-------------------------------------------------------------------------
//スターリング数 O(nk)
template<class T> struct Stirling {
    vector<vector<T> > S;
    constexpr Stirling(int MAX) noexcept : S(MAX, vector<T>(MAX, 0)) {
        S[0][0] = 1;
        for (int n = 1; n < MAX; ++n) {
            for (int k = 1; k <= n; ++k) {
                S[n][k] = S[n-1][k-1] + S[n-1][k] * k;
            }
        }
    }
    constexpr T get(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return S[n][k];
    }
};
Stirling<mint> sl(3100); // S(n, k) を n, k < 3100 の範囲で求める
sl.get(n, k);
//-------------------------------------------------------------------------
//ベル数 O(min(n,k)logn)
mint Bell(int n, int k) {
    if (k > n) k = n;
    vector<mint> jsum(k+2, 0);
    for (int j = 0; j <= k; ++j) {
        mint add = bc.finv(j);
        if (j % 2 == 0) jsum[j+1] = jsum[j] + add;
        else jsum[j+1] = jsum[j] - add;
    }
    mint res = 0;
    for (int i = 0; i <= k; ++i) {
        res += modpow(mint(i), n) * bc.finv(i) * jsum[k-i+1];
    }
    return res;
}
//-------------------------------------------------------------------------
//分割数
template<class T> struct Partition {
    vector<vector<T> > P;
    constexpr Partition(int MAX) noexcept : P(MAX, vector<T>(MAX, 0)) {
        for (int k = 0; k < MAX; ++k) P[0][k] = 1;
        for (int n = 1; n < MAX; ++n) {
            for (int k = 1; k < MAX; ++k) {
                P[n][k] = P[n][k-1] + (n-k >= 0 ? P[n-k][k] : 0);
            }
        }
    }
    constexpr T get(int n, int k) {
        if (n < 0 || k < 0) return 0;
        return P[n][k];
    }
};
//-------------------------------------------------------------------------
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

//-------------------------------------------------------------------------
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

//-------------------------------------------------------------------------
//Rolling-hash 事前準備計算量O(N) 文字列比較O(1)
//ハッシュ値(3つ)
struct HashData {
	int h1, h2, h3;
	bool operator==(const HashData& rhs) const {
		return h1 == rhs.h1 && h2 == rhs.h2 && h3 == rhs.h3;
	}
	bool operator!=(const HashData& rhs) const { return !(*this == rhs); }
};
class RollingHash {
	template<int B, int M>
	class RollingHashPart {
	private:
		size_t len;
		std::vector<int> pow_b, hash;
	public:
		RollingHashPart() {}
		template<typename T>
		RollingHashPart(const T& s) : len(s.size()), pow_b(s.size() + 1), hash(s.size() + 1) {
			pow_b[0] = 1;
			hash[0] = 0;
			for (int i = 0; i < len; i++) {
				pow_b[i + 1] = (ll)pow_b[i] * B % M;
				hash[i + 1] = ((ll)hash[i] * B + s[i]) % M;
			}
		}
		template<typename T>
		void add(const T & s) {
			int sz = pow_b.size();
			pow_b.resize(sz + s.size());
			hash.resize(sz + s.size());
			REP(i, s.size()) {
				pow_b[sz + i] = (ll)pow_b[sz + i - 1] * B % M;
				hash[sz + i] = ((ll)hash[sz + i - 1] * B + s[i]) % M;
			}
		}
		int size() const {
			return hash.size() - 1;
		}
		// [l, r)
		int get(int l, int r) const {
			if (l == r) return 0LL;
			int res = (hash[r] - (ll)hash[l] * pow_b[r - l]) % M;
			if (res < 0) res += M;
			return res;
		}
	};
public:
	RollingHashPart<1033, 1000000007> rh1;
	RollingHashPart<6037, 999999937> rh2;
	RollingHashPart<1009, 1000000009> rh3;

	RollingHash() {}
	template<typename T> RollingHash(const T & s) : rh1(s), rh2(s), rh3(s) {}
	// [l, r)
	HashData get(int l, int r) const {
		return HashData{ rh1.get(l, r), rh2.get(l, r), rh3.get(l, r) };
	}
	template<typename T> void add(const T& s) { rh1.add(s); rh2.add(s); rh3.add(s); }
};
//宣言　sは文字列
RollingHash rh(s);
//-------------------------------------------------------------------------
//ハッシュ2つ
struct RollingHash {
    static const int base1 = 1007, base2 = 2009;
    static const int mod1 = 1000000007, mod2 = 1000000009;
    vector<long long> hash1, hash2, power1, power2;

    // construct
    RollingHash(const string &S) {
        int n = (int)S.size();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        power1.assign(n+1, 1);
        power2.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i+1] = (hash1[i] * base1 + S[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + S[i]) % mod2;
            power1[i+1] = (power1[i] * base1) % mod1;
            power2[i+1] = (power2[i] * base2) % mod2;
        }
    }
    
    // get hash of S[left:right]
    inline pair<long long, long long> get(int l, int r) const {
        long long res1 = hash1[r] - hash1[l] * power1[r-l] % mod1;
        if (res1 < 0) res1 += mod1;
        long long res2 = hash2[r] - hash2[l] * power2[r-l] % mod2;
        if (res2 < 0) res2 += mod2;
        return {res1, res2};
    }

    // get lcp of S[a:] and T[b:]
    inline int getLCP(int a, int b) const {
        int len = min((int)hash1.size()-a, (int)hash1.size()-b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a+mid) != get(b, b+mid)) high = mid;
            else low = mid;
        }
        return low;
    }
};
//-------------------------------------------------------------------------
//Z-Algorithm(最長共通接頭辞)
//各iについてSとS[i,|S|]の最長共通接頭辞の長さを記録した配列を返す
//S:aaabaaaab
//v:921034210
//S$TみたいにするとSの接尾字とTの接頭辞の共通の長さを見れる
vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

//-------------------------------------------------------------------------
//最小共通祖先
//構築(VlogV),　クエリ(logV)
//verify(root) : https://atcoder.jp/contests/past201912-open/submissions/9203097
//verify(dist) : https://atcoder.jp/contests/abc148/submissions/9096709
template< typename G >
struct LCA{
    const int LOG;
    vector< int > depth;
    const G &g;
    vector< vector< int > > table;
    const int root;
    LCA(const G &g, int root = 0) : g(g), depth(g.size()), LOG(32 - __builtin_clz(g.size())), root(root) {
        table.assign(LOG, vector< int >(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        depth[idx] = d;
        for(auto &to : g[idx]) {
            if(to != par) dfs(to, idx, d + 1);
        }
    }

    void build() {
        dfs(root, -1, 0);
        for(int k = 0; k + 1 < LOG; k++) {
            for(int i = 0; i < table[k].size(); i++) {
                if(table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        for(int i = LOG - 1; i >= 0; i--) {
            if(((depth[v] - depth[u]) >> i) & 1) v = table[i][v];
        }
        if(u == v) return u;
        for(int i = LOG - 1; i >= 0; i--) {
            if(table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int dist(int u, int v) {
		int lca_ = lca(u, v);
		return depth[u] + depth[v] - 2 * depth[lca_];
	}
};
//-------------------------------------------------------------------------
//最大流(Dinic法)
//O(|E||V|^2)だけどグラフのサイズがある程度大きくても大丈夫な場合が多い
const int MAX_V = 2000005;
const int INF = 1 << 32;
// 辺を表す構造体 (行き先、　容量、　逆辺) 逆辺はインデックスでもつ
struct edge { int to, cap, rev; };
 
vector<edge> G[MAX_V]; // グラフの隣接リスト
int level[MAX_V]; // sからの距離(bfsで使う)
int iter[MAX_V]; // どこまで調べ終わったか(dfsで使う)
 
// from -> toへの容量capの辺をグラフに追加
void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)(G[from].size()-1)});
}
 
// sからの最短距離をBFSで計算
void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i=0; i<(int)G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}
 
// 増加パスをDFSで探す
int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i=iter[v]; i<(int)G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
// s -> tへの最大流を求める
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f=dfs(s, t, INF)) > 0){
            flow += f;
        }
    }
}
//-------------------------------------------------------------------------
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
//-------------------------------------------------------------------------
//ランレングス圧縮
vector<pair<int, int>> runLengthEncoding(vector<int> s) {
    int n = s.size();

    vector<pair<int, int>> res;
    int pre = s[0];
    int cnt = 1;
    for(int i=1;i<n;i++) {
        if (pre != s[i]) {
            res.push_back({ pre, cnt });
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }

    res.push_back({ pre, cnt });
    return res;
}
//char版
vector<pair<char, int>> runLengthEncoding(string &s) {
    int n = s.size();

    vector<pair<char, int>> res;
    char pre = s[0];
    int cnt = 1;
    for(int i=1;i<n;i++) {
        if (pre != s[i]) {
            res.push_back({ pre, cnt });
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }

    res.push_back({ pre, cnt });
    return res;
}
//-------------------------------------------------------------------------
// Sparse Table
template<class MeetSemiLattice> struct SparseTable {
    vector<vector<MeetSemiLattice> > dat;
    vector<int> height;
    
    SparseTable() { }
    SparseTable(const vector<MeetSemiLattice> &vec) { init(vec); }
    void init(const vector<MeetSemiLattice> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1<<h) < n) ++h;
        dat.assign(h, vector<MeetSemiLattice>(1<<h));
        height.assign(n+1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1;
        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for (int i = 1; i < h; ++i)
            for (int j = 0; j < n; ++j)
                dat[i][j] = min(dat[i-1][j], dat[i-1][min(j+(1<<(i-1)),n-1)]);
    }
    
    MeetSemiLattice get(int a, int b) {
        return min(dat[height[b-a]][a], dat[height[b-a]][b-(1<<height[b-a])]);
    }
};


// Suffix Array ( Manber&Myers: O(n (logn)^2) )
struct SuffixArray {
    string str;
    vector<int> sa;         // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> lcp;        // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
    inline int& operator [] (int i) {return sa[i];}
    
    SuffixArray(const string& str_) : str(str_) { buildSA(); calcLCP(); }
    void init(const string& str_) { str = str_; buildSA(); calcLCP(); }
    
    // build SA
    vector<int> rank_sa, tmp_rank_sa;
    struct CompareSA {
        int n, k;
        const vector<int> &rank;
        CompareSA(int n, int k, const vector<int> &rank_sa) : n(n), k(k), rank(rank_sa) {}
        bool operator()(int i, int j) {
            if (rank[i] != rank[j]) return (rank[i] < rank[j]);
            else {
                int rank_ik = (i + k <= n ? rank[i + k] : -1);
                int rank_jk = (j + k <= n ? rank[j + k] : -1);
                return (rank_ik < rank_jk);
            }
        }
    };
    void buildSA() {
        int n = (int)str.size();
        sa.resize(n+1), lcp.resize(n+1), rank_sa.resize(n+1), tmp_rank_sa.resize(n+1);
        for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
        sa[n] = n, rank_sa[n] = -1;
        for (int k = 1; k <= n; k *= 2) {
            CompareSA csa(n, k, rank_sa);
            sort(sa.begin(), sa.end(), csa);
            tmp_rank_sa[sa[0]] = 0;
            for (int i = 1; i <= n; ++i) {
                tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
                if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
            }
            for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
        }
    }
    vector<int> rsa;
    SparseTable<int> st;
    void calcLCP() {
        int n = (int)str.size();
        rsa.resize(n+1);
        for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
        lcp.resize(n+1);
        lcp[0] = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int pi = sa[rsa[i] - 1];
            if (cur > 0) --cur;
            for (; pi + cur < n && i + cur < n; ++cur) {
                if (str[pi + cur] != str[i + cur]) break;
            }
            lcp[rsa[i] - 1] = cur;
        }
        st.init(lcp);
    }
    
    // calc lcp
    int getLCP(int a, int b) {          // lcp of str.sutstr(a) and str.substr(b)
        return st.get(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
    }
};
//-------------------------------------------------------------------------
//指数全探索のテンプレ 計算量O(T^N)
void dfs(vector<int> v){
    if(v.size() == N){
        //ここに処理を書く
        REP(i,N){
            
        }
    }
    else{
        REP(i,T){//T : 状態の数
            auto tmp = v;
            tmp.push_back(i);
            dfs(tmp);
        }
    }
}
dfs(v)//適当な空のvectorを渡す

//-------------------------------------------------------------------------
//三分探索テンプレ的な
double l = 0, r = P;
REP(i,200){
    double ml = (r + 2*l) / 3;
    double mr = (2*r + l) / 3;
    if(f(ml) >= f(mr)) l = ml;
    else r = mr;
}
//-------------------------------------------------------------------------
//スライド最小値 O(N) N : vec.size()
template<class T> vector<T> SlideMin(vector<T>& vec, const int& width){
    vector<T> res(vec.size());
    deque<T> deq;
    for(int i = 0; i < vec.size(); ++i) {
        while(deq.size() && vec[deq.back()]>=vec[i]) deq.pop_back();
        deq.push_back(i);
        res[i] = vec[deq.front()];
        if(i+1>=width && deq.front()==i+1-width) deq.pop_front();
    }
    return res;
}

//スライド最大値
template<class T> vector<T> SlideMax(vector<T>& vec, const int& width){
    vector<T> res(vec.size());
    deque<T> deq;
    for(int i = 0; i < vec.size(); ++i) {
        while(deq.size() && vec[deq.back()]<=vec[i]) deq.pop_back();
        deq.push_back(i);
        res[i] = vec[deq.front()];
        if(i+1>=width && deq.front()==i+1-width) deq.pop_front();
    }
    return res;
}
//-------------------------------------------------------------------------
