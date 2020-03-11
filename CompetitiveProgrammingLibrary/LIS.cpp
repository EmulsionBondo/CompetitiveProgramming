//LISの長さを返す
//strict == trueなら狭義，strict == falseなら広義
template< typename T >
size_t LIS(const vector< T > &a, bool strict) {
  vector< T > lis;
  for(auto &p : a) {
    typename vector< T >::iterator it;
    if(strict) it = lower_bound(begin(lis), end(lis), p);
    else it = upper_bound(begin(lis), end(lis), p);
    if(end(lis) == it) lis.emplace_back(p);
    else *it = p;
  }
  return lis.size();
}