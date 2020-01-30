#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 3e18+7
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
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>> A(N);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    REP(i,N){
        cin>>A[i].second>>A[i].first;
        //A[i].second.second = (double)A[i].second.first / A[i].first;
        //div[i].first = i;
        //div[i].second = (double)A[i].second/A[i].first;
    }
    VSORT(A);
    //REP(i,N) cout<<A[i].first<<":"<<A[i].second<<endl;//":"<<A[i].second.second<<endl;
    ll ans = 0;
    ll sum = 0;
    int cnt = 0;
    for(int i=N-1;i>=0;i--){
        if(M-cnt < A[i].second){
            continue;
        }
        if(M-cnt-A[i].second+1>=0){
            sum += A[i].first;
            cnt++;
            q.push({A[i].first,A[i].second});
            //q.push({A[i].second.second()})
            //cout<<sum<<endl;
        }
        else{
            auto t =  q.top();
            if(t.first < A[i].first){
                q.pop();
                sum -= t.first;
                cnt--;
                sum += A[i].first;
                cnt++;
                q.push({A[i].first,A[i].second});
            }
        }
        ans = max(ans,sum);
    }
    cout<<ans<<endl;

    /*REP(i,N){
        //cout<<A[div[i].first].first<<":"<<A[div[i].first].second<<endl;
        if(cnt>M+1){
            while(cnt>(M-A[div[i].first].first) || !q.empty()){
                if(q.top().first > div[i].second) continue;
                else if(q.top().first > div[i].second){
                    if(A[q.top().second].first < A[div[i].first].first) continue;
                }
                auto t = q.top();q.pop();
                sum -= A[t.second].second;
                cnt -= A[t.second].first;
            }
            cout<<cnt<<endl;
        }
        else{
            q.push({(double)div[i].second,div[i].first});
            sum += A[div[i].first].second;
            cnt += A[div[i].first].first;
        }
        ans = max(ans,sum);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;*/
}