#include "queue.h"


void QueueInit(Queue* pq)//��ʼ������
{
	pq->_front = pq->_rear = NULL;//��ͷָ��Ͷ�βָ�������Ϊ��
	pq->size = 0;
}

void QueuePush(Queue* pq, QUDataType x)//���
{
	QueueNode * cur = (QueueNode*)malloc(sizeof(QueueNode));//����һ�����ռ�
	cur->_data = x;          //����������������x
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
void QueuePop(Queue* pq)//����
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

void QueueDestory(Queue* pq)//����һ������
{
	QueueNode * tmp;
	while (pq->_front != pq->_rear)
	{
		tmp = pq->_front;
		pq->_front = pq->_front->_next;
		free(tmp);
	}
}
int QueueEmpty(Queue* pq)//�ж϶ӿ�
{
	return pq->_front == NULL;
}
QUDataType QueueFront(Queue* pq)//ȡ����Ԫ��
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


