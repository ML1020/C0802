#include "queue.h"

void TestQueue()
{
	Queue test;
	QueueInit(&test);
	QueuePush(&test, 1);
	QueuePush(&test, 2);
	QueuePush(&test, 3);
	QueuePush(&test, 4);
	QueuePush(&test, 5);
	Print(&test);

}

int main()
{
	TestQueue();
	system("pause");
	return 0;
}


