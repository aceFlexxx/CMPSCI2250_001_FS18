#include <fstream>
#include <string>
#include <iostream>
#include <array> 
using namespace std;

ifstream inputFile;
ofstream dataFile;
float lowScore;
float highScore;
float averageScore;
float Scores[];

// Function prototypes
bool openFileIn(fstream &file, string name);
void showContents(ifstream &file);
void parseData(ifstream &file);
void writeScores(float low, float high, float average);

int main()
{
    //open file to be read in
    
    
}

//************************************************
// The function displays the file's content *
//************************************************
void showContents(ifstream &file)
{
   string line;

   while(file >> line)
   {
       cout << line << endl;
   }
}

//************************************************
// This function formats data for computation.*
//************************************************

void parseData(ifstream &file)
{ 
    inputFile.open("inputdat.txt");
    if(inputFile.fail())
    {
        cout << "Cannot detect input file./n";
        return; 
    }  
    else
    {
       string line;
       int counter = 0; 
       //counter tracks # of coures recordings
       //read in each string, delimetered by white space
       while(file >> line)
       {
         file >> line; 
           
       }
       cout <<  
    }
}
