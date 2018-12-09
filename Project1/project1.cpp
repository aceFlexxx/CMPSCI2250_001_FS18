#include <iostream>
#include <string>
using namespace std;

 // Function prototypes
 
 int validateInput(char[], int &);
 void selectionSort(int[], int);
 void showArray(const int [], int);

int main() {
	const int SIZE = 80;  // Array size
	char line[SIZE];      // To hold a line of input
	int count = 0;        // Loop counter variable
	int crt_num = 0;

	int capacity = 5;
	int crt_size = 0;
	int *datArr = nullptr;

	datArr = new int[capacity];

	int err_code = 0; // Use this variable to tell us the error types
					  // 0 means in integer, including 0, -1, and other negative numbers
					  // 1 means non-numeric string
					  // 2 means double or float
                      //
   cout << "***************************************\n";
   cout << "******** Welcome to project1! *********\n";
   cout << "*** Please enter a positive integer ***\n";
   cout << "*** Enter -1 to terminate program. ****\n";
   cout << "**** Enter 0 to view sorted array. ****\n";
   cout << "***************************************\n";
	// Get a line of input.
	cout << "Enter a positive integer: " << endl;

	cin.getline(line, SIZE);

	err_code = validateInput(line, crt_num);

	if (err_code == 1)
    {   
		cout << "A non-numerical string is entered." << endl;
	} 
    else if (err_code == 2) 
    {
		cout << "A non-integer number is entered." << endl;
	} 
    else
    {
		if (crt_num == 0) {
			cout << "0 is entered." << endl;
            
		} 
        else if (crt_num == -1) 
        {
			cout << "-1 is entered." << endl;
		}
        else if (crt_num < 0) 
        {
			cout << "A negative number other than -1 is entered." << endl;
		}
        else
        {
            cout << "A valid input: " << crt_num << endl;
            datArr[crt_size] = crt_num;
            crt_size++;
        }
    }
	while (crt_num != -1) {
		cout << "Enter a new input: ";
		cin.getline(line, SIZE);

		err_code = validateInput(line, crt_num);

		if (err_code == 1) 
        {
			cout << "A non-numerical string is entered." << endl;
		}
        else if (err_code == 2) 
        {
			cout << "A non-integer number is entered." << endl;
		}
        else 
        {
			if (crt_num == 0) 
            {
				cout << "0 is entered." << endl;
			    selectionSort(datArr, crt_size);
                showArray(datArr, crt_size);
            } 
            else if (crt_num == -1) 
            {
				cout << "-1 is entered." << endl;
			} 
            else if (crt_num < 0) 
            {
				cout << "A negative number other than -1 is entered." << endl;
			}
            else
            {
                bool flag = false; //duplicate flag
                for(int v = 0; v < crt_size; ++v)
                {
                    if(datArr[v] == crt_num)
                    {
                        cout << "Repeats not permitted\n";
                        flag = true;
                        break;   
                    }
                    else
                    {

                    }
           }
                if(flag==false)
                {
                    cout << "A valid input: " << crt_num << endl;
                    datArr[crt_size] = crt_num;
                    crt_size++;
                }
                else flag =false; //reset duplicate flag
                
                //When the capacity is met this if statement copies current array 
                //into new doubly larger array and deletes previous array
				if (crt_size == capacity) 
                {
                    int *tempArr = nullptr;
                    tempArr = new int[2*capacity];
                    for(int i=0; i < capacity; i++)
                    {
                        tempArr[i] = (datArr)[i];
                    }

                    capacity *= 2; 
                    delete[] datArr;
                    datArr = tempArr;
				}
			}
		}
	}

	return 0;
}

 //**************************************************************
 // Definition of function validatInput. *
 // This function insures the user has not sent any input *
 // that is not a positive inter (float, double, char, etc.), *
 // a zero for sort and reading, or a -1 for termination of *
 // the program. The input[] is the current input from user, *
 // and the num is the current number assigned once my_error *
 // _code is 0 (Yanked from Dr. He listing) *
 //**************************************************************
int validateInput(char input[], int &num) {
	int count;  // Loop counter

	int my_err_code = 0;

	int dot_num = 0; // indicating if it is a double or float
	int digit_num = 0;

	if (input[count] == '-') {
		count++;
	}

	while (input[count] != '\0') 
    {
		if (input[count] == '.') 
        {
			dot_num++;
        }
        else if (isdigit(input[count])) 
        {
			digit_num++;
		}
        else 
        {
			my_err_code = 1;
			break;
		}

		if (dot_num > 1) 
        {
			my_err_code = 1;
			break;
		}
		count++;
	}

	if (dot_num == 1) 
    {
		if (digit_num == 0) 
        {
			my_err_code = 1;
		}
        else
        {
			my_err_code = 2;
		}
	}

	if (my_err_code == 0) 
    {
		num = stoi(input);
	}

	return my_err_code;    
}

 //**************************************************************
 // Definition of function selectionSort. *
 // This function sorts the contents of array. size is the *
 // number of elements. * (Modified from project 1)
 //**************************************************************

void selectionSort(int array[], const int size)
 {
 	int  minValue;
	int startScan, minIndex;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
      		minIndex = startScan;
 		minValue = array[startScan];

		for(int index = startScan + 1; index < size; index++)
		{
 			if (array[index] < minValue)
 			{
 				minValue = array[index];
 				minIndex = index;
 			}
 		}
 		array[minIndex] = array[startScan];
 		array[startScan] = minValue;
 	}
 }

 //**************************************************************
 // Definition of function showArray. *
 // This function displays the contents of array. size is the *
 // number of elements. * (Modified from project 1)
 //**************************************************************

 void showArray(const int array[], int size)
 {
 	for (int count = 0; count < size; count++)
 	cout << array[count] << " ";
 	cout << endl;
 }
