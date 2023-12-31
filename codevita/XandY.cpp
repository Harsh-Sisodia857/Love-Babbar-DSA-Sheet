#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define Problem vector<int>
#define AllElements(a) (a).begin(), (a).end()
#define Size(a) ((int)((a).size()))

const ll INF = 4e18;

unordered_map<int, unordered_map<int, int>> memoizationTable;

int calculateCost(int startIndex, int endIndex, int costS, int costR, string &strX, string &strY, string &reversedStrY)
{
    if (startIndex > endIndex)
        return 0;
    if (memoizationTable.find(startIndex) != memoizationTable.end() && memoizationTable[startIndex].find(endIndex) != memoizationTable[startIndex].end())
        return memoizationTable[startIndex][endIndex];

    int minimumCost = 1e9;
    for (int k = startIndex; k <= endIndex; k++)
    {
        if (reversedStrY.find(strX.substr(startIndex, k - startIndex + 1)) != string::npos)
            minimumCost = min(minimumCost, costR + calculateCost(k + 1, endIndex, costS, costR, strX, strY, reversedStrY));
        if (strY.find(strX.substr(startIndex, k - startIndex + 1)) != string::npos)
            minimumCost = min(minimumCost, costS + calculateCost(k + 1, endIndex, costS, costR, strX, strY, reversedStrY));
    }

    return memoizationTable[startIndex][endIndex] = minimumCost;
}

int solve(int costS, int costR, string strX, string strY)
{
    string reversedStrY = strY;
    reverse(AllElements(reversedStrY));
    return calculateCost(0, Size(strX) - 1, costS, costR, strX, strY, reversedStrY);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string strX, strY;
    cin >> strX >> strY;
    int costS, costR;
    cin >> costS >> costR;

    int result = solve(costS, costR, strX, strY);
    if (result == 1e9)
    {
        cout << "Impossible";
        return 0;
    }
    cout << result;

    return 0;
}
