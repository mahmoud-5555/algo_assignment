#include <iostream>
#include "../lib/heap.hpp"
#include "../src/heap.cpp"

using namespace std;



int main() {


    cout << "hallo c++";
    
    // test heap
    // input [12, 4, 8, 11, 6, 3, 5]
    // push one by one
    Heap <int> myheap;

    myheap.push(12);
    myheap.push(4);
    myheap.push(8);
    myheap.push(11);
    myheap.push(6);
    myheap.push(3);
    myheap.push(5);
    for(int i = 0; i < 7; i++)
    {
    
        cout << myheap.pop() << " _&&_ ";
    }
    

    return 0;
}
