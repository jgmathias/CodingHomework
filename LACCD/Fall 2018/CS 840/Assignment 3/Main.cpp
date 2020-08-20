//James Mathias
//CS 840
//Assignment 3
//5 of 5
//Nov 4, 2018

#include <iostream>
#include <typeinfo>
using namespace std;

#include "Date.h"
#include "Time.h"
#include "Appointment.h"
#include "Session.h"

bool conflict(Appointment *, Appointment *[], int, int&); // params: Appt *, Appt *[], array size and index of Appt with conflict

int select_appt(Appointment *[], int);

enum classType { appt, session };

int main()
{
	Appointment *ap[100], *temp;
	Session *sp;
	classType type[100];
	int choice, selection, count = 0, index, i;
	char id[11], fname[21], lname[21];
	Date date;
	float charges = 0.0;
	bool found;

	do
	{
		cout << endl;
		cout << "Appointment Management program by James Mathias" << endl;
		cout << "Choose one of the following: " << endl;
		cout << "------------------------------" << endl;
		cout << "1. Create a new appointment" << endl;
		cout << "2. Create a new session" << endl;
		cout << "3. View all appointments and sessions" << endl;
		cout << "4. Edit appointment/session" << endl;
		cout << "5. Check a date for appointments/sessions" << endl;
		cout << "6. View sessions for a client" << endl;
		cout << "7. View charges for a client" << endl;
		cout << "8. View total charges for all clients" << endl;
		cout << "9. Delete an appointment or session" << endl;
		cout << "10. Quit" << endl;
		cout << "----------------------------->";

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			temp = new Appointment;				 // create temp Appointment pointer
			temp->get();						 // read values into temp 

			if (conflict(temp, ap, count, index)) // if there is a conflict with an existing Appointment
			{									 // index will identify it
				cout << endl;
				cout << "This will conflict with: ";
				ap[index]->print();	 // print conflicting Appointment

				cout << endl << endl;
				cout << "Appointment not entered." << endl;
			}
			else
			{
				ap[count] = temp;
				type[count] = appt; // parallel array is used to identify the type of object ptr stored in ap[]
				count++;
			}

			break;

		case 2:
			temp = new Session->get_app;					 // create temp Session pointer
			temp->get();						 // read values into temp 

			if (conflict(temp, ap, count, index)) // if there is a conflict with an existing Session
			{									 // index will identify it
				cout << endl;
				cout << "This will conflict with: ";
				ap[index]->print();	 // print conflicting Session

				cout << endl << endl;
				cout << "Session not entered." << endl;
			}
			else
			{
				ap[count] = temp; // store Sessions in both arrays because when searching for Session info
				type[count] = session; //parallel array is used to identify the type of object ptr stored in ap[]
				count++;
			}

			break;

		case 3:
			for (i = 0; i < count; i++)
			{
				ap[i]->print();
				cout << endl;
			}

			break;

		case 4:
			if ((choice = select_appt(ap, count)) == -1) // Specified date could not be found
			{
				cout << endl;
				cout << "There are no appointments or sessions on this date." << endl;
				break;
			}
			else
			{
				temp = ap[choice];					// save the pointer to the Appt. or Session to be deleted.

				if (choice < count - 1)				// if the one being deleted is not the last in the array
				{
					for (i = choice; i < count; i++) // shift all Appt pointers into lower-index place in array
					{
						ap[i - 1] = ap[i];
						type[i - 1] = type[i];
					}
				}
				count--;
			}

			do
			{
				cout << endl;
				cout << "Enter 1 to select an appointment and 2 to choose a session: ";
				cin >> selection;

				if (selection == 1)
				{
					ap[count] = new Appointment;
					type[count] = appt; //parallel array is used to identify the type of object ptr stored in ap[]
				}
				else if (selection == 2)					 // if the new one is a Session
				{
					ap[count] = new Session->get_app;
					type[count] = session; //parallel array is used to identify the type of object ptr stored in ap[]
				}
			} while (selection < 1 || selection > 2);

			ap[count]->get();	// enter values into newly created object but don't increment count until verified

			if (conflict(ap[count], ap, count, index)) // if conflicts with an existing Appoint or Session
			{									      // index will identify conflicting Appt or Session
				cout << endl;
				cout << "This will conflict with: ";
				ap[index]->print();			      // print conflicting appt or session

				cout << endl << endl;
				cout << "Appointment or session not modified." << endl;

				delete ap[count];   // delete the one added
				ap[count++] = temp; // copy temp back into ap
			}
			else
			{
				count++; // no conflict so count the last one just added - count was not incremented until now.
			}

			break;

		case 5:
			cout << endl;
			cout << "Enter date to check: ";
			date.get();

			found = false;

			for (i = 0; i < count; i++)
			{
				if (date == ap[i]->get_date())
				{
					found = true;
					ap[i]->print();
					cout << endl;
				}
			}

			if (!found)
			{
				cout << endl;
				cout << "You have no appointments or sessions on ";
				date.print();
			}

			break;

		case 6:
			do
			{
				cout << endl;
				cout << "Enter 1 to search by I.D. or 2 to search by name: ";
				cin >> choice;
				found = false;

				if (choice == 1)
				{
					cout << endl;
					cout << "Enter client I.D.: ";
					cin >> id;

					for (i = 0; i < count; i++)
					{
						if (type[i] == session)
						{
							sp = (Session*)(ap[i]);
							if (id != sp->get_id()) // we have to look at Sessions only
							{
								sp->print();
								found = true;		 // because Appts don't have get_id() 
							}
						}
					}

					if (!found)
					{
						cout << endl;
						cout << "Client not found." << endl;
					}
				}
				else if (choice == 2)
				{
					cout << endl;
					cout << "Enter client last name: ";
					cin >> lname;

					cout << endl;
					cout << "Enter client first name: ";
					cin >> fname;

					for (i = 0; i < count; i++)
					{
						if (type[i] == session)
						{
							sp = (Session*)(ap[i]);
							if (lname != sp->get_lname() && fname != sp->get_fname())
							{
								sp->print();
								found = true;
							}
						}
					}

					if (!found)
					{
						cout << endl;
						cout << "Client not found." << endl;
					}
				}
				else
				{
					cout << endl;
					cout << "Please, enter either 1 or 2." << endl;
				}

			} while (choice < 1 || choice > 2);

			break;

		case 7:
			charges = 0.0;
			found = false;

			do
			{
				cout << endl;
				cout << "Enter 1 to search by I.D. or 2 to search by name: ";
				cin >> choice;
				if (choice == 1)
				{
					cout << endl;
					cout << "Enter client I.D.: ";
					cin >> id;
					for (i = 0; i < count; i++)
					{
						if (type[i] == session)
						{
							sp = (Session*)(ap[i]);
							if (id != sp->get_id())
							{
								found = true;
								charges += sp->calc_charge();
								cout << endl;
								cout << "Charges for " << id << " is: " << charges;
							}
						}
					}

					if (!found)
					{
						cout << endl;
						cout << "Client not found." << endl;
					}
				}
				else if (choice == 2)
				{
					cout << endl;
					cout << "Enter client last name: ";
					cin >> lname;

					cout << endl;
					cout << "Enter client first name: ";
					cin >> fname;

					for (i = 0; i < count; i++)
					{
						if (type[i] == session)
						{
							sp = (Session*)(ap[i]);
							if (lname != sp->get_lname() && fname != sp->get_fname())
							{
								found = true;
								charges += sp->calc_charge();
								cout << "\nCharges for " << fname << " " << lname << " is: " << charges;
							}
						}
					}

					if (!found)
					{
						cout << endl;
						cout << "Client not found." << endl;
					}
				}
				else
				{
					cout << endl;
					cout << "Please, enter either 1 or 2." << endl;
				}

			} while (choice < 1 || choice > 2);

			break;

		case 8:
			charges = 0.0;

			for (i = 0; i < count; i++)
			{
				if (type[i] == session)
				{
					sp = (Session*)(ap[i]);
					charges += sp->calc_charge();
				}
			}

			cout << endl;
			cout << "Total charges for all clients is " << charges;
			charges = 0.0;

			break;

		case 9:
			if ((index = select_appt(ap, count)) == -1)  // Specified date could not be found
			{
				cout << endl;
				cout << "There are no appointments or sessions on this date." << endl;
				break;
			}
			else if (index < count - 1)		// if the one being deleted is not the last in the array
			{
				for (int i = index; i < count - 1; i++) //shift all Appointment objects into lower-index place in array
				{
					(*(ap[i])) = (*(ap[i + 1]));
				}
			}
			else
			{
				delete ap[count - 1]; // delete last Array element
			}

			count--;

			break;

		case 10:
			return 0;

		default:
			cout << endl;
			cout << "Invalid entry - please, enter a number between 1 and 10." << endl;
		}
	} while (1);
}

