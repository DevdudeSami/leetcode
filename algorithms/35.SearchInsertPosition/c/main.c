#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] >= target) return i;
    }
    return numsSize;
}

int main(void) {
		int nums[] = {1,3,5,6};
		int numsSize = 4;
		int target = 5;
		printf("%d\n", searchInsert(nums, numsSize, target));
		return 0;
}