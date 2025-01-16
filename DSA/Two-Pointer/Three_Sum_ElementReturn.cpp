#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class ThreeSUM {
  public:
    vector<vector<int>> Three_Sum (vector<int>&nums, int target){
      // check if array size  is less than 3
      if (nums.size()<3) return {};
      //to use three pointer, we need to sort the array
      sort(nums.begin(), nums.end());
            vector<vector<int>> result;
      //always put left pointer on 1st index and right on last index
      for (int fixed_Pointer = 0; fixed_Pointer<nums.size()-2; fixed_Pointer++){
        if (fixed_Pointer>0 && nums[fixed_Pointer] == nums[fixed_Pointer-1]) continue;
        int left = fixed_Pointer+1;
        int right = nums.size()-1;
        while (left<right){
          int sum = nums[fixed_Pointer] + nums[left] + nums[right];
          if (sum == target){
            result.push_back({nums[fixed_Pointer], nums[left], nums[right]});
            left++;
            right--;
            while(left<right && nums[left] == nums[left-1]) left++;
            while(left<right && nums[right] == nums[right+1]) right--;
          }
          else if (sum < target){
            left++;
          }
          else {
            right--;
          }
        }
      }
      return result;
    }
};

int main(){
  vector<int> vec = {2, 4, -6, 8, 5, 6, 3, 9};
  int target_sum = 0;
  //bool ans;
    vector<vector<int>> ans;
  ThreeSUM check_target;
  ans = check_target.Three_Sum(vec, target_sum);
    for (int i = 0; i<ans.size(); i++){
        for (int j = 0; j<ans[i].size(); j++){
          cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
  // if (ans){
  // 	cout<<"True"<<endl;
  // }
  // else{
  // 	cout<<"False"<<endl;
  // }
}
