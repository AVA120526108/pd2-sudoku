#include <vector>
#include <iostream>
#include <fstream>
#include<string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#include "Sudoku.h"
 using namespace std;

 Sudoku::Sudoku()
  {
  for(int i=0; i<9; ++i)
  for(int j=0; j<9; ++j)
  map[i][j]=0;
  }

void Sudoku::giveQuestion(){
 int problem[9][9]={0,4,0,2,1,0,0,0,0,
                8,0,7,0,0,0,0,9,0,
				2,0,0,8,0,0,4,0,1,
				3,0,0,0,0,2,9,0,5,
				0,0,5,7,0,8,6,0,0,
				7,0,6,5,0,0,0,0,4,
				5,0,1,0,0,4,0,0,9,
				0,6,0,0,0,0,7,0,8,
				0,0,0,0,2,7,0,5,0};
				 for( int i = 0 ; i < 9 ; i++ ){
                   for( int j = 0 ; j < 9 ; j++ ){
                   	map[i][j]=problem[i][j];
				   }}
 for( int i = 0 ; i < 9 ; i++ ){
        for( int j = 0 ; j < 9 ; j++ )
            printf( "%2d" , map[ i ][ j ] ) ;
        printf( "\n" ) ;
    }
    printf( "\n" ) ;
}

void Sudoku::readIn(){
	for( int i = 0 ; i < 9 ; i++ )
        for( int j = 0 ; j < 9 ; j++ )
        cin>>map[ i ][ j ] ;
}
void Sudoku::rotate(int n){
int tmp[ 9 ][ 9 ] ;
    n %= 4 ;
    while( n-- ){
        for( int i = 0 ; i < 9 ; i++ )
            for( int j = 0 ; j < 9 ; j++ )
                tmp[ j ][ 8 - i ] = map[ i ][ j ] ;
        for( int i = 0 ; i < 9 ; i++ )
            for( int j = 0 ; j < 9 ; j++ )
                map[ i ][ j ] = tmp[ i ][ j ] ;
    }
}
void Sudoku::changeNum(int a,int b){
  for( int i = 0 ; i < 9 ; i++ ){
        for( int j = 0 ; j < 9 ; j++ ){
            if( map[ i ][ j ] == a ) map[ i ][ j ] = b ;
            else if( map[ i ][ j ] == b ) map[ i ][ j ] = a ;
        }
    }
}
void Sudoku::changeCol(int a,int b){
for( int i = 0 , tmp ; i < 3 ; i++ ){
        for( int k = 0 ; k < 9 ; k++ ){
            tmp = map[ k ][ a * 3 + i ] ;
            map[ k ][ a * 3 + i ] = map[ k ][ b * 3 + i ] ;
            map[ k ][ b * 3 + i ] = tmp ;
        }
    }
}

void Sudoku::changeRow(int a,int b){
for( int i = 0 ; i < 3 ; i++ ){
        for( int j = 0 , tmp ; j < 9 ; j++ ){
            tmp = map[ a * 3 + i ][ j ] ;
            map[ a * 3 + i ][ j ] = map[ b * 3 + i ][ j ] ;
            map[ b * 3 + i ][ j ] = tmp ;
        }
    }
}
void Sudoku::flip(int n){
 if( n ){
        for( int i = 0 , tmp ; i < 4 ; i++ ){
            for( int j = 0 ; j < 9 ; j++ ){
                tmp = map[ i ][ j ] ;
                map[ i ][ j ] = map[ 8 - i ][ j ] ;
                map[ 8 - i ][ j ] = tmp ;
            }
        }
    }
    else{
        for( int i = 0 , tmp ; i < 9 ; i++ ){
            for( int j = 0 ; j < 4 ; j++ ){
                tmp = map[ i ][ j ] ;
                map[ i ][ j ] = map[ i ][ 8 - j ] ;
                map[ i ][ 8 - j ] = tmp ;
            }
        }
    }
}

