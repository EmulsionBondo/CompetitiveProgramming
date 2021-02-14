// 区間（半開区間）を管理するSet
// verify:https://atcoder.jp/contests/arc112/submissions/20176113
template<class T>
struct RangeSet {
private:
	const T TINF = numeric_limits<T>::max() / 2;
	set<pair<T, T>> st;

public:
	RangeSet() {
		st.emplace(-TINF, -TINF + 1);
		st.emplace(TINF, TINF + 1);
	}

	//[l, r) が含まれるかどうか
	bool covered(T l, T r) {
		assert(l < r);
		auto itr = prev(st.lower_bound({l + 1, -TINF}));
		return itr->first <= l and r <= itr->second;
	}

	//[l, l + 1) が含まれるかどうか
	bool covered(T l) { return covered(l, l + 1); }

    // [l, r）が覆う区間を返す
    // 存在しない場合[-TIN, -TINF）を返す
	pair<T, T> covered_by(T l, T r) {
		assert(l < r);
		auto itr = prev(st.lower_bound({l + 1, -TINF}));
		if(itr->first <= l and r <= itr->second) return *itr;
		return make_pair(-TINF, -TINF);
	}

	// [x, x+1）が覆う区間を返す
    // 存在しない場合[-TIN, -TINF）を返す
	pair<T, T> covered_by(T x) { return covered_by(x, x); }

    // [l, r)を追加する
    // 追加したときの増分を返す
	T insert(T l, T r) {
		if(l >= r) return 0;
		auto itr = prev(st.lower_bound({l + 1, -TINF}));
		if(itr->first <= l and r <= itr->second) return T(0);
		T sum_erased = T(0);
		if(itr->first <= l and l <= itr->second) {
			l = itr->first;
			sum_erased += itr->second - itr->first;
			itr = st.erase(itr);
		} else
			itr = next(itr);
		while(r > itr->second) {
			sum_erased += itr->second - itr->first;
			itr = st.erase(itr);
		}
		if(itr->first <= r) {
			sum_erased += itr->second - itr->first;
			r = itr->second;
			st.erase(itr);
		}
		st.emplace(l, r);
		return r - l - sum_erased;
	}

    // [x, x+1)を追加する
    // 追加したときの増分を返す
	T insert(T x) { return insert(x, x + 1); }

	// [l, r)を消す
    // 消したときの差分を返す
	T erase(T l, T r) {
		assert(l < r);
		auto itr = prev(st.lower_bound({l + 1, -TINF}));
		if(itr->first <= l and r <= itr->second) {
			if(itr->first < l) st.emplace(itr->first, l);
			if(r < itr->second) st.emplace(r, itr->second);
			st.erase(itr);
			return r - l;
		}

		T ret = T(0);
		if(itr->first <= l and l < itr->second) {
			ret += itr->second - l;
			if(itr->first < l) st.emplace(itr->first, l);
			itr = st.erase(itr);
		} else
			itr = next(itr);
		while(itr->second <= r) {
			ret += itr->second - itr->first;
			itr = st.erase(itr);
		}
		if(itr->first < r) {
			ret += r - itr->first;
			st.emplace(r, itr->second);
			st.erase(itr);
		}
		return ret;
	}

	// [x, x+1)を消す
    // 消したときの差分を返す
	T erase(T x) { return erase(x, x + 1); }

	int size() { return (int)st.size() - 2; }

	int mex(T x = 0) {
		auto itr = prev(st.lower_bound({x + 1, -TINF}));
		if(itr->first <= x and x < itr->second)
			return itr->second;
		else
			return x;
	}

	set<pair<T, T>> get() {
		set<pair<T, T>> res;
		for(auto &p : st) {
			if(abs(p.first) == TINF) continue;
			res.emplace(p.first, p.second + 1);
		}
		return res;
	}

    // 区間が覆っている要素数の総和を返す
	T sum_all() const {
		T res = 0;
		for(auto &p : st) {
			if(abs(p.first) == TINF) continue;
			res += p.second - p.first;
		}
		return res;
	}
};