#pragma once
#define cQ_SIZE 4

typedef char element;

typedef struct {
	element queue[cQ_SIZE];
	int front, rear;
}QueueType;

QueueType* createQueue(void);
int isQueueEmpty(QueueType* cQ);
int isQueueFull(QueueType* cQ);
void enCQueue(QueueType* cQ, element item);
element deCQueue(QueueType* cQ);
element peekCQ(QueueType* cQ);
void printCQ(QueueType* cQ);