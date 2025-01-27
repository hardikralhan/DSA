class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> stt;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> forSorting = {nums[i], nums[j], nums[k]}; // put in vector
                        sort(forSorting.begin(), forSorting.end()); // then sort
                        stt.insert(forSorting);
                    }
                }
            }
        }
        vector<vector<int>> result(stt.begin(), stt.end());
        return result;
    }
};

// hash set

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> stt;
        for(int i=0; i<nums.size(); i++){
            set<int> hashset;              // declare here so that new set is applied in every loop
            for(int j=i+1; j<nums.size(); j++){
                int moreNeeded = 0 - (nums[i]+nums[j]);
                if(hashset.find(moreNeeded) != hashset.end()){ //if found then add in set after sorting
                    vector<int> temp = {nums[i],nums[j],moreNeeded};
                    sort(temp.begin(),temp.end());
                    stt.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> result(stt.begin(), stt.end());
        return result;
    }
};


// two pointer -- need to do to again IMP------

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}