class Solution {
public:
    bool isVowel(char ch){
        switch (ch) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
        default:
            return false;
        }
    }

    string reverseVowels(string s) {
        int n = s.size();

        int l=0, r=n-1;
        while(l<r){
            while(l<r && !isVowel(s[l])) l++;
            while(l<r && !isVowel(s[r])) r--;

            
                swap(s[l], s[r]);
                l++;
                r--;
            
        }
        return s;
    }
};