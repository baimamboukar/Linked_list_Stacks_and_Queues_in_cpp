/*
-----------------------------------------------------
* IMPLEMENTATION OF STACKS USING LINKED LIST IN C++ *
-----------------------------------------------------

written by: BAIMAM BOUKAR JEAN JACQUES
email: baimam.jeanjaque@ictuniversity.edu.cm
phone: (+237) 690 53 57 59 / 679 78 22 55
github: www.github.com/baimamboukar

*/


#include <iostream>
#include<string>
#include "./node/node.h"
#include "./stack/stack.h"
using namespace std;

/*
 The function GetDataFromUser() returns a string, which is the data
 the user provided to push in the stack or to search in the stack

*/
string GetDataFromUser(bool isTarget){
    string data;
    if(!isTarget){
        std::cout << "Please enter the data to push: ";
        std::cin>>data;
    }
    else{
        std::cout << "Please enter the target you want to search: ";
        std::cin>>data;
    }

    return data;
}



int main(int argc, char** argv)
{
    int choice;
    string menu[7] = {
        "--------------- STACKS USING LINKED LIST IN C++ ----------------",
        "1 - INFO ABOUT STACKS",
        "2 - PUSH ITEM",
        "3 - POP THE STACK",
        "4 - SEARCH ITEM",
        "5 - DISPLAY THE STACK",
        "6 - EXIT"
    };

    
    //Creating a new object of type Stack
    Stack *stack = new Stack();

    /*
        checking if there are arguments passed from the terminal:
            ♦ if true: each item will be pushed in the stack
            ♦ if !true: no item will be pushed
    */

    if(argc < 2){
        std::cout << "No arguments passed... ! No item to push..." << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
    }
    else{
        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "Pushing " << argc - 1 << " items in the stack..." << std::endl;
           
           //traversing the arguments values and pushing each item in the stack
            for (int i = 1; i < argc; i++) {
                std::cout << argv[i] << " ==> ";
                stack->Push(string(argv[i]));

        }
    }

    while (true)
    {
        //displaying to menu to the user
        std::cout<<std::endl;
            for (int i = 0; i < 7; i++)
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
                    stack->Info();
                    break;
                case 2:
                    stack->Push(GetDataFromUser(false));
                    break;
                case 3:
                    stack->Pop();
                    break;
                case 4:
                    stack->Search(GetDataFromUser(true));
                    break;
                case 5:
                    stack->Display();
                    break;
                case 6:
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
