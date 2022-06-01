#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

int NUM_TRY = 4;
int checkGuess(char, string, string&);
void main_menu();
string message = "Hraj!";


int main(int argc, char* argv[])
{
	string name;
	char letter;
	string month;


	string months[] =
	{
		"januar",
		"februar",
		"marec",
		"april",
		"maj",
		"jun",
		"jul",
		"august",
		"september",
		"oktober",
		"november",
		"december"
	};

	srand(time(NULL));
	int n = rand() % 12;
	month = months[n];


	string hide_m(month.length(), 'X');




	while (NUM_TRY != 0)
	{
		main_menu();
		cout << "\n\n\t\t\t\t" << hide_m;
		cout << "\n\n\t\t\t\tHadaj pismenko: ";
		cin >> letter;
		 
		if (checkGuess(letter, month, hide_m) == 0)
		{
			message = "Zle pismemnko.";
			NUM_TRY = NUM_TRY - 1;
		}
		else
		{
			message = "Uhadol si pismenko";
		}



		if (month == hide_m)
		{
			message = "Gratulujem! Uhadol si.";
			main_menu();
			cout << "\n\t\t\t\tMesiac je : " << month << endl;
			break;
		}
	}
	if (NUM_TRY == 0)
	{
		message = "Prehral si.";
		main_menu();
		cout << "\n\t\t\tMesiac bol : " << month << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}


int checkGuess(char hadaj, string tajnymesiac, string& hadajmesiac)
{
	int i;
	int matches = 0;
	int len = tajnymesiac.length();
	for (i = 0; i < len; i++)
	{

		if (hadaj == hadajmesiac[i])
			return 0;

		if (hadaj == tajnymesiac[i])
		{
			hadajmesiac[i] = hadaj;
			matches++;
		}
	}
	return matches;
}

void main_menu()
{
	system("color 02 ");
	system("cls");
	
	
	cout << "\n\t\t\t\tObesenec!";
	cout << "\n\t\tMas este " << NUM_TRY << " pokusi. Hadaj nazvi mesiacov.";
	cout << "\n\n\t\t\t\t" + message;
	

}