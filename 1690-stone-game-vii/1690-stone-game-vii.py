class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        n = len(stones)
        preSum = [0] * (n + 1)
        for i in range(n):
            preSum[i + 1] = preSum[i] + stones[i]

        def getSum(left, right):
            return preSum[right + 1] - preSum[left]

        @lru_cache(2000)
        def dp(left, right):
            if left == right: return 0  # only 1 stone, score = 0 -> difference = 0 as well
            scoreRemoveLeftMost = getSum(left + 1, right)
            scoreRemoveRightMost = getSum(left, right - 1)
            return max(scoreRemoveLeftMost - dp(left + 1, right), scoreRemoveRightMost - dp(left, right - 1))

        return dp(0, n - 1)