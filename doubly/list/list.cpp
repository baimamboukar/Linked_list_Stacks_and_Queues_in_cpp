/*
--------------------------------------------------
* IMPLEMENTATION OF DOUBLY LINKED LIST USING C++ *
--------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/

#include <iostream>
#include <string>
#include "list.h"
#include "./../node/node.h"
using namespace std;

 
 /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ DoublyList(): default constructor, it creates an empty object of type List
            ♦ DoublyList(string): parametrized constructor, creates object of type List with
                data inside the first node

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~DoublyList(): destroys the list

    */


    DoublyList::DoublyList(){
        this->head = NULL;
        this->size = 0;
    }


    DoublyList::DoublyList(string data){
        Node *node = new Node(data);
        node->SetNext(NULL);
        this->head = node;
        this->size = 1;
    }

    DoublyList::~DoublyList(){
        std::cout << "Destroying the list......" << std::endl;
        Node *ptr = this->head, *next = NULL;
        while (ptr != NULL)
        {
            next = ptr->GetNext();
            delete(ptr);
            ptr = next;
        }
        std::cout << "List destructed...." << std::endl;
    }


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ Node* GetHead(): returns the head of the list
            ♦ int GetSize(): returns the size of the list
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetHead(Node*): updates the head of the list
            ♦ void SetSize(int): updates the size of the list
             
    */

    Node* DoublyList::GetHead(){
        return this->head;
    }
    int DoublyList::GetSize(){
        return this->size;
    }

    void DoublyList::SetHead(Node *head){
        this->head = head;
    }
    void DoublyList::SetSize(int size){
        this->size = size;
    }


    /*
        METHODS OF THE CLASS LIST:
        -----------------------INSERTIONS-----------------------------------
            ♦ void HeadInsert(string): add node at the head of the list
            ♦ void TailInsert(string): add node at the tail of the list
            ♦ void PositionInsert(string, int): add node at position k in the list

            ♦ bool Search(string): search a specific target in the list
            ♦ void DeleteNode(string): delete a node whose data is the target


    */

    void DoublyList::HeadInsert(string data){
        cout<<endl;
        std::cout << "Inserting " << data << " at the head of the list" << std::endl;
        Node *node = new Node(data);
        Node *head = this->GetHead();
        if(head == NULL){
            node->SetNext(NULL);
            node->SetPrevious(NULL);
            this->SetHead(node);
            this->SetSize(this->GetSize() + 1);
            std::cout << data << "has been inserted in the list" << std::endl;
        }
        else{
            
            node->SetNext(head); //the head becomes the next node of the new one
            head->SetPrevious(node); //vice-versa, the new node becomes the previous node of the head
            this->SetHead(node); //the new node becomes the head of the list
             this->SetSize(this->GetSize() + 1);
            std::cout << data << "has been inserted in the list" << std::endl;
            cout<<endl;
        }
       
        
        
    }
    void DoublyList::TailInsert(string data){
        std::cout << "Inserting " << data << " at the tail of the list..." << std::endl;
        /*
            -------Checking if the list is empty---------
        */

        //if so, insert data on the head(cannot insert node at tail of an empty list)
        if(this->GetHead() == NULL){
            std::cout << "The list is empty! Cannot insert at tail" << std::endl;
            this->HeadInsert(data);
            return;
        }
        //if not so, perform the tail insertion
        std::cout << "Inserting " << data << " at the tail of the list..." << std::endl;
        Node *node = new Node(data);
        Node *ptr = this->GetHead();
        //traversing the list until reaching the last node
        while (ptr->GetNext() != NULL)
        {
            ptr = ptr->GetNext();
        }
        //performing the tail insetion operations
        ptr->SetNext(node);
        node->SetPrevious(ptr);
        SetSize(GetSize() + 1);
        std::cout << data <<" has been inserted at tail..." << std::endl;

    }
    void DoublyList::PositionInsert(string data, int position){
         //Handling the case where the user gives a wrong value of position
        if(this->GetSize() < position){
            std::cout << "Cannot insert data at position " << position << "! Not enough elements in the list...." << std::endl;
            return;
        }
        //Handling the case where the position is 1 (inserting data at the head)
        if(position == 1){
            HeadInsert(data);
        }
        //handling the case where position != 1
        position -= 1;
        Node *ptr = this->GetHead();
        while(ptr != NULL && --position)
        {
            ptr = ptr->GetNext();
        }
        if(ptr == NULL){
            return;
        }
        Node *node = new Node(data);
        Node *next = ptr->GetNext();
        node->SetNext(next);
        next->SetPrevious(node);
        ptr->SetNext(node);
        node->SetPrevious(ptr);

        SetSize(GetSize() + 1);

        std::cout << data << " inserted at position " << position << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }

    bool DoublyList::Search(string target){
        std::cout << "Looking for " << target << " in the list..." << std::endl;
        Node *ptr = this->GetHead();
        //Handling the case where the target is at head
        if(ptr->GetData() == target){
            std::cout << target <<" found at head of the list..." << std::endl;
        }

        //traversing the list to find target
        int index = 1;
        while (ptr != NULL)
        {
            if(ptr->GetData() == target){
                std::cout << target << " found in the list at index " << index << std::endl;
                return true;
            }
            ptr = ptr->GetNext();
            index++;
        }
        
        std::cout << target << " not found in the list..." << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        return false;
    }




    void DoublyList::Delete(string target){
        if(this->Search(target) == true){
            //Traversing the list and looking for target
             Node *ptr = this->GetHead();
            std::cout << "Deleting " << target << " from the list..." << std::endl;

            //Handling the case where the target is found at the head of the list
            if(ptr->GetData() == target){
                this->SetHead(ptr->GetNext());
                delete(ptr);
                SetSize(GetSize() - 1);
                return;
            }
            //Handling the case where the target is not found at head
            Node *next = ptr->GetNext();
            while (ptr->GetNext() != NULL && next->GetData() != target)
            {
                ptr = ptr->GetNext();
                next = ptr->GetNext();
            }
            
            if(ptr != NULL){
                Node *previous = next->GetPrevious();
                previous->SetNext(next->GetNext());
                delete(next);   
            }

            SetSize(GetSize() - 1);
            std::cout << target << " deleted  from the list..." << std::endl;
        }
        else{
            std::cout << "Cannot delete a node that is not in the list..." << std::endl;
            return;
        }
        std::cout << "-------------------------------------------------------" << std::endl;
    }




    void DoublyList::Print(){
         if(this->GetHead() == NULL){
           std::cout << "There is no item in the list..." << std::endl;
           return;
       }
       std::cout << "---------------------------------------------------" << std::endl;
        Node *ptr = this->GetHead();
        std::cout << "THE LIST HAS "<< this->GetSize() << " ELEMENTS..." << std::endl;

        //Traversing the list and printing each node
        while (ptr != NULL)
        {
            std::cout 
                <<" [ "
                 << ptr->GetPrevious()
                 << " <== Previous |"
                 << " Data: " 
                 << ptr->GetData()
                 <<" | Next ==> "
                 <<ptr->GetNext()
                 <<" ] "
            << std::endl;

            ptr = ptr->GetNext(); //move our pointer to next, after printing data
        }
    }