/*

rubiks cube implementation using opengl. all of the rubik's code written from scratch so might be buggy in some scenarios. Modified a opengl for drawing cube to make the complete 3X3X3 rubik cube. 

author : lokendra sharma (ramanujam17)

compile with the opengl way:

gcc rube.cpp -lglut -lGLU -lGL 

use left,right,down,up arrow keys for changing the view of cube

use a,s,d,f,g,r,t,y,u,i,o,p for various rotations of faces of cube

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>


typedef struct {
	int pos_i,pos_j ,pos_k;
	int top,bottom,left,right,front,back;
} block;

#define SIZE 3
static   block cube[SIZE][SIZE][SIZE];

void rotate_left_clockwise( );
void rotate_right_clockwise( );
void rotate_top_clockwise( );
void rotate_bottom_clockwise( );
void rotate_front_clockwise( );
void rotate_back_clockwise( );
void rotate_left_anticlockwise( );
void rotate_right_anticlockwise( );
void rotate_top_anticlockwise(  );
void rotate_bottom_anticlockwise( );
void rotate_front_anticlockwise(  );
void rotate_back_anticlockwise(  );



static float whole_cube_angular_pos[] = { 0.0,  0.0, 0.0 } ;

static float materialColor[8][4] =
{
  {0.8, 0.8, 0.8, 1.0},
  {0.8, 0.0, 0.0, 1.0},
  {0.0, 0.8, 0.0, 1.0},
  {0.0, 0.0, 0.8, 1.0},
  {0.0, 0.8, 0.8, 1.0},
  {0.8, 0.0, 0.8, 1.0},
  {0.8, 0.8, 0.0, 1.0},
  {0.0, 0.0, 0.0, 0.6},
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



// for left face
void rotate_left_anticlockwise( )
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
						t.top = t.front;
						t.front = t.bottom;
						t.bottom = t.back;
						t.back = temp;
					}

			}
				

}




void rotate_left_clockwise()
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
                                                t.top = t.back;
                                                t.back = t.bottom;
                                                t.bottom = t.front;
                                                t.front = temp;
                                        }

                        }


}




//for right face
void rotate_right_anticlockwise()
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





void rotate_right_clockwise( )
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
                                                t.top = t.front;
                                                t.front = t.bottom;
                                                t.bottom = t.back;
                                                t.back = temp;
                                        }

                        }


}



// for front face
void rotate_front_anticlockwise( )
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




void rotate_front_clockwise( )
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
void rotate_back_anticlockwise( )
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





void rotate_back_clockwise( )
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
void rotate_top_anticlockwise( )
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




void rotate_top_clockwise(  )
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
void rotate_bottom_anticlockwise(  )
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





void rotate_bottom_clockwise(  )
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



static int useRGB = 1;
static int useLighting = 0;
static int useDB = 1;

static int moving = 1;

#define GREY	0
#define RED	1
#define GREEN	2
#define BLUE	3
#define CYAN	4
#define MAGENTA	5
#define YELLOW	6
#define BLACK	7




static float lightPos[4] =
{2.0, 4.0, 2.0, 1.0};
#if 0
static float lightDir[4] =
{-2.0, -4.0, -2.0, 1.0};
#endif
static float lightAmb[4] =
{0.2, 0.2, 0.2, 1.0};
static float lightDiff[4] =
{0.8, 0.8, 0.8, 1.0};
static float lightSpec[4] =
{0.4, 0.4, 0.4, 1.0};


static float cube_vertexes[6][4][4] =
{
  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0}}
};

static float cube_normals[6][4] =
{
  {-1.0, 0.0, 0.0, 0.0},
  {1.0, 0.0, 0.0, 0.0},
  {0.0, -1.0, 0.0, 0.0},
  {0.0, 1.0, 0.0, 0.0},
  {0.0, 0.0, -1.0, 0.0},
  {0.0, 0.0, 1.0, 0.0}
};


void initCube( )
{

	for(int i = 0 ; i< SIZE;i++)
		for(int j = 0 ;j<SIZE; j++)
			for(int  k =0; k<SIZE; k++)
			{
				block & t = cube[i][j][k];
				t.front = t.back = t.top = t.bottom = t.left = t.right = BLACK;
			}	
	

	for( int i = 0; i<SIZE; i++)
		for(int j = 0 ; j<SIZE; j++){
			
			cube[0][i][j].left = RED;
			cube[2][i][j].right  = GREEN;
			cube[i][0][j].top = BLUE;
			cube[i][2][j].bottom = MAGENTA;
			cube[i][j][0].front  = YELLOW;
			cube[i][j][2].back= CYAN;

		}


	for(int  i = 0; i< SIZE; i++)
		for(int j = 0 ;j<SIZE; j++)
			for(int k=0; k<SIZE; k++){
				cube[i][j][k].pos_i =SIZE- i-1;
				cube[i][j][k].pos_j =SIZE- j-1;
				cube[i][j][k].pos_k =SIZE- k-1;
			}


	
}

static void
setColor(int c)
{
  if (useLighting) {
    if (useRGB) {
      glMaterialfv(GL_FRONT_AND_BACK,
        GL_AMBIENT_AND_DIFFUSE, &materialColor[c][0]);
    } else {
      glMaterialfv(GL_FRONT_AND_BACK,
        GL_COLOR_INDEXES, &materialColor[c][0]);
    }
  } else {
    if (useRGB) {
      glColor4fv(&materialColor[c][0]);
    } else {
      glIndexf(materialColor[c][1]);
    }
  }
}



static void 
drawCube(block b)
{
	int i;

	int color_array[] = { b.front, b.left, b.right, b.bottom ,b.top,b.back };

	for(int i =0; i<6; ++i) {
		setColor( color_array[(i+1)%6]);;
		glNormal3fv(&cube_normals[i][0]);
		glBegin(GL_POLYGON);
		glVertex4fv(&cube_vertexes[i][0][0]);
		glVertex4fv(&cube_vertexes[i][1][0]);
    		glVertex4fv(&cube_vertexes[i][2][0]);
    		glVertex4fv(&cube_vertexes[i][3][0]);
    		glEnd();
	}		

	


}




void
idle(void)
{
  glutPostRedisplay();
}

void
keyboard(unsigned char ch, int x, int y)
{
  switch (ch) {
  case 27:             /* escape */
    exit(0);
    break;
  
