#include "StudentList.h"

void show(TStudent* head){
    std::cout << "Aktualny stan listy:" << std::endl;
    if(head == nullptr)
        std::cout << "Lista jest pusta" << std::endl;
    else{
        while(head != nullptr){
            std::cout << "id: " << head->_id << std::endl;
            head = head->_next;
        }
    }
}

void push_front(TStudent** head, int id){
    TStudent* temp = InitTStudent();
    temp->_id = id;
    temp->_next = *head;
    *head = temp;
}

void clear(TStudent **head){
    while(*head != nullptr){
        TStudent* temp = *head;
        *head = (*head)->_next;
        delete temp;
    }
}