/*
-----------------------------------------------------
* IMPLEMENTATION OF STACKS USING LINKED LIST IN C++ *
-----------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


#include "../node/node.h"


//DELCARATION OF THE CLASS STACK (implemented in stack.cpp)

class Stack{
    /*
        DATA ATTRIBUTES:
            ♦ top: stores the adress of the first element of the stack
            ♦ size: stores the number of elements of the stack

    */

    Node *top;
    int size;

    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ Satck(): default constructor, it creates an empty object of type Stack
            ♦ Stack(string): parametrized constructor, creates object of type Stack with
                data inside the first element

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~Stack(): destroys the satck

    */
public:
    Stack();
    Stack(string data);
    ~Stack();


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ Node* GetTop(): returns the top element of the stack
            ♦ int GetSize(): returns the size of the stack
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetTop(Node*): updates the top of the stack
            ♦ void SetSize(int): updates the size of the stack
             
    */

    Node* GetTop();
    int GetSize();

    void SetTop(Node *top);
    void SetSize(int size);


    /*
        METHODS OF THE CLASS STACK:
            ♦ void Info(): give some informations about stacks
            ♦ void Push(string): add element in the stack
            ♦ void Pop(): remove element from the stack
            ♦ bool IsEmpty(): returns true if the stack is empty
            ♦ bool Search(string): search a specific target in the stack
            ♦ Display(): traverse the stack an print each element


    */
    void Info();
    void Push(string data);
    void Pop();
    bool IsEmpty();

    bool Search(string target);

    void Display();

};