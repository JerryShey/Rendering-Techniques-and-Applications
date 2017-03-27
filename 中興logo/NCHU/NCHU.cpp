// NCHU.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "math.h"

#define unitAngle 3.1415926/180.0
#define YUp 43.0/221.0
#define yDown 11.0/221.0
#define yUp 34.0/221.0

void drowCircle(float x, float y, float r, int start, int angle){
	float pointOut[360][2];
	GLfloat certenX = x / 755.0, certenY = 1.0 - y / 221.0;
	for (int i = 0; i < angle; i++){
		pointOut[i][0] = (x + r*cosf(unitAngle*(start + i))) / 755.0;
		pointOut[i][1] = 1.0 - (y + r*sinf(unitAngle*(start + i))) / 221.0;
	}

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < angle - 2; i++){
		glVertex3f(certenX, certenY, 0.0);
		glVertex3f(pointOut[i][0], pointOut[i][1], 0.0);
		glVertex3f(pointOut[i+1][0], pointOut[i+1][1], 0.0);
	}
	glEnd();
}

void drowN(void){
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
	glBegin(GL_TRIANGLES);
		/*0*/
		glVertex3f(8.0 / 755.0, YUp, 0.0);
		glVertex3f(8.0 / 755.0, yDown, 0.0);
		glVertex3f(11.0 / 755, yDown, 0.0);
		/*1*/
		glVertex3f(8.0 / 755.0, YUp, 0.0);
		glVertex3f(11.0 / 755, yDown, 0.0);
		glVertex3f(11.0 / 755, YUp, 0.0);
		/*2*/
		glVertex3f(11.0 / 755, YUp, 0.0);
		glVertex3f(11.0 / 755, 38.0 / 221, 0.0);
		glVertex3f(29.0 / 755, yDown, 0.0);
		/*3*/
		glVertex3f(29.0 / 755, yDown, 0.0);
		glVertex3f(11.0 / 755, YUp, 0.0);
		glVertex3f(29.0 / 755, 16.0 / 221, 0.0);
		/*4*/
		glVertex3f(29.0 / 755, yDown, 0.0);
		glVertex3f(29.0 / 755, YUp, 0.0);
		glVertex3f(32.0 / 755, yDown, 0.0);
		/*5*/
		glVertex3f(29.0 / 755, YUp, 0.0);
		glVertex3f(32.0 / 755, yDown, 0.0);
		glVertex3f(32.0 / 755, YUp, 0.0);

	glEnd();
}

void drowU(int x){
	drowCircle(x + 14, 200, 10, 0, 105);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(x + 14, 200, 7, 0, 105);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	drowCircle(x + 10, 200, 10, 75, 105);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(x + 10, 200, 7, 75, 105);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f(x / 755.0, YUp, 0.0);
		glVertex3f(x / 755.0, 17.0/221.0, 0.0);
		glVertex3f((x+3) / 755.0, YUp, 0.0);
		/*2*/
		glVertex3f((x + 3) / 755.0, 17.0 / 221.0, 0.0);
		glVertex3f(x / 755.0, 17.0 / 221.0, 0.0);
		glVertex3f((x + 3) / 755.0, YUp, 0.0);
		/*3*/
		glVertex3f((x + 21) / 755.0, YUp, 0.0);
		glVertex3f((x + 21) / 755.0, 18.0 / 221.0, 0.0);
		glVertex3f((x + 24) / 755.0, YUp, 0.0);
		/*4*/
		glVertex3f((x + 24) / 755.0, 18.0 / 221.0, 0.0);
		glVertex3f((x + 21) / 755.0, 18.0 / 221.0, 0.0);
		glVertex3f((x + 24) / 755.0, YUp, 0.0);
	glEnd();
}

void drowi(int x){
	float x1 = x / 755.0;
	float x2 = (x + 3) / 755.0;
	float y2 = 39.0 / 221.0;
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f(x1, YUp, 0.0);
		glVertex3f(x1, y2, 0.0);
		glVertex3f(x2, y2, 0.0);
		/*2*/
		glVertex3f(x2, y2, 0.0);
		glVertex3f(x2, YUp, 0.0);
		glVertex3f(x1, YUp, 0.0);
		/*3*/
		glVertex3f(x2, yUp, 0.0);
		glVertex3f(x1, yUp, 0.0);
		glVertex3f(x2, yDown, 0.0);
		/*4*/
		glVertex3f(x1, yDown, 0.0);
		glVertex3f(x1, yUp, 0.0);
		glVertex3f(x2, yDown, 0.0);
	glEnd();
}

