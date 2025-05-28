class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        // brute force not passing all test cases
        //  int n=nums.size();
        //     vector<int>posNums;
        //     vector<int>negNums;
        //     // storing positive and negative elements in specific vectors
        //     for(int i=0; i<n; i++){
        //         if(nums[i]>0)
        //             posNums.push_back(nums[i]);
        //         else
        //             negNums.push_back(nums[i]);
        //     }

        //     // updating the original vector
        //     int i=0,j=0;
        //     while(i<n/2){
        //         nums[i] = posNums[j];
        //         nums[i+1] = negNums[j];
        //         i += 2;
        //         j++;
        //     }
        //     return nums;

        // optimizing
        int n = nums.size();
        vector<int> ans(n, 0);
        // positive elements start from 0 and negative from 1.
        int posIndex = 0, negIndex = 1;
        for (int i = 0; i < n; i++)
        {
            // fill positive elements in even indices and inc by 2.
            if (nums[i] > 0)
            {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
            // fill negative elements in odd indices and inc by 2.
            else
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};