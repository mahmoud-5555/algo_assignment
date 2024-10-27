/**
 * this modules for heap
 * mahmoudadam5555@gmail.com
 */


 //lib
#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

//classes

template <class T>
class Heap {
private:
    std::vector <T> data; // Internal storage for heap elements

    static bool lessThan(T a, T b) {
        return a < b;
    }
    static bool greaterThan(T a, T b) {
        return a > b;
    }
    bool (*comp)(T a, T b);

    // Private method to swap two elements
    void swap(T* element1, T* element2);


public:
    //constructor
    Heap(bool isMaxHeap = true);
    Heap(T array[], int size, bool isMaxHeap = true); // buled from an array
    Heap(bool(* comfun)(T, T)); // Constructor to initialize heap from an array
    Heap(T array[],int size, bool(* comfun)(T, T)); // Constructor to initialize heap from an array

    //heap Opratetion
    bool empty();
    void push(T); // insert element to heap
    T pop(); // pop element from heap abd return the value
    T root(); // get the root value
    unsigned int size();// return number of nodes at the heap

    void heapfy(int index);
    void max_min_heapfy(int index);

    void maxHeapify(int i, int n)
    vector<T> HeapSort();
};

#endif
