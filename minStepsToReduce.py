target = input()
target = int(target)

# Time = O(n) | Space = O(n)
def minStepReduction(target):
    # bottom-up DP
    array = [float("inf") for i in range(target + 1)]
    array[1] = 0
    for i in range(2, target + 1):
        array[i] = min(array[i], 1 + array[i - 1])

        if i % 2 == 0:
            array[i] = min(array[i], 1 + array[i // 2])
        if i % 3 == 0:
            array[i] = min(array[i], 1 + array[i // 3])

    return array[target]
    pass


# Time = 0(3^n)
def minStepReductionRecursive(target):
    if target == 1:
        return 0
    q1 = float("inf")
    q2 = float("inf")

    if target % 2 == 0:
        q1 = 1 + minStepReductionRecursive(target // 2)
    if target % 3 == 0:
        q2 = 1 + minStepReductionRecursive(target // 3)
    q3 = 1 + minStepReductionRecursive(target - 1)

    return min(q1, q2, q3)
    pass


print(minStepReductionRecursive(target))
print(minStepReduction(target))
