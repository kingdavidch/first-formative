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
    strcpy(newStop->name, name);
    newStop->next = NULL;
    newStop->prev = NULL;
    return newStop;
}

void addBusStop(BusStop** head, const char* name) {
    BusStop* newStop = createBusStop(name);
    if (*head == NULL) {
        *head = newStop;
    } else {
        BusStop* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStop;
        newStop->prev = current;
    }
}

void traverseForward(BusStop* head) {
    BusStop* current = head;
    while (current != NULL) {
        printf("%s\n", current->name);
        sleep(3);
        current = current->next;
    }
}

void traverseBackward(BusStop* tail) {
    BusStop* current = tail;
    while (current != NULL) {
        printf("%s\n", current->name);
        sleep(3);
        current = current->prev;
    }
}

BusStop* findLastStop(BusStop* head) {
    BusStop* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

int main() {
    BusStop* busRoute = NULL;
    
    // Add bus stops
    addBusStop(&busRoute, "Home");
    addBusStop(&busRoute, "Downtown");
    addBusStop(&busRoute, "University");
    addBusStop(&busRoute, "Campus");

    BusStop* lastStop = findLastStop(busRoute);

    int choice;
    printf("Choose direction:\n1. Forward\n2. Backward\n");
    scanf("%d", &choice);

    if (choice == 1) {
        traverseForward(busRoute);
    } else if (choice == 2) {
        traverseBackward(lastStop);
    }

    return 0;
}

