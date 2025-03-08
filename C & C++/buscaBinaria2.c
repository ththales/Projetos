#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target) {
    int left = 0, right = numsSize-1, mid;
    while(left<=right) {
        mid = (left+right)/2;
        if(nums[mid]<target)
            left = mid+1;
        else {
            if(nums[mid]>target)
                right = mid-1;
            else
                return mid;
        }
    }
    return right+1;
}

int main() {
    int size;
    printf("Size: ");
    scanf("%d", &size);
    int vet[size], result, numTarget;
    for(int i=0; i<size; i++) {
        printf("vet[%d]:", i);
        scanf("%d", &vet[i]);
    }
    printf("Target: ");
    scanf("%d", &numTarget);
    result = searchInsert(vet, size, numTarget);
    printf("%d", result);
}