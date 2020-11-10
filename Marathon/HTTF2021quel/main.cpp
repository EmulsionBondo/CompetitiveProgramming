#include <bits/stdc++.h>
#include <sys/time.h>
#pragma GCC optimize "O3,omit-frame-pointer,inline"
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

constexpr ll CYCLES_PER_SEC = 2800000000;
constexpr double TL = 1900;

const int MAX_N = 100;
const int MAX_H = 20;
const int MAX_W = 20;

double get_ms() { struct timeval t; gettimeofday(&t, NULL); return (double)t.tv_sec * 1000 + (double)t.tv_usec / 1000; }

const int MAX_LOOP = 1000;
const int BEAM_WIDTH = 1;

uint32_t XorShift(void) {
	static uint32_t x = 123456789;
	static uint32_t y = 362436069;
	static uint32_t z = 521288629;
	static uint32_t w = 88675123;
	uint32_t t;

	t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

double Prob(void){
	double ret = (double)XorShift() / UINT_MAX;
	return ret;
}

struct State{
    State(int n, int h, int w) : H(h), W(w), cards(n){
        is_card = vector<vector<int>>(H, vector<int>(W, -1));
    }

    int H;
    int W;
    vector<vector<int>> is_card;
    vector<pair<int, int>> cards;
    vector<int> deck;
};

namespace httf2021quel{

    vector<int> h(MAX_N), w(MAX_N);
    string ans = "";
    State initialState(MAX_N, MAX_H, MAX_W);
    State bestState(MAX_N, MAX_H, MAX_W);
	void input(){
		REP(i,MAX_N){
            cin >> initialState.cards[i].first >> initialState.cards[i].second;
            initialState.is_card[initialState.cards[i].first][initialState.cards[i].second] = i;
        }
	}

	void output(){
		cout << ans << endl;
        // while(!bestState.deck.empty()){
        //     cerr << bestState.deck.back() << " ";
        //     bestState.deck.pop_back();
        // }
	}

    void greedy(){
        State curState = initialState;
        int curH = 0, curW = 0;
        int dir = 0;
        REP(j,MAX_W/2){
            bool exist = false;
            bool exist2 = false;
            if(dir % 2 == 0){
                int cur_mah = 0;
                for(int k=curH;k<MAX_H/2;k++){
                    if(~curState.is_card[k][j]){
                        exist = true;
                        chmax(cur_mah, k);
                    }
                }

                int next_mah = 0;
                if(curW < MAX_W/2 - 1){
                    for(int k=curH;k<MAX_H/2;k++){
                        if(~curState.is_card[k][j+1]){
                            exist2 = true;
                            chmax(next_mah, k);
                        }
                    }
                }
                if(exist or exist2){

                    for(int i=curH;i<=max(cur_mah, next_mah);i++){
                        if(i == curH){
                            if(~curState.is_card[i][j]){
                                ans += 'I';
                                curState.deck.emplace_back(curState.is_card[i][j]);
                                curState.is_card[i][j] = -1;
                            }
                        }
                        else {
                            ans += 'D';
                            curH++;
                            if(~curState.is_card[i][j]){
                                ans += 'I';
                                curState.deck.emplace_back(curState.is_card[i][j]);
                                curState.is_card[i][j] = -1;
                            }
                        }
                    }
                }
                // cerr << curH << " " << curW << endl;
            }
            else{
                int cur_mih = MAX_H;
                for(int k=curH;k>=0;k--){
                    if(~curState.is_card[k][j]){
                        exist = true;
                        chmin(cur_mih, k);
                    }
                }
                int next_mih = MAX_H;
                if(j < MAX_W/2 - 1){
                    for(int k=curH;k>=0;k--){
                        if(~curState.is_card[k][j+1]){
                            exist2 = true;
                            chmin(next_mih, k);
                        }
                    }
                }
                if(exist or exist2){
                    for(int i=curH;i>=min(cur_mih, next_mih);i--){
                        if(i == curH){
                            if(~curState.is_card[i][j]){
                                ans += 'I';
                                curState.deck.emplace_back(curState.is_card[i][j]);
                                curState.is_card[i][j] = -1;
                            }
                        }
                        else {
                            ans += 'U';
                            curH--;
                            if(~curState.is_card[i][j]){
                                ans += 'I';
                                curState.deck.emplace_back(curState.is_card[i][j]);
                                curState.is_card[i][j] = -1;
                            }
                        }
                    }
                }
            }
            ans += 'R';
            curW++;
            /*if(exist or exist2)*/ dir = 1 - dir;
            // cerr << curH << " " << curW << endl;
        }

        ans += string(10-curW, 'R');
        ans += string(curH, 'U');
        curH = 0, curW = 10;
        dir = 0;

        REP(i,MAX_H){
            bool exist = false;
            bool exist2 = false;
            if(dir % 2 == 0){
                int cur_maw = 0;
                for(int k=curW;k<MAX_W;k++){
                    if(~curState.is_card[i][k]){
                        exist = true;
                        chmax(cur_maw, k);
                    }
                }
                int next_maw = 0;
                if(i < MAX_H - 1){
                    for(int k=curW;k<MAX_W;k++){
                        if(~curState.is_card[i+1][k]){
                            exist2 = true;
                            chmax(next_maw, k);
                        }
                    }
                }
                if(exist or exist2){
                    for(int j=curW;j<=max(cur_maw, next_maw);j++){
                        if(j == curW){
                            if(~curState.is_card[i][j]){
                                ans += 'I';
                                curState.deck.emplace_back(curState.is_card[i][j]);
                                curState.is_card[i][j] = -1;
                            }
                        }
                        else {
                            ans += 'R';
                            curW++;
                            if(~curState.is_card[i][j]){
                                ans += 'I';
                                curState.deck.emplace_back(curState.is_card[i][j]);
                                curState.is_card[i][j] = -1;
                            }
                        }
                    }
                }
            }
            else{
                int cur_miw = MAX_W;
                for(int k=curW;k>=0;k--){
                    if(~curState.is_card[i][k]){
                        exist = true;
                        chmin(cur_miw, k);
                    }
                }

                int next_miw = MAX_W;
                if(i < MAX_H - 1){
                    for(int k=curW;k>=0;k--){
                        if(~curState.is_card[i+1][k]){
                            exist2 = true;
                            chmin(next_miw, k);
                        }
                    }
                }
                if(exist or exist2){
                    for(int j=curW;j>=MAX_W/2;j--){
                        if(j == curW){
                            if(~curState.is_card[i][j]){
                                ans += 'I';
                                curState.deck.emplace_back(curState.is_card[i][j]);
                                curState.is_card[i][j] = -1;
                            }
                        }
                        else{
                            ans += 'L';
                            curW--;
                            if(~curState.is_card[i][j]){
                                ans += 'I';
                                curState.deck.emplace_back(curState.is_card[i][j]);
                                curState.is_card[i][j] = -1;
                            }
                        }
                    }
                }
            }
            if(i < MAX_H-1){
                ans += 'D';
                curH++;
                /*if(exist or exist2)*/ dir = 1 - dir;
            }
        }

        ans += string(curW-9, 'L');
        ans += string(19-curH, 'D');

        // 置く
        for(int i=MAX_H-1;i>=MAX_H/2;i--){
            if(i % 2  == 0){
                REP(j,MAX_W/2){
                    if(j == 0){
                        if(~curState.is_card[i][j]) continue;
                        ans += 'O';
                        if(!curState.deck.empty()){
                            int num = curState.deck.back();
                            curState.deck.pop_back();
                            curState.cards[num].first = i, curState.cards[num].second = j;
                        }
                    }
                    else{
                        ans += "R";
                        if(~curState.is_card[i][j]) continue;
                        ans += 'O';
                        if(!curState.deck.empty()){
                            int num = curState.deck.back();
                            curState.deck.pop_back();
                            curState.cards[num].first = i, curState.cards[num].second = j;
                        }
                    }
                }
            }
            else{
                for(int j=MAX_W/2-1;j>=0;j--){
                    if(j == MAX_W/2-1){
                        if(~curState.is_card[i][j]) continue;
                        ans += 'O';
                        if(!curState.deck.empty()){
                            int num = curState.deck.back();
                            curState.deck.pop_back();
                            curState.cards[num].first = i, curState.cards[num].second = j;
                        }
                    }
                    else{
                        ans += "L";
                        if(~curState.is_card[i][j]) continue;
                        ans += 'O';
                        if(!curState.deck.empty()){
                            int num = curState.deck.back();
                            curState.deck.pop_back();
                            curState.cards[num].first = i, curState.cards[num].second = j;
                        }
                    }
                }
            }
            if(i > MAX_H/2) ans += "U";
        }
        cerr << "ok" << endl;

        // 拾う
        int cur_h = MAX_H/2, cur_w = MAX_W/2-1;
        REP(i,MAX_N){
            int next_h = cur_h - curState.cards[i].first;
            int next_w = cur_w - curState.cards[i].second;
            if(next_h < 0) ans += string(abs(next_h), 'D');
            else ans += string(next_h, 'U');
            if(next_w < 0) ans += string(abs(next_w), 'R');
            else ans += string(next_w, 'L');
            ans += 'I';
            cur_h = curState.cards[i].first;
            cur_w = curState.cards[i].second;
        }
        bestState = curState;
    }

	void main(){
		input();
        // simulate();
        greedy();
		output();
		// test();
	}
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	httf2021quel::main();
}
