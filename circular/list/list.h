/*
--------------------------------------------------
* IMPLEMENTATION OF SINGLY LINKED CircularList USING C++ *
--------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


#include "../node/node.h"


//DELCARATION OF THE CLASS CircularList (implemented in list.cpp)

class CircularList{
    /*
        DATA ATTRIBUTES:
            ♦ head: stores the adress of the first node of the CircularList
            ♦ size: stores the number of elements of the CircularList

    */

    Node *head;
    int size;

    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ CircularList(): default constructor, it creates an empty object of type CircularList
            ♦ CircularList(string): parametrized constructor, creates object of type CircularList with
                data inside the first node

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~CircularList(): destroys the CircularList

    */
public:
    CircularList();
    CircularList(string data);
    ~CircularList();


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ Node* GetHead(): returns the head of the CircularList
            ♦ int GetSize(): returns the size of the CircularList
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetHead(Node*): updates the head of the CircularList
            ♦ void SetSize(int): updates the size of the CircularList
             
    */

    Node* GetHead();
    int GetSize();

    void SetHead(Node *head);
    void SetSize(int size);


    /*
        METHODS OF THE CLASS CircularList:
        -----------------------INSERTIONS-----------------------------------
            ♦ void HeadInsert(string): add node at the head of the CircularList
            ♦ void TailInsert(string): add node at the tail of the CircularList
            ♦ void PositionInsert(string, int): add node at position k in the CircularList

            ♦ bool Search(string): search a specific target in the CircularList
            ♦ void DeleteNode(string): delete a node whose data is the target


    */

    void HeadInsert(string data);
    void TailInsert(string data);
    void PositionInsert(string data, int position);

    bool Search(string target);
    void Delete(string target);

    void Print();

};