#include<iostream>
using namespace std;
int main()
{
	cout<< "Enter array of 3 * 2";
	int a[4][4];
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<2; j++)
		{
			cin >> a[i][j];		
		}
	}
	
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout << a[i][j] <<"\t";		
		}
		cout<<"\n";
	}
	
	
	return(0);
}