void drowl(void){
	float x1 = 190. / 755.0, x2 = 193.0 / 755.0;
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f(x1, YUp, 0.0);
		glVertex3f(x1, yDown, 0.0);
		glVertex3f(x2, YUp, 0.0);
		/*2*/
		glVertex3f(x2, YUp, 0.0);
		glVertex3f(x2, yDown, 0.0);
		glVertex3f(x1, yDown, 0.0);
	glEnd();
}

void drowe(void){
	drowCircle(641, 198, 12.5, 30, 330);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(641, 198, 9.5, 30, 330);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f(653.0 / 755.0, 22.0 / 221.0, 0.0);
		glVertex3f(653.0 / 755.0, 25.0 / 221.0, 0.0);
		glVertex3f(630.0 / 755.0, 25.0 / 221.0, 0.0);
		/*2*/
		glVertex3f(630.0 / 755.0, 25.0 / 221.0, 0.0);
		glVertex3f(653.0 / 755.0, 22.0 / 221.0, 0.0);
		glVertex3f(630.0 / 755.0, 22.0 / 221.0, 0.0);
	glEnd();


}

void drowH(void){
	float x1 = 380.0 / 755.0, x2 = 383.0 / 755.0, x3 = 401.0 / 755.0, x4 = 404.0 / 755.0;
	float y2 = 30.0 / 221.0, y3 = 26.0 / 221.0;
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f(x1, YUp, 0.0);
		glVertex3f(x2, YUp, 0.0);
		glVertex3f(x1, yDown, 0.0);
		/*2*/
		glVertex3f(x2, YUp, 0.0);
		glVertex3f(x1, yDown, 0.0);
		glVertex3f(x2, yDown, 0.0);
		/*3*/
		glVertex3f(x2, y2, 0.0);
		glVertex3f(x2, y3, 0.0);
		glVertex3f(x3, y2, 0.0);
		/*4*/
		glVertex3f(x3, y2, 0.0);
		glVertex3f(x3, y3, 0.0);
		glVertex3f(x2, y3, 0.0);
		/*5*/
		glVertex3f(x3, YUp, 0.0);
		glVertex3f(x4, YUp, 0.0);
		glVertex3f(x3, yDown, 0.0);
		/*6*/
		glVertex3f(x4, YUp, 0.0);
		glVertex3f(x3, yDown, 0.0);
		glVertex3f(x4, yDown, 0.0);
	glEnd();
}

void drowv(void){
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
	float x1 = 603.0 / 755.0, x2 = 607.0 / 755.0, x3 = 611.0 / 755.0, x4 = 613.0 / 755.0,
		x5 = 616.0 / 755.0, x6 = 620.0 / 755.0, x7 = 624.0 / 755.0;
	float y = 15.0 / 221.0;
	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f(x1, yUp, 0.0);
		glVertex3f(x2, yUp, 0.0);
		glVertex3f(x3, yDown, 0.0);
		/*2*/
		glVertex3f(x2, yUp, 0.0);
		glVertex3f(x3, yDown, 0.0);
		glVertex3f(x4, y, 0.0);
		/*3*/
		glVertex3f(x3, yDown, 0.0);
		glVertex3f(x4, y, 0.0);
		glVertex3f(x5, yDown, 0.0);
		/*4*/
		glVertex3f(x6, yUp, 0.0);
		glVertex3f(x4, y, 0.0);
		glVertex3f(x5, yDown, 0.0);
		/*5*/
		glVertex3f(x7, yUp, 0.0);
		glVertex3f(x6, yUp, 0.0);
		glVertex3f(x5, yDown, 0.0);
	glEnd();
}

void drowy(void){
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
	float x1 = 733.0 / 755.0, x2 = 737.0 / 755.0, x3 = 741.0 / 755.0, x4 = 743.0 / 755.0,
		x5 = 746.0 / 755.0, x6 = 750.0 / 755.0, x7 = 754.0 / 755.0;
	float y = 15.0 / 221.0;
	glBegin(GL_TRIANGLES);
	/*1*/
	glVertex3f(x1, yUp, 0.0);
	glVertex3f(x2, yUp, 0.0);
	glVertex3f(x3, yDown, 0.0);
	/*2*/
	glVertex3f(x2, yUp, 0.0);
	glVertex3f(x3, yDown, 0.0);
	glVertex3f(x4, y, 0.0);
	/*3*/
	glVertex3f(x3, yDown, 0.0);
	glVertex3f(x4, y, 0.0);
	glVertex3f(x5, yDown, 0.0);
	/*4*/
	glVertex3f(x6, yUp, 0.0);
	glVertex3f(x4, y, 0.0);
	glVertex3f(x5, yDown, 0.0);
	/*5*/
	glVertex3f(x7, yUp, 0.0);
	glVertex3f(x6, yUp, 0.0);
	glVertex3f(x5, yDown, 0.0);
	/*v畫法↑*/
	/*6*/
	glVertex3f(x3, yDown, 0.0);
	glVertex3f(743.0/755.0, 4.0/221.0, 0.0);
	glVertex3f(x5, yDown, 0.0);
	/*7*/
	glVertex3f(x3, yDown, 0.0);
	glVertex3f(743.0 / 755.0, 5.0 / 221.0, 0.0);
	glVertex3f(739.0 / 755.0, 5.0 / 221.0, 0.0);
	/*8*/
	glVertex3f(739.0 / 755.0, 5.0 / 221.0, 0.0);
	glVertex3f(742.0 / 755.0, 5.0 / 221.0, 0.0);
	glVertex3f(739.0 / 755.0, 1.0 / 221.0, 0.0);
	/*9*/
	glVertex3f(743.0 / 755.0, 5.0 / 221.0, 0.0);
	glVertex3f(740.0 / 755.0, 1.0 / 221.0, 0.0);
	glVertex3f(734.0 / 755.0, 4.0 / 221.0, 0.0);
	/*10*/
	glVertex3f(740.0 / 755.0, 1.0 / 221.0, 0.0);
	glVertex3f(734.0 / 755.0, 4.0 / 221.0, 0.0);
	glVertex3f(735.0 / 755.0, 1.0 / 221.0, 0.0);
	glEnd();
}

