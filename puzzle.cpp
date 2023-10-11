#include <iostream>
#include <vector>

using namespace std;

int countCombinations(vector<int> &pieces, int K, int index, vector<bool> &used)
{
    if (K == 0)
    {
        return 1; // Found a valid combination
    }

    if (K < 0 || index < 0)
    {
        return 0; // Reached an invalid state
    }

    int include = 0;
    if (!used[index])
    {
        used[index] = true;
        include = countCombinations(pieces, K - pieces[index], index - 1, used);
        used[index] = false;
    }

    int exclude = countCombinations(pieces, K, index - 1, used);

    return include + exclude;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> pieces(N);
    for (int i = 0; i < N; i++)
    {
        cin >> pieces[i];
    }

    vector<bool> used(N, false);
    int combinations = countCombinations(pieces, K, N - 1, used);
    cout << combinations << endl;

    return 0;
}
