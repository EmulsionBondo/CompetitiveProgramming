#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000003//1000000007
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

const int MAX = 1000003;
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

ll mod_inv(ll x) {
    return mod_pow(x,MOD-2,MOD);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin>>Q;
    comb_init();
    ll mod = 1000003;
    REP(i,Q){
        ll x, d, n;
        cin>>x>>d>>n;
        if(d==0){
            cout<<mod_pow(x,n,mod)<<endl;
            continue;
        }
        if(n>mod) cout<<0<<endl;
        else{
            ll res = fac[n] * comb(mod - x * mod_inv(d) % mod,n) % mod * mod_pow(mod-d,n,mod) % mod;
            cout<<res%mod<<endl;
        }
    }
    
}