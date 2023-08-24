#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int search(int* nums, int numsSize, int target){
    int prev = INT_MIN;
    bool passed_pivot = false;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == target) return i;
        if(!passed_pivot && nums[i] < prev) {
            passed_pivot = true;
        }
        if(passed_pivot) {
            if(nums[i] > target) return -1;
        }

        prev = nums[i];
    }

    return -1;
}

int main(void) {
		int nums[] = {4,5,6,7,0,1,2};
		int numsSize = 7;
		int target = 0;
		printf("%d\n", search(nums, numsSize, target));
		return 0;
}