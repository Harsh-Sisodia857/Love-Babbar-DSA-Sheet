int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    sort(arr, arr + N);
    int i = N - 1;
    int sum = 0;
    while (i > 0)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff < K)
        {
            sum += (arr[i] + arr[i - 1]);
            i = i - 2;
        }
        else
        {
            i = i - 1;
        }
    }
    return sum;
}