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
    std::vector <T> *DATA; // Internal storage for heap elements

        bool defaultCompare(T a, T b) {
        return a <= b;  // Adjust for max-heap if needed
    }

    bool (*comp)(T a, T b) = defaultCompare(); // comparison function

    // Private method to swap two elements
    void swap (T *element1, T *element2); 


    public:
    //constructor
    Heap();// default Constructor
    Heap(T array[], int size); // buled from an array
    Heap(T array[], bool *comfun(T, T)); // Constructor to initialize heap from an array

    //heap Opratetion

    void push(T); // insert element to heap
    T pop(); // pop element from heap abd return the value
    T root(); // get the root value
    unsigned int size();// return number of nodes at the heap

    void heapfy(int index, bool *comfun(T, T));
    void max_min_heapfy(int index, bool *comfun(T, T));
};

#endif
