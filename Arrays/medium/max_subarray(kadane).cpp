class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            // kadane's algorithm
            // it keeps on adding in a loop till it gets sum less than 0
            // if got less than 0 it sum = 0
            // at the same time it does find the max
    
            int sum = 0;
            int maximum = INT_MIN;
            for(int i=0; i<nums.size(); i++){  // step 1 loop the array
                sum += nums[i];                // step 2 add every el in sum
                maximum = max(sum, maximum);
                if(sum < 0) sum = 0;         // step 3 if sum < 0 sum = 0 so that loop can start with new sum
            }
            return maximum;
        }
    };

// to find the indexes of subaaray
vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
int sum = 0;
int start = 0; int end = 0;
int maximum = INT_MIN;
for(int i=0; i<nums.size(); i++){
    if(sum == 0) start = i;   // it will always start with sum 0
    sum += nums[i];
    if(sum > maximum){
        maximum = sum;    // always end with getting a maximum
        end = i;
    }
    if(sum < 0) sum = 0;
    
}
cout << start << " " << end << " " << maximum;

