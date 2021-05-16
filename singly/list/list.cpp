/*
--------------------------------------------------
* IMPLEMENTATION OF SINGLY LINKED LIST USING C++ *
--------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


//IMPLEMENTATION FILE OF THE CLASS LIST (declared in list.h)
#include <iostream>
#include <string>
#include "list.h"
#include "../node/node.h"

using namespace std;

    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ List(): default constructor, it creates an empty object of type List
            ♦ List(string): parametrized constructor, creates object of type List with
                data inside the first node
                
            ----------------------DESTRUCTOR---------------------------------

            ♦ ~List(): destroys the list

    */

    List::List(){
        this->head = NULL;
        this->size = 0;
    }

    List::List(string data){
        Node *node = new Node(data);
        node->SetNext(NULL);
        this->head = node;
        this->size = 1;
    }

    List::~List(){
        std::cout << "Destroying the list...." << std::endl;
        Node *ptr = this->GetHead(), *next = NULL;
        while( ptr!= NULL)
        {
            next = ptr->GetNext();
            delete(ptr);
            ptr = next;
        }
        std::cout << "List destroyed...." << std::endl;
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

    Node* List::GetHead(){
        return this->head;
    }
    int List::GetSize(){
        return this->size;
    }

    void List::SetHead(Node *head){
        this->head = head;
    }
    void List::SetSize(int size){
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

    void List::HeadInsert(string data){
        std::cout << "Inserting " << data << " at the head of the list..." << std::endl;

        Node *node = new Node(data);
        node->SetNext(GetHead());
        SetHead(node);

        SetSize(GetSize() + 1); //incrementing the size of the list

        std::cout << data << " Inserted at head of the list..." << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    }
    void List::TailInsert(string data){
        /*
            Checking if the list is empty...
                If so, data will be inserted at head
        */

        if(GetHead() == NULL){
            std::cout << "Cannot insert data at tail! This list is empty...." << std::endl;
            HeadInsert(data);
            return;
        }
        //Inserting data at tail
        Node *node = new Node(data);
        Node *ptr = GetHead();

        //looping trought the list and finding the last element
        while(ptr->GetNext() != NULL)
        {
            ptr = ptr->GetNext();
        }

        //performing tail insertion operation
        ptr->SetNext(node);
        SetSize(GetSize() + 1); //incrementing the size of the list after insertion
        std::cout << "-------------------------------------------------------" << std::endl;
    }
    void List::PositionInsert(string data, int position){
        //Handling the case where the user gives a wrong value of position
        if(GetSize() < position){
            std::cout << "Cannot insert data at position " << position << "! Not enough elements in the list...." << std::endl;
            return;
        }
        //Handling the case where the position is 1 (inserting data at the head)
        if(position == 1){
            HeadInsert(data);
        }
        //handling the case where position != 1
        position -= 1;
        Node *ptr = GetHead();
        while(ptr != NULL && --position)
        {
            ptr = ptr->GetNext();
        }
        if(ptr == NULL){
            return;
        }
        Node *node = new Node(data);
        node->SetNext(ptr->GetNext());
        ptr->SetNext(node);
        SetSize(GetSize() + 1);
        std::cout << "Data inserted at position " << position << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;

    }

    bool List::Search(string target){
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
    void List::DeleteNode(string target){
        
        if(this->Search(target) == true){
            //Traversing the list and looking for target
             Node *ptr = this->GetHead();
            std::cout << "Deleting " <<target << " from the list..." << std::endl;

            //Handling the case where the target is found at the head of the list
            if(ptr->GetData() == target){
                SetHead(ptr->GetNext());
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
                Node *tmp = ptr->GetNext(); //store the next node in a tmp variable
                Node *tmpNext = ptr->GetNext(); //stores the next node of the next node in second tmp variable to avoid chaining pointes ( xxx ptr->GetNext()->GetNext() xxx)
                ptr->SetNext(tmpNext->GetNext());
                delete(tmp);
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

    void List::Print(){
       if(GetSize() == 0){
           std::cout << "There is no item in the list..." << std::endl;
           return;
       }
       std::cout << "---------------------------------------------------" << std::endl;
        Node *ptr = GetHead();
        std::cout << "THE LIST HAS "<< this->GetSize() << " ELEMENTS..." << std::endl;
        //Traversing the list and prining each node
        while (ptr != NULL)
        {
            std::cout << "[data => " 
                 << ptr->GetData()
                 <<" | next => "
                 <<ptr->GetNext()
                 <<" ]"
            << std::endl;

            ptr = ptr->GetNext(); //move our pointer to next, after printing data
        }

       
    }




