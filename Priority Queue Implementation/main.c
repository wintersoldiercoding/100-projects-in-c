// Project: Priority Queue Implementation
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for a priority queue
typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

// Function to initialize the priority queue
void initializeQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// Function to check if the priority queue is empty
int isQueueEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

// Function to swap two elements in the priority queue
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the heap property after adding a new element
void heapifyUp(PriorityQueue* pq, int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && pq->data[index] < pq->data[parent]) {
        swap(&pq->data[index], &pq->data[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to add an element to the priority queue
void enqueue(PriorityQueue* pq, int value) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority queue is full.\n");
        return;
    }

    pq->data[pq->size] = value;
    pq->size++;

    heapifyUp(pq, pq->size - 1);
}

// Function to maintain the heap property after removing the root element
void heapifyDown(PriorityQueue* pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < pq->size && pq->data[leftChild] < pq->data[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < pq->size && pq->data[rightChild] < pq->data[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&pq->data[index], &pq->data[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Function to remove and return the smallest element from the priority queue
int dequeue(PriorityQueue* pq) {
    if (isQueueEmpty(pq)) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    int minValue = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    heapifyDown(pq, 0);

    return minValue;
}

int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    printf("Welcome to the Priority Queue Implementation!\n");
    printf("Commands: E - Enqueue, D - Dequeue, P - Print Priority Queue, Q - Quit\n");

    char command;
    int value;

    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        if (command == 'Q' || command == 'q') {
            break;
        }

        switch (command) {
            case 'E':
            case 'e':
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&pq, value);
                break;
            case 'D':
            case 'd':
                value = dequeue(&pq);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 'P':
            case 'p':
                printf("Priority Queue: ");
                for (int i = 0; i < pq.size; i++) {
                    printf("%d ", pq.data[i]);
                }
                printf("\n");
                break;
            default:
                printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}
