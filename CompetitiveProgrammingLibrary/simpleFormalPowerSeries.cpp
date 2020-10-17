// NTTを使わないFPS
template<typename mint> struct SimpleFormalPowerSeries : std::vector<mint> {
	using std::vector<mint>::vector;
	using FPS = SimpleFormalPowerSeries;

	void shrink() {
		while(this->size() && this->back() == mint(0)) this->pop_back();
	}

	FPS operator+(const FPS &r) const { return FPS(*this) += r; }

	FPS operator+(const mint &v) const { return FPS(*this) += v; }

	FPS operator-(const FPS &r) const { return FPS(*this) -= r; }

	FPS operator-(const mint &v) const { return FPS(*this) -= v; }

	FPS operator*(const FPS &r) const { return FPS(*this) *= r; }

	FPS operator*(const mint &v) const { return FPS(*this) *= v; }

	FPS operator/(const FPS &r) const { return FPS(*this) /= r; }

	FPS operator%(const FPS &r) const { return FPS(*this) %= r; }

	FPS &operator+=(const FPS &r) {
		if(r.size() > this->size()) this->resize(r.size());
		for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
		return *this;
	}

	FPS &operator+=(const mint &r) {
		if(this->empty()) this->resize(1);
		(*this)[0] += r;
		return *this;
	}

	FPS &operator-=(const FPS &r) {
		if(r.size() > this->size()) this->resize(r.size());
		for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
		shrink();
		return *this;
	}

	FPS &operator-=(const mint &r) {
		if(this->empty()) this->resize(1);
		(*this)[0] -= r;
		shrink();
		return *this;
	}

	FPS &operator*=(const mint &v) {
		const int n = (int)this->size();
		for(int k = 0; k < n; k++) (*this)[k] *= v;
		return *this;
	}

	FPS &operator*=(const FPS &r) {
		int n = (int)this->size();
		int m = r.size();
		(*this).resize(n + m - 1);
		for(int i = n + m - 2; i >= 0; i--) {
			(*this)[i] *= r[0];
			for(int j = 1; j < std::min(i + 1, m); j++) (*this)[i] += (*this)[i - j] * r[j];
		}
		return *this;
	}

	FPS &operator%=(const FPS &r) { return *this -= *this / r * r; }

	FPS operator-() const {
		FPS ret(this->size());
		for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
		return ret;
	}

	FPS &operator/=(const FPS &r) {  // naive
		int n = this->size();
		int m = r.size();
		for(int i = 0; i < n; i++) {
			for(int j = 1; j < std::min(i + 1, m); j++) (*this)[i] -= (*this)[i - j] * r[j];
			(*this)[i] /= r[0];
		}
		return *this;
	}

	FPS dot(FPS r) const {
		FPS ret(std::min(this->size(), r.size()));
		for(int i = 0; i < ret.size(); i++) ret[i] = (*this)[i] * r[i];
		return ret;
	}

	FPS pre(int sz) const { return FPS(std::begin(*this), std::begin(*this) + std::min((int)this->size(), sz)); }

	FPS operator>>(int sz) const {
		if(this->size() <= sz) return {};
		FPS ret(*this);
		ret.erase(ret.begin(), ret.begin() + sz);
		return ret;
	}

	FPS operator<<(int sz) const {
		FPS ret(*this);
		ret.insert(ret.begin(), sz, mint(0));
		return ret;
	}

	FPS rev(int deg = -1) const {
		FPS ret(*this);
		if(deg != -1) ret.resize(deg, mint(0));
		std::reverse(std::begin(ret), std::end(ret));
		return ret;
	}

	FPS inv(int deg = -1) const {
		assert(((*this)[0]) != mint(0));
		const int n = (int)this->size();
		if(deg == -1) deg = n;
		FPS ret;
		ret.resize(deg);
		ret[0] = 1;
		return ret / (*this);
	}
};