def longestCommon(dnaOne, dnaTwo, n1, n2, i, j):
    if i == n1:
        return 0
    if j == n2:
        return 0
    if dnaOne[i] == dnaTwo[j]:
        return 1 + longestCommon(dnaOne, dnaTwo, n1, n2, i + 1, j + 1)
    else:
        q1 = longestCommon(dnaOne, dnaTwo, n1, n2, i + 1, j)
        q2 = longestCommon(dnaOne, dnaTwo, n1, n2, i, j + 1)
        return max(q1, q2)


dnayz = input().split()
dnaSampleOne = dnayz[0]
dnaSampleTwo = dnayz[1]

res = longestCommon(
    dnaSampleOne, dnaSampleTwo, len(dnaSampleOne), len(dnaSampleTwo), 0, 0
)

print(res)
