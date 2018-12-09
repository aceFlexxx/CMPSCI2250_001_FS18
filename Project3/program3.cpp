#include <iostream>
#include <string>
#include "DynamicStack.h"
#include <string>
using namespace std;

// Constants for the menu choices
// Not needed for this program (taken from book example)
//const int PUSH_CHOICE = 1,
//POP_CHOICE = 2,
//QUIT_CHOICE = 3;
string phrase; //holds input to be checked
char openDelimeters[] = {'{','[', '('};
char closeDelimeters[] = {'}',']', ')'};
//The order is important for parsing
bool complete = false;
//flag to terminate program when finished parsing or if error

// Function prototypes
bool menu(DynamicStack<char> stack);
void getStackSize(int &);
void pushItem(DynamicStack<char> &, char);
void popItem(DynamicStack<char> &);
int main()
{
    //int choice; // To hold a menu choice
    // Create the stack.
    DynamicStack<char> stack;
    do
    {
     // Get the user's menu choice.
     menu(stack);
     // Perform the user's choice.
     //if (choice != QUIT_CHOICE)
     //{
      //   switch (choice)
       //  {
        //     case PUSH_CHOICE:
         //        pushItem(stack);
          //       break;
           //  case POP_CHOICE:
           //      popItem(stack);

        // }

    // }
    } while (!complete);
    return 0;
}
//************************************************
// The menu function displays the menu and gets *
// the user's choice, which is assigned to the *
// reference parameter. *
//************************************************

bool menu(DynamicStack<char> stack)  
{
    // Display the menu and get the user's choice.
   cout << "Enter delimeted string to be parsed:\n";
   cin >> phrase;
   // Validate the choice
    
   char dummy;//dummy char to hold pop and check if it is allowed
   for(int i = 0; i < phrase.length(); i++) 
   {
       for(int j = 0;j  < 3; j++) 
       {

           if(openDelimeters[j] == phrase[i])
           { 
               pushItem(stack, phrase[i]);
           }
           else if(closeDelimeters[j] == phrase[i])
           {
                //reset dummy flag just before popping
               dummy = '\0';
               stack.pop(dummy);
               //Check to see if corresponding delimeter is found 
               
               if((dummy != openDelimeters[j])) 
               {       
                   
                    cout << "You violated the delimeter rules!\n";
                    complete = true;
                    return complete; 

               }
           }
       
       }
    
   }
   dummy = '\0';//reset dummy flag just before popping
   stack.pop(dummy);
   if(dummy != '\0')
   {
       //Check to see if any brackets were left open
        cout << "You violated the delimeter rules!\n";
        complete = true;
        return complete; 
   }
   else//If it the stack is empty. They made it!
   {

        cout << "You passed the delimeter rules!\n";
        complete = true;
        return complete; 

   }
   return complete;
}

//************************************************
// The pushItem function gets an item from the *
// user and pushes it onto the stack. *
//************************************************
void pushItem(DynamicStack<char> &stack, char item)
{
    stack.push(item);
}
//***************************************************
// We don't actually use this function anymore 
//
// The popItem function pops an item from the stack *
//***************************************************
void popItem(DynamicStack<char> &stack)
{
    char item = '\0';
    // Pop the item.
    stack.pop(item);
    // Display the item.
    //if (item != '\0')
    //cout << item << " was popped.\n"; 
}

