#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 1000000000000000000//1e18
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
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T;
    cin >> S >> T;
    vector<vector<int>> idx(26);
    REP(i,S.size()){
        idx[(S[i]-'a')].push_back(i+1);
    }
    ll ans = 0;
    int cur = 0;

    REP(i,T.size()){
        if(idx[T[i]-'a'].size() != 0){
            int next_idx = upper_bound(idx[T[i]-'a'].begin(),idx[T[i]-'a'].end(),cur) - idx[T[i]-'a'].begin();
            int next;
            if(next_idx == idx[T[i]-'a'].size()){
                next = idx[T[i]-'a'][0];
                ans += (int)S.size() - cur;
                cur = next;
                ans += cur;
            }
            else{
                next = idx[T[i]-'a'][next_idx];
                ans += next - cur;
                cur = next;
            }
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
