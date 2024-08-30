#include<cstdlib>
#include<iostream>
#include <conio.h>
#include <windows.h>
#include<ctime>
using namespace std;

int x = 15;
int y = 5;
int fruitX;
int fruitY;

int random_number(int max){
    srand(static_cast<unsigned>(time(0)));
    int randomN = rand() % max;  
    return randomN;
}

void fruit_generate(){
    int maxNumber = 21;
    fruitX = random_number(maxNumber);
    fruitY = random_number(maxNumber);
}

bool each_fruit(){
    if(x == fruitX && y == fruitY){
        fruit_generate();
    }
}

void draw(){
    int width = 20;
    int height = 20;
    
    for(int i= 0; i < width; i++){
        cout << "#";
    }
    cout << endl;

    for(int i= 0; i < height; i++){
        for(int j= 0; j < width; j++){
            if( j == 0 || j == width - 1){
                cout << "#";
            }
            else if(j == x && i == y){
                cout << "O";
            }
            else if(j == fruitX && i == fruitY){
                cout << "F";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }

    for(int i= 0; i < width; i++){
        cout << "#";
    }
    cout << endl;

}

void left(){
    x = x - 1;
}
void right(){
    x = x + 1;
}
void top(){
    y = y - 1;
}
void bottom(){
    y = y + 1;
}

void input(){
    
    if (_kbhit()){
        switch (_getch()){
            case 'a':
                left();
                break;
            case 'd':
                right();
                break;
            case 'w':
                top();
                break;
            case 's':
                bottom();
                break;
        }
    }
    
}

int main(){
    bool gameover = false;
    fruit_generate();
    while(!gameover){
        system("cls");
        draw();
        input();
        each_fruit();
    }

    
}