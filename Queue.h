#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	size_t size;//���������Ԫ�صĸ���
	QueueNode* _front; // ��ͷ
	QueueNode* _rear; // ��β
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(QUDataType x);

void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);

QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);

int QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);
void TestQueue();
void Print(Queue* pq);

#endif//QUEUE_H_

