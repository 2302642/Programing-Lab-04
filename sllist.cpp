/*!**************************************************************************************************************************************************************************************************************************************************************
\file       sllist.cpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202
\par        Section:         RSE
\par        Tutorial:        Lab 4
\par        File created on: 02/02/2024
\brief      Singly Linked List Implementation

\par        File information:
            This file contains 15 function definitions, 2 structures, and 3 namespaces to be called by main in q-driver.

            Namespaces:
            - hlp2
            - Two anonymous namespaces

            Structures:
            - struct node { int value; node *next; };                                                                   // Data portion and pointer portion
            - struct sllist { node *head; };                                                                            // Starting for singly linked list

            Functions:
            - int data(node const *p);                                                                                  // Accessor to node's data
            - void data(node *p, int newval);                                                                           // Mutator to node's data
            - node* next(node *p);                                                                                      // Pointer to successor node
            - node const* next(node const *p);                                                                          // Pointer to successor node 

            Interface declarations for singly-linked list :
            - sllist* construct();                                                                                      // To create a new singly linked list
            - void destruct(sllist *ptr_sll);                                                                           // To destroy/erase all the data in the singly linked list as well as the list itself
            - bool empty(sllist const *ptr_sll);                                                                        // Implement logic to check if the list is empty
            - size_t size(sllist const *ptr_sll);                                                                       // Calculating the size of the list using a loop through the list and count elements found in the list
            - void push_front(sllist *ptr_sll, int value);                                                              // Add an element to the front of the linked list
            - void push_back(sllist *ptr_sll, int value);                                                               // To add a new node to the back of the singly linked list
            - void remove_first(sllist *ptr_sll, int value);                                                            // To remove a node containing a specified value from the singly linked list
            - void insert(sllist *ptr_sll, int value, size_t index);                                                    // To insert a new node with the specified value into the singly linked list at a specified index
            - node* front(sllist *ptr_sll);                                                                             // To check the first value in the singly linked list
            - node const* front(sllist const *ptr_sll);                                                                 // To check the first value in the singly linked list
            - node* find(sllist const *ptr_sll, int value);                                                             // To find the node with the specified value
**************************************************************************************************************************************************************************************************************************************************************/

//! Other than sllist.hpp, you really don't have to include any other files except when testing your code.
//! When you're ready to submit, don't include either of the following two headers: <forward_list> and <list>
//! Private functions must be declared and defined in an anonymous namespace!!!
//! See the spec for structure and interface definitions!!!
#include "sllist.hpp"

