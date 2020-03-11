// string s全体を小/大文字化
transform(s.begin(),s.end(),s.begin(),::tolower);
//string 1文字を小/大文字化
s[0] = toupper(s[0]);