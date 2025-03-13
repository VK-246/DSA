class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp; // stores char and index
        int l = 0,r = 0;
        int maxi = 0;
        while( r < n ){
            // if( )
            if( mpp.find(s[r]) == mpp.end() || mpp[s[r]] < l ){
                mpp[s[r]] = r;
            }
            else{
                l = mpp[s[r]]+1;
                mpp[s[r]] = r;
            }
            // update maxi
            maxi = max( maxi , r-l+1);
            cout<<maxi<<" ";
            r++;
        }
        return maxi;

}
};