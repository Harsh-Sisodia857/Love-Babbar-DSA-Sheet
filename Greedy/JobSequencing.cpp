#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    // Custom comparator to sort jobs by profit in descending order
    static bool cmp(Job &a, Job &b)
    {
        return a.profit > b.profit;
    }

    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // Sort the jobs by profit in descending order
        sort(arr, arr + n, cmp);

        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // Create a vector to track job deadlines, initialized with -1
        vector<int> deadline(maxDeadline + 1, -1);

        int countOfJobs = 0;
        int currProfit = 0;

        // Iterate through the sorted jobs
        for (int i = 0; i < n; i++)
        {
            int k = arr[i].dead;

            // Check for available slots in reverse order (earlier deadlines first)
            for (int j = k; j > 0; j--)
            {
                if (deadline[j] == -1)
                {
                    countOfJobs++;
                    deadline[j] = arr[i].id;     // Mark the job as scheduled
                    currProfit += arr[i].profit; // Update the current profit
                    // if schedule of job is found then break the loop
                    break;
                }
            }
        }

        // Create a vector to store the count of jobs and the total profit
        vector<int> ans;
        ans.push_back(countOfJobs);
        ans.push_back(currProfit);
        return ans;
    }
};

// Driver program to test methods
int main()
{
    int t;
    // Number of test cases
    cin >> t;

    while (t--)
    {
        int n;
        // Size of the array
        cin >> n;
        Job arr[n];

        // Adding id, deadline, profit for each job
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }

        Solution ob;
        // Function call to find the maximum profit and number of jobs done
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
