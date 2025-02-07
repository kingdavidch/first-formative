#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_STOP_NAME 50

typedef struct BusStop {
    char name[MAX_STOP_NAME];
    struct BusStop* next;
    struct BusStop* prev;
} BusStop;

BusStop* createBusStop(const char* name) {
    BusStop* newStop = (BusStop*)malloc(sizeof(BusStop));
    if (newStop == NULL) return NULL;
    strcpy(newStop->name, name);
    newStop->next = NULL;
    newStop->prev = NULL;
    return newStop;
}

// Time Complexity: O(n) where n is number of stops
void addBusStop(BusStop** head, const char* name) {
    BusStop* newStop = createBusStop(name);
    if (*head == NULL) {
        *head = newStop;
        return;
    }
    BusStop* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStop;
    newStop->prev = current;
}

void traverseForward(BusStop* head) {
    BusStop* current = head;
    printf("\nForward Journey Started\n");
    while (current != NULL) {
        printf("Arriving at: %s\n", current->name);
        sleep(3);  // 3-second delay
        current = current->next;
    }
    printf("Reached final destination!\n");
}

void traverseBackward(BusStop* tail) {
    BusStop* current = tail;
    printf("\nReverse Journey Started\n");
    while (current != NULL) {
        printf("Arriving at: %s\n", current->name);
        sleep(3);  // 3-second delay
        current = current->prev;
    }
    printf("Reached starting point!\n");
}

int main() {
    BusStop* route = NULL;
    
    // Adding bus stops
    addBusStop(&route, "Home");
    addBusStop(&route, "Market Square");
    addBusStop(&route, "Downtown");
    addBusStop(&route, "Library");
    addBusStop(&route, "University");
    addBusStop(&route, "Campus");

    // Find last stop for reverse journey
    BusStop* lastStop = route;
    while (lastStop->next != NULL) {
        lastStop = lastStop->next;
    }

    int choice;
    printf("Choose direction:\n1. Forward (Home to Campus)\n2. Backward (Campus to Home)\nEnter choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        traverseForward(route);
    } else if (choice == 2) {
        traverseBackward(lastStop);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
} 
