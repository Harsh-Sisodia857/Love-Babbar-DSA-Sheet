// recursion
// recursive part of the function is where the count of binary trees is calculated for heights greater than 1. It uses a recursive formula to calculate the number of binary trees for a given height h.

// For a height h, it calculates the number of binary trees by considering three different cases:

// The left subtree has a height of h - 2, and the right subtree has a height of h - 2.
// The left subtree has a height of h - 1, and the right subtree has a height of h - 2.
// The left subtree has a height of h - 2, and the right subtree has a height of h - 1.
// It calculates the number of binary trees for each of these cases and then adds them together to get the total count of binary trees for height h
long long int count(int h)
{
    // count(h-2), count(h-2)
    // count(h-1), count(h-2)
    // count(h-2), count(h-1)
    if (h == 0 || h == 1)
        return 1;
    return (2 * count(h - 2) * count(h - 1)) + (count(h - 2) * count(h - 2));
}
long long int countBT(int h)
{
    return count(h);
}

// memoization

int mod = 1e9 + 7;
long long int count(int h, vector<int> &dp)
{
    // count(h-1), count(h-1) 
    // count(h-1), count(h-2)
    // count(h-2), count(h-1)
    // count(h) = 2 * count(h - 1) * count(h - 2) + count(h - 1) * count(h - 1);
    // count(h) = count(h - 1) [2 * count(h - 2) + count(h - 1)]
    if (h == 0 || h == 1)
        return 1;
    if (dp[h] != -1)
        return dp[h];
    return dp[h] = ((2 * count(h - 2, dp) % mod) + (count(h - 1, dp) % mod)) *
                   (count(h - 1, dp) % mod) % mod;
}
long long int countBT(int h)
{
    vector<int> dp(h + 1, -1);
    return count(h, dp);
}