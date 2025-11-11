#include <stdio.h>
#include <stdlib.h> // for system()
#define MAX 10

int deque[MAX];
int left = -1, right = -1;

void insert_right(void);
void insert_left(void);
void delete_right(void);
void delete_left(void);
void display(void);

int main() {
    int choice;

    // system("cls"); // uncomment for Windows
    // system("clear"); // uncomment for Linux/Mac

    do {
        printf("\n1. Insert at right");
        printf("\n2. Insert at left");
        printf("\n3. Delete from right");
        printf("\n4. Delete from left");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_right(); break;
            case 2: insert_left(); break;
            case 3: delete_right(); break;
            case 4: delete_left(); break;
            case 5: display(); break;
            case 6: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

// ------- INSERT AT RIGHT -------
void insert_right() {
    int val;
    printf("\nEnter the value to be added: ");
    scanf("%d", &val);

    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("\nOVERFLOW");
        return;
    }

    if (left == -1) { // queue is empty
        left = 0;
        right = 0;
    } else if (right == MAX - 1) {
        right = 0;
    } else {
        right++;
    }

    deque[right] = val;
}

// ------- INSERT AT LEFT -------
void insert_left() {
    int val;
    printf("\nEnter the value to be added: ");
    scanf("%d", &val);

    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("\nOVERFLOW");
        return;
    }

    if (left == -1) { // queue is empty
        left = 0;
        right = 0;
    } else if (left == 0) {
        left = MAX - 1;
    } else {
        left--;
    }

    deque[left] = val;
}

// ------- DELETE FROM RIGHT -------
void delete_right() {
    if (left == -1) {
        printf("\nUNDERFLOW");
        return;
    }

    printf("\nThe deleted element is %d", deque[right]);

    if (left == right) {
        left = -1;
        right = -1;
    } else if (right == 0) {
        right = MAX - 1;
    } else {
        right--;
    }
}

// ------- DELETE FROM LEFT -------
void delete_left() {
    if (left == -1) {
        printf("\nUNDERFLOW");
        return;
    }

    printf("\nThe deleted element is %d", deque[left]);

    if (left == right) {
        left = -1;
        right = -1;
    } else if (left == MAX - 1) {
        left = 0;
    } else {
        left++;
    }
}

// ------- DISPLAY -------
void display() {
    int i;

    if (left == -1) {
        printf("\nQUEUE IS EMPTY");
        return;
    }
}
