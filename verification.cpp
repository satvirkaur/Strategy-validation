#include"verification.h"
//#include"input.in"
void verification :: getInput()
{
	inFile.open("input.in");
	inFile >> totalRoom;
	for( i=0; i < totalRoom; i++)
	{
		inFile >> rows[i] >>cols[i];
	}
	
	inFile >> totalBranches;
	for(i=0; i< totalBranches; i++)
	{
		inFile >> branchName[i] >> branchStudent[i];
	}
	inFile.close();
}

// to select strategy
void verification :: methodSelection()
{
	do
	{
		cout<<"Select Strategy and enter your choice\n"
			<<"1. two group Strategy.Example:\n\tgroupA\tgroupA\tgroupA\n\tgroupB\tgroupB\tgroupB\n\tgroupA\tgroupA\tgroupA\n\t"
				<<"groupB\tgroupB\tgroupB\n"
			<<"2. Four group Strategy.Example:\n\tgroupA\tgroupC\tgroupA\n\tgroupB\tgroupD\tgroupB\n\t"
				<<"groupC\tgroupA\tgroupC\n\tgroupD\tgroupB\tgroupD\n\tgroupA\tgroupC\tgroupA\n"
			<<"\nEnter your choice:\n";
	
		cin >> strategyChoice;
		switch(strategyChoice)
		{
			case 1:
				checkValidation(strategyChoice);
				break;
		
			case 2:
				checkValidation(strategyChoice);
				break;
		
			default:
			cout<<"Oops!!! Wrong choice\n Enter your choice Again\n";
		}
	
	}while(strategyChoice != 1 && strategyChoice !=2);
}

// to calculate total available seats in all rooms
int verification :: roomsCapacity()
{
	totalSeats = 0;

	for( j=0; j<totalRoom; j++)
	{
		totalSeats += ( rows[j] * cols[j] );
	}
	outFile << "\ntotal Seats = " << totalSeats;
	return(totalSeats);
}


// member function to calculate the cpacity of one group 
void verification :: checkValidation(int strategyChoice)
{
	int temp;
	outFile.open("output.txt");
	switch(strategyChoice)
	{
		case 1:
			temp = display(2);
			if(temp == true)
				outFile << "\ncongrats!!!!!!!!!! this strategy is applicable";
			if(temp == false)
				outFile << "\nBadddddddddddd";			
			break;
			
		case 2:
			temp = display(4);
			if(temp == true)
				outFile << "\ncongrats!!!!!!!!!! this strategy is applicable ";
			if(temp == false)
				outFile << "\nBadddddddddddd";			
			break;
	}
}


int verification :: maxStudent(int groups)
{
	min = 3265;
	max = 0;
	for(i=0; i<groups; i++)
	{
		groupArray[i] = branchStudent[i];
		if(groupArray[i] < min)
		{
			min = groupArray[i];
			minPos = i;	
		}	
		if(groupArray[i] > max)
			max = groupArray[i];			
	}
				
	for(i=groups; i<totalBranches; i++)
	{
		groupArray[minPos] += branchStudent[i];
		min = max;
		for(j=0; j<2; j++)
		{
			if(groupArray[j] <= min)
			{
				min = groupArray[j];
				minPos = j;
			}
			if(groupArray[j] > max)
				max = groupArray[j];
		}
	}
				
	outFile <<"\n Min group students = " << min <<"\tMax group students =" << max;
	return(max);	
}

bool verification :: display(int groups)
{
			groupSeats = 0;
			if(totalBranches <groups)
			outFile << "\n\nSorry!!!\nStrategy not possible because this strategy requires minimum 4 classes\n";
			else
			{
				groupSeats = (roomsCapacity()) / groups;
				outFile << "\ngroup seats= " << groupSeats;
				groupStudents = maxStudent(groups);
				if( groupStudents > groupSeats)
				{
					outFile <<"\n\n\nstrategy is not possible bcz of less rooms\n\n";
					outFile << groupStudents - groupSeats <<" More seats are required\n";
				
					float	extraRooms=(float) (groupStudents - groupSeats) / (32/groups);
					outFile <<"\n Add  " << extraRooms <<" Rooms of 8 * 4 to follow this strategy where"
							<<" 8 is rows and 4 is columns\n\n";
					return(false);
				}
				
				else
				{
					return(true);
				}
			}
}
