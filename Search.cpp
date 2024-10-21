#include <vector>
using namespace std;

template < typename T >
long long sequentialSearch(const vector<T>& list, T target) {
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i] == target)
		{
			return i;
		}
	}
	return -1;
}

template < typename T >
long long recursiveSequentialSearch(const vector<T>& list, T target, size_t index = 0) {
	if (index >= list.size())
	{
		return -1;
	}
	if (index < 0)
	{
		return recursiveSequentialSearch(list, target, 0);
	}
	if (list[index] == target)
	{
		return index;
	}
	return recursiveSequentialSearch(list, target, index+1);
}

template < typename T >
long long recursiveBinarySearch(const vector<T>& list, T target, size_t begin, size_t end) {
	if (begin > end)
	{
		return -1;
	}
	size_t mid = (begin + end) / 2;
	if (list[mid] == target)
	{
		return mid;
	}
	else if (list[mid] > target)
	{
		return recursiveBinarySearch(list, target, begin, mid - 1);
	}
	return recursiveBinarySearch(list, target, mid + 1, end);
}
template < typename T >
long long recursiveBinarySearch(const vector<T>& list, T target) {
	return recursiveBinarySearch(list, target, 0, list.size() - 1);
}