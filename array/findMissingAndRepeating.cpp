vector<int> findTwoElement(vector<int> arr, int n)
{
    // code here
    int xorSum = 0; // Corrected variable name
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ arr[i]; // Corrected variable name
    }
    for (int i = 1; i <= n; i++)
        xorSum = xorSum ^ i;

    int xorBit = 0; // Variable to store the rightmost set bit
    while (1)
    {
        if (xorSum & (1 << xorBit))
        {
            break;
        }
        xorBit++;
    }

    int xor0 = 0, xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & (1 << xorBit))
            xor1 = xor1 ^ arr[i];
        else
            xor0 = xor0 ^ arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & (1 << xorBit))
            xor1 = xor1 ^ i;
        else
            xor0 = xor0 ^ i;
    }

    int c = 0, repeating = -1, missing = -1;
    for (int i = 0; i < n; i++)
    {
        if (xor1 == arr[i])
        {
            c++;
        }
    }
    if (c == 2)
    {
        repeating = xor1;
        missing = xor0;
    }
    else
    {
        repeating = xor0;
        missing = xor1;
    }
    vector<int> ans;
    ans.push_back(repeating); // Removed unnecessary curly braces
    ans.push_back(missing);
    return ans;
}