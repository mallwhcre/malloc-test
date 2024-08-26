#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int* allocate_array(int size);
void fill_array(int* arr, int size);
void print_array(int* arr, int size);
void double_values(int* arr, int size);
int* resize_array(int* arr, int old_size, int new_size);
void fill_newArray(int* arr, int old_size, int new_size);

int main() {
    int size, new_size;
    int *array = NULL;

    // Step 1: Dynamic Array Allocation
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    array = allocate_array(size);
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Step 2: Input and Output
    fill_array(array, size);
    printf("Original array: ");
    print_array(array, size);

    // Step 3: Memory Reallocation
    printf("Enter the new size of the array: ");
    scanf("%d", &new_size);

    array = resize_array(array, size, new_size);
    if (array == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }
    else{

    }
    fill_newArray(array,size,new_size);
    // Wait for user input before closing
    printf("Press Enter to exit...");
    getchar(); // This will consume the leftover newline character from the previous input
    getchar(); // This will wait for the user to press Enter
    printf("Resized array: ");

    print_array(array, new_size);

   

    // Step 4: Freeing Memory
    free(array);
    printf("Memory successfully freed.\n");
    
    // Wait for user input before closing
    printf("Press Enter to exit...");
    getchar(); // This will consume the leftover newline character from the previous input
    getchar(); // This will wait for the user to press Enter

    return 0;
}

// Function to allocate memory for an array
int* allocate_array(int size) {
    return (int*)malloc(size * sizeof(int));
}

// Function to fill the array with user input
void fill_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to print the array
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Function to resize the array
int* resize_array(int* arr, int old_size, int new_size) {
    int* new_arr = (int*)realloc(arr, new_size * sizeof(int));
    
    if (new_arr == NULL) {
        return NULL;
    }
    /*Initialize new elements to 0 if the array has grown
     if (new_size > old_size) {
        for (int i = old_size; i < new_size; i++) {
            new_arr[i] = 0;
        }
    }
    */
    return new_arr;
}

void fill_newArray (int* arr, int old_size, int new_size){
//filling the new array elements

    if (new_size>old_size){
        for (int i= old_size; i<new_size; i++){
            printf("Enter new element %d: ", i+1);
            scanf("%d", &arr[i]);
            printf("\n!Element appended!\n");
        }
       // printf("Loop exited");
    }
    //printf("Function exited");
}
