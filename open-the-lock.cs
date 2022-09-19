public class Solution {
    private const int START = 0;
    private static int[] ORDERS = new int[] { 1, 10, 100, 1000, 10000 };
    
    public int OpenLock(string[] deadends, string target) {
        HashSet<int> deSet = new HashSet<int>();
        foreach (var de in deadends) {
            deSet.Add(StringToInt(de));
        }
        var targetInt = StringToInt(target);
        if (deSet.Contains(START)) return -1;
        Dictionary<int, int> visited = new Dictionary<int, int>();
        Queue<int> frontier = new Queue<int>();
        frontier.Enqueue(START);
        visited[START] = 0;
        while (frontier.Count > 0) {
            var code = frontier.Dequeue();
            var distance = visited[code];
            if (code == targetInt) return distance;
            foreach (var nextCode in Neighbors(code)) {
                if (deSet.Contains(nextCode) || visited.ContainsKey(nextCode)) continue;
                frontier.Enqueue(nextCode);
                visited[nextCode] = distance + 1;
            }
        }
        return -1;
    }
    
    private static int StringToInt(string code) {
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            ret += (code[i] - '0') * ORDERS[i];
        }
        return ret;
    }
    
    private static IEnumerable<int> Neighbors(int code) {
        for (int i = 0; i < 4; i++) {
            int digit = code % ORDERS[i + 1] / ORDERS[i];
            yield return code - digit * ORDERS[i] + ((digit + 1) % 10) * ORDERS[i];
            yield return code - digit * ORDERS[i] + ((digit + 9) % 10) * ORDERS[i];
        }
    }
}
