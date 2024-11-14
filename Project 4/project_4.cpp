// #include <./p_4_header.hpp>
#include <iostream>

std::size_t     length( char const *a ){
    int i{-1};
    char curr{a[0]};
    for (i;curr!='\0';i++){
        curr = a[i];
    }
    return i;
}



int main(){
    char test_string[21] {""};

    // length
    std::cout << "The length of " << test_string << " is " << length(test_string) << std::endl;

    return 0;
}