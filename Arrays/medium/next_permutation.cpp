class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // step 1 - find the dip
            // start loop from end(n-2) 
            // and find number less than i+1 then break
        int n = nums.size();
        int index = -1;  // to store dip value
        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }

        // step 2 - find the greatest nearest to that index number
            // if didnt found means we are on the last [5,4,3,2,1]
            // so then just reverse pr sort
            // else swap index with greatest nearest
        if(index != -1){
            for(int i= n-1; i>index; i--){
                // return greatest number from index
                if(nums[i]>nums[index]){
                    // swap and break
                    int temp = nums[i];
                    nums[i] = nums[index];
                    nums[index] = temp;
                    break;
                }
            }  
        }else{
            sort(nums.begin(), nums.end());
            return;
        }

        // step 3 reverse the numbers which are after dip
        reverse(nums.begin() + index + 1, nums.end());
        return;
    }
};