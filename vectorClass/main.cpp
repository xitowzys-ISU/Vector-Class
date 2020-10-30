//
//  main.cpp
//  vectorClass
//
//  Created by xitowzys on 24.10.2020.
//

#include <iostream>
#include "array.hpp"
#include "array.cpp"

int main(int argc, const char * argv[]) {
    
    Array<int> arr(10);
    Array<int> arr2(10);
    
    for(int i = 0; i < 10; i++){
        arr.insert(i);
        arr2.insert(i * 23);
    }
    
    for(int i = 0; i < arr.getSize(); i++){
        std::cout<<arr[i]<<std::endl;
    }
    
    std::cout<<"--------------------------"<<std::endl;
    
    for(int i = 0; i < arr.getSize(); i++){
        std::cout<<arr2[i]<<std::endl;
    }
    
    std::cout<<"--------------------------"<<std::endl;
    
    arr.insert(7, arr2);
    
    for(int i = 0; i < arr.getSize(); i++){
        std::cout<<arr[i]<<std::endl;
    }
    
    return 0;
}
