#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

const int MAX = 510000;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    a = a * mod_inv(100) % MOD;
    b = b * mod_inv(100) % MOD;
    ll ret = 0;
    comb_init();
    REP(i,n){
        ll res = comb(n+i-1,i) * mod_pow(a,n,MOD) % MOD * mod_pow(b,i,MOD) % MOD * mod_pow(mod_pow(a+b,n+i,MOD),MOD-2,MOD) % MOD;
        ret += (n+i) * mod_pow(a+b,MOD-2,MOD) % MOD * res % MOD;
        ret %= MOD;
    }
    REP(i,n){
        ll res = comb(n+i-1,i) * mod_pow(b,n,MOD) % MOD * mod_pow(a,i,MOD) % MOD * mod_pow(mod_pow(a+b,n+i,MOD),MOD-2,MOD) % MOD;
        ret += (n+i) * mod_pow(a+b,MOD-2,MOD) % MOD * res % MOD;
        ret %= MOD;
    }
    cout<<ret<<endl;
}
