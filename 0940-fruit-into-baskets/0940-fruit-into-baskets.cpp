class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        unordered_map<int,int> mpp;
        int types = 0;
        int maxi = 0;
        while( right < n ){
            if( (mpp.find(fruits[right]) == mpp.end())  ){
                // fruit is not present
                if( types == 2 ){
                    // decrease on type
                    while( types == 2 ){
                        int val = fruits[left];
                        if( mpp[val] == 1 ){
                            types--;
                            mpp.erase(val);
                            left++;
                        }
                        else{
                            mpp[val]--;
                            left++;
                        }
                    }
                }
                types += 1;
            }

            mpp[fruits[right]] += 1;
            maxi = max( maxi , right - left + 1 );
            right++;
        }
        return maxi;
    }
};