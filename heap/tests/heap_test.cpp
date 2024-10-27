#include <iostream>
#include "../lib/heap.hpp"
#include "../src/heap.cpp"

using namespace std;

int main()
{
    // test heap
    // input [12, 4, 8, 11, 6, 3, 5]
    // push one by one
    Heap<int> myheap;

    myheap.push(12);
    myheap.push(4);
    myheap.push(8);
    myheap.push(11);
    myheap.push(6);
    myheap.push(3);
    myheap.push(5);

    vector<int> sortArray = myheap.HeapSort();
    for (int i = 0; i < 7; i++)
    {

        cout << sortArray[i] << " _ ";
    }
    cout << "\n";
    // test excute the max an the min of the heap:
    vector <int> max_min = myheap.max_min_from_Heap();
    for (int i = 0; i < 2; i++)
    {

        cout << max_min[i] << " _&&_ ";
    }
     cout << "\n";

    for (int i = 0; i < 7; i++)
    {

        cout << myheap.pop() << " _&&_ ";
    }
    cout << "\n";
    vector <int> max_min_empty = myheap.max_min_from_Heap();
    for (int i = 0; i < 2; i++)
    {

        cout << max_min_empty[i] << " _&&_ ";
    }
    
   
    return 0;
}
