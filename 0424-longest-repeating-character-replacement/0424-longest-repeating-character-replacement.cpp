class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlength = 0;
        int l = 0;
        int maxf = 0; // Frequency of the most common character in the window
        vector<int> count(26, 0);

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            
            // Update the maximum frequency seen in the current window
            maxf = max(maxf, count[s[r] - 'A']);

            // Window Size = (r - l + 1)
            // Letters to replace = (Window Size) - maxf
            // If letters to replace > k, the window is invalid. Shrink it.
            while ((r - l + 1) - maxf > k) {
                count[s[l] - 'A']--;
                l++;
            }
            
            // The window is now valid, check if it's the longest we've seen
            maxlength = max(maxlength, r - l + 1);
        }
        
        return maxlength;
    }
};