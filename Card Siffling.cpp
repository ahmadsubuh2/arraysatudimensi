#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>

void swapCards(char[], char[]);

int card1[] = { 20, 20, 70, 20, 70, 100, 20, 100, 20, 20 };
int card2[] = { 80, 20, 130, 20, 130, 100, 80, 100, 80, 20 };
int card3[] = { 140, 20, 190, 20, 190, 100, 140, 100, 140, 20 };

char cardVal[3][2] = { "1", "2", "3" };

int main() {
  system("cls");
  char count[2] = "0";
  int swapnum = 0; //for number of times to swap the cards
  int driver, mode;

  driver = DETECT;

  initgraph( & driver, & mode, "c:\tc\bgi");

  setfillstyle(HATCH_FILL, BLUE);
  fillpoly(5, card1);
  fillpoly(5, card2);
  fillpoly(5, card3);

  settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
  setcolor(BLUE);
  moveto(25, 25);
  outtext(cardVal[0]);
  moveto(85, 25);
  outtext(cardVal[1]);
  moveto(145, 25);
  outtext(cardVal[2]);

  delay(1500);
  do {
    int num = 0;
    int choice[2];
    count[0]++;

    delay(1500);

    settextstyle(3, HORIZ_DIR, 2);
    moveto(20, 150);
    outtext("No. of Times Cards have been swapped:");
    settextstyle(3, HORIZ_DIR, 3);
    moveto(20 + swapnum * 20, 170);
    outtext(count);
    setfillstyle(HATCH_FILL, BLUE);
    fillpoly(5, card1);
    fillpoly(5, card2);
    fillpoly(5, card3);

    do {
	  srand( (unsigned)time(NULL));
      choice[num] = (rand() + num) % 3;

      switch (choice[num]) {
      case 0:
        setfillstyle(LTSLASH_FILL, YELLOW);
        fillpoly(5, card1);
        break;
      case 1:
        setfillstyle(LTSLASH_FILL, YELLOW);
        fillpoly(5, card2);
        break;
      case 2:
        setfillstyle(LTSLASH_FILL, YELLOW);
        fillpoly(5, card3);
        break;
      }
      num++;
    } while (num < 2);

    swapCards(cardVal[(choice[0])], cardVal[(choice[1])]);

  } while (swapnum++ < 6);

  settextstyle(3, HORIZ_DIR, 3);
  moveto(20, 200);
  setcolor(YELLOW);
  outtext("What is card number 2?	");
  char userChoice;
  userChoice = getch();
  
  moveto(20, 230);
  if (userChoice == cardVal[1][0]) {
    outtext("You Win");
  } else {
    outtext("You Lose");
  }

  getch();
  closegraph();
  return 0;
}

void swapCards(char card1[], char card2[]) {
  char temp;
  temp = card1[0];
  card1[0] = card2[0];
  card2[0] = temp;
}