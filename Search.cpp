#include <vector>
#include <iostream>
using namespace std;

template <typename T>
long long sequentialSearch(const vector<T> &list, T target)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == target)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
long long recursiveSequentialSearch(const vector<T> &list, T target, size_t index = 0)
{
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
	return recursiveSequentialSearch(list, target, index + 1);
}

template <typename T>
long long BinarySearch(const vector<T> &list, T target)
{

	int begin = 0, end = list.size() - 1;

	while (begin <= end)
	{
		size_t mid = (begin + end) / 2;
		if (list[mid] == target)
		{
			return mid;
		}
		else if (list[mid] > target)
		{
			end = mid - 1;
		}
		else
		{
			begin = mid + 1;
		}
	}
	return -1;
}

template <typename T>
long long recursiveBinarySearch(const vector<T> &list, T target, size_t begin, size_t end)
{
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
template <typename T>
long long recursiveBinarySearch(const vector<T> &list, T target)
{
	return recursiveBinarySearch(list, target, 0, list.size() - 1);
}

int main()
{

	vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50, 88, 990, 1000, 11111, 111111, 122222222, 555555555};

	cout << "sequentialSearch: " << sequentialSearch(c, 50) << "\n";
	cout << "recursiveSequentialSearch: " << recursiveSequentialSearch(c, 50) << "\n";
	cout << "BinarySearch: " << BinarySearch(c, 50) << "\n";
	cout << "recursiveBinarySearch: " << recursiveBinarySearch(c, 50) << "\n";
}