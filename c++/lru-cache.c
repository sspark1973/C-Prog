/*
Implement LRU Cache
How to implement LRU caching scheme? What data structures should be used?

We are given total possible page numbers that can be referred. 
We are also given cache (or memory) size (Number of page frames that cache can hold at a time). 

The LRU caching scheme is to remove the least recently used frame when the cache is full 
and a new page is referenced which is not there in cache. 

Please see the Galvin book for more details (see the LRU page replacement slide here).

We use two data structures to implement an LRU Cache.

1. A Queue which is implemented using a doubly linked list. 
The maximum size of the queue will be equal to the total number of frames available (cache size).
The most recently used pages will be near front end and least recently pages will be near rear end.

2. A Hash with page number as key and address of the corresponding queue node as value.

When a page is referenced, the required page may be in the memory. 
If it is in the memory, we need to detach the node of the list and bring it to the front of the queue.

If the required page is not in the memory, we bring that in memory. 
In simple words, we add a new node to the front of the queue and update the corresponding node address in the hash. 

If the queue is full, i.e. all the frames are full, 
we remove a node from the rear of queue, and add the new node to the front of queue.

Note: Initially no page is in the memory.

Below is C implementation:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
	struct QNode *prev, *next;
	unsigned pageNumber;
} QNode;

typedef struct Queue
{
	unsigned count;
	unsigned numberOfFrames;
	QNode *front, *rear;
} Queue;

typedef struct Hash
{
	int capacity;
	QNode **array;
} Hash;

Queue *createQueue(int numberOfFrames)
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));

	queue->count = 0;
	queue->front = queue->rear = NULL;
	queue->numberOfFrames = numberOfFrames;

	return queue;
}

Hash *createHash(int capacity)
{
	Hash *hash = (Hash *)malloc(sizeof(Hash));

	hash->capacity = capacity;

	hash->array = (QNode **)malloc(hash->capacity * sizeof(QNode*));

	int i;
	for(i = 0; i < hash->capacity; ++i)
		hash->array[i] = NULL;
	
	return hash;
}

int AreAllFramesFull(Queue *queue)
{
	return queue->count == queue->numberOfFrames;
}

int isQueueEmpty(Queue *queue)
{
	return queue->rear == NULL;
}

void deQueue(Queue *queue)
{
	if(isQueueEmpty(queue))
		return;

	if(queue->front == queue->rear)
		queue->front = NULL;

	QNode *temp = queue->rear;
	queue->rear = queue->rear->prev;

	if(queue->rear)
		queue->rear->next = NULL;

	free(temp);

	queue->count--;
}

QNode *newQNode(unsigned pageNumber)
{
	QNode *qnode = (QNode *)malloc(sizeof(QNode));
	qnode->pageNumber = pageNumber;

	qnode->prev = qnode->next = NULL;

	return qnode;
}

void Enqueue(Queue *queue, Hash *hash, unsigned pageNumber)
{
	if(AreAllFramesFull(queue)) {
		hash->array[queue->rear->pageNumber] = NULL;
		deQueue(queue);
	}

	QNode *temp = newQNode(pageNumber);
	temp->next = queue->front;

	if(isQueueEmpty(queue))
		queue->rear = queue->front = temp;
	else {
		queue->front->prev = temp;
		queue->front = temp;
	}

	hash->array[pageNumber] = temp;

	queue->count++;
}

void ReferencePage(Queue *queue, Hash *hash, unsigned pageNumber)
{
	QNode *reqPage = hash->array[pageNumber];

	// the page is not in cache, bring it
	if(reqPage == NULL)
		Enqueue(queue, hash, pageNumber);

	else if(reqPage != queue->front) {
		reqPage->prev->next = reqPage->next;

		if(reqPage->next)
			reqPage->next->prev = reqPage->prev;

		if(reqPage == queue->rear) {
			queue->rear = reqPage->prev;
			queue->rear->next = NULL;
		}

		reqPage->next = queue->front;
		reqPage->prev = NULL;

		reqPage->next->prev =reqPage;

		queue->front = reqPage;
	}
}

int main()
{
	// Let cache can hold 4 pages
	Queue *q = createQueue(4);

	// Let 10 different pages can be requested (pages to be
    // referenced are numbered from 0 to 9
	Hash *hash = createHash(10);

	// Let us refer pages 1, 2, 3, 1, 4, 5
    ReferencePage( q, hash, 1);
	ReferencePage( q, hash, 2);
	ReferencePage( q, hash, 3);
	ReferencePage( q, hash, 1);
	ReferencePage( q, hash, 4);
	ReferencePage( q, hash, 2);
	ReferencePage( q, hash, 4);
	ReferencePage( q, hash, 5);

	printf("%d ", q->front->pageNumber);
	printf("%d ", q->front->next->pageNumber);
	printf("%d ", q->front->next->pageNumber);
	printf("%d ", q->front->next->next->pageNumber);

	return 0;
}
