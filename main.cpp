#include <windows.h>
#include <GL\glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float shift = -300,mov=0,s=0;
float x1 = 650, y1=20;
int exit1=1,miss=0;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640, 0.0, 480);
}
void boat() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.3, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 380);
	glVertex2f(640, 380);
	glVertex2f(640, 0);
    glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(385 + shift, 400);
	glVertex2f(405+ shift, 380);
	glVertex2f(470+ shift, 380);
	glVertex2f(485+ shift, 400);
    glEnd();
    //glutSwapBuffers();

}
void rod(float shift,float mov)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(420 + shift, 400);
	glVertex2f(427 + shift, 400);
	glVertex2f(500 + shift, 420+mov);
    glVertex2f(507 + shift, 420+mov);
	glEnd();

    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(503 + shift, 420+mov);
	glVertex2f(503 + shift, 100+mov);
	glVertex2f(505 + shift, 100+mov);
	glVertex2f(505 + shift, 420+mov);
	glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(504 + shift,100+mov);
    glVertex2f(501 + shift,85+mov);
    glVertex2f(507 + shift,85+mov);
    glEnd();
    //glutSwapBuffers();
}
//void hook(float )
void fish1(float a, float b)
{
    //glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3,0.0,0.7);
	glBegin(GL_POLYGON);//body
	glVertex2f(100+a,100+b);
	glVertex2f(125+a,125+b);
	glVertex2f(150+a,100+b);
	glVertex2f(125+a,75+b);
	//glVertex2f(100+a,100+b);
     glEnd();
glColor3f(1.0,0.0,0.9);
	glBegin(GL_LINES);//body
	glVertex2f(147+a,105+b);
	glVertex2f(147+a,95+b);
	glEnd();
glColor3f(1.0,0.0,0.9);
	glBegin(GL_LINES);//body
	glVertex2f(135+a,115+b);
	glVertex2f(135+a,85+b);
	glEnd();
glColor3f(1.0,0.0,0.9);
	glBegin(GL_LINES);//body
	glVertex2f(127+a,125+b);
	glVertex2f(127+a,75+b);
	glEnd();
 glBegin(GL_POLYGON);//fins1
	glColor3f(1.0,0.0,0.9);
	glVertex2f(125+a,125+b);
	glVertex2f(120+a,160+b);
	glVertex2f(125+a,140+b);
	glVertex2f(130+a,160+b);
	glVertex2f(125+a,125+b);
	 glEnd();
glBegin(GL_POLYGON);//fin2
	glColor3f(1.0,0.0,0.9);
	glVertex2f(125+a,75+b);
	glVertex2f(120+a,45+b);
	glVertex2f(125+a,60+b);
	glVertex2f(130+a,45+b);
	glVertex2f(125+a,75+b);
	glEnd();
  glBegin(GL_POLYGON);//tail
	glColor3f(1.0,0.0,0.9);
    glVertex2f(150+a,100+b);
	glVertex2f(175+a,125+b);
	glVertex2f(175+a,75+b);
	glEnd();
glBegin(GL_POINTS);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(115+a,105+b);
	glEnd();
	//g//lutSwapBuffers();
}

void score(int s){
    //glClear(GL_COLOR_BUFFER_BIT);
int i=0, j=0, k=0;
 i = s / 100;
 j = s / 10 - i * 10;
 k = s - j * 10 - i * 100;
 glPushMatrix();
 glColor3f(1.0, 0.0, 0.0);
 glTranslated(480, 440, 0);
 glScaled(.2, .2, 0);
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'c');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)':');
 glColor3f(1.0, 0.0, 0.0);
