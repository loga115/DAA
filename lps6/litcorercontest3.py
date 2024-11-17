'''
This module provides a function to count the number of valid split points in an array of integers
representing gold in each city. A valid split point is defined as a point where the sum of the 
northern subarray is greater than or equal to the sum of the southern subarray.
Functions:
    count_valid_splits(gold: List[int]) -> int:
        Count the number of valid split points in the gold array.

'''
from typing import List

def count_valid_splits(gold: List[int]) -> int:
    """
    Count the number of valid split points in the gold array where the sum of the northern subarray
    is greater than or equal to the sum of the southern subarray.

    Args:
    gold (List[int]): An array of integers representing the gold in each city.

    Returns:
    int: The number of valid split points.
    """
    total_gold = sum(gold)
    northern_sum = 0
    valid_splits = 0

    for i in range(len(gold) - 1):
        northern_sum += gold[i]
        southern_sum = total_gold - northern_sum
        if northern_sum >= southern_sum:
            valid_splits += 1

    return valid_splits

gold = [10, 4, 8, 2]
print(count_valid_splits(gold))  # Output: 2
