#include <stdio.h>

int main ()
{
    int n, i , a, low, high, mid;
    
    // n = no of elements
    // i = counter variable
    // a = element to find


    //getting the number of elements
    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    int array[n];
    //getting the elements of the array
    printf("Enter the elements in a sorted manner: \n");
    for(i = 0; i<n; i++)
    {
        scanf("%d", &array[i]);
    }

    //getting the element to find
    printf("Enter the value to find: \n");
    scanf("%d", &a);

    //initializing the values
    low = 0;
    high = n-1;
    mid = (low + high)/2;

    while(low<=high)
    {
        if(array[mid]<a)
        {
            low = mid + 1;
        }
        else if(array[mid] == a)
        {
            printf("%d found at the location %d\n", a, mid+1);
            break;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high)/2;
    }
    if (low>high)
    {
        printf("%d is not found\n", a);
    }


    return 0;
}














