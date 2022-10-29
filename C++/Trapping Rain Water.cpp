 #include <bits/stdc++.h>
 using namespace std;
  
 int trap(vector<int>& h) {
        int water = 0, l = 0, r = h.size()-1, lmax = INT_MIN, rmax = INT_MIN;
        while(l < r){
            lmax = max(h[l], lmax);
            rmax = max(h[r], rmax);
            water += (lmax < rmax) ? lmax-h[l++] : rmax-h[r--] ;
        }
        return water;
  }
  
 int main()
 {
    vector<int>arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << trap(arr);
    return 0;
 }
