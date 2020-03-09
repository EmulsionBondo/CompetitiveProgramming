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
    deque<char> dq;
    string S;
    cin >> S;
    REP(i,S.size()) dq.push_back(S[i]);
    int Q;
    cin >> Q;
    bool flg = true;//先頭
    while(Q--){
        int T;
        cin >> T;
        if(T == 1){
            flg ^= 1;
        }
        else{
            int F;
            char C;
            cin >> F >> C;
            if(F == 1){
                if(flg) dq.push_front(C);
                else dq.push_back(C);
            }
            else{
                if(flg) dq.push_back(C);
                else dq.push_front(C);
            }
        }
    }
    while(!dq.empty()){
        if(flg){
            cout << dq.front();
            dq.pop_front();
        }
        else{
            cout << dq.back();
            dq.pop_back();
        }
    }
    cout << endl;
}