namespace { hlp2::node* create_node(int value, hlp2::node *next = nullptr); }
namespace hlp2 {
//################################################################################################################################################################################################################################
//================================================================================================================================================================================================================================
//|                                                                          GIVEN STURCTURES SECTION                                                                                                                            |
//================================================================================================================================================================================================================================
    struct node {
        int value;                                                                                                      // data portion
        node *next;                                                                                                     // pointer portion
    };
    struct sllist { node *head; };                                                                                      // statring for sllist
//================================================================================================================================================================================================================================
//|                                                                             GIVEN CODE SECTION                                                                                                                               |
//================================================================================================================================================================================================================================
    int data(node const *p) { return p->value; }                                                                        // accessor to node's data
    void data(node *p, int newval) { p->value = newval; }                                                               // mutator to node's data
    node* next(node *p) { return p->next; }                                                                             // pointer to successor node
    node const* next(node const *p) { return p->next; }                                                                 // pointer to successor node
    sllist* construct() { return new sllist{nullptr}; }                                                                 // to create a new sllist
    void push_front(sllist *ptr_sll, int value) { ptr_sll->head = create_node(value, ptr_sll->head); }                  // add element to front of linked list
    size_t size(sllist const *ptr_sll) {                                                                                // calculating the size of the list using a loop through the list and count elements found in the list
        size_t cnt = 0;
        for (node *head = ptr_sll->head; head; head = next(head)) { ++cnt; }
        return cnt;
    }
//================================================================================================================================================================================================================================
//|                                                                            CREATED CODE SECTION                                                                                                                              |
//================================================================================================================================================================================================================================
    bool empty(sllist const *ptr_sll) { return size(ptr_sll) == 0; }                                                    // Implement logic to check if the list is empty
//********************************************************************************************************************************************************************************************************************************
    void destruct(sllist* ptr_sll) {                                                                                    // to destroy/erase the all the data in the sllist as well as the sllist
        node* current = ptr_sll->head;                                                                                  // starting with the head of the sllist
        while (current) {                                                                                               // looping through sllist
            node* next_node = current->next;                                                                            // keeping a temporary pointer to the next node         
            delete current;                                                                                             // deallocating the current node          
            current = next_node;                                                                                        // moving onto the next node
        }
        delete ptr_sll;                                                                                                 // deallocating the sllist after deleting all elements strored in the sllist 
    }
//********************************************************************************************************************************************************************************************************************************
    void push_back(sllist* ptr_sll, int value) {                                                                        // to add a new node to the back of the sllist
        if (empty(ptr_sll)) { ptr_sll->head = create_node(value); return; }                                             // if the list is empty make the new node the head
        node* last = ptr_sll->head;
        while (last->next != nullptr) { last = last->next; }                                                            // loop through the list to find the last node             
        last->next = create_node(value);                                                                                // creating a new node with the specified value to the end of the sllist
    }
//********************************************************************************************************************************************************************************************************************************
    void remove_first(sllist *ptr_sll, int value){                                                                      // to remove a node contaning a specified value from the sllist
        if(empty(ptr_sll)){ return; }
        
        node *current = ptr_sll->head;                                                                                  // creating pointers to look into the sllist
        node *previous = nullptr;
        while (current != nullptr && data(current) != value) {                                                          // looping through the sllist to find the node with the specified value
            previous = current;
            current = next(current);
        }
       
        if (current == nullptr) { return; }                                                                             // if the value is not found do nothing
        if (previous == nullptr) { ptr_sll->head = next(current); }                                                     // if the node being removed is the first node update the head
        else { previous->next = next(current); }                                                                        // else update the "next" pointer of the previous node
            
        delete current;                                                                                                 // deallocate the memory of the removed node
    }
//********************************************************************************************************************************************************************************************************************************
    void insert(sllist *ptr_sll, int value, size_t index) {                                                             // to insert a new node with the specified valued into the sllist at a specified index
    
        node* new_node = create_node(value);                                                                            // creating a new node with the specified value        
        if (index == 0 || empty(ptr_sll)) {                                                                             // if the index is 0 or if the list is empty insert the new node at the start of the sllist 
            new_node->next = ptr_sll->head;
            ptr_sll->head = new_node;
            return;
        }
    
        node* current = ptr_sll->head;                                                                 
        for (size_t i = 0; i < index - 1 && current->next != nullptr; i++) { current = current->next; }                 // loop through the sllist to find the node at the specified index

        new_node->next = current->next;                                                                                 // inserting the new node after the current node
        current->next = new_node;
    }
//********************************************************************************************************************************************************************************************************************************
    node* front(sllist *ptr_sll){                                                                                       // to check the first value in the sllist
        if(empty(ptr_sll)){ return nullptr; }                                                                           // if sllist is empty return nulptr
        return ptr_sll->head;                                                                                           // else return the first element found in slist
    }
//********************************************************************************************************************************************************************************************************************************
    node const* front(sllist const*ptr_sll){                                                                            // to check the first value in the sllist
        if(empty(ptr_sll)){ return nullptr; }                                                                           // if sllist is empty return nulptr
        return ptr_sll->head;                                                                                           // else return the first element found in slist
    }
//********************************************************************************************************************************************************************************************************************************
    node* find(sllist const *ptr_sll, int value){                                                                       // to find a the node with the specified value         
        node* current = ptr_sll->head;
        while(current != nullptr){                                                                                      // loop through the sllist to find the node with the specified value
            if(data(current) == value){ return current; }                                                               // identifing the node with the desired value 
            current = next(current);
        }
        return current;                                                                                                 // if value is not found return nullptr
    }
//################################################################################################################################################################################################################################
} namespace{ hlp2::node* create_node(int value, hlp2::node* next) { return new hlp2::node {value, next}; } }
