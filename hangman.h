#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

class Game
{
    private:
        char letter;
        int category=0;
        int x;
        int found=0;
        int badTries=0;
        int maxTries=5;
        string unknown;
        string word, categoryName;
        string fruits[10]={"jablko","banan","gruszka","truskawka","jagoda","grapefruit","arbuz","wisnia","czeresnia","melon"};
        string animals[10]={"pies","kot","kon","kaczka","jez","ryba","chomik","ptak","mysz","cos"};

    public:
        void image(int); //wyswietla obraz wisielca
        int letterFill(char, string, string&); //sprawdza wprowadzona litere
        void startGame(); //rozpoczyna gre
        int showMenu(); // wyswietla menu
        void categoryDraw(); // generuje wyraz z wybranej kategorii
        int randomNumber(); // losuje randomowa liczbe
        int showGame(); //wyswietla ekran gry
};