void Sudoku::solve()
{
	int map3[81];

for(int row = 0; row < 9; row++) 
        for(int column = 0; column < 9; column++) {
        	
            int j=row*9 + column ;
			map2[j] = map[row][column]; 
        }

 int sum=0 ;
 int tempSp=0;
 int tempNum[100] ;
 int j;   
   int sp=getNextBlank(-1) ;                    // 眔材フ竚秨﹍恶计
   do {
      map2[sp]++ ;                            // 盢セ竚计 1
      if(map2[sp] > 9) {                  // 狦セ竚计 9 玥竚膥尿代刚
         map2[sp]= 0 ;
         if(tempSp<=0) sp=-1 ;
                else sp=tempNum[--tempSp] ;
      } else {
         if(check(sp)==0) {                     // 狦︽甤常⊿Τ计玥フ矪膥尿
             tempNum[tempSp++]= sp ;                        // 讽礛狦祇瞷Τ计碞惠р竚计 1(┮セ矪ぐ或常ぃ暗)
            sp= getNextBlank(sp) ;
            if(sp==81) {
              
               for(int j=0; j< 81; j++) map3[j]=map2[j];
               sum++ ;
              if(tempSp<=0) sp=-1 ;
                 else sp=tempNum[--tempSp] ;
            }           
         }
      }
   } while(sp>=0 && sp< 81 && sum<2);
  
   
   if(sum>1) printf( "2\n");
   else if (sum==1){printf( "1\n");
               for(int i=0; i< 81; i++) {
                printf( "%2d", map3[i]);
                if(i%9==(8)) printf("\n");
                }}
            
       else  printf( "0\n");

}

int Sudoku::getNextBlank(int sp) {
   // 眔フ竚
   do {
      sp++ ;
   } while(sp< 81 && map2[sp]>0) ;
   return(sp) ;
}

int Sudoku::check(int sp) {

int startH[100] ;                                // 竚癬翴
int startV[100] ;                                // ︽竚癬翴
int startB[100] ;                                // 甤竚癬翴
int addH[10] ;                                   // 竚
int addV[10] ;                                   // ︽竚
int addB[10] ;    

   int i ;
for(i=0; i<81; i++) {
	      startH[i]= i/9* 9 ;                       // 竚癬翴
	      startV[i]= i% 9 ;                         // ︽竚癬翴
	      startB[i]= ((i/9)/3)*27+ ((i%9)/3)*3 ;    // 甤竚癬翴
	   }
	   for(i=0; i<9; i++) {
	      addH[i]= i ;                              // 竚
	      addV[i]= i*9 ;                            // ︽竚
	      addB[i]= (i/3)*9+ (i%3) ;                 // 甤竚
	   }
   int fg= 0 ;
   fg= check1(sp, startH[sp], addH) ;           // 浪琩甤Τ⊿Τ计
   if(!fg) fg= check1(sp, startV[sp], addV) ;   // 浪琩甤Τ⊿Τ计
   if(!fg) fg= check1(sp, startB[sp], addB) ;   // 浪琩甤Τ⊿Τ计
   return(fg) ;
}   

int Sudoku::check1(int sp, int start, int *addnum) {
   // 浪琩﹚︽甤Τ⊿Τ计璝Τ肚 1
   
   int fg= 0, i, sp1  ;
   for(i=0; i< 9; i++) {
      sp1= start+ addnum[i] ;
      if(sp!=sp1 && map2[sp]==map2[sp1]) fg++ ;
   }
   return(fg) ;
}   





void Sudoku::transform(){
  srand( time( NULL ) ) ;
    for( int i = 0 , j = rand() % 9 ; i < j ; i++ )
        changeNum( rand() % 9 + 1 , rand() % 9 + 1 ) ;
    for( int i = 0 , j = rand() % 3 + 1 ; i < j ; i++ ){
        changeRow( rand() % 3 , rand() % 3 ) ;
        changeCol( rand() % 3 , rand() % 3 ) ;
    }
    rotate( rand() % 4 ) ;
    flip( rand() % 2 ) ;
    
for( int i = 0 ; i < 9 ; i++ ){
        for( int j = 0 ; j < 9 ; j++ )
            printf( "%2d" , map[ i ][ j ] ) ;
        printf( "\n" ) ;
    }
    printf( "\n" ) ;
  
}

