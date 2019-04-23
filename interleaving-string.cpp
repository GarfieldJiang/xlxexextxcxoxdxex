// https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n3 != n1 + n2) return false;
        if (!n1) return s2 == s3;
        if (!n2) return s1 == s3;
        vector<bool> dp(n2 + 1, false);
        dp[0] = true;
        for (size_t j = 1; j < n2 + 1; j++) dp[j] = dp[j - 1] && s3[j - 1] == s2[j - 1];
        for (size_t i = 1; i < n1 + 1; i++) {
            dp[0] = dp[0] && s3[i - 1] == s1[i - 1];
            for (size_t j = 1; j < n2 + 1; j++)
                dp[j] = dp[j - 1] && s3[i + j - 1] == s2[j - 1] || dp[j] && s3[i + j - 1] == s1[i - 1];
        }
        return dp[n2];
    }
};
