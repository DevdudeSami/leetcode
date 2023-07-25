#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int maxArea(int* height, int heightSize){
    // brute force
    int max_area = 0;

    for(int i = 0; i < heightSize; i++) {
        for(int j = i; j < heightSize; j++) {
            int area = min(height[i], height[j]) * (j-i);
            if(area > max_area) {
                max_area = area;
            }
        }
    }

    return max_area;
}

int main() {
		int height[] = {1,8,6,2,5,4,8,3,7};
		int heightSize = 9;
		printf("%d\n", maxArea(height, heightSize));
		return 0;
}