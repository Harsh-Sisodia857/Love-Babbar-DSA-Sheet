#include <iostream>
    using namespace std;

int main()
{
    int N;
    cin >> N;

    int donations[N];
    for (int i = 0; i < N; i++)
    {
        cin >> donations[i];
    }

    int maxDonation = 0;
    int currentDonation = 0;

    for (int i = 0; i < N; i++)
    {
        // Try collecting donations starting from the current house
        for (int j = i; j < N; j++)
        {
            // Find the minimum donation in the current block
            int minDonation = donations[i];
            for (int k = i; k <= j; k++)
            {
                minDonation = min(minDonation, donations[k]);
            }

            // Calculate the maximum amount that can be collected in this block
            int totalAmount = minDonation * (j - i + 1);

            // Update the maximum donation if the current house gives more
            maxDonation = max(maxDonation, totalAmount);
        }
    }

    cout << maxDonation << endl;

    return 0;
}