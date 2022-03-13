public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        var cache = new List<HashSet<string>>();
        cache.Add(new HashSet<string> {"()"});
        for (int i = 2; i <= n; i++) {
            HashSet<string> row = new HashSet<string>();
            for (int l = 1; l < i; l++) {
                var r = i - l;
                var lCache = cache[l - 1];
                var rCache = cache[r - 1];
                foreach (var lItem in lCache) {
                    foreach (var rItem in rCache) {
                        row.Add(lItem + rItem);
                    }
                }
            }
            foreach (var item in cache[i - 2]) {
                row.Add($"({item})");
            }
            cache.Add(row);
        }
        return new List<string>(cache[n - 1]);
    }
}
