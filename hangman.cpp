#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "hangman.h"

using namespace std;

void Game::startGame()
{
    cout << "Witaj w grze Wisielec!" << endl;
    showMenu();

    if(category)
    {
    categoryDraw();
    showGame();
    }
}
int Game::randomNumber()
{
    srand(time(NULL));
    int x=rand()%10;
    return x;
}

int Game::showMenu()
{
    int option;

    cout << "Wybierz Kategorie:" << endl;
    cout << "------------------- "<< endl;
    cout << "1. Owoce" << endl;
    cout << "2. Zwierzeta" << endl;
    cout << "3. Wyjdz z gry" << endl;
    cout << endl;

    option=getche();

    switch (option)
    {
    case '1':
        {
            return category=1;
        }
    break;

    case '2':
         {
           return category=2;
        }
    break;
    case '3':
         {
             system("cls");
            return 0;
        }
    break;
    default:
        {
            system("cls");
            cout << "Nie ma takiej opcji w menu. Wybierz ponownie"<<endl;
            showMenu();
        }
    }
}

void Game::categoryDraw()
{
    system("cls");

    int x=randomNumber();

    if(category==1)
        {
            word=fruits[x];
            categoryName="Owoce";
        }
        else
        {
            word=animals[x];
            categoryName="Zwierzeta";
        }
           cout<<"Wylosowany wyraz: "<<word<<" Kategoria: "<<categoryName;
}



int Game::showGame()
{
    int wordLength = word.length();
	string unknown(wordLength, '*');

    while (badTries < maxTries)
	{

        system("cls");

	    image(badTries);

        cout <<"Bledne: "<< badTries <<"/"<< maxTries << endl;
        cout <<"Kategoria: "<< categoryName << endl;

		cout << "\n" << unknown;
		cout << "\n\nWprowadz litere: ";
		cin >> letter;



		if (letterFill(letter, word, unknown)==0)
		{
			badTries++;
		}
		else
		{
            found++;
		}

		if (word==unknown)
		{
			system("cls");
			image(badTries);
			cout <<"Bledne: "<< badTries <<"/"<< maxTries << endl;
            cout <<"Kategoria: "<< categoryName << endl;
			cout << "\n" << unknown;
            cout<<endl<<"\nGratulacje! Wygrales!"<<endl;

            break;
		}


	}
	if(badTries == maxTries)
	{
            system("cls");
			image(badTries);
			cout <<"Bledne: "<< badTries <<"/"<< maxTries << endl;
            cout <<"Kategoria: "<< categoryName << endl;
			cout << "\nSzukane slowo: " << word;
            cout<<endl<<"\nNiestety!Przegrales!"<<endl;


	}

	cin.ignore();
	cin.get();
	return 0;

}

void Game::image (int badTries){
    cout << "___________" << endl;
    cout << "|        " ;   if(badTries>=1){  cout <<" |";} cout<< endl;;
    cout << "|        " ; if(badTries>=2){ cout <<" O"; }cout<< endl;
    cout << "|        " ; if(badTries>=3){ cout <<"/|\\"; }cout<< endl;
    cout << "|        " ; if(badTries>=4){ cout <<" | "; }cout<< endl;;
    cout << "|        " ; if(badTries>=5){ cout <<"/ \\ "; }cout<<endl;;
    cout << "--    " << endl;
    }

int Game::letterFill (char guess, string secretWord, string &guessWord)
{
	int i;
	int matches=0;
	int len=secretWord.length();
	for (i = 0; i< len; i++)
	{
		if (guess == secretWord[i])
		{
			guessWord[i] = guess;
			matches++;
		}
	}
	return matches;
}
