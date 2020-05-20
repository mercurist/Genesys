def kordLCS(dnaOne, dnaTwo, n1, n2, i, j, order):
    if i == n1:
        return 0
    if j == n2:
        return 0
    if dnaOne[i] == dnaTwo[j]:
        return 1 + kordLCS(dnaOne, dnaTwo, n1, n2, i + 1, j + 1, order)
    else:
        q1 = kordLCS(dnaOne, dnaTwo, n1, n2, i + 1, j, order)
        q2 = kordLCS(dnaOne, dnaTwo, n1, n2, i, j + 1, order)
        q3 = None
        if order != 0:
            q3 = 1 + kordLCS(dnaOne, dnaTwo, n1, n2, i + 1, j + 1, order - 1)
            return max(q1, q2, q3)
        return max(q1, q2)


dnayz = input().split()
dnaSampleOne = dnayz[0]
dnaSampleTwo = dnayz[1]

k = input()
k = int(k)

res = kordLCS(dnaSampleOne, dnaSampleTwo, len(dnaSampleOne), len(dnaSampleTwo), 0, 0, k)

print(res)
