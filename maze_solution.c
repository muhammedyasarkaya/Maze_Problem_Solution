#include <stdio.h>
#include <stdlib.h>

int main()
{

  int maze[1000][1000];

  int counter , counter2 ;

  int X , Y ;

  int m , n ;

  int direction;

  FILE *infile;
  infile = fopen("maze.txt", "r");

  if( ( infile = fopen("maze.txt", "r") ) == NULL)
    {
    printf( "!!!  The 'maze.txt' CAN NOT BE FOUND  !!!\n" );
    return 0;
  }

  fscanf( infile , "%d" , &m );

  fgetc(infile);

  fscanf(infile , "%d" , &n );

  fgetc(infile);

  fscanf( infile , "%d" , &X );

  fgetc(infile);

  fscanf(infile , "%d" , &Y );

  fgetc(infile);

  for(counter = 0 ; counter < m ; counter++ )
  {
  for(counter2 = 0 ; counter2 < n ; counter2++ )
  {
  maze[counter][counter2] = fgetc(infile);
  }

  fgetc(infile);
  }

  if(maze[X][Y+1] == '0' && maze[X+1][Y] == '1' ){
    direction = 1; 
  }
  else if( maze[X][Y+1] == '0' && maze[X+1][Y] == '0' ){
    direction = 3;
    if( maze[X][Y-1] == '0' ){
      printf("There is no exit !\n"); 
    }
  } 

  while ( 1 ){
    if ( direction == 1 ){
      if ( maze[X][Y+1] == '0' && maze[X+1][Y] == '1' ){
        X++;
        if( X == m-1 ) { break; } 
      }
      else if ( maze[X][Y+1] == '1' ){
        Y++;
        direction = 2 ;
      }
      else if ( maze[X][Y+1] == '0' && maze[X+1][Y] == '0' ){
        direction = 3 ;
      }
    }
    
    else if ( direction == 2 ){
      if ( maze[X-1][Y] == '0' && maze[X][Y+1] == '1' ){
        Y++;
        if( Y == n-1 ) { break; } 
      }
      else if ( maze[X-1][Y] == '1' ){
        X--;
        direction = 4 ;
      }
      else if ( maze[X-1][Y] == '0' && maze[X][Y+1] == '0' ){
        direction = 1;
      } 
    }

    else if( direction == 3 ){
      if( maze[X+1][Y] == '0' && maze[X][Y-1] == '1' ){
        Y--;
        if( Y == 0 ) { break; }    
      }
      else if ( maze[X+1][Y] == '1' ){
        X++;
        direction = 1 ;
      }
      else if ( maze[X+1][Y] == '0' && maze[X][Y-1] == '0' ){
        direction = 4 ;
      }
    }

    else if ( direction == 4 ){
      if( maze[X][Y-1] == '0' && maze[X-1][Y] == '1' ){
        X--;
        if( X == 0 ) { break; } 
      }
      else if ( maze[X][Y-1] == '1' ){
        Y--;
        direction = 3 ;
      }
      else if ( maze[X][Y-1] == '0' && maze[X-1][Y] == '0' ){
        direction = 2 ;
      }
    }
  }

  printf( "Exit is ( %d,%d ) \n" , X , Y );
  return 0 ;
}
