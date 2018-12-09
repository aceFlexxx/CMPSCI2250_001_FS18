#include <fstream>
#include <string>
#include <iostream> // std::cout, std::fixed, std::scientific
#include <array>
#include <math.h>
#include <iomanip>
using namespace std;

ifstream inputFile;
ofstream dataFile;
float lowScore = 100;//low score and high score defaults help 
float highScore = 0; // with computation.
float averageScore;
float Scores[100];
int scoreCount = 0;

// Function prototypes
bool openFileIn(fstream &file, string name);
void showContents(ifstream &file); //Used for debugging 
int parseData(ifstream &file);
void computeLow();
void computeHigh();
void computeAverage();
void writeScores();

int main()
{
   //open file to be read in
   scoreCount = parseData(inputFile); 
   computeLow();
   computeHigh();
   computeAverage();
   writeScores();
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

int parseData(ifstream &file)
{
    int counter = 0; 
    //counter helps build total scores

    inputFile.open("inputdat.txt");
    if(inputFile.fail())
    {
        cout << "Cannot detect input file./n";
        return counter; 
    }  
    else 
    {
       string line;
       //read in each string, delimetered by white space
       while(file >> line)
       {
         file >> line;          //Skip every other line because of input format. 
         Scores[counter] = stof(line);  //Convert to float value. 
            
         counter += 1;          //Find out how many scores we have.Goes to next space in array. 
       }       
        inputFile.close(); //Close input file when done. 
    }
    return counter;
    
}

//************************************************
// This function computes low score.*
//************************************************

void computeLow()
{
    for(int i = 0; i < scoreCount; i++)
    {
        if(Scores[i] < lowScore)
        {
            lowScore = Scores[i];
        } 
    }
    return;
}

//************************************************
// This function computes high score.*
//************************************************
void computeHigh()
{
    for(int i = 0; i < scoreCount; i++)
    {
        if(Scores[i] > highScore)
        {
            highScore = Scores[i];
        }
        
    }
    return;
}

//************************************************
// This function computes average score.*
//************************************************
void computeAverage()
{
    for(int i = 0; i < scoreCount; i++)
    {
        averageScore += Scores[i];
        
        
    }
    averageScore /= scoreCount;
    averageScore = round(averageScore * 10) / 10; //Round to nearest 10th
}

//************************************************
// This function writes scores to file.*
//************************************************
void writeScores()
{
    dataFile.open("scoreFile.txt", ios::out);
    dataFile << "Lowest Score:   " << fixed << setprecision(0) << lowScore << endl;   
    dataFile << "Highest Score:   " << setprecision(0) << highScore << endl;   
    dataFile << "Average Score:   " << setprecision(1) << averageScore << endl;   
    
    dataFile.close();//Close input file when done.

    return;
}
