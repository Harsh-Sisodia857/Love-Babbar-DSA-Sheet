vector<int> sieveOfEratosthenes(int N)
{
    vector<bool> isPrime(N + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i < N + 1; i++)
    {
        if (isPrime[i])
            ans.push_back(i);
    }
    return ans;
}