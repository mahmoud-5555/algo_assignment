/**
 * source code of the classes
 * mahmoudadam5555@gmail.com
 */

#include "../lib/heap.hpp"
#include <stdexcept>
#include <algorithm>
using namespace std;

/**
 * swap - Extra function make swap between element
 * @element1: The address of the first element
 * @element2: The address of the second element
 * return: void
 */
template <class T>
void Heap<T>::swap(T *element1, T *element2)
{
    T temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

template <class T>
void Heap<T>::maxHeapify(int i, int n, std::vector<T> &sort)
{
    if (i == n)
        return;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l <= n && sort[i] < sort[l])
        largest = l;
    if (r <= n && sort[largest] < sort[r])
        largest = r;

    if (largest != i)
    {
        std::swap(sort[i], sort[largest]);
        maxHeapify(largest, n, sort);
    }
}

template <class T>
vector<T> Heap<T>::HeapSort()
{
    std::vector<T> sort = data;
    for (int i = data.size() - 1; i > 0; i--)
    {
        std::swap(sort[i], sort[0]);
        maxHeapify(0, i - 1, sort);
    }
    return sort;
}
/**
 * heapfy - Function is used for heapfy element it's
 * work from spcfic node and the go two parent node
 * @index: Is the index of the node at array
 * @comfun: Pointer to function that make the copmarson
 * this frist elemnt should be the child element and the secound
 * should be the parent element
 */
template <class T>
void Heap<T>::heapfy(int index)
{

    // check index in range
    if (index < 0 || index >= data.size())
        return;

    // check parent and swap if the parent is
    // < greater : maxheap, smallest : minheap>
    if (comp(data[index / 2], data[index]))
    {
        swap(&data[index], &data[index / 2]);
        // heapfy the parent
        heapfy(index / 2);
    }
}

/**
 * size - function that return number of element in heap
 * return: unsigned int the size
 */
template <class T>
unsigned int Heap<T>::size()
{
    return data.size();
}

/**
 * push - function that insert element and make heapfy
 * @element: the element that want to push
 * return: void
 */
template <class T>
void Heap<T>::push(T element)
{
    data.push_back(element);
    heapfy(size() - 1);
}
/**
 * pop - function that pop p from heap
 * return: element
 */
template <class T>
T Heap<T>::pop()
{
    // Check if there is node at the heap
    if (empty())
        throw runtime_error("Heap is empty, cannot pop element.");

    // make swap between the root and the last element
    swap(&data[0], &data[size() - 1]);

    // save the value at temp befor deleted
    T temp = data[size() - 1];

    // delete the element from data
    data.pop_back();

    // make down_heapfy starting from heap
    if (!empty())
    {
        max_min_heapfy(0);
    }

    // return the value that was at the root
    return temp;
}
template <class T>
bool Heap<T>::empty()
{
    return data.size() <= 0;
}
/**
 * root - function return the first priority without delete it
 * return: element
 */
template <class T>
T Heap<T>::root()
{
    if (empty())
        throw runtime_error("Heap is empty, cannot access root.");
    return data[0];
}

// The default  constructor of the heap
template <class T>
Heap<T>::Heap(bool isMaxHeap) : Heap(isMaxHeap ? lessThan : greaterThan) {}

template <class T>
Heap<T>::Heap(bool (*comfun)(T, T)) : comp(comfun) {}

template <class T>
Heap<T>::Heap(T array[], int size, bool isMaxHeap) : Heap(array, size,
                                                          isMaxHeap ? lessThan : greaterThan) {}

// build from an array
template <class T>
Heap<T>::Heap(T array[], int size, bool (*comfun)(T, T)) : comp(comfun)
{
    // Move element from the array to vector
    for (int i = 0; i < size; i++)
    {
        data.push_back(array[i]);
    }
    int non_leaf = (this->size() / 2) - 1;
    while (non_leaf >= 0)
    {
        max_min_heapfy(non_leaf);
        non_leaf--;
    }
}

/**
 * min_max_heapfy - function for make min_heap or maxheap depends on the function comp
 * return: void
 */
template <class T>
void Heap<T>::max_min_heapfy(int index)
{
    // Left - Right chiledren
    int left = (index * 2) + 1;
    int Right = (index * 2) + 2;
    int index_of_child_paiortize;

    // check if the lift node is outside the range of the heap
    if (left > size() - 1)
        return;
    if (Right > size() - 1)
        index_of_child_paiortize = left;
    else if (comp(data[left], data[Right]))
        index_of_child_paiortize = Right;
    else
        index_of_child_paiortize = left;
    if (comp(data[index], data[index_of_child_paiortize]))
    {
        swap(&data[index], &data[index_of_child_paiortize]);
        max_min_heapfy(index_of_child_paiortize);
    }
}
