# Solution for the knapsack problem with dynamic programing
# Parameters:
#   _ W: total capacity of the sack (int)
#   _ values: value for each object (list)
#   _ weights: weigth of each object (list)
#   _ value_only: True to only return the best filled value (bool)
#
# Returns: value, objects
#   _ value: total value for the best solution (int)
#   _ objects: state of each object, True if taken (list)

def knapsack(W, values, weights, value_only=False):

    n = len(values)    
    
    # Array of filled values
    # Accessed by S[i][c]
    S = [[0 for c in range(W+1)] for i in range(n+1)]

    for i in range(1, n+1):
        w = weights[i-1]
        v = values[i-1]
        for c in range(W+1):
            if c >= w:
                S[i][c] = max(S[i-1][c], S[i-1][c-w] + v)
            else:
                S[i][c] = S[i-1][c]

    if value_only:
        return S[n][W], None

    # Tracing back an optimal solution
    i = n
    c = W
    K = [False for i in range(n)]
    
    while i != 0:
        v = values[i-1]
        w = weights[i-1]

        if S[i][c] == S[i-1][c-w] + v:
            # The current i-th object is added
            K[i-1] = True
            i -= 1
            c -= w
            print(K)
        else:
            # Not added
            i -= 1
        print("")
                
    return S[n][W], K


if __name__ == '__main__':

    print(knapsack(10, [3, 5, 1, 2], [2, 5, 6, 3]))
