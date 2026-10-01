class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int left=0, current=0, right=0;

        for(int i = 0; i < len && n > 0; i++){
            if(flowerbed[i] == 0){
                bool leftEmpty = (i==0 || flowerbed[i-1] == 0);
                bool rightEmpty = (i==len-1 || flowerbed[i+1] == 0);

                if(leftEmpty && rightEmpty){
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }

        return n==0;
    }
};