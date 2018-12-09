#include <iostream>
#include <string>
using namespace std;

int validateInput(char[], int &);
// void getInput(char *, int);

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

	// Get a line of input.
	cout << "Enter a positive integer: " << endl;

	cin.getline(line, SIZE);

	err_code = validateInput(line, crt_num);

	if (err_code == 1) {
		cout << "A non-numerical string is entered." << endl;
	} else if (err_code == 2) {
		cout << "A non-integer number is entered." << endl;
	} else {
		if (crt_num == 0) {
			cout << "0 is entered." << endl;
		} else if (crt_num == -1) {
			cout << "-1 is entered." << endl;
		} else if (crt_num < 0) {
			cout << "A negative number other than -1 is entered." << endl;
		} else {
			cout << "A valid input: " << crt_num << endl;
			datArr[crt_size] = crt_num;
			crt_size++;
		}
	}

	while (crt_num != -1) {
		cout << "Enter a new input: ";
		cin.getline(line, SIZE);

		err_code = validateInput(line, crt_num);

		if (err_code == 1) {
			cout << "A non-numerical string is entered." << endl;
		} else if (err_code == 2) {
			cout << "A non-integer number is entered." << endl;
		} else {
			if (crt_num == 0) {
				cout << "0 is entered." << endl;
			} else if (crt_num == -1) {
				cout << "-1 is entered." << endl;
			} else if (crt_num < 0) {
				cout << "A negative number other than -1 is entered." << endl;
			} else {
				cout << "A valid input: " << crt_num << endl;
				datArr[crt_size] = crt_num;
				crt_size++;

				if (crt_size == capacity) {
					cout << "Current data: " << endl;

					for (int i = 0; i < crt_size; i++) {
						cout << "Item " << (i+1) << ": " << datArr[i] << endl;
					}

					break;
				}
			}
		}
	}

	return 0;
}

int validateInput(char input[], int &num) {
	int count;  // Loop counter

	int my_err_code = 0;

	int dot_num = 0; // indicating if it is a double or float
	int digit_num = 0;

	if (input[count] == '-') {
		count++;
	}

	while (input[count] != '\0') {

		if (input[count] == '.') {
			dot_num++;
		} else if (isdigit(input[count])) {
			digit_num++;
		} else {
			my_err_code = 1;
			break;
		}

		if (dot_num > 1) {
			my_err_code = 1;
			break;
		}

		count++;
	}

	if (dot_num == 1) {
		if (digit_num == 0) {
			my_err_code = 1;
		} else {
			my_err_code = 2;
		}
	}

	if (my_err_code == 0) {
		num = stoi(input);
	}

	return my_err_code;
}
