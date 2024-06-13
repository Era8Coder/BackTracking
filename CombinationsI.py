def solve(ans, temp, n, left, k):
    # This implies that we had made the k-sized Array Now it's time to push it into the Answer Array/List
    if k == 0:  
        ans.append(temp[:])  # Append a copy of temp
        return
    
    # Loop iterates from left to n -> First Time left will be "1"
    for i in range(left, n + 1):
        temp.append(i)
        solve(ans, temp, n, i + 1, k - 1)  # Decreasing k till it reaches Zero and increasing the index
        temp.pop()

def make_combinations(n, k):
    ans = []
    temp = []
    solve(ans, temp, n, 1, k)
    return ans

# Read input values
n = int(input())
k = int(input())

# Generate combinations
v = make_combinations(n, k)

# Print the result
for combination in v:
    print(" ".join(map(str, combination)))
