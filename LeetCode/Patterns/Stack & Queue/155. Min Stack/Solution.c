#include <stdlib.h>

#define MAX_CALLS 30000

// Define a structure to hold both the value and the minimum at that point
typedef struct {
    int val;
    int min;
} Element;

typedef struct {
    Element* stack;
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    // Allocate memory based on the maximum number of operations constraint
    obj->stack = (Element*)malloc(sizeof(Element) * MAX_CALLS);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int value) {
    obj->top++;
    obj->stack[obj->top].val = value;
    
    // If it's the first element, it is the minimum
    if (obj->top == 0) {
        obj->stack[obj->top].min = value;
    } else {
        // Otherwise, the minimum is the smaller of the new value and the previous minimum
        int prev_min = obj->stack[obj->top - 1].min;
        obj->stack[obj->top].min = (value < prev_min) ? value : prev_min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->stack[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj);
}