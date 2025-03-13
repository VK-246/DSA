class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = 0;
        int cnt0 = 0;
        int maxi = 0;
        // Optimized 1
        // while( end < n ){
        //     if( nums[end] == 0 ){
        //         cnt0++;
        //     }
        //     if( cnt0 > k ){
        //         while( cnt0 > k ){
        //             if( nums[start] == 0 ){
        //                 cnt0--;
        //             }
        //             start++;
        //         }
        //     }
        //     else{
        //         maxi = max( maxi , end - start + 1);
        //     }
        //     end++;
        // }


        // OPtimized 2
        // uses the idea that max will never be greater until zero is not trimmed, so no need to move for start using a loop , move with end itself.
        while( end < n){
            if( nums[end] == 0){
                cnt0++;
            }
            if( cnt0 > k){
                if(nums[start] == 0){cnt0--;}
                start++;
            }
            if( cnt0 <= k ){
                maxi = max( maxi , end - start + 1 );
            }
            end++;
        }

        return maxi;
    }
};
