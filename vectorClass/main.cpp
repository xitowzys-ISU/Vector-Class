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
    
    Array<Array<int>> arr(4);

    
    for(int i=0; i<10; i++){
        arr.insert(Array<int>());
        for (int j = 0; j < 10; j++)
            arr[i].insert(j);
    }
    
    std::cout<<arr[1][4]<<std::endl;
    
    arr[1].remove(4);
    
    std::cout<<arr[1][4]<<std::endl;
    
    
    
//    std::cout<<arr<<std::endl;
//    arr[4] =  Array<int>();
//    arr[4].insert(10);
//    std::cout<<arr<<std::endl;
//    for (int i = 0; i< 7; i++)
//        arr.insert(Array<int>());
//    std::cout<<arr<<std::endl;
//    for (int i = 0; i<3; i++)
//        arr.remove(0);
//    std::cout<<arr<<std::endl;
//
//    for (int i = 0; i < 4; i++)
//        arr.insert(i + 1);
//    std::cout << arr << std::endl;
//
//    for (int i = 0; i < 8; i += 2)
//        arr.insert(10 + i, i);
//    std::cout << arr << std::endl;
//
//    for (int i = 1; i < 8; i += 2)
//        arr[i] = 20 + i;
//    std::cout << arr << std::endl;
//
//    for (int i = 6; i >= 0; i -= 3)
//        arr.remove(i);
//    std::cout << arr << std::endl;

    return 0;
}
