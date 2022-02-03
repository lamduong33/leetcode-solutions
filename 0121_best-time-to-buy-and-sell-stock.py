class Solution:
    """ Solution for the best time to buy and sell problem"""

    @staticmethod
    def maxProfit(prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        highest = 0
        buy_point = 0
        sell_point = 1
        for i in range(len(prices)):
            if len(prices) == 1:
                return 0
            difference = prices[sell_point] - prices[buy_point]

            # Make a profit
            if difference > 0:
                # Move selling point up
                if difference > highest:
                    highest = difference
            # Else don't make a profit
            else:
                buy_point = sell_point
            sell_point += 1
            if sell_point >= len(prices):
                break

            return highest


prices = [1, 2, 3, 4, 5]
print(Solution.maxProfit(prices))
Solution.maxProfit(prices)

def main():
    print("Hello world!")
