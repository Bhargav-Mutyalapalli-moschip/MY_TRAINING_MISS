#include <stdio.h>
#define r 4
#define c 4

int main()
{   
    int a[2][3] = { { 1, 2, 3 },

                    { 5, 6, 7, }};

    int i, left = 0, right = c-1, top = 0, bottom = r-1;

    while (left <= right && top <= bottom) {

        /* Print the first row
        from the remaining rows */
        for (i = left; i <= right; ++i) {
            printf("%d ", a[top][i]);
        }
        top++;

        /* Print the last column
        from the remaining columns */
        for (i = top; i <= bottom; ++i) {
         printf("%d ", a[i][right]);
        }
        right--;
    
        /* Print the last row from
        the remaining rows */
        if (top <= bottom) { for (i = right; i >= left; --i) {
            printf("%d ", a[bottom][i]);
          }
          bottom--;
        }
    
        /* Print the first column from
        the remaining columns */
        if (left <= right) { for (i = bottom; i >= top; --i) {
            printf("%d ", a[i][left]);
        }
        left++;
        }
    }
    
    return 0;
}
