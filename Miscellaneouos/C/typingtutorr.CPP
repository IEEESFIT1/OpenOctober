#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>
#include <time.h>

int score = 0;
int missedCounter = 0;
int levelChoice = 0;
int wrongKeyCounter = 0;
int speedChoice = 0;
char startingIntroString[] ="Typing Tutor game by Manisha";
char startNewGameString[] = "\nStart New Game \nSelect Game Level \n(1) Capital Alphabet Mode (A-Z)\n(3) Digits Mode (0-9)\nYour Choice is ";
char selectLevelString[] = "\nSelect Speed Level\n(1) Speed Level One\n(2) Speed Level Two\nYour Choice is ";
char authorString[] = "\nAbout";
char helpString[] = "\nThis game helps to improve your typing speed and sharpens your brain. Game has  three modes for the players. First is Begineers mode which is for basic typing,  next one is Learner mode which is designed for Medium typing speed and last one  is Expert Mode which is designed to sharpen your skills at their best\n\nSpeed Level 1 : 1 second time delay\nSpeed Level 2 : 500 milisecond time delay\nSpeed level 3 : 300 milisecond time delay\n\nGame consits of Capital Alphabets, Small Alphabets, and Numbers (0-9) which varies with different difficulty level\n\nThis game also consist of Score Card which displays your currant Score and also Consists of Missing Alphabets Counter displayed in the game.\nBackSpace to return to Main Menu.\nESC to Exit Game";
int choice= 0 ;
int t=100 ;
int  delayTime = 0;
int missedNum[100];

struct node{
       int data;
       int x;
       int y;
       node *next;
       }*first,*l,*temp;

void InsertNode(int dat);
void deleteNode(int data);
void author();
void startingScreen();
void levelSelection();
void gameBoard();
void helpScreen();
int randX();
void printChar();
void capitalAlphabet();
void digits();
void gameLost();
int searchInLinkList(int data);
void keyPressed();
void winningScreen();

void main(){
 clrscr();
 srand ( time(NULL) );
 startingScreen();
 getch();
}

void author(){
 char k;
 int key;
 clrscr();
 for (int i=0 ; authorString[i]!= '\0' ; i++){
  printf("%c",authorString[i]);
  delay(50);
 }
 do {
 k = getch();
 key = k;
 if(key == 8){
 startingScreen();
 }
 }while(key!=27);
}

void startingScreen(){
  choice = 0;
 clrscr();
 for (int i=0 ; startingIntroString[i]!='\0' ; i++){
  printf("%c",startingIntroString[i]);
  delay(100);
 }
 delay(100);
 printf("\n(1) To Start Game\n(2) To Help\n(3) About Author\n(4) Exit Game\nEnter your choice");
 scanf("%d",&choice);
 if(choice == 1){
  levelSelection();
 }
 if(choice == 2){
  helpScreen();
 }
 if(choice == 3){
  author();
 }
 else if (choice == 4){
  exit(0);
 }
 else
 startingScreen();
}

void levelSelection(){
 clrscr();
 for (int i=0 ; startNewGameString[i]!= '\0' ; i++){
  printf("%c",startNewGameString[i]);
  delay(10);
 }
 scanf("%d",&levelChoice);
 for (int j=0 ; selectLevelString[j]!='\0' ; j++){
  printf("%c",selectLevelString[j]);
  delay(10);
 }
 scanf("%d",&speedChoice);
 if (levelChoice>=1 && levelChoice<=3 && speedChoice>=1 && speedChoice<=2){
  if (speedChoice == 1){
   delayTime = 1000;
  }
  else if (speedChoice == 2){
   delayTime = 500;
  }
  keyPressed();
 }
 else{
  levelSelection();
 }
}
void InsertNode(int data , int x , int y ){
     if(first == NULL){
     first = new node();
     first->data = data;
     first->x = x;
     first->y = y;
  first->next = NULL;
     l = first;
     }
     else {
   while(l->next!=NULL)
    l=l->next;
    temp = new node();
    temp->data = data;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    l->next = temp;
    l = temp;
   }
   }
   
void deleteNode(int data){
   temp = l =first;
   while(l){
   if(l->data == data){
        if(l==first){
    first = first->next;
    l=NULL;
    l=first;
	}
        else if(l->next!=NULL){
       temp->next=l->next;
       l=NULL;
       l=temp->next;
	}
        else {
      temp->next = NULL;
      l = NULL;
      l=temp;
	}
   }
   temp  = l;
   l = l->next;
   }
}

