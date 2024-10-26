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
		bool operator= > (const QueueElement& other) const {
			return priority >= other.priority;
		}
	};
	Heap<QueueElement> heap;
public:
	void insert(T element, int priority) {
		QueueElement queueElement{ element,priority };
		heap.push(queueElement);
	}
	T extract() {
		QueueElement queueElement = heap.pop();
		return queueElement.element;
	}
};