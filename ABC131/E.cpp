#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VRSORT(v) sort(v.rbegin(), v.rend());//vectorの降順ソート
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

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int ma = (n-1)*(n-2)/2;
    if(ma<k) cout<<-1<<endl;
    else{
        vector<P> res;
        for(int i=1;i<n;i++) res.push_back({i,n});
        int rem = ma - k;
        int ci=1,cj=2;
        for(int k=0;k<rem;k++){
            res.push_back({ci,cj});
            ++cj;
            if(cj==n){
                ++ci;
                cj=ci+1;
            }
        }
        cout<<res.size()<<endl;
        for(auto p:res) cout<<p.first<<" "<<p.second<<endl;
    }

}