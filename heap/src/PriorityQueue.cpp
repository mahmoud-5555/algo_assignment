#include "../../../../mahmoud-5555/algo_assignment/heap/lib/heap.hpp"
template <typename T>
class PriorityQueue
{
	struct QueueElement {
		T element;
		int priority;
		bool operator<(const QueueElement& other) const {
			return priority < other.priority;
		}
		bool operator<=(const QueueElement& other) const {
			return priority <= other.priority;
		}
		bool operator>(const QueueElement& other) const {
			return priority > other.priority;
		}
		bool operator>= (const QueueElement& other) const {
			return priority >= other.priority;
		}
	};
	Heap<QueueElement> heap;
public:
	bool empty() {
		return heap.empty();
	}
	void insert(T element, int priority) {
		QueueElement queueElement{ element,priority };
		heap.push(queueElement);
	}
	T extract() {
		if (empty())
		{
			throw std::runtime_error("PriorityQueue is empty, cannot extract element.");
		}
		QueueElement queueElement = heap.pop();
		return queueElement.element;
	}
};