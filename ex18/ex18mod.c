#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);

/**
 * A classic bubble sort function that uses the 
 * compare_cb to do the sorting. 
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int quick_part(int *numbers, int lo, int hi, compare_cb cmp)
{
    int temp = 0;
    int i = 0;

    int pivotIndex = lo + (hi - lo) / 2;
    int pivotValue = numbers[pivotIndex];

    temp = numbers[hi];
    numbers[hi] = pivotValue;
    numbers[pivotIndex] = temp;

    int storeIndex = lo;

    for(i = lo; i < hi; i++){
        if( cmp(pivotValue, numbers[i]) > 0 ){
            temp = numbers[i];
            numbers[i] = numbers[storeIndex];
            numbers[storeIndex] = temp;
            storeIndex++;
        }
    }
    // move pivot to final place
    temp = numbers[storeIndex];
    numbers[storeIndex] = numbers[hi];
    numbers[hi] = temp;
    
    return storeIndex;
}

int quick_recursion(int *numbers, int lo, int hi, compare_cb cmp)
{
    if ( lo < hi){
        int p = quick_part(numbers, lo, hi, cmp);
        quick_recursion(numbers, lo, p - 1, cmp);
        quick_recursion(numbers, p + 1, hi, cmp);
    }
    return 0;
}

int *quick_sort(int *numbers, int count, compare_cb cmp)
{
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    quick_recursion(target, 0, count - 1, cmp);

    return target;
}


int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}


// a typedef creates a fake type, in this
// case for a function pointer
typedef int* (*sort_type)(int *numbers, int count, compare_cb cmp);

/** 
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(sort_type s_fun, int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = s_fun(numbers, count, cmp);

    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    // quicksort
    /*
    int *sorted2 = quick_sort(numbers, count, cmp);

    if(!sorted2) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted2[i]);
    }
    printf("\n");
    */


    // print function area hexes
    unsigned char *data = (unsigned char *)cmp;

    for(i = 0; i < 25; i++) {
            printf("%02x:", data[i]);
    }

    printf("\n");

    free(sorted);
}


int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    printf("\n \tbubble sort\n====================\n");
    test_sorting(bubble_sort, numbers, count, sorted_order);
    test_sorting(bubble_sort, numbers, count, reverse_order);
    test_sorting(bubble_sort, numbers, count, strange_order);

    // quicksort test

    printf("\n \tquicksort\n====================\n");
    test_sorting(quick_sort, numbers, count, sorted_order);
    test_sorting(quick_sort, numbers, count, reverse_order);
    test_sorting(quick_sort, numbers, count, strange_order);
    
    
    free(numbers);

    return 0;
}
