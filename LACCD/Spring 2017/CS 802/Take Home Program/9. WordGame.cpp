#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void Header()
{
	cout << "          Word Games" << endl;
	cout << "++++++++++++++++++++++++++++++" << endl;
}

string askNoun()
{
	cout << "Enter a noun (person, place or thing): ";
	string Noun;
	cin >> Noun;
	return Noun;
}

string askVerb()
{
	cout << "Enter a verb (an action!): ";
	string Verb;
	cin >> Verb;
	return Verb;
}

string askAdjective(string Noun)
{
	cout << "Enter an adjective (describes the " << Noun << "): ";
	string Adjective;
	cin >> Adjective;
	return Adjective;
}

string askAdverb(string Verb)
{
	cout << "Enter an adverb (describes how it " << Verb << "): ";
	string Noun;
	cin >> Noun;
	return Noun;
}

int main()
{
	Header();
	
	char more;
	do {
		cout << endl;
		string Noun = askNoun();
		string Verb = askVerb();
		string Adjective = askAdjective(Noun);
		string Adverb = askAdverb(Verb);

		cout << "\tThe " << Noun << " " << Verb << " " << Adverb << " " << Adjective << "." << endl;
		cout << "More sentences? (y/n): ";
		cin >> more;

	} while (more == 'y');
	
	cout << "Goodbye for now." << endl;

	return 0;
}