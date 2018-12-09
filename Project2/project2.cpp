// This program demonstrates the Account class.
  #include <iostream>
  #include <cctype>
  #include <iomanip>
  #include "Account.h"
  #include <algorithm>

  using namespace std;

  // Function prototypes
  void displayMenu();
  void makeDeposit(Account &);
  void withdraw(Account &);
  
  void makeInvestment(Account &);
  void withdrawInvestment(Account &);
  void contributeRetirement(Account &);

  int main()
  {
       Account savings; // Savings account object
       char choice;     // Menu Selection
       char options[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G','I','R','S','W','X'};//List of menu options allowed for input      
       bool found = false;//Flag to see if input is found
       do
       {
           //displays the menu and get a valid selection.
           displayMenu();
           cin >> choice;
           found = false;//Makes sure found flag is reset every time char is entered

           while (!found)
           {
               //Process the user's menu selection
               for(int i = 0; i < sizeof(options);++i)//For loop checks if choice is allowed.
               {
                   //If it's found break the loop and resume.
                   if(options[i] == toupper(choice))
                   {
                       found = true;
                       break;
                   }
                   else 
                   {
                       found = false;
                   }
                
               }
               if(!found)//Checks to see if it was an incorrect choice.
               {
                   cout << "Please make a choice from the menu: ";
                   cin >> choice;
               }
           }
           switch(choice)
           {
               case 'a':
               case 'A': cout << "The current balance is $";
                         cout << savings.getBalance() << endl;
                         break;
               case 'b':
               case 'B': cout << "There have been ";
                         cout << savings.getTransactions() << " transactions.\n";
                         break;
                         
               case 'c':
               case 'C': cout << "Interest earned for this period: $";
                         cout << savings.getInterest() << endl;
                         break;
               case 'd':
               case 'D': makeDeposit(savings);
                         break;
               case 'e':
               case 'E': withdraw(savings);
                         break;
               case 'f':
               case 'F': savings.calcInterest();
                         cout << "Interest added.\n";
                         break; 
               case 'I':
               case 'i': makeInvestment(savings); 
                         break;
               case 'R':
               case 'r': contributeRetirement(savings); 
                         break;
                         
               case 'S':
               case 's': cout << "Balance of retirment fund is $";
                         cout << savings.getRetirementAmount() << endl;
                         break;               
               case 'W':
               case 'w': withdrawInvestment(savings);
                         break;
               case 'X':
               case 'x': 
                         cout << "Balance of investment fund is $";
                         cout << savings.getInvestmentAmount() << endl;
                         break;               

           }
       }while (toupper(choice) != 'G');
       return 0;
      
  }

//*****************************************************
// Definition of function displayMenu. This function 
// displays the user's menu on the screen. 
//*****************************************************
void displayMenu()
 {
     cout << "\n MENU\n";
     cout << "-----------------------------------------\n";
     cout << "A) Display the account balance\n";
     cout << "B) Display the number of transactions\n";
     cout << "C) Display interest earned for this period\n";
     cout << "D) Make a deposit\n";
     cout << "E) Make a withdrawal\n";
     cout << "F) Add interest for this period\n";
//Added options on Menu and moved G down.
     cout << "I) Make an investment\n";
     cout << "R) Make a retirement contribution\n";
     cout << "S) Display the amount of the retirement fund\n";
     cout << "W) Withdraw from the investment\n";
     cout << "X) Display the amount of the investment fund\n";
     cout << "G) Exit the program\n\n";
     cout << "Enter your choice: ";
 }

//**************************************************************
// Definition of function makeDeposit. This function accepts *
// a reference to an Account object. The user is prompted for *
// the dollar amount of the deposit, and the makeDeposit *
// member of the Account object is then called. *
//**************************************************************
void makeDeposit(Account &acnt)
{
    double dollars;
    
    cout << "Enter the amount of the deposit: ";
    cin >> dollars;
    cin.ignore();
    acnt.makeDeposit(dollars);
}

//**************************************************************
// Definition of function Withdraw. This function accepts *
// a reference to an Account object. The user is prompted for *
// the dollar amount of the withdraw, and the Withdraw *
// member of the Account object is then called. Checks to see if amount is allowed*
//**************************************************************
void withdraw(Account &acnt)
{  
    double dollars;
    
    cout << "Enter the amount of the withdrawal: ";
    cin >> dollars; 
    cin.ignore();
    if (!acnt.withdraw(dollars))
    {
        cout << "ERROR: Withdrawal amount too large.\n\n";
    }
    else
    {

    }
    
}

//**************************************************************
// Definition of function makeInvestment. This function accepts *
// a reference to an Account object. The user is prompted for *
// the dollar amount of the investment, and the makeInsvestment *
// member of the Account object is then called.*
//*************************************************************
void makeInvestment(Account &acnt)
{
    double dollars;
    
    cout << "Enter the amount of the investment: ";
    cin >> dollars;
    cin.ignore();   
    if (!acnt.makeInvestment(dollars))
    {
        cout << "ERROR: Withdrawal amount too large.\n\n";
    }
    else
    {

    }
}


//**************************************************************
// Definition of function contributeRetirment. This function accepts *
// a reference to an Account object. The user is prompted for *
// the dollar amount of the contribution, and the contributeRetirment *
// member of the Account object is then called.*
//*************************************************************
void contributeRetirement(Account &acnt)
{
    double dollars;
    
    cout << "Enter the amount of the contribution: ";
    cin >> dollars;
    cin.ignore();
    acnt.contributeRetirementFund(dollars);
}


//**************************************************************
// Definition of function withdrawInvest. This function accepts *
// a reference to an Account object. The user is prompted for *
// the dollar amount of the withdraw, and the withdrawInvestment *
// member of the Account object is then called. Checks to see if amount is allowed*
//**************************************************************
void withdrawInvestment(Account &acnt)
{  
    double dollars;
    
    cout << "Enter the amount of the withdrawal: ";
    cin >> dollars; 
    cin.ignore();
    if (!acnt.withdrawInvestment(dollars))
    {
        cout << "ERROR: Withdrawal amount too large.\n\n";
    }
    else
    {

    }
    
}
