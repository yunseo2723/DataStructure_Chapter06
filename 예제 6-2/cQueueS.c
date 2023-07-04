#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

QueueType* createCQueue(void) {
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

//공백 확인
int isCQueueEmpty(QueueType* cQ) {
	if (cQ->front == cQ->rear) {
		printf("Circular Queue is empty! ");
		return 1;
	}
	else return 0;
}

//포화 확인
int isCQueueFull(QueueType* cQ) {
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {
		printf(" Circular Queue is full! ");
		return 1;
	}
	else return 0;
}

//rear에 원소 삽입
void enCQueue(QueueType* cQ, element item) {
	if (isCQueueFull(cQ)) return;
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

//front에서 원소 삭제후 반환
element deCQueue(QueueType* cQ) {
	if (isCQueueEmpty(cQ)) return;
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

//가장 앞에 있는 원소 검색
element peekCQ(QueueType* cQ) {
	if (isCQueueEmpty(cQ)) return;
	else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

//원소 출력
void printCQ(QueueType* cQ) {
	int i, first, last;
	first = (cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;
	printf(" Circular Queue : [");
	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;
	}
	printf(" ] ");
}