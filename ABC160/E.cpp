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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<int> p(A), q(B), r(C);
    REP(i,A) cin >> p[i];
    REP(i,B) cin >> q[i];
    REP(i,C) cin >> r[i];
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    REP(i,X) pq1.push(p[i]);
    REP(i,Y) pq2.push(q[i]);

    REP(i,C){
        int pt = pq1.top();
        int qt = pq2.top();
        if(pt < qt){
            if(pt < r[i]){
                pq1.pop();
                pq1.push(r[i]);
            }
        }
        else{
            if(qt < r[i]){
                pq2.pop();
                pq2.push(r[i]);
            }
        }
    }
    ll ans = 0;
    while(!pq1.empty()){
        ans += pq1.top(); pq1.pop();
    }
    while(!pq2.empty()){
        ans += pq2.top(); pq2.pop();
    }
    cout << ans << endl;
}