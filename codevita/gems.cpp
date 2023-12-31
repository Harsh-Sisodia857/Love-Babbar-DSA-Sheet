// #include <iostream>
// #include <vector>
// #include <sstream>

// using namespace std;

// vector<string> splitTheDishByColon(const string &input, char delimiter)
// {
//     vector<string> result;
//     istringstream iss(input);
//     string token;

//     while (getline(iss, token, delimiter))
//     {
//         result.push_back(token);
//     }

//     return result;
// }

// int main()
// {
//     int numDishes;
//     cin >> numDishes;

//     vector<string> dishStrings(numDishes);

//     for (int i = 0; i < numDishes; ++i)
//     {
//         cin >> dishStrings[i];
//     }

//     int totalPositiveRatings = 0;

//     for (int i = 0; i < numDishes; ++i)
//     {
//         vector<string> parts = splitTheDishByColon(dishStrings[i], ':');

//         if (parts.size() == 2 && parts[1].find('-') == string::npos)
//         {
//             totalPositiveRatings += stoi(parts[1]);
//         }
//     }

//     cout << totalPositiveRatings << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeGems(vector<pair<int, int>> &dishes)
{
    sort(dishes.begin(), dishes.end());

    int maxGemsMax = 0, maxGemsMin = 0;
    int currentSumMax = 0, currentSumMin = 0;

    for (const auto &dish : dishes)
    {
        int dishId = dish.first;
        int rating = dish.second;

        if (rating >= 0)
        {
            currentSumMax += rating;
            currentSumMin -= abs(rating);
        }
        else
        {
            currentSumMax -= abs(rating);
            currentSumMin += rating;
        }

        maxGemsMax = max(maxGemsMax, currentSumMax);
        maxGemsMin = max(maxGemsMin, currentSumMin);
    }

    return max(maxGemsMax, maxGemsMin);
}

int main()
{
    vector<pair<int, int>> dishes = {{6, -3}, {2, 10}, {8, 63}, {-4, 5}, {1, -92}, {-12, 9}, {10, 10}};
    int maxGems = maximizeGems(dishes);

    cout << "Maximum number of gems: " << maxGems << endl;

    return 0;
}
