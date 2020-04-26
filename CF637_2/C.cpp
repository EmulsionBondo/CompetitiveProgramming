#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> &v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];

        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};



void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    REP(i,n){
        cin >> p[i].first;
        p[i].second = i + 1;
    }

    sort(p.begin(), p.end());
    vector<int> cnt(n+1, 1);
    SegmentTree seg(cnt);
    set<int> st;
    REP(i,n) st.insert(i+1);
    st.insert(INF);
    bool ok = true;
    for(auto [x, idx] : p){
        int ma = seg.getmax(1, n+2);
        // cerr << ma << " " << seg.getmax(idx, idx+1) << endl;
        if(ma != seg.getmax(idx, idx+1)){
            ok = false;
            break;
        }

        auto itr = st.find(idx);
        auto next = itr;
        next++;
        // cerr << *itr << " " << *next << endl;
        if(*next == INF) seg.update(*itr, 0);
        else{
            seg.update(*itr, 0);
            int t = seg.getmax(*next, *next + 1);
            seg.update(*next, t + ma);
        }
        st.erase(itr);
    }

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    // solve();
    int Q; cin >> Q; REP(i,Q) solve();
}