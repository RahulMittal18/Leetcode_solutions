class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        def recurse(r,c):

            # base
            if r == len(grid)-1:
                return grid[r][c]
            if c > len(grid[c])-1:
                return float('inf')

            # memo cond
            if (r,c) in memo:
                return memo[(r,c)]

            # recursive - O(1) is the cost of the recursive call.- isolated
            result = grid[r][c] + min(recurse(r+1, c), recurse(r+1, c+1))
            memo[(r,c)] = result
            return result

        # main 
        memo = {}
        grid = triangle
        return recurse(0,0)