class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int nG = g.size();
        int nS = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0;
        int r = 0;
        int cnt = 0;

        while(l<nG && r<nS){
            if(s[r] >= g[l]){
                cnt++;
                r++; l++;
            }
            else{
                r++;
            }
        }
        return cnt;
    }
};