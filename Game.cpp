#include <iostream>
#include <conio.h>

using namespace std;

bool GameOver;

int width = 40;
int height = 20;

int snakeX, snakeY, fruitX, fruitY;
enum eDirection {Stop, LEFT, RIGHT, UP, DOWN};
eDirection dir;

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
            if (x == 0 || x == width -1) {
                cout << '|';
            }
            if (x == snakeX && y == snakeY) {
                cout << '#';
            } else if (x == fruitX && y == fruitY) {
                cout << 'F';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    int end = 0;
    while (end <= width){
        cout << '-';
        end++;
    }
    cout << endl;
    
}

void Input() {

}

void Logic() {

}

int main() {
    Setup();
    while(!GameOver) {
        Draw();
        Input();
        Logic();
    }
}