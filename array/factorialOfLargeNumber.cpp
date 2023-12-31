// Ex - 5 ! = 5 * 4 * 3 * 2 * 1 
// 1 * 2 -- > 2  (2)
// 2 * 3 -- > 6  (6)
// 6 * 4 -- > 4 carry = 2  (2 --> 4)
// 5 * (2 --> 4)  =====>    120
//     1 (carry)  +  0 + 2(carry)    0 ==> 120
vector<int> factorial(int N)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int x = ans[j] * i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
