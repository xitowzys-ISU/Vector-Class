//
//  main.cpp
//  vectorClass
//
//  Created by xitowzys on 24.10.2020.
//

#include <iostream>
#include "array.hpp"

int main(int argc, const char * argv[]) {

    Array arr(4);
    for (int i = 0; i < 4; i++)
        arr.insert(i + 1);
    std::cout << arr << std::endl;
    
    for (int i = 0; i < 8; i += 2)
        arr.insert(10 + i, i);
    std::cout << arr << std::endl;
    
    for (int i = 1; i < 8; i += 2)
        arr[i] = 20 + i;
    std::cout << arr << std::endl;
    
    for (int i = 6; i >= 0; i -= 3)
        arr.remove(i);
    std::cout << arr << std::endl;

    return 0;
}
