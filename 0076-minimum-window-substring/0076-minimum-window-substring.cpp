class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int min_size = INT_MAX; // store minimum size of ans string
        unordered_map<char,int> mpp;
        int S_ind = -1; // to get the index of start
        int cnt = 0; // signifies the elements found
        int l = 0, r = 0;
        // adding elements of t into map
        for( int i=0; i<n; i++){
            mpp[t[i]]++;
        }
        // 
        while( r<m ){
            if( mpp[s[r]] > 0 ){ cnt++; }//element found increment count
            mpp[s[r]]--; // cut from map
            while( cnt == n ){ // cnt is n .. so check if smaller substr as ans is present
                // moving l
                if( r-l+1 < min_size ){ min_size = r-l+1; S_ind = l;}//storing min string
                mpp[s[l]]++;//add in map
                if( mpp[s[l]] > 0 ){ cnt--; }//not present in current substr so cnt--
                l++;
            }
            r++;
        }
        return S_ind == -1?"":s.substr(S_ind,min_size);

    }
};