#include <iostream>
 class Sudoku {
 public:
  Sudoku();
 
  void giveQuestion();
  void readIn();
  void solve();

  
  void changeNum(int a, int b);
  void changeRow(int a, int b);
  void changeCol(int a,int b);
  void rotate(int n);
  void flip(int n);
  void transform();


int getNextBlank(int sp);
int check(int sp);
int check1(int sp, int start, int *addnum);
int push(int sp) ;
int pop();





 private:
 int map[9][9];
 int map2[81];
 int startH[100] ;                                // 列位置的起點
int startV[100] ;                                // 行位置的起點
int startB[100] ;                                // 宮位置的起點
int addH[10] ;                                   // 列位置的加值
int addV[10] ;                                   // 行位置的加值
int addB[10] ;    

 };
