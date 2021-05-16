/*
--------------------------------------------------
* IMPLEMENTATION OF SINGLY LINKED LIST USING C++ *
--------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


//Driver code: manipulates the classes Node(node/node.cpp) and List(list/list.cpp)


#include <iostream>
#include <string>
#include "./node/node.h"
#include "./list/list.h"

using namespace std;

/*
 The function GetDataFromUser() returns a string, which is the data
 the user provided to insert in a specific node or a target to search or delete

*/
string GetDataFromUser(bool isTarget){
    string data;
    if(!isTarget){
        std::cout << "Please enter the data of the node: ";
        std::cin>>data;
    }
    else{
        std::cout << "Please enter the target: ";
        std::cin>>data;
    }

    return data;
}


int main(int argc, char** argv)
{
    int choice;
    string menu[8] = {
        "------------------CRUD OPERATIONS WITH SINGLY LINKED LIST---------------------",
        "1 - INSERT NODE ON HEAD",
        "2 - INSERT NODE AT POSITION K",
        "3 - INSERT NODE AT TAIL",
        "4 - SEARCH DATA IN THE LIST",
        "5 - DELETE DATA FROM THE LIST",
        "6 - PRINT THE LIST",
        "7 - EXIT"
    };

    //Creating a new object of type list
    List *LinkedList = new List();

    /*
        checking if there are arguments passed from the terminal:
            ♦ if true: nodes will be constructed with those value and added to the list
            ♦ if !true: no nodes will be contructed
    */

    if(argc < 2){
        std::cout << "No arguments passed... ! No node to build..." << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
    }
    else{
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "Constructing " << argc - 1 << " nodes with the provided arguments..." << std::endl;
           
           //traversing the arguments values and inserting nodes at tail of the list with nodes built with each item of argv
            for (int i = 1; i < argc; i++) {
                std::cout << argv[i] << " ==> ";
                LinkedList->TailInsert(argv[i]);

        }

        std::cout << "List successful built with arguments..." << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;

    }

    while (true)
    {
        //displaying to menu to the user
        std::cout<<std::endl;
            for (int i = 0; i < 8; i++)
            {
                 std::cout << menu[i] << std::endl;   
            }
        std::cout<<std::endl;
            std::cout << "Press the corresponding key to your choice: ";
            std::cin>>choice;

            

            //Performing specifing action depending to the choice of the user
            switch (choice)
            {
                case 1:
                    LinkedList->HeadInsert(GetDataFromUser(false));
                    break;
                case 2:
                    int position;
                    std::cout << "Please enter the position where you want to insert data: ";
                    std::cin>>position;
                    LinkedList->PositionInsert(GetDataFromUser(false), position);
                    break;
                case 3:
                    LinkedList->TailInsert(GetDataFromUser(false));
                    break;
                case 4:
                    LinkedList->Search(GetDataFromUser(true));
                    break;
                case 5:
                    LinkedList->DeleteNode(GetDataFromUser(true));
                    break;
                case 6:
                    LinkedList->Print();
                    break;
                case 7:
                    exit(0);
                default:
                    std::cout << "Please press the right key: ";
                    exit(0);
                    break;
            }

    }    
    system("pause");
    return 0;
}
