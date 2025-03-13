class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = 0;
        int cnt0 = 0;
        int maxi = 0;
        while( end < n ){
            if( nums[end] == 0 ){
                cnt0++;
            }
            if( cnt0 > k ){
                while( nums[start] != 0){
                    start++;
                }
                cnt0--;
                start++;
            }
            else{
                maxi = max( maxi , end - start + 1);
            }
            end++;
        }
        return maxi;
    }
};