void helpScreen(){
 char k;
 int key;
 clrscr();
 for (int i=0 ; helpString[i] ; i++){
  printf("%c",helpString[i]);
  delay(25);
 }
 do {
 k = getch();
 key = k;
 if(key == 8){
 startingScreen();
 }
 }while(key!=27);
}

int randX(){
 int x = 0 ;
 x = (rand_r()%80)+1;
 return x;
}

void printChar(){
 clrscr();
  l = first;
     while(l->next){
         gotoxy(l->x,l->y++);
              printf("%c",l->data);
            if(l->y<=20)
     l =  l->next;
     else{
   missedNum[missedCounter++] = l->data ; 
     deleteNode(l->data);
     printChar();
   } 
       } 
       gotoxy(l->x,l->y++);
       printf("%c\n",l->data);
 gotoxy(1,20);
 printf("______________________________________________________________________________");
 gotoxy(1,22);
 printf("Score : %d",score);
 gotoxy(27,22);
 printf("Time Left : %d ",t--);
 gotoxy(60,22);
 printf("Digits Missed : %d",missedCounter);
 gotoxy(1,24);
 printf("Characters Missed : ");
 for (int i=0 ; i<missedCounter ; i++){
  printf("%c ",missedNum[i]);
} 
 gotoxy(60,24);
 printf("Wrong Key Hits : %d",wrongKeyCounter);
} 

void capitalAlphabet(){
 int randNum = 0;
 randNum = 65 + (rand_r() % (int)(90 - 65 + 1)); 
 InsertNode(randNum,randX(),0);
 printChar();
} 
void digits(){
 int randNum = 0;
 randNum = 48 + (rand_r() % (int)(57 - 48 + 1)); 
 InsertNode(randNum,randX(),0);
 printChar();
} 
void keyPressed(){
  int key=0;
  do{
  if(kbhit()){
  char k =getch();
  key = k;
  if(searchInLinkList(key) == 1){
   score++;
   deleteNode(key);
  } 
  else{
  wrongKeyCounter++;
  } 
 } 
 if (levelChoice == 1){
  capitalAlphabet();
 } 
 else if(levelChoice == 3){
  digits();
 } 
 delay(delayTime);
}while(key != 27 && missedCounter+wrongKeyCounter<10 && t>0); 
if(missedCounter+wrongKeyCounter>=10){
 gameLost();
} 
if (t<=0){
 winningScreen();
}
 } 

void gameLost(){
 clrscr();
 delay(1000);
 printf("\n\n\t\t\t\tSummary");
 delay(1000);
 printf("\n\n\t\t\tYou Have Lost the Game");
 delay(1000);
 printf("\n\n\t\t\tScore : %d",score);
 delay(1000);
 printf("\n\n\t\t\tNumber of Wrong Keys Hit : %d",wrongKeyCounter);
 delay(1000);
 printf("\n\n\t\t\tNumber of Character Missed : %d",missedCounter);
 printf("\n\n\t\t\tCharacters Missed : ");
 for (int i = 0; i<missedCounter ; i++){
  printf("%c  ",missedNum[i]);
  delay(1000);
 } //ending of for.
 delay(1000);
 printf("\n\n\t\t\tBetter Luck Next Time");
 delay(1000);
 printf("\n\n\tYou should try again to increase your score.");
 delay(1000);
 printf("\n\nYou will be redirected to Exit after 1 Second ........... Please Wait");
 delay(4000);
 exit(0);
}

int searchInLinkList(int data){
 int search = 0;
 l = first;
 while(l){
   if(l->data == data){
        search = 1;
        return search;
   }        
   l = l->next;
 }
 return search;
} 

void winningScreen(){
 clrscr();
 delay(1000);
 printf("\n\tCongratulations :) ");
 delay(1000);
 printf("\n\tYou Have Won the Game !!!!");
 delay(1000);
 printf("\n\tNumber of Wrong key Hits : %d ",wrongKeyCounter);
 delay(1000);
 printf("\n\tNumber of Character Missed : %d ",missedCounter);
 delay(1000);
 printf("\n\tCharacters Missed : ");
 for (int i = 0; i< missedCounter ; i++){
  printf("%c ",missedNum[i]);
  delay(1000);
 }
 delay(1000);
 printf("\n\t\Try Again to Increase your Score.");
 delay(1000);
 printf("\n\t\tYou will be redirected to Exit after 2 Seconds.");
 sleep(3);
 exit(0);
}
