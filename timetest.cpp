#include <iostream>
#include <fstream>
#include "CPUTimer.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "vector.h"
#include "SkipList.h"

vector<CursorNode <int> > cursorSpace(500001);  

using namespace std;

int getChoice() 
{ 
	int choice; 

	cout << "\n      ADT Menu " << endl;
	cout << "0. Quit \n"; 
	cout << "1. LinkedList\n"; 
	cout << "2. CursorList\n"; 
	cout << "3. StackAr\n"; 
	cout << "4. StackLi\n"; 
	cout << "5. QueueAr\n"; 
	cout << "6. SkipList\n"; 
	cout << "Your choice >> "; 

	cin >> choice; 	
	
return choice; 
}

void RunList(char* file) 
{ 
	List<int> normalList;
	ListItr<int> iter = normalList.zeroth(); 
	
	int num; 
	char instruction, arr[512];  
	fstream datFile(file); 

	datFile.getline(arr, 512); 

	while(datFile >> instruction >> num) 
	{
		if(instruction == 'i') 
			normalList.insert(num, iter);
		else 
			normalList.remove(num); 
	} 
} 
 
void RunCursorList(char* file) 
{ 
	CursorList<int> curList(cursorSpace); 
	CursorListItr<int> iter = curList.zeroth(); 

	int num; 
	char instruction, arr[512]; 
	fstream datFile(file); 

	datFile.getline(arr, 512); 
	
	while(datFile >> instruction >> num) 
	{ 

		if(instruction == 'i') 
			curList.insert(num, iter);
		else
			curList.remove(num); 
	} 	 
} 

void RunStackAr(char* file) 
{ 
	StackAr<int> stackArray(500001); 
	
	int num;
	char instruction, arr[512]; 
	fstream datFile(file); 
	
	datFile.getline(arr, 512); 

	while( datFile >> instruction  >> num) 
	{ 
		if(instruction == 'i') 
			stackArray.push(num);
		else
			stackArray.pop(); 
	} 

	
} 

void RunStackLi(char* file) 
{ 
	StackLi<int> stackList;
	
	int num; 
	char instruction, arr[512]; 
	fstream datFile(file); 

	datFile.getline(arr,512); 
	
	while(datFile >> instruction >> num)
	{ 
		if( instruction == 'i')
			stackList.push(num); 
		else
			stackList.pop(); 
	}
 
} 

void RunQueueAr(char* file) 
{ 
	Queue<int> queueArray(500001);
	
	int num;
	char instruction, arr[512];
	fstream datFile(file); 
	
	datFile.getline(arr, 512); 
	
	while(datFile >> instruction >> num)
	{ 
		if(instruction == 'i') 
			queueArray.enqueue(num);
		else
			queueArray.dequeue(); 
	} 
} 

void RunSkipList(char* file) 
{
	SkipList<int> skipList(0, 500001); 
	
	int num;
	char instruction, arr[512]; 
	fstream datFile(file); 

	datFile.getline(arr, 512); 

	while(datFile >> instruction >> num) 
	{ 
		if(instruction == 'i') 
			skipList.insert(num); 
		else
			skipList.deleteNode(num); 
	} 

} 


int main (int argc, char** argv) 
{ 
	int choice;
	const int SIZE = 10; 
	char filename[SIZE];
	CPUTimer ct;  
 
	cout << "Filename >> "; 
	cin >> filename;

do 
{
	choice = getChoice();
	ct.reset();
	switch (choice)
	{
		case 1: RunList(filename); break;
		case 2: RunCursorList(filename); break;
		case 3: RunStackAr(filename); break;
		case 4: RunStackLi(filename); break;
		case 5: RunQueueAr(filename); break;
		case 6: RunSkipList(filename); break;
	}

	cout << "CPU time: " << ct.cur_CPUTime() << endl;
} while(choice > 0);

return 0; 

} 




























