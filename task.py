from collections import Counter

def numTilePossibilities(tiles: str) -> int:
    def backtrack(counter):
        total = 0
        for char in counter:
            if counter[char] > 0:
                # Choose the character
                counter[char] -= 1
                total += 1  # Count this sequence
                total += backtrack(counter)  # Explore further
                # Undo the choice (backtrack)
                counter[char] += 1
        return total
    
    return backtrack(Counter(tiles))

# Test cases
print(numTilePossibilities("AAB"))     # Output: 8
print(numTilePossibilities("AAABBC"))  # Output: 188
print(numTilePossibilities("V"))       # Output: 1
