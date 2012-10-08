#include<iostream>
#include<fstream>
using namespace std;
class verification
{
	public:
	int rows[13], cols[13], totalRoom, totalBranches, groupSeats, groupStudents, totalSeats, strategyChoice, branchStudent[50];
	int branchArray[12], min, max, minPos,groupArray[7];
	string  branchName[15];
	ifstream inFile;
	ofstream outFile;
	int i,j;
	
	//methods
	void getInput();
	void checkValidation( int );
	int roomsCapacity();
	void methodSelection();
	int maxStudent(int);
	bool display(int);
};
