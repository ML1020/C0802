#include "queue.h"


void QueueInit(Queue* pq)//初始化队列
{
	pq->_front = pq->_rear = NULL;//队头指针和队尾指针相等且为空
	pq->size = 0;
}

void QueuePush(Queue* pq, QUDataType x)//入队
{
	QueueNode * cur = (QueueNode*)malloc(sizeof(QueueNode));//申请一个结点空间
	cur->_data = x;          //结点的数据域里面存放x
	cur->_next = NULL;
	pq->size++;
	if (pq->_rear == NULL)
	{
		pq->_front = pq->_rear = cur;
	}
	else
	{
		pq->_rear->_next = cur;
		pq->_rear = cur;
	}
}
void QueuePop(Queue* pq)//出队
{
	pq->size--;
	QueueNode * tmp;
	if (pq->_front)
	{
		tmp = pq->_front;
		pq->_front = pq->_front->_next;
		free(tmp);
	}
	else
	{
		pq->_rear = NULL;
	}
}

void QueueDestory(Queue* pq)//销毁一个队列
{
	QueueNode * tmp;
	while (pq->_front != pq->_rear)
	{
		tmp = pq->_front;
		pq->_front = pq->_front->_next;
		free(tmp);
	}
}
int QueueEmpty(Queue* pq)//判断队空
{
	return pq->_front == NULL;
}
QUDataType QueueFront(Queue* pq)//取队首元素
{
	return pq->_front->_data;
}
void Print(Queue* pq)
{
	for (QueueNode * cur = pq->_front; cur != NULL; cur = cur->_next)
	{
		printf("%d-->", cur->_data);
	}
	printf("\n");
}


