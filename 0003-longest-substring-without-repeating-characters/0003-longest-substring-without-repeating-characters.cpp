class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // using hashmap -> store elements until dulicate is encountered
        int maxi = 0;
        int n = s.size();
        if(n == 1){ return 1;}
        cout<<n;
        for( int i = 0; i<n; i++){
            map<char,int> mpp;
            int cnt = 0;
            for( int j = i; j<n; j++){
                if( mpp.find(s[j]) == mpp.end() ){
                    mpp[s[j]]++;
                    cnt++;
                    maxi = max(maxi,cnt);
                }
                else{
                    maxi = max(maxi,cnt);
                    // cnt = 1;
                    break;
                }
            }
        }
            return maxi;    
}
};