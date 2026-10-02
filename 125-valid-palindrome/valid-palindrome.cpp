class Solution {
public:
    bool isPalindrome(string s) {
        string st = "";
        for (char c : s) {
            if (isalnum(c))
                st += tolower(c);
        }


        int n = st.size();
        int l = 0, r = n-1;

        while(l<=r){
            if(st[l] != st[r])  return false;
            l++; r--;
        }

        return true;
    }
};