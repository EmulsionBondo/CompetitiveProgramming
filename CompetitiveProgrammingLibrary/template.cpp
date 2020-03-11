//ミニマックス法のテンプレ
char Board[H][W]; // ゲームの状態を持つ

// 盤面を評価する関数。自分の得点を求める。
int value() {
    // 中身を書く
}

int MIN_MAX(int turn) {
    // 終局したら盤面の値を返す
    if (turn == END) return value();

    if (/*自分の局面*/) {
        int Max = -INF;
        for () {
            // 今の盤面で自分が打てるすべての状態を列挙
            Max = max(Max, MIN_MAX(turn + 1));
        }
        return Max;
    } else { // 相手の局面
        int Min = INF;
        for () {
            // 今の盤面で相手が打てるすべての状態を列挙
            Min = min(Min, MIN_MAX(turn + 1));
        }
        return Min;
    }
}

int main() {
    // こんな感じで呼び出せば自分の得点の最大値を知ることができる。
    int myPoint = MIN_MAX(0);
}


//指数全探索のテンプレ 計算量O(T^N)
void dfs(vector<int> v){
    if(v.size() == N){
        //ここに処理を書く
        REP(i,N){
            
        }
    }
    else{
        REP(i,T){//T : 状態の数
            auto tmp = v;
            tmp.push_back(i);
            dfs(tmp);
        }
    }
}
dfs(v)//適当な空のvectorを渡す


//三分探索テンプレ的な
double l = 0, r = LINF;
REP(i,200){
    double ml = (r + 2*l) / 3;
    double mr = (2*r + l) / 3;
    if(f(ml) >= f(mr)) l = ml;
    else r = mr;
}


//しゃくとり法の汎用的な形式
int right = 0;
for (int left = 0; left < n; ++left) {
    while (right < n && (right を 1 個進めたときに条件を満たす)) {
        /* 実際に right を 1 進める */
        // ex: sum += a[right];
        ++right;
    }

    /* break した状態で right は条件を満たす最大なので、何かする */
    // ex: res += (right - left);

    /* left をインクリメントする準備 */
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];
}