#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

        std::string
        toggle(const std::string &num)
{
    std::string result = "";
    for (char bit : num)
    {
        if (bit == '0')
        {
            result += '1';
        }
        else
        {
            result += '0';
        }
    }
    return result;
}

std::pair<int, std::vector<int>> get_max_sum(std::vector<int> &arr, int k)
{
    int max_val = *std::max_element(arr.begin(), arr.end());
    auto max_index = std::distance(arr.begin(), std::find(arr.begin(), arr.end(), max_val));
    int left = std::max(0, static_cast<int>(max_index) - k);
    int right = std::min(static_cast<int>(arr.size()) - 1, static_cast<int>(max_index) + k);

    std::vector<int> selected(arr.begin() + left, arr.begin() + max_index + 1);
    selected.insert(selected.end(), arr.begin() + max_index, arr.begin() + right + 1);
    arr.erase(std::remove_if(arr.begin(), arr.end(),
                             [&selected](int x)
                             { return std::find(selected.begin(), selected.end(), x) != selected.end(); }),
              arr.end());

    int sum_selected = accumulate(selected.begin(), selected.end(), 0);
    return std::make_pair(sum_selected, arr);
}

int main()
{
    std::vector<int> arr;
    int a1, b1, a2, b2, k;
    int sum1 = 0, sum2 = 0;

    // Input
    int num;
    while (std::cin >> num)
    {
        arr.push_back(num);
    }

    std::cin >> a1 >> b1 >> a2 >> b2 >> k;

    while (!arr.empty())
    {
        auto temp1 = get_max_sum(arr, k);
        int s1 = temp1.first;
       
        sum1 += s1;

        if (arr.empty())
        {
            break;
        }

        auto temp2 = get_max_sum(arr, k);
         int s2 = temp2.first;
         sum2 += s2;
    }

    if (sum1 > sum2)
    {
        a1 = std::stoi(toggle(std::to_string(a1)), nullptr, 2);
        b2 = std::stoi(toggle(std::to_string(b2)), nullptr, 2);
    }
    else
    {
        a2 = std::stoi(toggle(std::to_string(a2)), nullptr, 2);
        b1 = std::stoi(toggle(std::to_string(b1)), nullptr, 2);
    }

    int xor1 = a1 ^ b1;
    int xor2 = a2 ^ b2;

    if (xor1 > xor2)
    {
        std::cout << "Rahul";
    }
    else if (xor2 > xor1)
    {
        std::cout << "Rupesh";
    }
    else
    {
        std::cout << "both";
    }

    return 0;
}
