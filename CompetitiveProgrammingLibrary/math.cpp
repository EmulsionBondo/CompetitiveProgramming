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

//素因数分解 O(√n) くらい？
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

//高速な素因数分解  osa_k法
//verify:https://yukicoder.me/submissions/440227
//前処理 O(n)
template<typename T>
vector<T> smartPrimeFactors(T n) {
    vector<T> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;
    for (T i = 2; i * i <= n; i++) {
        // 素数だったら
        if (spf[i] == i) {
            for (T j = i * i; j <= n; j += i) {
                // iを持つ整数かつまだ素数が決まっていないなら
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    return spf;
}
//各クエリ O(log n)
template<typename T>
map<T, T> factorize(T x, vector<T> &spf) {
    map<T, T> ret;
    while (x > 1) {
        ret[spf[x]]++;
        x /= spf[x];
    }
    //sort(ret.begin(), ret.end());
    return ret;
}


//エラトステネスの篩
//O(n log log n)
//だいたいnの線形時間と考えて問題ない
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

//nCkをO(k)で求める
mint kai(ll x, ll y){
    mint res = 1;
    for(ll i=0;i<min(x,y);i++) res *= (x - i);
    return res;
}
mint nCk(ll n, ll k){
    if(n < k) return 0;
    return kai(n, k) * modpow(kai(k, k), MOD-2);
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

//パスカルの三角形
long double  nCr[1001][1001];
nCr[0][0] = 1;
REP(i, 1000) REP(j, i + 1) {
    nCr[i + 1][j] += nCr[i][j];
    nCr[i + 1][j + 1] += nCr[i][j];
}

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