case 'r' :rotate_left_clockwise( );break;
 case 't' :rotate_right_clockwise( );break;
 case 'y' :rotate_top_clockwise( );break;
 case 'u':rotate_bottom_clockwise( );break;
 case 'i' :rotate_front_clockwise( );break;
 case 'o':rotate_back_clockwise( );break;
 case 'p':rotate_left_anticlockwise( );break;
 case 'a':rotate_right_anticlockwise( );break;
 case 's':rotate_top_anticlockwise(  );break;
 case 'd': rotate_bottom_anticlockwise( );break;
 case 'f' :rotate_front_anticlockwise(  );break;
 case 'g': rotate_back_anticlockwise(  );break;



  case ' ':
    if (!moving) {
      idle();
      glutPostRedisplay();
    }
  }


}

void
display(void)
{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



   glRotatef ( whole_cube_angular_pos[0], 1, 0 , 0 );
   glRotatef ( whole_cube_angular_pos[1], 0, 1 , 0 );
//   glRotatef ( whole_cube_angular_pos[2], 0, 0 , 1 );
	
  

  for(int i = 0; i<3; i++)
	for(int j =0; j<3;j++)
		for(int k =0; k<3; k++)
	{
	 glPushMatrix();
		
	block & t =  cube[i][j][k];
 	glTranslatef(0.9 -0.3*t.pos_i, 0.3*t.pos_j, 0.3*t.pos_k);
  	glScalef(0.1, 0.1, 0.1);
  	drawCube(cube[i][j][k]);        /* draw cube */
  	glPopMatrix();
	}

  glRotatef ( -whole_cube_angular_pos[0], 1, 0 , 0 );
  glRotatef ( -whole_cube_angular_pos[1],0,1,0 );
//  glRotatef ( -whole_cube_angular_pos[2],0,0,1);

  if (useDB) {
    glutSwapBuffers();
  } else {
    glFlush();
  }
}

void
menu_select(int mode)
{
  switch (mode) {
  case 1:
    moving = 1;
    glutIdleFunc(idle);
    break;
  case 2:
    moving = 0;
    glutIdleFunc(NULL);
    break;
  case 5:
    exit(0);
    break;
  }
}

void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
	whole_cube_angular_pos[0] += 1;
break;
case GLUT_KEY_DOWN:
	whole_cube_angular_pos[0] -= 1;
break;
case GLUT_KEY_LEFT:
	whole_cube_angular_pos[1] -= 1;
break;
case GLUT_KEY_RIGHT:
	whole_cube_angular_pos[1] +=1;
break;


}

glutPostRedisplay();
} 


void
visible(int state)
{
  if (state == GLUT_VISIBLE) {
    if (moving)
      glutIdleFunc(idle);
  } else {
    if (moving)
      glutIdleFunc(NULL);
  }
}

int
main(int argc, char **argv)
{
  int width = 350, height = 350;
  int i;
  char *name;
  int fog_menu;



   initCube();



  glutInitWindowSize(width, height);
  glutInit(&argc, argv);
  /* process commmand line args */
  for (i = 1; i < argc; ++i) {
    if (!strcmp("-c", argv[i])) {
      useRGB = !useRGB;
    } else if (!strcmp("-l", argv[i])) {
      useLighting = !useLighting;
    } else if (!strcmp("-db", argv[i])) {
      useDB = !useDB;
    }
  }

  /* choose visual */
  if (useRGB) {
    if (useDB) {
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    } else {
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    }
  } else {
    if (useDB) {
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_INDEX | GLUT_DEPTH);
    } else {
      glutInitDisplayMode(GLUT_SINGLE | GLUT_INDEX | GLUT_DEPTH);
    }
  }

  glutCreateWindow("my rubik -- lokendra");

  glutSpecialFunc(SpecialInput);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
  glutVisibilityFunc(visible);

  /* setup context */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 3.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -2.5);

  glEnable(GL_DEPTH_TEST);

   /*
  if (useLighting) {
    glEnable(GL_LIGHTING);
  }
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
  glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
  */


  glClearColor(0.0, 0.0, 0.0, 1);
  glClearIndex(0);
  glClearDepth(1);

  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
