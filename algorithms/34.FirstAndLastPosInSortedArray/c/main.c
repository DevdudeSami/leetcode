#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int index = numsSize/2;

    int first_index, last_index;

    if(numsSize <= 1) {
        if(numsSize == 0 || nums[0] != target) {
            first_index = -1;
            last_index = -1;
        } else {
            first_index = 0;
            last_index = 0;
        } 

        int *result = (int *)calloc(2, sizeof(int));
        result[0] = first_index;
        result[1] = last_index;
        
        *returnSize = 2;
        return result;
    }

    if(target == nums[index]) {
        // check before
        if(index != 0 && nums[index-1] == target) {
            int backwards_index = index;
            while(backwards_index >= 0) {
                if(nums[backwards_index] != target) break;
                backwards_index--;
            }
            first_index = backwards_index+1;
        } else first_index = index;
        // check after
        if(index != numsSize-1 && nums[index+1] == target) {
            int forwards_index = index;
            while(forwards_index < numsSize) {
                if(nums[forwards_index] != target) break;
                forwards_index++;
            }
            last_index = forwards_index-1;
        } else last_index = index;

        int *result = (int *)calloc(2, sizeof(int));
        result[0] = first_index;
        result[1] = last_index;
        
        *returnSize = 2;
        return result;
    }

    if(target > nums[index]) {
        int *result = searchRange(nums+index, numsSize-index, target, returnSize);
        if(result[0] != -1) {
            result[0] += index;
            result[1] += index;
        }
        return result;
    } else {
        return searchRange(nums, index, target, returnSize);
    }
    
}

int main() {
		int nums[] = {5,7,7,8,8,10};
		int numsSize = 6;
		int target = 8;
		int returnSize;
		int *result = searchRange(nums, numsSize, target, &returnSize);
		printf("result: %d, %d\n", result[0], result[1]);
		free(result);
		return 0;
}