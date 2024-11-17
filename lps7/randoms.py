import random
import string
def generate_two_random_strings(t, p_length):
    characters = string.ascii_letters + string.digits
    random_string_t = ''.join(random.choice(characters) for _ in range(t))
    random_string_p = ''.join(random.choice(characters) for _ in range(p_length))
    return random_string_t, random_string_p

# Example usage
t = 500  # Length of the first random string
p_length = 250  # Length of the second random string
random_string_t, random_string_p = generate_two_random_strings(t, p_length)
print( random_string_t)
print( random_string_p)