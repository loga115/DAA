import random
import string

def generate_random_string(length):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for _ in range(length))

def generate_lengths(n1,n2):
    with open(f"random_strings_{n1}_{n2}.txt", "w") as file:
        # Write the value of n at the top of the file
        length1 = n1
        length2 = n2
        
        random_str1 = generate_random_string(length1)
        random_str2 = generate_random_string(length2)
        
        # Write the pair of strings to the file, separated by a newline
        file.write(random_str1 + "\n" + random_str2 + "\n")  # Write the pair with space separation

# Input: number of pairs
n1 = int(input())
n2 = int(input())
generate_lengths(n1,n2)




