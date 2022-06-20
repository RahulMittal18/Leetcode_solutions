class Solution(object):
    def maxProfit(self, prices):
        
        min_price, profit = 10001, 0
        for price in prices:
            if min_price < price:
                profit += price - min_price
            min_price = price
        return profit