// NTTを使わないFPS
template<typename mint> struct SimpleFormalPowerSeries : std::vector<mint> {
	using std::vector<mint>::vector;
	using P = SimpleFormalPowerSeries;

	void shrink() {
		while(this->size() && this->back() == mint(0)) this->pop_back();
	}

	P operator+(const P &r) const { return P(*this) += r; }

	P operator+(const mint &v) const { return P(*this) += v; }

	P operator-(const P &r) const { return P(*this) -= r; }

	P operator-(const mint &v) const { return P(*this) -= v; }

	P operator*(const P &r) const { return P(*this) *= r; }

	P operator*(const mint &v) const { return P(*this) *= v; }

	P operator/(const P &r) const { return P(*this) /= r; }

	P operator%(const P &r) const { return P(*this) %= r; }

	P &operator+=(const P &r) {
		if(r.size() > this->size()) this->resize(r.size());
		for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
		return *this;
	}

	P &operator+=(const mint &r) {
		if(this->empty()) this->resize(1);
		(*this)[0] += r;
		return *this;
	}

	P &operator-=(const P &r) {
		if(r.size() > this->size()) this->resize(r.size());
		for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
		shrink();
		return *this;
	}

	P &operator-=(const mint &r) {
		if(this->empty()) this->resize(1);
		(*this)[0] -= r;
		shrink();
		return *this;
	}

	P &operator*=(const mint &v) {
		const int n = (int)this->size();
		for(int k = 0; k < n; k++) (*this)[k] *= v;
		return *this;
	}

	P &operator*=(const P &r) {
		int n = (int)this->size();
		int m = r.size();
		(*this).resize(n + m - 1);
		for(int i = n + m - 2; i >= 0; i--) {
			(*this)[i] *= r[0];
			for(int j = 1; j < std::min(i + 1, m); j++) (*this)[i] += (*this)[i - j] * r[j];
		}
		return *this;
	}

	P &operator%=(const P &r) { return *this -= *this / r * r; }

	P operator-() const {
		P ret(this->size());
		for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
		return ret;
	}

	P &operator/=(const P &r) {  // naive
		int n = this->size();
		int m = r.size();
		for(int i = 0; i < n; i++) {
			for(int j = 1; j < std::min(i + 1, m); j++) (*this)[i] -= (*this)[i - j] * r[j];
			(*this)[i] /= r[0];
		}
		return *this;
	}

	P dot(P r) const {
		P ret(std::min(this->size(), r.size()));
		for(int i = 0; i < ret.size(); i++) ret[i] = (*this)[i] * r[i];
		return ret;
	}

	P pre(int sz) const { return P(std::begin(*this), std::begin(*this) + std::min((int)this->size(), sz)); }

	P operator>>(int sz) const {
		if(this->size() <= sz) return {};
		P ret(*this);
		ret.erase(ret.begin(), ret.begin() + sz);
		return ret;
	}

	P operator<<(int sz) const {
		P ret(*this);
		ret.insert(ret.begin(), sz, mint(0));
		return ret;
	}

	P rev(int deg = -1) const {
		P ret(*this);
		if(deg != -1) ret.resize(deg, mint(0));
		std::reverse(std::begin(ret), std::end(ret));
		return ret;
	}

	P inv(int deg = -1) const {
		assert(((*this)[0]) != mint(0));
		const int n = (int)this->size();
		if(deg == -1) deg = n;
		P ret;
		ret.resize(deg);
		ret[0] = 1;
		return ret / (*this);
	}
};