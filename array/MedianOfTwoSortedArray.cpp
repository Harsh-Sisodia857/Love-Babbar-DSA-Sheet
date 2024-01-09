class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        double idx1 = n / 2;
        double idx2 = idx1 - 1;
        cout << idx1 << " " << idx2 << endl;
        double ele1 = 0, ele2 = 0, i = 0, j = 0, cnt = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
            {
                if (cnt == idx1)
                    ele1 = nums1[i];
                if (cnt == idx2)
                    ele2 = nums1[i];
                cnt++;
                i++;
            }
            else
            {
                if (cnt == idx1)
                    ele1 = nums2[j];
                if (cnt == idx2)
                    ele2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while (i < n1)
        {
            if (cnt == idx1)
                ele1 = nums1[i];
            if (cnt == idx2)
                ele2 = nums1[i];
            cnt++;
            i++;
        }
        while (j < n2)
        {
            if (cnt == idx1)
                ele1 = nums2[j];
            if (cnt == idx2)
                ele2 = nums2[j];
            cnt++;
            j++;
        }
        cout << ele1 << " " << ele2;
        if (n % 2)
        {
            return ele1;
        }
        return (ele1 + ele2) / 2;
    }
};