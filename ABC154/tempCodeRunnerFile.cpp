REP(i,r+1){
        res += rec(k+1, tight && i == r, (i == 0 ? zero + 1 : zero));
    }