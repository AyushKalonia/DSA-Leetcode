class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int> st;

        int i=0;
        while(i<n){
            int e = asteroids[i];
            if(e>0) st.push_back(e);

            else{
                while(!st.empty() && st.back()>0 && st.back()<abs(e))   st.pop_back();
                if(!st.empty() && st.back()==abs(e))    st.pop_back();
                else if(st.empty() || st.back()<0) st.push_back(e);
            }
            i++;
        }

        return st;
    }
};