#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<pair<pair<int, int>, int>> stockData;
    for (int i = 0; i < num; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        stockData.push_back({{a, b}, c});
    }

    int m;
    cin >> m;

    int realizedPL = 0;
    int UnRealizedPL = 0;
    vector<vector<int>> stockPrices;
    for (int i = 0; i < num; ++i)
    {
        vector<int> priceArray;
        for (int j = 0; j < m; ++j)
        {
            int value;
            cin >> value;
            priceArray.push_back(value);
        }
        stockPrices.push_back(priceArray);
    }

    int day;
    cin >> day;
    for (int i = 0; i < num; ++i)
    {
        int quantity, startDay, endDay;
        quantity = stockData[i].first.first;
        startDay = stockData[i].first.second;
        endDay = stockData[i].second;
        if (startDay > day)
            continue;
        else if (endDay > day || !endDay)
            UnRealizedPL += quantity * (stockPrices[i][day - 1] - stockPrices[i][startDay - 1]);
        else
            realizedPL += quantity * (stockPrices[i][endDay - 1] - stockPrices[i][startDay - 1]);
    }

    cout << realizedPL << endl;
    cout << UnRealizedPL;

    return 0;
}
