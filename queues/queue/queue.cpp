/*
-----------------------------------------------------
* IMPLEMENTATION OF QUEUES USING LINKED LIST IN C++ *
-----------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


#include <iostream>
#include "../item/item.h"
#include "queue.h"

//IMPLEMENTATION OF THE CLASS Queue (declared in queue.h)


    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ Queue(): default constructor, it creates an empty object of type Queue
            ♦ Queue(string): parametrized constructor, creates object of type Queue with
                data inside the first element

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~Queue(): destroys the satck

    */

    Queue::Queue(){
        this->front, this->rear = NULL;
        this->size = 0;
    }
    Queue::Queue(string data){
        QueueItem *item = new QueueItem(data);
        this->front = item;
        this->rear = NULL;
        this->size = 1;
    }
    Queue::~Queue(){
        std::cout << "Destroying the Queue...." << std::endl;
        QueueItem *ptr = this->GetFront(), *next = NULL;
        while( ptr!= NULL)
        {
            next = ptr->GetNext();
            delete(ptr);
            ptr = next;
        }
        std::cout << "Queue destroyed...." << std::endl;
    }


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

    QueueItem* Queue::GetFront(){
        return this->front;
    }
    QueueItem* Queue::GetRear(){
        return this->rear;
    }
    int Queue::GetSize(){
        return this->size;
    }

    void Queue::SetFront(QueueItem *front){
        this->front = front;
    }
    void Queue::SetRear(QueueItem *rear){
        this->rear = rear;
    }
    void Queue::SetSize(int size){
        this->size = size;
    }


    /*
        METHODS OF THE CLASS Queue:
            ♦ void Info(): give some informations about Queues
            ♦ void EnQueue(string): add element in the Queue
            ♦ void DeQueue(): remove element from the Queue
            ♦ bool IsEmpty(): returns true if the Queue is empty
            ♦ bool Search(string): search a specific target in the Queue
            ♦ Display(): traverse the Queue an print each element


    */
    void Queue::Info(){
        std::cout << "---------------WHAT ARE QUEUES ?----------------" << std::endl;
        std::cout 
            <<"QUES are FIFO(First In First Out) data structures \n"
            << "When dealing with Queues, we have generally three methods \n"
            <<"*[EnQueue method] => to push element in the Queue: It insert element at the top element of the Queue \n"
            <<"*[DeQueue mehtod] => to delete element from the Queue: It removes the last element of the Queue"
            <<"i.e the oldest element \n"
            <<"* A method to check if the Queue is empty"
        <<std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    }
    void Queue::EnQueue(string data){
        QueueItem *item = new QueueItem(data);
        cout<<endl;
        std::cout << "Inserting " << data << " in the Queue...." << std::endl;
        cout<<endl;

        //Handling the case where the Queue is empty
        if(this->GetRear() == NULL){
            this->SetFront(item);
            this->SetRear(item);
            return;
        }

        //Hanadling the case where the Queue is not empty
        QueueItem *rear = this->GetRear();
        rear->SetNext(item); //inserting the new item after last element
        this->SetRear(item); //the new item becomes now the last element

        this->SetSize(this->GetSize() + 1); //incrementing the size of the queue after enqueue
        cout<<endl;
        std::cout << data << " successful inserted in the Queue...." << std::endl <<std::endl;
        cout<<endl;


    }
    void Queue::DeQueue(){
        //Handling the case where the Queue is empty
        if(this->GetSize() == 0){
            cout<<endl;
            std::cout << "|||--- Impossible to DeQueue an empty Queue ---|||" << std::endl;
            cout<<endl;
            return;
        }

        //Performing the DeQueue operation
        QueueItem *front = this->GetFront();
        this->SetFront(front->GetNext());
        delete(front);

         this->SetSize(this->GetSize() - 1); //decrementing the size of the queue after dequeue
         cout<<endl;
         std::cout << "Successful DeQueue operation........." << std::endl;
         cout<<endl;

    }
    bool Queue::IsEmpty(){
        if(this->GetSize() > 0){
            return true;
        }
        else{
            return false;
        }
    }

    bool Queue::Search(string target){

        //Handling the case where the Queue is empty
        if(this->GetSize() == 0){
            cout<<endl;
            std::cout << "|||--- The Queue is empty, cannot search ---|||" << std::endl;
            cout<<endl;
            return false;
        }
        QueueItem *ptr = this->GetFront();
        int index = 1;

        //Traversing the Queue and looking for the target item
        while (ptr->GetNext() != NULL)
        {
            if(ptr->GetData() == target){
                cout<<endl;
                std::cout <<"Eureka! " << target << " found in the Queue at position " << index << std::endl;
                cout<<endl;
                return true;
            }
            ptr = ptr->GetNext(); //mooving the ptr to the next QueueItem after checking
            index++;
        }

        //Checking if the rear of the Queue is the target item
        if(ptr->GetData() == target){
            cout<<endl;
                std::cout << target << " found in the Queue at position " << index << std::endl;
            cout<<endl;
                return true;
        }
        else{
            cout<<endl;
            std::cout << "Sorry! " << target<< " is not found in this Queue..." << std::endl;
            cout<<endl;
            return false;
        }

            
    }

    void Queue::Display(){
        //Handling the case where the Queue is empty
        if(this->GetSize() == 0){
            std::cout << "|||--- The Queue is empty, nothing to print ---|||" << std::endl;
            return;
        }
        QueueItem *ptr = this->GetFront();
        int index = 1;

        //Traversing the Queue and printing each item
        while (ptr->GetNext() != NULL)
        {
            std::cout 
                << index
                << " - "
                << ptr->GetData()
                <<
            std::endl;

            ptr = ptr->GetNext(); //mooving the ptr to the next QueueItem after printing
            index++;
        }

            //Printing the last element of the Queue
            std::cout 
                << index
                << " - "
                << ptr->GetData()
                <<
            std::endl;
    }

