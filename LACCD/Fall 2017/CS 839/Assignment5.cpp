/*
Define a structure called Date with month, day and year as its data members, Time with hour and minute with its members and Event with desc (string for description), date (of type Date) and time(of type Time).
Write a readEvents() function that will read as many Events as the user wants up to a MAX of 100 and store them in an array of Events of max size and the number of Events entered in size.
Dates should be entered like 12/12/17 and times as 10:15.
When finished entering, the user will enter an empty string for desc.
Also, write a display() function that takes an array of Event pointers and prints them.
Declare an array of Event pointers of the same MAX size as the array of Events created above.
Then, keep asking the user if he or she wants to add a new event, if so, allocate memory dynamically for each Event being added, storing the pointer returned by the new operator in the array of Event pointers.
Write two sort functions (may use the same function name): one to sort the Events by their description by rearranging the Event structures rather than the pointers, passing it the array of pointers and the size of all Events entered and added and the other to sort the pointers by rearranging the pointers rather than the structures again by passing the array of pointers and size.
Print the Events by using the display function after each sort.
Open a file for output and write to it all Events created.
Then, close and reopen the file to read from it.
Ask for a month from the user and read and display all Events stored in the file that are in the given month.
*/

//CS 839
//Assignment 5

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Date
{
	int month;
	int day;
	int year;
};

struct Time
{
	int hour;
	int minute;
};

struct Event
{
	string desc;
	Date date;
	Time time;
};

int getEvents(Event Events[], int MaxSize);

void display1(Event &Event);
void displayAll(Event *Ptr[], int Count);

void sort(Event Events[], int Count);
void sort(Event *Ptr[], int Count);


int main()
{
	const int maxSize = 100;
	Event events[maxSize];
	int count = getEvents(events, maxSize);

	Event *ptr[maxSize];

	for (int i = 0; i < count; i++) {
		ptr[i] = &events[i];
	}


	char choice;
	cout << "Display all? ";
	cin >> choice;
	if (choice == 'y')
	{
		displayAll(ptr, count);
	}
	
	int newCount;

	for (newCount = count; newCount < maxSize; newCount++)
	{
		string Desc;
		cout << "Enter description of event " << newCount + 1 << " or enter nothing to stop: ";
		cin.ignore();
		getline(cin, Desc);

		if (Desc == "")
		{
			cout << endl;
			break;
		}
		else
		{
			events[newCount].desc = Desc;

			cout << "Enter date of event (mm/dd/yy): ";
			char slash = '/';
			cin >> events[newCount].date.month >> slash >> events[newCount].date.day >> slash >> events[newCount].date.year;

			cout << "Enter time of event in 24-hour format (hh:mm): ";
			char colon = ':';
			cin >> events[newCount].time.hour >> colon >> events[newCount].time.minute;

			ptr[newCount] = &events[newCount];

			cout << endl;
		}
	}

	sort(events, newCount);
	
	cout << "Display events after sorting? ";
	cin >> choice;
	if (choice == 'y')
	{
		displayAll(ptr, count);
	}

	sort(ptr, newCount);

	cout << "Display pointers after sorting? ";
	cin >> choice;
	if (choice == 'y')
	{
		displayAll(ptr, count);
	}

	ofstream myfile;
	myfile.open("eventfile.txt");
	myfile << displayAll(ptr, count);;
	myfile.close();

	string line;
	ifstream myfile("eventfile.txt");
	while (getline(myfile, line))
	{
		cout << line << endl;
	}
	myfile.close();


	return 0;
}

int getEvents(Event Events[], int MaxSize)
{
	int Count = 0;
	for (Count = 0; Count < MaxSize; Count++)
	{
		string Desc;
		cout << "Enter description of event " << Count+1 << " or enter nothing to stop: ";
		cin.ignore();
		getline(cin, Desc);

		if (Desc == "")
		{
			cout << endl;
			return Count;
		}
		else
		{
			Events[Count].desc = Desc;

			cout << "Enter date of event (mm/dd/yy): ";
			char slash = '/';
			cin >> Events[Count].date.month >> slash >> Events[Count].date.day >> slash >> Events[Count].date.year;

			cout << "Enter time of event in 24-hour format (hh:mm): ";
			char colon = ':';
			cin >> Events[Count].time.hour >> colon >> Events[Count].time.minute;

			cout << endl;
		}
	}

	return Count;
}

void display1(Event &Event)
{
	cout << "Event: " << Event.desc << endl;
	cout << "Date: " << Event.date.month << '/' << Event.date.day << '/' << Event.date.year << endl;
	cout << "Time: " << Event.time.hour << ':' << Event.time.minute << endl;
	cout << endl;
}

void displayAll(Event *Ptr[], int Count)
{
	for (int i = 0; i < Count; i++)
	{
		display1(*Ptr[i]);
	}
	cout << endl;
}

void sort(Event Events[], int Count)
{
	for (int i = 0; i < Count - 1; i++)
	{
		for (int j = i + 1; j < Count; j++)
		{
			if (Events[i].desc > Events[j].desc)
			{
				Event Temp = Events[i];
				Events[i] = Events[j];
				Events[j] = Temp;
			}
		}
	}
}

void sort(Event *Ptr[], int Count)
{
	for (int i = 0; i < Count - 1; i++)
	{
		for (int j = i + 1; j < Count; j++)
		{
			if (Ptr[i].desc > Ptr[j].desc)
			{
				Event Temp = *Ptr[i];
				Ptr[i] = Ptr[j];
				Ptr[j] = &Temp;
			}
		}
	}
}