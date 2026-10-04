class Solution {
public:
    bool isVowel(char ch) {
        switch (ch) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default:
                return false;
        }
    }

    int maxVowels(string s, int k) {
        int n = s.size();

        int cnt = 0;
        int maxi = 0;
        int i;
        for(i=0; i<k; i++){
            if(isVowel(s[i]))   cnt++;
        }
        maxi = cnt;

        while(i<n){
            if(isVowel(s[i-k])) cnt--;
            if(isVowel(s[i]))   cnt++;

            maxi = max(maxi, cnt);
            i++;
        }

        return maxi;
    }
};