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
#include<string>
#include "./item/item.h"
#include "./queue/queue.h"
using namespace std;

/*
 The function GetDataFromUser() returns a string, which is the data
 the user provided to push in the Queue or to search in the Queue

*/
string GetDataFromUser(bool isTarget){
    string data;
    if(!isTarget){
        std::cout << "Please enter the data to enQueue: ";
        std::cin>>data;
    }
    else{
        std::cout << "Please enter the target you want to search: ";
        std::cin>>data;
    }

    return data;
}


#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int choice;
    string menu[7] = {
        "------------- OPERATIONS ON QUEUES USING LINKED LIST IN C++ ------------",
        "1 - INFO ABOUT QUEUES",
        "2 - ENQUEUE ITEM",
        "3 - DEQUEUE THE QUEUE",
        "4 - SEARCH ITEM IN QUEUE",
        "5 - DISPLAY THE QUEUE",
        "6 - EXIT"
    };

    
    //Creating a new object of type queue
    Queue *queue = new Queue();

    /*
        checking if there are arguments passed from the terminal:
            ♦ if true: each item will be pushed in the queue
            ♦ if !true: no item will be queue
    */

    if(argc < 2){
        std::cout << "No arguments passed... ! No item to EnQueue..." << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
    }
    else{
        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "EnQueue-ing " << argc - 1 << " items in the Queue..." << std::endl;
           
           //traversing the arguments values and enqueu-ing each item in the Queue
            for (int i = 1; i < argc; i++) {
                std::cout << argv[i] << " ==> ";
                queue->EnQueue(string(argv[i]));

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
                    queue->Info();
                    break;
                case 2:
                    queue->EnQueue(GetDataFromUser(false));
                    break;
                case 3:
                    queue->DeQueue();
                    break;
                case 4:
                    queue->Search(GetDataFromUser(true));
                    break;
                case 5:
                    queue->Display();
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
