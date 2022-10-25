  int trap(vector<int>& h) {
        int water = 0, l = 0, r = h.size()-1, lmax = INT_MIN, rmax = INT_MIN;
        while(l < r){
            lmax = max(h[l], lmax);
            rmax = max(h[r], rmax);
            water += (lmax < rmax) ? lmax-h[l++] : rmax-h[r--] ;
        }
        return water;
    }
