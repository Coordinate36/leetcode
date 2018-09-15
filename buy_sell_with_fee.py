def get_input():
    str = input().replace(' ', '').replace('[', '').replace(']', '')
    nums = [int(x) for x in str.split(',')]
    return nums[:-1], nums[-1]

def solution(prices, fee):
    size = len(prices)
    buy = [0] * size
    sell = [0] * size
    buy[0] = -prices[0] - fee
    
    for i in range(1, size):
        buy[i] = max(buy[i-1], sell[i-1] - prices[i] - fee)
        sell[i] = max(sell[i-1], buy[i-1] + prices[i])

    return sell[size-1]

def main():
    prices, fee = get_input()
    print(solution(prices, fee))

main()
