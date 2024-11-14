#include <iostream>
#include <cassert>

void pattern( unsigned int n );
unsigned int log10( unsigned int n );
unsigned int count( unsigned int n, unsigned int bit );
unsigned int swap_bytes( unsigned int n, unsigned int b0, unsigned int b1 );


void pattern(unsigned int n){
    for(unsigned int i = 0; i< n*2+1;i++){
        unsigned int val = n - abs((int)n - (int)i);
        for(unsigned int j = 0; j< n*2+1;j++){
            if(j >= val && j <= n*2-val){
                std::cout << "*";
            }else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

unsigned int log10( unsigned int n){
    assert(n != 0);
    
    unsigned long long exp = 10;
    int m = 1;

    while (exp <= n){
        m++;
        exp = exp * 10;
    }
    
    return m-1;
}

unsigned int count( unsigned int n, unsigned int bit ){
    assert(bit == 0 || bit == 1);
    unsigned int counter = 0;
    for (int i = 0; i<32;i++){
        if ((n & 1) == bit){
            ++counter;
        }
        n >>= 1;
    } 
    return counter;
}



unsigned int swap_bytes( unsigned int n, unsigned int b0, unsigned int b1 ){
    assert(b0 >= 0 && b0 <= 3);
    assert(b1 >= 0 && b1 <= 3);

    if (b0 == b1){
        return n;
    }

    unsigned int byte1 = (n >> (b0 * 8)) & 0xFF;
    unsigned int byte2 = (n >> (b1 * 8)) & 0xFF;

    n &= ~(0xFF << (b0*8));
    n &= ~(0xFF << (b1*8));

    n |= (byte2 << (b0*8));
    n |= (byte1 << (b1*8));

    return n;
}


int main(){
    pattern(5);
    std::cout << log10(2147483647) << std::endl;
    std:: cout << count(0x6ab68582, 0) << std::endl;
    std::cout << swap_bytes(0b1000000000000001, 0, 1) << std::endl;
    return 0;
} 