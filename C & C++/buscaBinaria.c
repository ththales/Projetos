#include <stdio.h>

int main()
{
    int A[9] = {30, 70, 319, 350, 356, 388, 662, 888, 933}, key, left, right, mid;
    left = 0, right = 8;
    printf("Key: ");
    scanf("%d", &key);
    while(left<=right)
    {
        mid = (left+right)/2;
        if(A[mid]<key)
        {
            left = mid+1;
        }
        else
        {
            if(A[mid]>key)
            {
                right = mid-1;
            }
            else
            {
                printf("Key %d found at position %d.", key, mid);
                return 0;
            }
        }
    }
    printf("Key %d not found.", key);
    return 0;
}