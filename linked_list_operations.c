#include "include/linked_list.h"
int main(){
    int arr[]= {};
    node * head = create(arr, 0);
    print(head);
    head = insertafter(head, 5, 1);
    print(head);
    return 0;
}

