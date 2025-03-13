class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        unordered_map<char, int> charIndex;  // Map to store character positions
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];
            
            // If character is seen and its last position is >= start
            if (charIndex.find(currentChar) != charIndex.end() && 
                charIndex[currentChar] >= start) {
                // Move start pointer to position after last occurrence
                start = charIndex[currentChar] + 1;
            } else {
                // Update maxLength if current window is larger
                maxLength = max(maxLength, end - start + 1);
            }
            
            // Update character's last position
            charIndex[currentChar] = end;
        }
        
        return maxLength;
    }
};