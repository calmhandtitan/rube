#include<bits/stdc++.h>

using namespace std;;




#define RED 	0
#define BLUE 	1
#define GREEN 	2
#define WHITE 	3
#define YELLOW 	4
#define ORANGE 	5


const int SIZE = 3;


typedef struct {
	int pos_i,pos_j ,pos_k;
	int top,bottom,left,right,front,back;
} block;

void initCube(block cube[SIZE][SIZE][SIZE] );

void rotate_left_clockwise(block cube[SIZE][SIZE][SIZE]);
void rotate_right_clockwise(block cube[SIZE][SIZE][SIZE]);
void rotate_top_clockwise(block cube[SIZE][SIZE][SIZE]);
void rotate_bottom_clockwise(block cube[SIZE][SIZE][SIZE]);
void rotate_front_clockwise(block cube[SIZE][SIZE][SIZE]);
void rotate_back_clockwise(block cube[SIZE][SIZE][SIZE]);


void rotate_left_anticlockwise(block cube[SIZE][SIZE][SIZE]);
void rotate_right_anticlockwise(block cube[SIZE][SIZE][SIZE]);
void rotate_top_anticlockwise(block cube[SIZE][SIZE][SIZE] );
void rotate_bottom_anticlockwise(block cube[SIZE][SIZE][SIZE]);
void rotate_front_anticlockwise(block cube[SIZE][SIZE][SIZE] );
void rotate_back_anticlockwise(block cube[SIZE][SIZE][SIZE] );


void rotate90(int &x int &y)
{
	x-=1;
	y-=1;
	int temp  = x;
	x = -y;
	y= temp;
	x+=1;
	y+=1;
}

void rotate_minus_90(int &x,int &y)
{
	x-=1;
	y-=1;
	int temp  =x;
	x = y;
	y = -temp;
	x+=1;
	y+=1;
	
}


void initCube(block cube[SIZE][SIZE][SIZE])
{

	for( int i = 0; i<SIZE; i++)
		for(int j = 0 ; j<SIZE; j++){
			
			cube[0][i][j].left = RED;
			cube[2][i][j].right  = BLUE;
			cube[i][0][j].top = GREEN;
			cube[i][2][j].down = WHITE;
			cube[i][j][0].front  = YELLOW;
			cube[i][j][2].back= ORANGE;

		}


	for(int  i = 0; i< SIZE; i++)
		for(int j = 0 ;j<SIZE; j++)
			for(int k=0; k<SIZE; k++){
				cube[i][j][k].pos_i = i;
				cube[i][j][k].pos_j = j;
				cube[i][j][k].pos_k = k;
			}


	
}


void rotate_left_anticlockwise(block cube[SIZE][SIZE][SIZE] )
{

	for(int i = 0; i< SIZE; i++)
		for(int  j =0; j<SIZE; j++)
			for(int k =0; k<SIZE ; k++)
			{
				block & t = cube[i][j][k];
				if( t.pos_i == 0  ) // all those small cubes which form the left surface
					{
						//rotate them about the center of that face
						rotate90(t.pos_j,t.pos_k);
						int temp = t.top;
						t.top = t.front;
						t.front = t.bottom;
						t.bottom = t.back;
						t.back = temp;
					}

			}
				

}




void rotate_left_clockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_i == 0  ) // all those small cubes which form the left surface
                                        {
                                                //rotate them about the center of that face
                                                rotate_minus_90(t.pos_j,t.pos_k);
                                                int temp = t.top;
                                                t.top = t.back;
                                                t.back = t.bottom;
                                                t.bottom = t.front;
                                                t.front = temp;
                                        }

                        }


}










void takeNextMove()
{
	
	




}



void solveCube()
{

	while( !solved() )
	{
		takeNextMove();
		displayCube();
	}


}
		





int main()
{

	initCube();
	solveCube();

}
