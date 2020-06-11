// 線分ab の偏角 [-π, π] を返す
double argument(const pair<double, double> &a, const pair<double, double> &b){
    double ax = a.first, ay = a.second, bx = b.first, by = b.second;
    return atan2(by - ay, bx - ax);
}

// 偏角ソート
void argumentSort(vector<pair<long double, long double>> &v){
    pair<long double, long double> o(0, 0);
    sort(v.begin(), v.end(), [&](auto a, auto b){return argument(o, a) < argument(o, b);});
}