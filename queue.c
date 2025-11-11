#include <stdio.h>
#define SIZE 5   // Define the maximum size of the queue

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return rear == SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to add an element (enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

// Function to remove an element (dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("%d dequeued from queue.\n", queue[front]);
        front++;
    }
}

// Function to display all elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
