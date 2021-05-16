/*
--------------------------------------------------
* IMPLEMENTATION OF DOUBLY LINKED LIST USING C++ *
--------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


#include "../node/node.h"
#include <string>


//DELCARATION OF THE CLASS DOUBLYLIST (implemented in list.cpp)

class DoublyList{
    /*
        DATA ATTRIBUTES:
            ♦ head: stores the adress of the first node of the list
            ♦ size: stores the number of elements of the list

    */

    Node *head;
    int size;

    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ DoublyList(): default constructor, it creates an empty object of type List
            ♦ DoublyList(string): parametrized constructor, creates object of type List with
                data inside the first node

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~DoublyList(): destroys the list

    */
public:
    DoublyList();
    DoublyList(string data);
    ~DoublyList();


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ Node* GetHead(): returns the head of the list
            ♦ int GetSize(): returns the size of the list
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetHead(Node*): updates the head of the list
            ♦ void SetSize(int): updates the size of the list
             
    */

    Node* GetHead();
    int GetSize();

    void SetHead(Node *head);
    void SetSize(int size);


    /*
        METHODS OF THE CLASS LIST:
        -----------------------INSERTIONS-----------------------------------
            ♦ void HeadInsert(string): add node at the head of the list
            ♦ void TailInsert(string): add node at the tail of the list
            ♦ void PositionInsert(string, int): add node at position k in the list

            ♦ bool Search(string): search a specific target in the list
            ♦ void DeleteNode(string): delete a node whose data is the target


    */

    void HeadInsert(string data);
    void TailInsert(string data);
    void PositionInsert(string data, int position);

    bool Search(string target);
    void Delete(string target);

    void Print();

};