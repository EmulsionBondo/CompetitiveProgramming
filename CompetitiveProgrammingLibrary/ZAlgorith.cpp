//Z-Algorithm(最長共通接頭辞)
//各iについてSとS[i,|S|]の最長共通接頭辞の長さを記録した配列を返す
//S:aaabaaaab
//v:921034210
//S$TみたいにするとSの接尾字とTの接頭辞の共通の長さを見れる
vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}