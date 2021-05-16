/*
--------------------------------------------------
* IMPLEMENTATION OF DOUBLY LINKED LIST USING C++ *
--------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


//DELCARATION FILE OF THE CLASS NODE (implemented in node.cpp)
#pragma once
#include <string>
using namespace std;


class Node{
    /*
        DATA ATTRIBUTES:
            *data: stores the data that will be kept in the node
            *prev: stores the address of the previous node
            *next: stores the address of the next node

    */
    string data;
    Node *prev;
    Node *next;

    /*
        CONTRUCTORS:
            ♦ Node(): default constructor, it creates an empty object of type Node
            ♦ Node(string): parametrized constructor, creates object of type Node with data inside

    */
public:
    Node();
    Node(string);


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ string GetData(): returns the data kept in the node
            ♦ Node* GetPrev(): returs the previous node
            ♦ Node* GetNext(): returns the thex node
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetData(string): updates the data kept in the node
            ♦ void SetPrev(Node*): updates the previous node
            ♦ void SetNext(Node*): updates the next node
             
    */

    string GetData();
    Node* GetPrevious();
    Node* GetNext();

    void SetData(string);
    void SetPrevious(Node*);
    void SetNext(Node*);

};