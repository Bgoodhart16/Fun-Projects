#include <iostream>
const int N = 9;
using namespace std;

//playable grid w 0's
/*int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};*/


//correct grid
int grid[N][N] = {
   {3, 1, 6, 5, 7, 8, 4, 9, 2},
   {5, 2, 9, 1, 3, 4, 7, 6, 8},
   {4, 8, 7, 6, 2, 9, 5, 3, 1},
   {2, 6, 3, 4, 1, 5, 9, 8, 7},
   {9, 7, 4, 8, 6, 3, 1, 2, 5},
   {8, 5, 1, 7, 9, 2, 6, 4, 3},
   {1, 3, 8, 9, 4, 7, 2, 5, 6},
   {6, 9, 2, 3, 5, 1, 8, 7, 4},
   {7, 4, 5, 2, 8, 6, 3, 1, 9}
};


bool isSafe(int row, int col, int num) {
	for (int i = 0; i < 9; ++i)
		if (grid[row][i] == num) {
			cout << "Number is already in row. " << endl;
			return false;
		}
	for (int j = 0; j < 9; ++j) {
		if (grid[j][col] == num) {
			cout << "Number is already in column. " << endl;
			return false;
		}
	}
}

bool isPuzzelCorrect() {
	int total = 0;
	int boxStartColumn = 0;
	int boxStartRow = 0;
	//checking box totals

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			total += grid[boxStartColumn][boxStartRow];
		}
	cout << total;
	if (total == 45) {
		return true;
		total = 0;
		boxStartColumn += 3;
		boxStartRow += 3;}
	else {
		cout << "Your box test failed" << endl;
		return false;}

	//checking column totals
	for (int c = 0; c < 9; ++c)
		for (int r = 0; r < 9; ++r) {
			total += grid[c][r];
		}
	if (total == 45)
		return true;

	else {
		cout << "Your column test failed" << endl;
		return false;
	}
	//cheacking row totals
	for (int r = 0; r < 9; ++r)
		for (int c = 0; c < 9; ++c) {
			total += grid[c][r];
		}
	if (total == 45)
		return true;
	else {
		cout << "Your row test failed" << endl;
		return false;
	}
}

void playSudoku() {
	int userInput1 = 0;
	char response;
	for (int r = 0; r < 9; ++r) {
		for (int c = 0; c < 9; ++c) {
			if (grid[r][c] == 0) {
				cout << "Input your guess at " << r + 1 << " , " << c + 1 << endl;;
				cout << "Guess 1: "; cin >> userInput1;
				
				while (!isSafe(r, c, userInput1)) {
					cout << "Guess again. Your number wasn't a valid choice. " << endl;
					cout << "Guess again: ";
					cin >> userInput1;
				}
				grid[r][c] = userInput1;
			}
		}
	}

	cout << "Would you like us to check your puzzle? ('Y' or 'N'): ";
	cin >> response;

	if (response == 'y')
		if(isPuzzelCorrect() == false)
			cout << "Your puzzle was incorrect";
	else cout << "Okay, that was like kind of rude... " << endl;
}

 
void sudokuGrid() { //print the sudoku grid after solve
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (col == 3 || col == 6)
				cout << " | ";
			cout << grid[row][col] << " ";
		}
		if (row == 2 || row == 5) {
			cout << endl;
			for (int i = 0; i < N; i++)
				cout << "---";
		}
		cout << endl;
	}
}


int main()
{
	sudokuGrid();
	playSudoku();


}











// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
