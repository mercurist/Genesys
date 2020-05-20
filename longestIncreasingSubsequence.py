def longestIncreasingSubsequence(array):
    n = len(array)
    dp = [1 for i in range(n)]
    for i in range(1, n):
        for j in range(0, i):
            if array[j] < array[i]:
                dp[i] = max(dp[i], dp[j] + 1)

    return dp


array = input().split()
for i in range(len(array)):
    array[i] = int(array[i])

result = longestIncreasingSubsequence(array)
for i in range(len(result)):
    print(result[i], end=" ")