void drowt(float x){
	GLfloat x1 = x / 755.0, x2 = (x + 3) / 755.0, x3 = (x + 6) / 755.0,
		x4 = (x + 10) / 755.0;
	GLfloat y1 = YUp, y2 = 39.0 / 221.0, y3 = yUp, y4 = 31.0 / 221.0,
		y5 = 14.0 / 221.0, y6 = yDown;
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f(x3, y1, 0.0);
		glVertex3f(x3, y2, 0.0);
		glVertex3f(x2, y2, 0.0);
		/*2 3主幹*/
		glVertex3f(x3, y2, 0.0);
		glVertex3f(x2, y2, 0.0);
		glVertex3f(x3, y5, 0.0);
		/*3*/
		glVertex3f(x3, y5, 0.0);
		glVertex3f(x2, y2, 0.0);
		glVertex3f(x2, y5, 0.0);
		/*4 橫槓*/
		glVertex3f(x1, y3, 0.0);
		glVertex3f(x1, y4, 0.0);
		glVertex3f(x4, y3, 0.0);
		/*5*/
		glVertex3f(x1, y4, 0.0);
		glVertex3f(x4, y3, 0.0);
		glVertex3f(x4, y4, 0.0);
		/*6底下轉彎處*/
		glVertex3f(x2, y5, 0.0);
		glVertex3f(x3, y5, 0.0);
		glVertex3f(x3, y6, 0.0);
		/*7 8右下小方塊*/
		glVertex3f(x3, y5, 0.0);
		glVertex3f(x3, y6, 0.0);
		glVertex3f(x4, y5, 0.0);
		/*8*/
		glVertex3f(x3, y6, 0.0);
		glVertex3f(x4, y5, 0.0);
		glVertex3f(x4, y6, 0.0);
	glEnd();
}

void drowg(int x){

	drowCircle(x+11, 198, 13, 0, 360);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(x+11, 198, 10, 0, 360);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	drowCircle(x + 13, 210, 10, 0, 105);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(x + 13, 210, 7, 0, 105);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	drowCircle(x + 9, 210, 10, 78, 85);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(x + 9, 210, 7, 78, 85);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f((x + 24) / 755.0, 36.0 / 221.0, 0.0);
		glVertex3f((x + 21) / 755.0, 36.0 / 221.0, 0.0);
		glVertex3f((x + 24) / 755.0, yDown, 0.0);
		/*2*/
		glVertex3f((x + 24) / 755.0, 36.0 / 221.0, 0.0);
		glVertex3f((x + 24) / 755.0, yDown, 0.0);
		glVertex3f((x + 21) / 755.0, yDown, 0.0);
	glEnd();
	
}

void drowo(void){
	drowCircle(112, 199, 13, 0, 360);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(112, 199, 10, 0, 360);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
}

void drowr(int x){
	drowCircle(x + 10, 197, 11, 175, 130);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(x + 10, 197, 8, 175, 130);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f((x - 1) / 755.0, yUp, 0.0);
		glVertex3f((x + 2) / 755.0, yUp, 0.0);
		glVertex3f((x - 1) / 755.0, yDown, 0.0);
		/*2*/
		glVertex3f((x + 2) / 755.0, yUp, 0.0);
		glVertex3f((x + 2) / 755.0, yDown, 0.0);
		glVertex3f((x - 1) / 755.0, yDown, 0.0);
	glEnd();
}

