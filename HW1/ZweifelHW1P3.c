#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef struct elem {
    int value;
    struct elem *next;
    struct elem *prev;
} elem_t;

void print_list(elem_t *head) {
    elem_t *elem = head;
    while(elem != NULL) {
        printf("%d ", elem->value);
        elem = elem->next;
    }
    printf("\n");
}

void bubble_sort_copy_value(elem_t **head) {

    int swaps;
    elem_t *current;
    elem_t *end = NULL;

    do {
        current = *head;
        swaps = 0;
        while (current->next != end) {
            if (current->value > current->next->value) {
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swaps = 1;
            }
            current = current->next;
        }
        end = current;
    } while (swaps);
}

elem_t *swap_ref(elem_t *A, elem_t *B) {
    elem_t *temp;

    temp = A->next;
    A->next = B->next;
    B->next = temp;

    if (A->next != NULL) { //not end of list
        A->next->prev = A;
    }
    if (B->next != NULL) { //not end of list
        B->next->prev = B;
    }

    temp = A->prev;
    A->prev = B->prev;
    B->prev = temp;

    if (A->prev != NULL) { //A is not head of list
        A->prev->next = A;
    }
    if (B->prev == NULL) { // B is now head of list
        return B; //return new head of list
    }
    B->prev->next = B;
    return A; //this case runs whenever B is not the new head of the list 
}

void bubble_sort_copy_ref(elem_t **head) {
    // implement me
    int swaps;
    elem_t *current;
    elem_t *end = NULL;
    elem_t *temp;

    do {
        current = *head;
        swaps = 0;

        while (current->next != end) {

            if (current->value > current->next->value) {
                temp = swap_ref(current, current->next);
                
                if (current->prev->prev == NULL) {
                    *head = temp;
                }
                swaps = 1;
            
            } else {
                current = current->next;
            }
        }
        
        end = current;
    } while (swaps);
}

elem_t *build_list(int num_elements) {
    srand(1234);
    elem_t *head = NULL;
    for (int i = 0; i < num_elements; i++) {
        elem_t *e = (elem_t *) malloc(sizeof(elem_t));
        
        e->value = random() % 100;
        e->next = NULL;
        e->prev = NULL;
        if (head == NULL) {
            head = e;
        } else {
            e->next = head;
            head->prev = e;
            head = e;
        }
    }
    return head;
}
int main() {
    elem_t *head = build_list(100);
    print_list(head);
    printf("==================================\n");
    bubble_sort_copy_value(&head);
    bubble_sort_copy_ref(&head);
    print_list(head);
}