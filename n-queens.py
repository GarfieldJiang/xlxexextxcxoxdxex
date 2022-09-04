class Solution:
    def _test_row_with_before(self, queens, i):
        for k in range(i):
            if (queens[k] == queens[i]):
                return False
            if (abs(queens[k] - queens[i]) == abs(k - i)):
                return False
        return True

    def _backtrace(self, queens, i):
        while queens[i] == len(queens):
            if i == 0:
                return -1
            queens[i] = 0
            queens[i - 1] += 1
            i = i - 1
        return i
    
    def _gen_result(self, queens):
        rows = []
        for i in range(len(queens)):
            sb = []
            for k in range(len(queens)):
                sb.append('Q' if queens[i] == k else '.')
            rows.append(''.join(sb))
        return rows

    def solveNQueens(self, n: int) -> List[List[str]]:
        ret = []
        queens = [0] * n
        i = 0
        while True:
            i = self._backtrace(queens, i)
            if i < 0:
                break
            if not self._test_row_with_before(queens, i): 
                queens[i] += 1
                continue
            if i < n - 1:
                i += 1
                continue
            ret.append(self._gen_result(queens))
            queens[i] += 1
        return ret
