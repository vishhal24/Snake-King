#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
enum Direction{STOP = 0,LEFT,RIGHT,UP,DOWN};
Direction dir;
bool gameOver;
const int height = 20;
const int width = 20;
int headX,headY,fruitX,fruitY,score;
int Tail_len;
int tailx[100],taily[100];
void setup();
void draw();
void input();
void logic();


int main(){
    char start;
    cout<<"\t--------------------"<<endl;
    cout<<"\t : Snake King :"<<endl;
    cout<<"\t--------------------"<<endl;
    cout<<"press 's' to start :";
    cin>>start;
    if(start == 's'){
        cout<<"Game Start :";
        setup();
        while(!gameOver){
            draw();
            input();
            logic();
            Sleep(200);//window.h->make your lopp slow;
            system("cls");//remove previour screen, and we will be able to print our new screen at same place;
        }
    }
    return 0;
}
void draw(){
 system("cls");
 //upper border;
 cout<<"\t\t";
 for(int i = 0 ;i<width-8;i++){
    cout<<"||";
}
cout<<endl;
//snake,fruit,space and side borders;
for(int i = 0 ;i<height;i++){
    for(int j = 0 ;j<width;j++){
        if(j == 0){
            cout<<"\t\t||";
        }
        //Snake - head;
        if(i == headY && j == headX){
            cout<<"O";
        }
        //fruit->used else if because head and fruit can not be in same place;
        else if (i == fruitY && j == fruitX){
            cout<< "*";
        }
        // space ,snake tail;
        else{
            bool print = false;
            //tail
            for(int k = 0 ;k<Tail_len;k++){
                if(tailx[k] == j && taily[k] == i){
                    cout<<"o";
                    print = true;
                }
            }
            //space
            if(!print){
                cout<<" ";
            }
        }//right Border
        if(j == width - 1){
            cout<<"||";
        }
    }
        cout<<endl;
}
 //lower border;
 cout<<"\t\t";
 for(int i = 0 ;i<width-8;i++){
    cout<<"||";
}
cout<<endl;
cout<<"\t\tScore: "<<score<<endl;
}
void input(){
   if(_kbhit())//return true till any value in keyboard is hit;
    switch(getch()){
        case 'a':
        dir = LEFT;
        break;
         case 'w':
        dir = UP;
         break;
         case 's':
        dir = DOWN;
         break;
         case 'd':
        dir = RIGHT;
         break;
        default:
        break;
    }
}
void logic(){
    //tail logic;
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x , prev2y;
    tailx[0]= headX;
    taily[0]=headY;
    for(int i = 1;i<Tail_len;i++){
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
        }
        //direction Logic
         switch(dir){
        case UP:
        headY--;
        break;
         case DOWN:
        headY++;
        break;
         case RIGHT:
         headX++;
         break;
         case LEFT:
        headX--;
        break;
        default:
        break;
    } 
    //touch walls
    if(headX>= width){
        headX= 0;
    }
    else if(headX <0){
        headX = width - 1;
    }
    if( headY>=height){
        headY = 0;
    }
    else if(headY<0){
        headY = height-1;
    }
    //snake bite itself
    for(int i = 0 ; i< Tail_len;i++){
        if(tailx[i] == headX && taily[i] == headY){
            gameOver= true;
        }
    }
    //snake eat fruit;
    if(headX == fruitX && headY == fruitY){
        score+=1;
        fruitX = rand()%width;
        fruitY = rand()%height;
        Tail_len++;
    }
}
void setup(){
     gameOver =false;
    dir = STOP;
    headX = width/2;
    headY = height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;
}
