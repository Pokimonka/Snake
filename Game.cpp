#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;


bool GameOver;

int width = 40;
int height = 20;

int snakeX, snakeY, fruitX, fruitY;
enum eDirection { Stop, LEFT, RIGHT, UP, DOWN };
eDirection dir;
int counter;

void Setup() {
    GameOver = false;
    dir = Stop;
    snakeX = width / 2;
    snakeY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw() {
    system("cls");
    for (int top = 0; top <= width; top++) {
        cout << '-';
    }
    cout << endl;
    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {
            if (x == 0 || x == width - 1) {
                cout << '|';
            }
            if (x == snakeX && y == snakeY) {
                cout << '#';
            }
            else if (x == fruitX && y == fruitY) {
                cout << 'F';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    int end = 0;
    while (end <= width) {
        cout << '-';
        end++;
    }
    cout << endl;
    std::cout << "Score: " << counter << std::endl;

}

void Input() {

    if (_kbhit()) {
        int k = _getch();
        if (k == 0 || k == 224) {
            k = _getch();
        }

        switch (k) {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            GameOver = true;
            break;
        }
    }

}

void Logic() {

    switch (dir) {
    case UP:
        snakeY--;
        break;
    case LEFT:
        snakeX--;
        break;
    case DOWN:
        snakeY++;
        break;
    case RIGHT:
        snakeX++;
        break;
    }

    if (snakeX == fruitX && snakeY == fruitY) {
        counter += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
    if (snakeX == width || snakeX == -1 || snakeY == height || snakeY == -1) {
        GameOver = true;
    }

}

int main() {
    CONSOLE_CURSOR_INFO curs = { 0 };
    curs.dwSize = sizeof(curs);
    curs.bVisible = FALSE;
    ::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
    Setup();
    while (!GameOver) {
        Draw();
        Sleep(100);
        Input();
        Logic();
    }
    std::cout << "GAME OVER";
}