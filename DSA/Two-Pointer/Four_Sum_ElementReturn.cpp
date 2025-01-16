#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class FourSUM {
  public:
    vector<vector<int>> Four_Sum (vector<int>&nums, int target){
      // check if array size  is less than 4
      if (nums.size()<4) return {};
      //to use three pointer, we need to sort the array
      sort(nums.begin(), nums.end());
            vector<vector<int>> result;
      //always put left pointer on 1st index and right on last index
      for (int First_Pointer = 0; First_Pointer<nums.size()-3; First_Pointer++){
        //to avoid element duplicasy
        if (First_Pointer>0 && nums[First_Pointer] == nums[First_Pointer-1]) continue;
        for (int second_pointer = First_Pointer+1; second_pointer<nums.size()-2; second_pointer++){
          //to avoid element duplicasy
          if (second_pointer>First_Pointer+1 && nums[second_pointer] == nums[second_pointer-1]) continue;
          int left = second_pointer+1;
          int right = nums.size()-1;
          while (left<right){
            int sum = nums[First_Pointer] + nums[second_pointer] + nums[left] + nums[right];
            if (sum == target){
              result.push_back({nums[First_Pointer], nums[second_pointer], nums[left], nums[right]});
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
      }
      return result;
    }
};

int main(){
  vector<int> vec = {2, 4, -6, 8, 5, 6, 3, 9};
  int target_sum = 19;
  //bool ans;
    vector<vector<int>> ans;
  FourSUM check_target;
  ans = check_target.Four_Sum(vec, target_sum);
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
