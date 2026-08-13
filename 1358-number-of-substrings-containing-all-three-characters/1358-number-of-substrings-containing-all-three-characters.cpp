class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int left = 0;
        int total_substrings = 0;
        
        // Expand the window using the right pointer
        for (int right = 0; right < s.length(); right++) {
            count[s[right] - 'a']++;
            
            // min_len core: while the window is VALID, shrink it from the left
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[left] - 'a']--;
                left++;
            }
            
            // At this point, 'left' has moved past all valid starting positions 
            // for the current 'right' ending position. 
            // The number of valid starting positions is exactly 'left'.
            total_substrings += left;
        }
        
        return total_substrings;
    }
};