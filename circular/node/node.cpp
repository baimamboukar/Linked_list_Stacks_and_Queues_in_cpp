/*
----------------------------------------------------
* IMPLEMENTATION OF CIRCULAR LINKED LIST USING C++ *
----------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/

//IMPLEMENTATION FILE OF THE CLASS NODE (declared in node.h)
#include "node.h"
#include <string>
#include <iostream>
using namespace std;


    /*
        CONTRUCTORS:
            ♦ Node(): default constructor, it creates an empty object of type Node
            ♦ Node(string): parametrized constructor, creates object of type Node with data inside

    */

    Node::Node(){
        std::cout << "building node with default constructor..." << std::endl;
        this->data = "";
        this->next = NULL;
        std::cout << "Node successful built..." << std::endl;
    }
    Node::Node(string value){
        std::cout << "building node with parametried constructor..." << std::endl;
        this->data = value;
        this->next = NULL;
        std::cout << "Node built with paramater " << value  << std::endl;
    }


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ string GetData(): default constructor, it creates an empty object of type Node
            ♦ Node *GetNext(): parametrized constructor, creates object of type Node with data inside
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetData(string): updates the data kept in the node
            ♦ void SetNext(Node*): updates the next node
             
    */

    string Node::GetData(){
        return this->data;
    }
    Node* Node::GetNext(){
        return this->next;
    }

    void Node::SetData(string value){
        this->data = value;
    }
    void Node::SetNext(Node *next){
        this->next = next;
    }
