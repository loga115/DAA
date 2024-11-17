from typing import List
from collections import Counter

"""
This module provides functionality to determine the most common plant type from a list of plant 
sightings. Each plant type is identified by a unique integer ID. If multiple plant types are equally 
common, the plant with the smallest ID number is chosen.
"""

def most_common_plant(sightings: List[int]) -> int:
    """
    Determine the most common plant type from the list of sightings.

    Args:
        sightings (List[int]): A list of integers where each integer represents a plant ID.

    Returns:
        int: The ID of the most common plant. If multiple types are equally common,
             the smallest ID is returned.
    """

    # Count the occurrences of each plant ID
    plant_counts = Counter(sightings)

    # Find the plant ID with the highest count, and in case of a tie, the smallest ID
    most_common_id = min(plant_counts, key=lambda x: (-plant_counts[x], x))

    return most_common_id

sightings = [int(x) for x in input().split(' ')]
print(most_common_plant(sightings))
