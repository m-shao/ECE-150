#include <iostream>
#include <cassert>

/*
    returns the address
    of a dynamically allocated array of double that stores the values a, ar, ar2, ar3, up to arn−1 where r is the
    ratio and n is the capacity of the array.
 */
double *geometric( double a, double ratio, std::size_t cap );

/*
will return a dynamically allocated array of capacity cap0 + cap1 - 1. With each entry of this new array
initialized to zero, you will then calculate each pair of products array0[i]*array1[j] and add this to the
result at index i + j. You may assert that cap0 + cap1 >= 1
*/
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);

/*
will move
duplicate entries to the end of the array. The unique entries will be moved to the front of the array in the
same order that they first appear, while the duplicate entries will be moved to the end of the array, but the
order does not matter. The value returned will be the number of unique entries.
*/
std::size_t shift_duplicates( int array[], std::size_t capacity);

/*
1. If is_array is true, then you will loop through the array setting each entry to zero. The third argument
will contain the capacity of the array. You will then deallocate that memory.

2. Otherwise, it is not an array, so it is just a pointer to one instance of type double. You will set that
entry to zero and the third argument will be ignored.
In both cases, the last action you will take is to set ptr to nullptr
*/
void deallocate( double *&ptr, bool is_array, std::size_t capacity = 0);

void printArr(int arr[], int cap){
    for (int i = 0;i<cap;i++){
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void printArr(double arr[], int cap){
    for (int i = 0;i<cap;i++){
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

double *geometric( double a, double ratio, std::size_t cap ){
    double *arr{ new double[cap]};
    for (int i = 0; i<cap; i++){
        arr[i] = a;
        for (int j = 0;j<i;j++){
            arr[i] *= ratio;
        }
         
    }
    return arr;
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){
    assert(cap0 + cap1 - 1 >= 1);
    double *arr{new double[cap0 + cap1 - 1]{}};
    for (int i = 0;i<cap0;i++){
        for (int j = 0; j<cap1;j++){
            arr[i + j] += array0[i]*array1[j];
        }
    }
    return arr;
}

std::size_t shift_duplicates( int array[], std::size_t capacity){
    if (capacity == 0){
        return 0;
    } else if(capacity == 1){
        return 1;
    }
    int found[capacity - 1]{};
    int unique[capacity - 1]{};
    int uniqueCap{0};
    int foundCap{0};
    bool foundDup;
    for (int i{0};i<capacity;i++){
        foundDup = false;
        for (int j{0};j<uniqueCap;j++){
            if (array[i] == unique[j]){
                foundDup = true;
                found[foundCap++] = array[i];
                break;
            }
        }
        if (!foundDup){
            unique[uniqueCap++] = array[i];
        }
    }
    int cumsum{0};
    for (int i{0};i<uniqueCap;i++){
        array[cumsum++] = unique[i];
    }
    for (int i{0};i<foundCap;i++){
        array[cumsum++] = found[i];
    }

    return uniqueCap;
}

void deallocate( double *&ptr, bool is_array, std::size_t capacity){
    if (is_array){
        for (int i{0};i< capacity;i++){
            ptr[i] = 0;
        }
        delete[] ptr;
    } else {
        *ptr = 0;
        delete ptr;  
    }
    ptr = nullptr;
}

int main () {
    // int cap = 10;
    // int arr[cap] = {5, 4, 2, 2, 2, 4, 5, 1, 4, 3};
    // std::cout << shift_duplicates(arr, cap) << std::endl;
    // printArr(arr, cap);
    int cap0 = 3;
    double arr0[cap0] = {1,2,3};
    int cap1 = 3;
    double arr1[cap1] = {3,2,1};

    printArr(cross_correlation(arr0, cap0, arr1, cap1), cap0 + cap1 - 1);


    return 0;
}


#include <iostream>
#include <cassert>

double *geometric(double a, double ratio, std::size_t cap); 
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1); 
std::size_t shift_duplicates(int array[], std::size_t capacity); 
void deallocate(double *&ptr, bool is_array, std::size_t capacity); 

int main () {
    return 0; 
}

double *geometric(double a, double ratio, std::size_t cap) {
    double *array = ; 

    array[0] = a; 
    for (int i = 1; i < cap; ++i) {
        array[i] = array[i-1] * ratio; 
    }

    return array; 
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    assert(cap0 + cap1 >= 1); 

    double *array = new double[cap0 + cap1 - 1](); 

    for (int i = 0; i < cap0; ++i) {
        for (int j = 0; j < cap1; ++j) {
            array[i + j] += array0[i] * array1[j]; 
        }
    }

    return array; 
}

std::size_t shift_duplicates(int array[], std::size_t capacity) {
    int unique[capacity], duplicate[capacity]; 
    for (int i = 0; i < capacity; ++i) {
        unique[i] = array[i]; 
        duplicate[i] = array[i]; 
    }

    for (int i = 0; i < capacity; ++i) {
        bool isDuplicate = false; 
        for (int j = 0; j < capacity; ++j) {
            if (j != i && array[i] == array[j]) {
                unique[j] = -1; 
                isDuplicate = true; 
            }
        }

        if (isDuplicate) {
            unique[i] = -1; 
        }
        else duplicate[i] = -1; 
    }

    int uniques = 0; 
    for (int i = 0; i < capacity; ++i) {
        if (unique[i] != -1) {
            array[uniques] = unique[i]; 
            ++uniques; 
        }
    }

    int duplicates = 0; 
    for (int i = 0; i < capacity; ++i) {
        if (duplicate[i] != -1) {
            array[uniques + duplicates] = duplicate[i]; 
            ++duplicates; 
        }
    }

    return uniques; 
}

void deallocate(double *&ptr, bool is_array, std::size_t capacity) {
    if (is_array) {
        for (int i = 0; i < capacity; ++i) {
            ptr[i] = 0; 
        }

        delete[] ptr; 
    } else {
        *ptr = 0; 

        delete ptr; 
    }

    ptr = nullptr; 
}