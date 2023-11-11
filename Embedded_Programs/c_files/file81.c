#include <stdio.h>
 
int main() {
    int arr[] = {2, 4, 6, 8};
    int arrLen = sizeof arr / sizeof arr[0];
     
    for (int i = 0; i < arrLen; i++) {
        printf("%d\n", arr[i]);
    }
     
    return 0;
}