void drown(int x){
	drowCircle(x+10, 197, 11, 175, 168);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(x + 10, 197, 8, 175, 173);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f((x-1)/755.0, yUp, 0.0);
		glVertex3f((x + 2)/755.0, yUp, 0.0);
		glVertex3f((x - 1) / 755.0, yDown, 0.0);
		/*2*/
		glVertex3f((x + 2) / 755.0, yUp, 0.0);
		glVertex3f((x + 2) / 755.0, yDown, 0.0);
		glVertex3f((x - 1) / 755.0, yDown, 0.0);
		/*3*/
		glVertex3f((x + 17) / 755.0, yDown, 0.0);
		glVertex3f((x + 17) / 755.0, 27.0/221.0, 0.0);
		glVertex3f((x + 20) / 755.0, yDown, 0.0);
		/*4*/
		glVertex3f((x + 20) / 755.0, yDown, 0.0);
		glVertex3f((x + 17) / 755.0, 27.0 / 221.0, 0.0);
		glVertex3f((x + 20) / 755.0, 27.0 / 221.0, 0.0);
	glEnd();
}

void drowu(int x){
	drowCircle(x + 9, 200, 11, 13, 145);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(x + 9, 200, 8, 13, 145);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

	glBegin(GL_TRIANGLES);
	/*1*/
	glVertex3f((x - 1) / 755.0, yUp, 0.0);
	glVertex3f((x + 2) / 755.0, yUp, 0.0);
	glVertex3f((x - 1) / 755.0, 16.0/221.0, 0.0);
	/*2*/
	glVertex3f((x + 2) / 755.0, yUp, 0.0);
	glVertex3f((x + 2) / 755.0, 16.0 / 221.0, 0.0);
	glVertex3f((x - 1) / 755.0, 16.0 / 221.0, 0.0);
	/*3*/
	glVertex3f((x + 17) / 755.0, yDown, 0.0);
	glVertex3f((x + 17) / 755.0, yUp, 0.0);
	glVertex3f((x + 20) / 755.0, yDown, 0.0);
	/*4*/
	glVertex3f((x + 20) / 755.0, yDown, 0.0);
	glVertex3f((x + 17) / 755.0, yUp, 0.0);
	glVertex3f((x + 20) / 755.0, yUp, 0.0);
	glEnd();
}

void drowC(void){
	drowCircle(228, 194, 16, 30, 300);
	glColor3f(1.0, 1.0, 1.0);
	drowCircle(228, 194, 13, 30, 300);
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

}

void drowh(int x){
	{
		drowCircle(x + 10, 197, 11, 175, 170);
		glColor3f(1.0, 1.0, 1.0);
		drowCircle(x + 10, 197, 8, 175, 175);
		glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);

		glBegin(GL_TRIANGLES);
		/*1*/
		glVertex3f((x - 1) / 755.0, YUp, 0.0);
		glVertex3f((x + 2) / 755.0, YUp, 0.0);
		glVertex3f((x - 1) / 755.0, yDown, 0.0);
		/*2*/
		glVertex3f((x + 2) / 755.0, YUp, 0.0);
		glVertex3f((x + 2) / 755.0, yDown, 0.0);
		glVertex3f((x - 1) / 755.0, yDown, 0.0);
		/*3*/
		glVertex3f((x + 17) / 755.0, yDown, 0.0);
		glVertex3f((x + 17) / 755.0, 27.0 / 221.0, 0.0);
		glVertex3f((x + 20) / 755.0, yDown, 0.0);
		/*4*/
		glVertex3f((x + 20) / 755.0, yDown, 0.0);
		glVertex3f((x + 17) / 755.0, 27.0 / 221.0, 0.0);
		glVertex3f((x + 20) / 755.0, 27.0 / 221.0, 0.0);
		glEnd();
	}
}

void display(void)
{
	/* clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* draw white polygon (rectangle) with corners at
	* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	drowN();
	drowi(89);
	drowi(442);
	drowi(591);
	drowi(705);
	drowH();
	drowv();
	drowl();
	drowC();
	drowy();
	drowe();
	drowt(71);
	drowt(716);
	drowo();
	drown(132);
	drown(310);
	drown(456);
	drown(562);
	drowr(660);
	drowu(280);
	drowh(251);
	drowg(337);
	drowg(483);
	drowU(528);

	glutSwapBuffers();
	/* don't wait!
	* start processing buffered OpenGL routines
	*/
	// glFlush ();
}

void init(void)
{

	printf("OpenGL version: %s\n", (char*)glGetString(GL_VERSION));
	printf("OpenGL renderer: %s\n", (char*)glGetString(GL_RENDERER));

	/* select clearing color 	*/
	glClearColor(1.0, 1.0, 1.0, 0.0);

	/* initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA).  Open window with "hello"
* in its title bar.  Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(755, 221);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("NCHU logo");
	init();
	glewInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

/*
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
*/
