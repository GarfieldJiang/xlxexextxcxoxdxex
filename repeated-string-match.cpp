class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m = A.size();
        int n = B.size();
        if (n == 0) return 0;
        if (m == 0) return -1;
        
        int maxTimes = (2 * m + n) / m;
        string repeated;
        repeated.reserve(maxTimes * m);
        for (int i = 0; i < maxTimes; i++) {
            for (int j = 0; j < m; j++) {
                repeated.push_back(A[j]);
            }
        }
        
        int pos = repeated.find(B);
        if (pos == string::npos) return -1;
        return (pos + n) / m + ((pos + n) % m != 0);
    }
};
