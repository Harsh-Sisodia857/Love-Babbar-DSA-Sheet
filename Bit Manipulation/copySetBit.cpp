   int setSetBit(int x, int y, int l, int r){

        int mask = 1 << (r-l+1);
        mask = mask - 1;
        mask = mask << (l-1);
        mask = mask & y;
        int res = mask | x;
        return res;
        
    }