#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int n)
{
    int profit[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;
    // 1st Transaction
    int maxPrice = price[n - 1];
    for (int i = n - 2; i >= 0; i--){
        if (price[i] > maxPrice)
            maxPrice = price[i];
        profit[i] = max(maxPrice - price[i],profit[i+1]);
    }
    // 2nd Transaction
    int minPrice = price[0];
    for (int i = 1; i < n; i++){
        if(minPrice > price[i]){
            minPrice = price[i];
        }
        profit[i] = max(profit[i - 1],profit[i] + (price[i] - minPrice));
    }
    return profit[n - 1];
}
int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}