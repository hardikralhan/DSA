class Solution {
    public:
        void sortColors(vector<int>& nums) {
            // sol 1
            // get count of 0, 1 and 2 and put them in the array (O(2N))
            int count0 = 0; int count1 = 0; int count2 = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == 0) count0++;
                else if(nums[i] == 1) count1++;
                else count2++;
            }
    
            for(int i = 0; i<count0; i++) nums[i] = 0;
            for(int i = count0; i< count0+count1; i++) nums[i] = 1;
            for(int i = count0 + count1; i< count0+count1+count2; i++) nums[i] = 2;

            //======================================================================
    
            // sol 2
            // dutch national flag algo (3 pointer)
            // check diagram by striver (in DA notebook)
            int low = 0; int mid = 0; int high = nums.size()-1;
            while(mid<=high){
                if(nums[mid] == 0){
                    // swap mid with low
                    int temp = nums[mid];
                    nums[mid] = nums[low];
                    nums[low] = temp;
                    low++; mid++;
                }
                else if(nums[mid] == 1) mid++;
                else if(nums[mid] == 2){
                    // swap mid with high
                    int temp = nums[mid];
                    nums[mid] = nums[high];
                    nums[high] = temp;
                    high--;
                }
            } 
    
        }
    };