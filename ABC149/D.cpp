int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    ll ans = 0;
    char pre = '!';
    REP(j,K){
        char pre = '!';
        for(int i=j;i<N;i+=K){
            if(pre == '!'){
                if(T[i] == 'r'){
                    ans += P;
                    pre = 'r';
                }
                else if(T[i] == 's'){
                    ans += R;
                    pre = 's';
                }
                else if(T[i] == 'p'){
                    ans += S;
                    pre = 'p';
                }
            }
            else{
                if(pre == T[i]){
                    pre = '!';
                    continue;
                }
                if(T[i] == 'r'){
                    ans += P;
                    pre = 'r';
                }
                else if(T[i] == 's'){
                    ans += R;
                    pre = 's';
                }
                else if(T[i] == 'p'){
                    ans += S;
                    pre = 'p';
                }
            }
        }
    }
    cout << ans << endl;
}