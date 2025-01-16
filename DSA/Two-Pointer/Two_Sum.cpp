#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class TwoSUM {
	public:
		bool Two_Sum (vector<int>&nums, int target){
			// check if array size  is less than 2
			if (nums.size()<2) return false;
			//to use two pointer, we ned t sort the array
			sort(nums.begin(), nums.end());
			//always put left pointer on 1st index and right on last index
			int left = 0;
			int right = nums.size()-1;
			while (left<right){
				int sum = nums[left] + nums[right];
				if (sum == target) return true;
				else if (sum < target){
					left++;
				}
				else {
					right--;
				}
			}
			return false;
		}
};

int main(){
	vector<int> vec = {2, 4, -6, 8, 5, 6, 3, 9};
	int target_sum = 0;
	bool ans; 
	TwoSUM check_target;
	ans = check_target.Two_Sum(vec, target_sum);
	if (ans){
		cout<<"True"<<endl;
	}
	else{
		cout<<"False"<<endl;
	}
}
