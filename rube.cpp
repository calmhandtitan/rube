#include<bits/stdc++.h>

using namespace std;;




#define RED 	1
#define BLUE 	2
#define GREEN 	3
#define WHITE 	4
#define YELLOW 	5
#define ORANGE 	6


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



void  (*functions[])(block cube[][SIZE][SIZE]) = { 
								rotate_left_clockwise , 
								rotate_left_anticlockwise ,
								rotate_right_clockwise,
								rotate_right_anticlockwise,
								rotate_front_clockwise,
								rotate_front_anticlockwise,
								rotate_back_clockwise,
								rotate_back_anticlockwise,
								rotate_top_clockwise,
								rotate_top_anticlockwise,
								rotate_bottom_clockwise,
								rotate_bottom_anticlockwise
							};





void rotate90(int &x, int &y)
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
			cube[i][2][j].bottom = WHITE;
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

// for left face
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




//for right face
void rotate_right_anticlockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_i == 2  ) // all those small cubes which form the left surface
                                        {
                                                //rotate them about the center of that face
                                                rotate90(t.pos_j,t.pos_k);
                                                int temp = t.top;
                                                t.top = t.back;
                                                t.back = t.bottom;
                                                t.bottom = t.front;
                                                t.front = temp;
                                        }

                        }


}





void rotate_right_clockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_i == 2  ) // all those small cubes which form the left surface
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



// for front face
void rotate_front_anticlockwise(block cube[SIZE][SIZE][SIZE] )
{

	for(int i = 0; i< SIZE; i++)
		for(int  j =0; j<SIZE; j++)
			for(int k =0; k<SIZE ; k++)
			{
				block & t = cube[i][j][k];
				if( t.pos_k == 0  ) // all those small cubes which form the left surface
					{
						//rotate them about the center of that face
						rotate90(t.pos_i,t.pos_j);
						int temp = t.top;
						t.top = t.left;
						t.left = t.bottom;
						t.bottom = t.right;
						t.right = temp;
					}

			}
				

}




void rotate_front_clockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_k == 0  ) // all those small cubes which form the left surface
                                        {
                                                //rotate them about the center of that face
                                                rotate_minus_90(t.pos_i,t.pos_j);
                                                int temp = t.top;
                                                t.top = t.right;
                                                t.right = t.bottom;
                                                t.bottom = t.left;
                                                t.left = temp;
                                        }

                        }


}




//for back face
void rotate_back_anticlockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_k == 2  ) // all those small cubes which form the left surface
                                        {
                                                //rotate them about the center of that face
                                                rotate90(t.pos_i,t.pos_j);
                                                int temp = t.top;
                                                t.top = t.left;
                                                t.left = t.bottom;
                                                t.bottom = t.right;
                                                t.right = temp;
                                        }

                        }


}





void rotate_back_clockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_k == 2  ) // all those small cubes which form the left surface
                                        {
                                                //rotate them about the center of that face
                                                 rotate_minus_90(t.pos_i,t.pos_j);
                                                int temp = t.top;
                                                t.top = t.right;
                                                t.right = t.bottom;
                                                t.bottom = t.left;
                                                t.left = temp;
                                        }

                        }


}



// for top face
void rotate_top_anticlockwise(block cube[SIZE][SIZE][SIZE] )
{

	for(int i = 0; i< SIZE; i++)
		for(int  j =0; j<SIZE; j++)
			for(int k =0; k<SIZE ; k++)
			{
				block & t = cube[i][j][k];
				if( t.pos_j == 0  ) // all those small cubes which form the left surface
					{
						//rotate them about the center of that face
						rotate90(t.pos_i,t.pos_k);
						int temp = t.back;
						t.back = t.right;
						t.right = t.front;
						t.front = t.left;
						t.left = temp;
					}

			}
				

}




void rotate_top_clockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_j == 0  ) // all those small cubes which form the left surface
                                        {
                                                //rotate them about the center of that face
                                                rotate_minus_90(t.pos_i,t.pos_k);
                                                int temp = t.back;
                                                t.back = t.left;
                                                t.left = t.front;
                                                t.front = t.right;
                                                t.right = temp;
                                        }

                        }


}




//for bottom face
void rotate_bottom_anticlockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_j == 2  ) // all those small cubes which form the left surface
                                        {
                                                //rotate them about the center of that face
                                                rotate90(t.pos_i,t.pos_k);
						int temp = t.back;
						t.back = t.right;
						t.right = t.front;
						t.front = t.left;
						t.left = temp;
                                        }

                        }


}





void rotate_bottom_clockwise(block cube[SIZE][SIZE][SIZE] )
{

        for(int i = 0; i< SIZE; i++)
                for(int  j =0; j<SIZE; j++)
                        for(int k =0; k<SIZE ; k++)
                        {
                                block & t = cube[i][j][k];
                                if( t.pos_j == 2  ) // all those small cubes which form the left surface
                                        {
                                                //rotate them about the center of that face
                                                rotate_minus_90(t.pos_i,t.pos_k);
                                                int temp = t.back;
                                                t.back = t.left;
                                                t.left = t.front;
                                                t.front = t.right;
                                                t.right = temp;
                                        }

                        }


}











void displayCube(block cube[SIZE][SIZE][SIZE])
{


	for(int i =0 ; i<SIZE; i++)
		for(int j = 0; j<SIZE; j++)
			for(int k =0; k<SIZE; k++){
				block & t= cube[i][j][k];
				printf("%d,%d,%d -> %d,%d,%d,%d,%d,%d\n", i,j,k, t.front,t.back,t.left,t.right,t.top,t.bottom);
	

	}
	printf("\n\n");
}


void invariant(block cube[SIZE][SIZE][SIZE])
{

	int colors[7];
	memset(colors,0,sizeof(colors));
	for(int i = 0; i< SIZE; i++)
		for(int j =0 ; j<SIZE; j++)
			for(int k =0 ; k<SIZE; k++)
			{
				block & t = cube[i][j][k];
				colors[ t.left ] ++;
				colors[ t.right] ++;
				colors[ t.top  ] ++;
				colors[ t.bottom] ++;
				colors[ t.front ] ++;
				colors[ t.back  ] ++;
			}

	for(int i=0; i<7; i++)
		printf("%d ",colors[i] );
	cout << endl;
	assert( colors[1] == 9 and colors[2] == 9 and colors[3] == 9 and colors[4] == 9 and colors[5] == 9 and colors[6] == 9 );
			



}





int main()
{

	block cube[SIZE][SIZE][SIZE];
	
	memset(cube,0,sizeof(cube));

	initCube(cube);


	for(int i = 0; i<12; i++)
	{
		printf("fucntion : %d\n",i);
		functions[i]( cube );
		invariant(cube);
		displayCube(cube);
	}		


	

	return 0;
}