//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int) s + 48);
glutStrokeCharacter(GLUT_STROKE_ROMAN, 48+ (int)i /*+ 48*/);
 glutStrokeCharacter(GLUT_STROKE_ROMAN, 48+ (int)j /*+ 48*/);
 glutStrokeCharacter(GLUT_STROKE_ROMAN, 48+ (int)k /*+ 48*/);
 glPopMatrix();
 glutSwapBuffers();
 //glFlush();
}
void endp(){ glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glColor3f(0.1, 0.1, 0.1);
  glVertex2f(0, 550);
  glVertex2f(650, 550);
  glVertex2f(650, 0);
  glVertex2f(0, 0);
  glEnd();
    score(s);
  glPushMatrix();
  glColor3f(1, 1, 0);
  glTranslated(200, 400, 0);
  glScaled(.4, .4, 0);

  glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'G');
  glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'A');
  glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'M');
  glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'E');
  glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'O');
  glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'V');
  glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'E');
  glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'R');
  //glEnd();
  glPopMatrix();
    glutSwapBuffers();
  //glFlush();
}

//}
int random()
{
   // srand((int)time(0));
 int c= rand() % 5 + 1;
 if(c==1)
 {
  y1=110;
 }
 else if(c==2)
 {
  y1=50;
 }
 else if(c==3)
 {
  y1=-10;
 }
 else if(c==4)
 {
  y1=-50;
 }
 else if(c==4)
 {
  y1=-110;
 }
 return y1;

}
void page1()
{
    if(exit1 == 1)
 {

  if(x1<=shift+507 && x1>shift+501 && mov<=100 )
  {
      s=s+0.1;
   exit1 = 1;
  }

  if (s < 25)
  {
   x1 -= 0.2;
  }
  if (s >= 20 && s < 50)
  {
   x1 -= 0.4;
  }
  if (s >= 50)
  {
   x1 -= 0.6;
  }

  if (x1 < -500)
  {
      //srand((int)time(0));
   miss += 1;
   if(miss == 15)
 {
     //printf("%d/n",miss);
     exit1=0;
 }
 //srand((int)time(0));
   int c= rand() % 8 + 1;
   if(c==1)
   {
    x1 = 300;
    y1=130;
   }
   else if(c==2)
   {
    x1 = 590;
    y1=110;
   }
   else if(c==3)
   {
    x1 = 610;
    y1=90;
   }
   else if(c==4)
   {
    x1 = 620;
    y1=70;
   }
   else if(c==5)
   {
    x1 = 590;
    y1=50;
   }
   else if(c==6)
   {
    x1 = 620;
    y1=30;
   }
   else if(c==7)
   {
    x1 = 580;
    y1=10;
   }
   else if(c==8)
   {
    x1 = 610;
    y1=-10;
   }

  }
  score(s);
  if(exit1==1)
  {
   rod(shift,mov);
  }
  boat();
  rod(shift,mov);
  fish1(x1, y1);
 }
 if (exit1==0)
 {
     endp();
  glutPostRedisplay();
  for(int i =0;i<900000000;i++)
  {
  }
  //endp();
 }
}

//}
void disp(){
    glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.1,0.1);
	glVertex2i(0,0);
	glVertex2i(0,1000);
	glVertex2i(1000,1000);
	glVertex2i(1000,0);
	glEnd();


glColor3f(0.0, 0.0, 1.0);
 glPushMatrix();
 glColor3f(0.0, 1.0, 0.0);
 glTranslated(480, 50, 0);
 glScaled(.06, .1, 0);
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'a');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
 glPopMatrix();

 glPushMatrix();
 glColor3f(0.0, 1.0, 0.0);
 glTranslated(480, 35, 0);
 glScaled(.06, .1, 0);
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'q');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'q');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'u');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'i');
 glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
 glPopMatrix();
 //glutSwapBuffers();
 //glEnd();
    glFlush();
}
void keyboards(unsigned char key, int x4, int y4)
{
 //start key
 if (key == 's')
 {
  glutIdleFunc(page1);
 }
 //stop key
 if (key == 'q')
 {
  exit(-1);
 }
 if(key=='w')
    glutIdleFunc(endp);
//glutPostRedisplay();
}
void key(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		shift-=20;
		//glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		shift+=20;
		//glutPostRedisplay();
		break;
    case GLUT_KEY_DOWN:
        mov-=20;
        //glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        mov+=20;
        //glutPostRedisplay();
        break;
}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("FISHING GAME");
	init();
	glutDisplayFunc(disp);
	glutSpecialFunc(key);
	glutKeyboardFunc(keyboards);
	glutMainLoop();
	return 0;
}
