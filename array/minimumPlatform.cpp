// using heap

int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, int>> trains(n);
    for (int i = 0; i < n; i++)
    {
        trains[i] = {arr[i], dep[i]};
    }

    sort(trains.begin(), trains.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(trains[0].second);
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (pq.top() >= trains[i].first)
        {
            count++;
        }
        else
        {
            pq.pop();
        }
        pq.push(trains[i].second);
    }

    return count;
}

// using sorting
// The idea is to consider all events in sorted order.Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, but not departed.

// Illustration: 

// arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
// dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

// All events are sorted by time.

// Total platforms at any time can be obtained by subtracting total departures from total arrivals by that time.

//  Time      Event Type     Total Platforms Needed at this Time
//  9:00       Arrival                  1
//  9:10       Departure                0
//  9:40       Arrival                  1
//  9:50       Arrival                  2
//  11:00      Arrival                  3 
//  11:20      Departure               2
//  11:30      Departure               1
//  12:00      Departure               0
//  15:00      Arrival                 1
//  18:00      Arrival                 2 
//  19:00      Departure               1
//  20:00      Departure               0

// Minimum Platforms needed on railway station = Maximum platforms needed at any time = 3

int findPlatform(int arr[], int dep[], int n)
{

    sort(arr, arr + n);
    sort(dep, dep + n);
    int count = 0;
    int ans = INT_MIN;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        ans = max(ans, count);
    }
    return ans;
}