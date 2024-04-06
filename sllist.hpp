/*!**************************************************************************************************************************************************************************************************************************************************************
\file       sllist.hpp
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
//! Provide include guards, Don't include either of the following two headers: <forward_list> and <list>
//! You may need to include <cstddef> for size_t [which is the largest unsigned type from the C standard library]
//! All names from here on must be in namespace hlp2. Don't add any names that are private to the implementation source file sllist.cpp in this file.
//! Necessary declarations are described in the spec. These forward declarations make only names of types node and sllist known to the compiler.
//! However, the compiler has no knowledge of the definitions of these types, i.e., the specific data members and member functions of these types.

#ifndef SLLIST_HPP
#define SLLIST_HPP

#include <iostream>
#include <cstddef>

namespace hlp2{

    struct node;
    struct sllist;
    
    // interface to individual elements of singly-linked list
    int data(node const *p);                                                          // accessor to node's data
    void data(node *p, int newval);                                                   // mutator to node's data
    node* next(node *p);                                                              // pointer to successor node
    node const* next(node const *p);                                                  // pointer to successor node

    // interface declarations for singly-linked list...
    sllist* construct();
    void destruct(sllist *ptr_sll);
    bool empty(sllist const *ptr_sll);
    size_t size(sllist const *ptr_sll);
    void push_front(sllist *ptr_sll, int value);
    void push_back(sllist *ptr_sll, int value);
    void remove_first(sllist *ptr_sll, int value);
    void insert(sllist *ptr_sll, int value, size_t index);
    node* front(sllist *ptr_sll);
    node const* front(sllist const *ptr_sll);
    node* find(sllist const *ptr_sll, int value);
}
#endif // SLLIST_HPP
