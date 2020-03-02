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
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    string S;
    vector<set<int>> idx(26);
    REP(i, 26) idx[i].insert(INF);
    cin >> N >> S >> Q;
    REP(i,N) idx[S[i]-'a'].insert(i);
    while(Q--){
        int q, l, r;
        char c;
        cin >> q;
        if(q == 1){
            cin >> l >> c;
            l--;
            idx[S[l]-'a'].erase(l);
            S[l] = c;
            idx[c-'a'].insert(l);
        }
        else{
            cin >> l >> r;
            l--, r--;
            int cnt = 0;
            REP(i,26){
                auto itr = idx[i].lower_bound(l);
                if(*itr <= r) cnt++;
            }
            cout << cnt << endl;
        }
    }
}
