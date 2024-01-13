#include <cstdio>
#include <queue>

using namespace std;

void check_order(priority_queue<int> &_prio_queue, queue<pair<int, int>> &_queue, int _doc_index)
{
	int order = 0;

	while (!_queue.empty()) {
		int index = _queue.front().first;
		int prio = _queue.front().second;
		_queue.pop();

		if (_prio_queue.top() == prio) {
			_prio_queue.pop();
			order++;

			if (_doc_index == index) {
				printf("%d\n", order);
				return;
			}
		}
		else {
			_queue.push({ index, prio });
		}
	}

	return;
}


int main()
{
	int nr_testcase;
	scanf("%d", &nr_testcase);

	for (int i = 0; i < nr_testcase; i++) {
		int nr_document;
		int document_index;
		scanf("%d %d", &nr_document, &document_index);

		priority_queue<int> priority_print_queue;
		queue<pair<int, int>> print_queue;

		for (int j = 0; j < nr_document; j++) {
			int doc_prio;
			scanf("%d", &doc_prio);

			priority_print_queue.push(doc_prio);
			print_queue.push({ j, doc_prio });
		}

		check_order(priority_print_queue, print_queue, document_index);
	}

	return 0;
}