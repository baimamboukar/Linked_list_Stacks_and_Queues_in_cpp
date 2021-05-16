/*
----------------------------------------------------
* IMPLEMENTATION OF CIRCULAR LINKED LIST USING C++ *
----------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/

#include <iostream>
#include <string>
#include "list.h"
#include "../node/node.h"


//IMPLEMENTATION FILE OF THE CLASS CIRCULARLIST(declared in list.h)
    

     /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ List(): default constructor, it creates an empty object of type List
            ♦ List(string): parametrized constructor, creates object of type List with
                data inside the first node
                
            ----------------------DESTRUCTOR---------------------------------

            ♦ ~List(): destroys the list

    */


    CircularList::CircularList(){
        this->head = NULL;
        this->size = 0;
    }
    CircularList::CircularList(string data){
        Node *node = new Node(data);
        node->SetNext(NULL);
        this->head = node;
        this->size = 1;
    }
    CircularList::~CircularList(){
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
            ♦ Node* GetHead(): returns the head of the CircularList
            ♦ int GetSize(): returns the size of the CircularList
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetHead(Node*): updates the head of the CircularList
            ♦ void SetSize(int): updates the size of the CircularList
             
    */

    Node* CircularList::GetHead(){
        return this->head;
    }
    int CircularList::GetSize(){
        return this->size;
    }

    void CircularList::SetHead(Node *head){
        this->head = head;
    }
    void CircularList::SetSize(int size){
        this->size = size;
    }


    /*
        METHODS OF THE CLASS CircularList:
        -----------------------INSERTIONS-----------------------------------
            ♦ void HeadInsert(string): add node at the head of the CircularList
            ♦ void TailInsert(string): add node at the tail of the CircularList
            ♦ void PositionInsert(string, int): add node at position k in the CircularList

            ♦ bool Search(string): search a specific target in the CircularList
            ♦ void Delete(string): delete a node whose data is the target


    */

    void CircularList::HeadInsert(string data){
        Node *node = new Node(data);
        cout<<endl;
        std::cout << "Inserting " << data <<" in the list...." << std::endl;

        /*
            -----Checking if the list is empty or not-------
        */

        //if so, insert new noed at head, and make it points to itself
        if(this->GetHead() == NULL){
            this->SetHead(node); //inserting the new node at head
            node->SetNext(this->GetHead()); // the head points to itself, at it is the only node

            this->SetSize(this->GetSize() + 1); //incrementing the size after inserting
            std::cout << data << " inserted in the list..." << std::endl;
            return;
        }


        //if not so, perform the insertion process
        Node *ptr = this->GetHead();

        while (ptr->GetNext() != this->GetHead())
        {
            ptr = ptr->GetNext();
        }
        node->SetNext(this->GetHead());
        this->SetHead(node);
        ptr->SetNext(this->GetHead());

         this->SetSize(this->GetSize() + 1); //incrementing the size after inserting
        std::cout << data << " inserted in the list..." << std::endl;
        cout<<endl;

    }


    void CircularList::TailInsert(string data){
        /*
            Checking if the list is empty...
                If so, data will be inserted at head
        */

        if(this->GetHead() == NULL){
            std::cout << "Cannot insert data at tail! This list is empty...." << std::endl;
            this->HeadInsert(data);
            return;
        }

        //Inserting data at tail
        Node *node = new Node(data);
        Node *ptr = this->GetHead();

        //looping trought the list and finding the last element
        while(ptr->GetNext() != this->GetHead())
        {
            ptr = ptr->GetNext();
        }

        //performing tail insertion operation
        ptr->SetNext(node);
        node->SetNext(this->GetHead());
        SetSize(GetSize() + 1); //incrementing the size of the list after insertion
        std::cout << "-------------------------------------------------------" << std::endl;
    }



    void CircularList::PositionInsert(string data, int position){

         //Handling the case where the user gives a wrong value of position
        if(this->GetSize() < position){
            std::cout << "Cannot insert data at position " << position << "! Not enough elements in the list...." << std::endl;
            return;
        }
        //Handling the case where the position is 1 (inserting data at the head)
        if(position == 1){
            this->HeadInsert(data);
        }
        //handling the case where position != 1
        position -= 1;
        Node *ptr = this->GetHead();
        while(ptr != this->GetHead() && --position)
        {
            ptr = ptr->GetNext();
        }

        Node *node = new Node(data);
        node->SetNext(ptr->GetNext());
        ptr->SetNext(node);
        SetSize(GetSize() + 1);
        std::cout << "Data inserted at position " << position << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;

    }

    bool CircularList::Search(string target){

        std::cout << "Looking for " << target << " in the list..." << std::endl;
        Node *ptr = this->GetHead();
        //Handling the case where the target is at head
        if(ptr->GetData() == target){
            std::cout << target <<" found at head of the list..." << std::endl;
            return true;
        }

        //traversing the list to find target
        int index = 1;
        
        do{
            if(ptr->GetData() == target){
                std::cout << target << " found in the list at index " << index << std::endl;
                return true;
            }
            ptr = ptr->GetNext();
            index++;
        }
        while (ptr != this->GetHead());
        
        std::cout << target << " not found in the list..." << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        return false;
    }
    void CircularList::Delete(string target){
        if(this->Search(target) == true){
            //Traversing the list and looking for target
             Node *ptr = this->GetHead();
            std::cout << "Deleting " << target << " from the list..." << std::endl;

            //Handling the case where the target is found at the head of the list
            if(ptr->GetData() == target){
                SetHead(ptr->GetNext());
                delete(ptr);
                SetSize(GetSize() - 1);
                return;
            }
            //Handling the case where the target is not found at head
            Node *next = ptr->GetNext();

            do{
                 ptr = ptr->GetNext();
                next = ptr->GetNext();
            }
            while (ptr->GetNext() != this->GetHead() && next->GetData() != target);
            
            if(ptr != this->GetHead()){
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

    void CircularList::Print(){
        if(this->GetSize() < 1){
           std::cout << "There is no item in the list..." << std::endl;
           return;
       }
       std::cout << "---------------------------------------------------" << std::endl;
        Node *ptr = this->GetHead();
        std::cout << "THE LIST HAS "<< this->GetSize() << " ELEMENTS..." << std::endl;

        //Traversing the list and prining each node
        if(this->GetHead() != NULL){
            do{
                std::cout << "[data => " 
                 << ptr->GetData()
                 <<" | next => "
                 <<ptr->GetNext()
                 <<" ]"
                << std::endl;

                 ptr = ptr->GetNext();
            } 
            while(ptr != this->GetHead());

        }
    }
