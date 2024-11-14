#include "p_4_header.hpp"
#include <iostream>

std::size_t length( char const *a ){
    int i{0};
    char curr{a[0]};
    for (i;curr!='\0';i++){
        curr = a[i];
    }
    if (i != 0) return i - 1;
    return i;
}

int compare( char const *str1, char const *str2 ){
    int i{0};
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            if (str1[i] < str2[i]){
                return -1;
            } else{
                return 1;
            }
        }
        ++i;
    }
    if (str1[i] == str2[i]) return 0;
    else if (str1[i] == '\0') return -1;
    return 1;
}

void assign( char *str1, char const *str2 ){
    int i{0};
    while (str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

unsigned int distance( char const *str1, char const *str2 ){
    return 0;
}

std::size_t is_sorted( char *array[], std::size_t capacity ){
    if (capacity == 0) return 0;
    for (int i{0};i<capacity - 1;++i){
        if (compare(array[i], array[i + 1]) > 0){
            return i + 1;
        }
    }
    return capacity;
}


int main(){

    //1. length test
    // char test_string[21] {""};
    // std::cout << "The length of " << test_string << " is " << length(test_string) << std::endl;


    //2. compare test
    // char str1[21] {""};
    // char str2[21] {""};
    // std::cout << compare(str1, str2);


    //3. assign test
    // char str1[21] {"he"};
    // char str2[21] {""};
    // assign(str1, str2);
    // std::cout << str1;


    //4. distance test


    //5. is_sorted test
    // char* sortedArray[] = {(char*)"banana"};
    // std::size_t result = is_sorted(sortedArray, 1);
    // std::cout << result;
    // assert(result == 3); // Expect capacity since the array is sorted

    


    return 0;
}