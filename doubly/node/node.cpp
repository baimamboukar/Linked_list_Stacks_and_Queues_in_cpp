/*
--------------------------------------------------
* IMPLEMENTATION OF DOUBLY LINKED LIST USING C++ *
--------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


//IMPLEMENTATION FILE OF THE CLASS NODE (declared in node.h)
#include <string>
#include "./node.h"
using namespace std;



    /*
        CONTRUCTORS:
            ♦ Node(): default constructor, it creates an empty object of type Node
            ♦ Node(string): parametrized constructor, creates object of type Node with data inside

    */

    Node::Node(){
        this->prev, this->next = NULL;
    }
    Node::Node(string data){
        this->data = data;
        this->prev, this->next = NULL;

    }


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

    string Node::GetData(){
        return this->data;
    }
    Node* Node::GetPrevious(){
        return this->prev;
    }
    Node* Node::GetNext(){
        return this->next;
    }

    void Node::SetData(string data){
        this->data = data;
    }
    void Node::SetPrevious(Node *prev){
        this->prev = prev;
    }
    void Node::SetNext(Node *next){
        this->next = next;
    }