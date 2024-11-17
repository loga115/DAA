"""
Module to generate a zigzag sequence from an array of unique numbers.

A zigzag sequence is defined as a sequence where the first k elements are in increasing order
and the last k elements are in decreasing order, where k is equal to (n+1)/2.
"""
from typing import List

def zigzag_sequence(arr: List[int], k: int) -> List[int]:
    """
    Permute the elements of an array to create a zigzag pattern.
    
    Args:
    arr (List[int]): A list of unique integers.
    
    Returns:
    List[int]: The lexicographically smallest zigzag sequence.
    """
    n = len(arr)
    #remove duplicates
    arr = list(set(arr))
    arr.sort()

    
    k = (n + 1) // 2
    first_half = arr[:k]
    second_half = arr[k:]
    
    second_half.reverse()
    
    result = first_half + second_half
    
    # Swap elements to ensure the zigzag pattern
    for i in range(1, k):
        if k + i - 1 < n:
            result[i], result[n - i] = result[n - i], result[i]

    return result

k = int(input())
input2 = [int(x) for x in input().split(' ')]
result = zigzag_sequence(input2, k)
print(' '.join(map(str, result)))