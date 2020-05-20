def maximumProfit(wines):
    left = 0
    right = len(wines) - 1
    amount = 0
    count = 1
    while left <= right:
        leftBarrel = wines[left]
        rightBarrel = wines[right]
        minimum = None
        if leftBarrel <= rightBarrel:
            minimum = leftBarrel
            left += 1
        else:
            minimum = rightBarrel
            right -= 1
        amount += minimum * count
        count += 1
    return amount


wines = input().split()
for i in range(len(wines)):
    wines[i] = int(wines[i])
print(maximumProfit(wines))
