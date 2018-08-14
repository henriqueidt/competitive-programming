/*A sequence of n>0 integers is called a jollyjumper if the absolute values of the difference between
successive elements take on all the values 1 through n-1. For instance,
1 4 2 3
is a jolly jumper, because the absolutes differences are 3, 2, and 1 respectively. The definition implies
that any sequence of a single integer is a jolly jumper. You are to write a program to determine whether
or not each of a number of sequences is a jolly jumper.
Input
Each line of input contains an integer n < 3000 followed by n integers representing the sequence.
Output
For each line of input, generate a line of output saying 
Jolly
 or 
Not jolly

SampleInput
4 1 4 2 3
5 1 4 2 -1 6
SampleOutput
Jolly
Not jolly
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main ()
{
	int n = 0;
	int x = 0;
	int difference = 0;
	vector<int> integers;
	vector<bool> differences;
	

	while(cin >> n)
	{
		x = 0;
		integers.clear();
		differences.clear();

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			integers.push_back(x);
			differences.push_back(false);
		}

		

		for(int i = 0; i < n; i ++)
		{
			int a = integers[i];
			int b = integers[i+1];
			difference = abs(a - b);
			
			if(difference < n && difference > 0)
			{
				if(!differences[difference])
					differences[difference] = true;
			}
		}

		differences[0] = true;

		for(int i = 0; i < n; i++)
		{
			if(!differences[i])
			{
				printf("Not jolly\n");
				break;
			}
			if(i == n - 1)
				printf("Jolly\n");
		}
		
	}

	return 0;
}
