class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int a = 0, b =0;

        while(a<word1.size() && b<word2.size()){
            s+=word1[a];
            s+=word2[b];
            a++; b++;
        }

        while(a<word1.size()){
            s+=word1[a];
            a++;
        }
        while(b<word2.size()){
            s+=word2[b];
            b++;
        }

        return s;
    }
};