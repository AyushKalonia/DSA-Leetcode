class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int bill5 = 0;
        int bill10 = 0;

        for(int i=0; i<n; i++){
            if(bills[i] == 5)   bill5++;
            else if(bills[i] == 10){
                if(bill5){
                    bill5--;
                    bill10++;
                }
                else    return false;
            }
            else{
                if(bill5 && bill10){
                    bill5--;
                    bill10--;
                }
                else if(bill5 >= 3) bill5 -=3;
                else    return false;
            }
        }

        return true;
    }
};