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
	

	while(cin >> n)
	{
		x = 0;
		integers.clear();

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			integers.push_back(x);
		}

		vector<int>::iterator it = integers.begin();
		

		while(it < integers.end()-1)
		{
			//printf("Antes da diferenca\n");
			int a = *it;
			//printf("a = %d\n", a);
			//printf("it antes = %d\n", *it);
			int b = *(it+1);
			//printf("it depois = %d\n", *it);
			//printf("b = %d\n", b);

			difference = abs(a - b);
			//printf("difference = %d\n", difference);
			
			if(difference < n && difference > 0)
			{
				//printf("Chega aqui %d\n", *it);
				integers.erase(it);
				it = integers.begin();
				//printf("Novo it %d\n", *it);
				//printf("comeco do integers %d\n", *integers.begin());
				//printf("final do integers %d\n", *integers.end());
			}
			else
				it++;
		}
		
		if(integers.size() == 1)
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
		
	}

	return 0;
}
