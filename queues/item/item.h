/*
-----------------------------------------------------
* IMPLEMENTATION OF QUEUES USING LINKED LIST IN C++ *
-----------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/ 


//DELCARATION FILE OF THE CLASS QueueItem (implemented in item.cpp)
#pragma once
#include <string>
using namespace std;


class QueueItem{
    /*
        DATA ATTRIBUTES:
            *data: stores the data that will be kept in the QueueItem
            *next: stores the address of the next QueueItem

    */
    string data;
    QueueItem *next;

    /*
        CONTRUCTORS:
            ♦ QueueItem(): default constructor, it creates an empty object of type QueueItem
            ♦ QueueItem(string): parametrized constructor, creates object of type QueueItem with data inside

    */
public:
    QueueItem();
    QueueItem(string);


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ string GetData(): returns the data kept in the QueueItem
            ♦ QueueItem *GetNext(): returns the thex QueueItem
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetData(string): updates the data kept in the QueueItem
            ♦ void SetNext(QueueItem*): updates the next QueueItem
             
    */

    string GetData();
    QueueItem* GetNext();

    void SetData(string);
    void SetNext(QueueItem*);

};