/*
-----------------------------------------------------
* IMPLEMENTATION OF QUEUES USING LINKED LIST IN C++ *
-----------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/ 

//IMPLEMENTATION FILE OF THE CLASS QueueItem (declared in item.h)
#include "item.h"
#include <string>
#include <iostream>
using namespace std;


    /*
        CONTRUCTORS:
            ♦ QueueItem(): default constructor, it creates an empty object of type QueueItem
            ♦ QueueItem(string): parametrized constructor, creates object of type QueueItem with data inside

    */

    QueueItem::QueueItem(){
        std::cout << "building item with default constructor..." << std::endl;
        this->data = "";
        this->next = NULL;
        std::cout << "Queue item successfuly built..." << std::endl;
    }
    QueueItem::QueueItem(string value){
        std::cout << "building Queue item with parametried constructor..." << std::endl;
        this->data = value;
        this->next = NULL;
        std::cout << "Queue item built with paramater " << value  << std::endl;
    }


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ string GetData(): default constructor, it creates an empty object of type QueueItem
            ♦ QueueItem *GetNext(): parametrized constructor, creates object of type QueueItem with data inside
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetData(string): updates the data kept in the QueueItem
            ♦ void SetNext(QueueItem*): updates the next QueueItem
             
    */

    string QueueItem::GetData(){
        return this->data;
    }
    QueueItem* QueueItem::GetNext(){
        return this->next;
    }

    void QueueItem::SetData(string value){
        this->data = value;
    }
    void QueueItem::SetNext(QueueItem *next){
        this->next = next;
    }
