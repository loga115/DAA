'''
This module provides a function to find the number of pairs of integers in an array whose sum is divisible by a given number.
Functions:
    divisible_sum_pairs(arr, k): Finds the number of pairs whose sum is divisible by k.
'''
def divisible_sum_pairs(arr: list[int], k: int) -> int:
    """
    Find the number of pairs of integers in an array whose sum is divisible by a given number.

    Args:
        arr (list): List of integers.
        k (int): The divisor.

    Returns:
        int: The number of pairs whose sum is divisible by k.
    """
    count = 0
    n = len(arr)
    for i in range(n):
        for j in range(i + 1, n):
            if (arr[i] + arr[j]) % k == 0:
                count += 1
    return count

k = int(input())
ar = [int(x) for x in input().split(' ')]

result = divisible_sum_pairs(ar, k)
print(result)
