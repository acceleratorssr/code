#include <stdio.h>

int trap(int* height, int heightSize) {
    int left = 0, sum = 0;
    int right = heightSize - 1;
    if (right == 0) {
        return 0;
    }
    while (height[left] <= height[left + 1]) {
        left++;
        if (left == heightSize - 1) {
            return 0;
        }
    }
    while (height[right] <= height[right - 1]) {
        right--;
        if (right == 0) {
            return 0;
        }
    }
    if (left == right) {
        return 0;
    }
    int leftmax = height[left];
    int rightmax = height[right];
    while (left < right) {
        while (height[left] < height[right]) {
            left++;
            if (left == right) {
                break;
            }
            if (leftmax < height[left]) {
                leftmax = height[left];
            }
            if (leftmax > height[left]) {
                sum += leftmax - height[left];          
            }
        }
        
        while (height[left] == height[right] && left != right) {
            leftmax = rightmax;
            left++;
            if (left == right) {
                break;
            }
            if (leftmax > height[left]) {
                sum += leftmax - height[left];
            }
            if (rightmax > height[right]) {
                sum += rightmax - height[right];
            }
            if (leftmax < height[left]) {
                leftmax = height[left];
            }
        }
        
        while (height[left] > height[right]) {
            right--;
            if (left == right) {
                break;
            }
            if (rightmax < height[right]) {
                rightmax = height[right];
            }
            if (rightmax > height[right]) {
                sum += rightmax - height[right];
            }
        }
    }

    return sum;
}
int main() {
    int height[] = {5,4,2,5,7,8,6,2,9,1,6,9,1,0,3,7,7,7,3,4,7};
    int k = trap(height, 21);
    printf("%d", k);
}


   