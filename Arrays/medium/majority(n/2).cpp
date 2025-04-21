class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            // Maps solution
            unordered_map<int,int> mpp;
            int target = nums.size()/2;
            //add count inside map
            for(int i = 0; i< nums.size(); i++){
                mpp[nums[i]] = mpp[nums[i]]+1;
                if(mpp[nums[i]] > target) return nums[i];
            }
            return 0;
    
            // ======================================================================
            // Boyre-More voting algorithm (this algo doesnt gaurantee a major element)
            // while looping take first element, increase count one by one
            // decrease if the next element is not that selected element
            // at any time you got count 0 means no major element present till that part of array
            // take the next element from the array and do the same process
            // once looping is done return the element( because this question gaurantees a major el)
            // (if it didnt gaurantees than loop again with the last el selected and check the count with n/2)
            // it will be obvious if there is no gaurantee than after checking the count there wont be any majority el
            
            int el = nums[0];
            int count = 1;
            for(int i=1; i<nums.size(); i++){
                if(count == 0){
                    el = nums[i];
                }
                if(el == nums[i]){
                    count++;
                }
                if(el != nums[i]) count--;
            }
            return el; // no need to loop to find if it is actually > n/2 because ques. gaurantees
        }
    };