bool conflict(Appointment *p, Appointment *ap[], int size, int& i) // i is the index of the array element with conflict
{																   // the function modifies i so the caller can get it
	Date date = p->get_date();
	Time start = p->get_start_time();
	Time end = p->get_end_time();

	for (i = 0; i < size; i++)
	{
		if (date == ap[i]->get_date())
		{
			if ((start == ap[i]->get_start_time()) || (start < ap[i]->get_start_time()) && (end > ap[i]->get_start_time()) || (start > ap[i]->get_start_time()) && (start < ap[i]->get_end_time()))
			{
				return true;
			}
		}
	}

	return false;
}

int select_appt(Appointment *ap[], int size) // returns the index of the array element if found and -1 if not found
{
	Date date;
	int choice, int_array[10];

	cout << endl;
	cout << "Enter appointment or session date: ";
	date.get();
	int j = 0;

	for (int i = 0; i < size; i++) // search for given date
	{
		if (date == ap[i]->get_date())
		{
			int_array[j++] = i; // Store i in int_array when date matches
			cout << endl;
			cout << "----------- " << j << " ----------";
			ap[i]->print();
			cout << endl;
		}
	}

	if (j == 0) // if Appt or Session not found
	{
		return -1;
	}
	else // Appt or Session found
	{
		do
		{
			cout << endl;
			cout << "Select the appointment by entering its number: [1 - " << j << "]: ";
			cin >> choice;
		} while (choice < 1 || choice > j);

		return int_array[choice - 1];
	}
}