// https://leetcode.com/problems/edit-distance/description/

// DP method. Let m = word1.length() and n = word2.length().
// Logically a (m + 1) x (n + 1) 2-dimensional array dp[0 .. m, 0 .. n] is used,
// where dp[i, j] means the edit distance between words[0 .. i - 1] and words[0 .. j - 1].
// Intuitively,
// - dp[0, j] = j, 0 <= j <= m;
// - dp[i, 0] = i, 1 <= i <= n.
// Besides, dp[i, j] is determined as follows:
// - If words1[i - 1] == words2[j - 1], then dp[i, j] = dp[i - 1, j - 1], which means that
//   appending the same letter after two words doesn't change the edit distance.
// - Otherwise, dp[i, j] = 1 + min(dp[i - 1, j], dp[i, j - 1], dp[i - 1, j - 1]).
// The implementation uses 2 rolling arrays, dp and dp1 to save space.

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) (MIN(MIN((a), (b)), (c)))
#define SWAP(a, b) { auto tmp = a; a = b; b = tmp; }

class Solution {
public:
    int minDistance(string word1, string word2) {
        int height = word1.length() + 1;
        int width = word2.length() + 1;
        vector<int> dp(width);
        vector<int> dp2(width);

        for (int j = 0; j < width; j++) dp[j] = j;
        
        for (int i = 1; i < height; i++) {
            dp2[0] = i;
            for (int j = 1; j < width; j++) {
                if (word1[i - 1] == word2[j - 1]) dp2[j] = dp[j - 1];
                else dp2[j] = 1 + MIN3(dp[j], dp2[j - 1], dp[j - 1]);
            }
            
            SWAP(dp, dp2);
        }
        return dp[width - 1];
    }
};
