/*
-----------------------------------------------------
* IMPLEMENTATION OF QUEUES USING LINKED LIST IN C++ *
-----------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/

#pragma once
#include "../item/item.h"
#include <string>

//DELCARATION OF THE CLASS Queue (implemented in queue.cpp)
class Queue{
    /*
        DATA ATTRIBUTES:
            ♦ front: stores the adress of the first element of the Queue
            ♦ rear: stores the address of the last element of the Queue
            ♦ size: stores the number of elements of the Queue

    */

    QueueItem *front;
    QueueItem *rear;
    int size;

    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ Queue(): default constructor, it creates an empty object of type Queue
            ♦ Queue(string): parametrized constructor, creates object of type Queue with
                data inside the first element

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~Queue(): destroys the satck

    */
public:
    Queue();
    Queue(string data);
    ~Queue();


    /*
                             ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ QueueItem* GetFront(): returns the top element of the Queue
            ♦ QueueItem* GetRear(): returns the last element of the Queue
            ♦ int GetSize(): returns the size of the Queue
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetFront(QueueItem*): updates the top of the Queue
            ♦ void SetRear(QueueItem*): updates the back of the Queue
            ♦ void SetSize(int): updates the size of the Queue
             
    */

    QueueItem* GetFront();
    QueueItem* GetRear();
    int GetSize();

    void SetFront(QueueItem *top);
    void SetRear(QueueItem *top);
    void SetSize(int size);


    /*
        METHODS OF THE CLASS Queue:
            ♦ void Info(): give some informations about Queues
            ♦ void EnQueue(string): add element in the Queue
            ♦ void DeQueue(): remove element from the Queue
            ♦ bool IsEmpty(): returns true if the Queue is empty
            ♦ bool Search(string): search a specific target in the Queue
            ♦ Display(): traverse the Queue an print each element


    */
    void Info();
    void EnQueue(string data);
    void DeQueue();
    bool IsEmpty();

    bool Search(string target);

    void Display();

};