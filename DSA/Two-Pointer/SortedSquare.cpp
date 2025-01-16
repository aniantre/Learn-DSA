#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> sorted_square(vector<int>&nums){
      //create a new array ro store all element after squaring
      vector<int> result(nums.size());
      int left = 0;
      int right = nums.size()-1;
      //create move ptr initially points to last index of new array(result)
      //and then it will store the biggest number after squaring 
      //and then it will shift to left
      int move_ptr = result.size()-1;
      while(left<=right){
        if(abs(nums[left])>abs(nums[right])){
              result[move_ptr] = nums[left]*nums[left];
              left++;
          }
          else{
              result[move_ptr] = nums[right]*nums[right];
              right--;
          }
          move_ptr--;
      }
      return result;
    }
};

int main(){
  vector<int> vec = {-6, -4, 2, 3, 7, 10};
  vector<int> ans;
  Solution sortedsquare;
  ans = sortedsquare.sorted_square(vec);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
