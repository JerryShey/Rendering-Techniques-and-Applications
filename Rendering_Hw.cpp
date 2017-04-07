// Rendering_Hw.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "math.h"
#include <fstream>
#include "myArrays.cpp"

#define unitAngle 3.1415926/180.0
#define YUp 43.0/221.0
#define yDown 11.0/221.0
#define yUp 34.0/221.0

std::fstream fp;

void drowCircle(float x, float y, float r, int start, int angle, int color){
	float pointOut[360][2];
	int nowAngle = start, cnt = 0;
	GLfloat certenX = x / 755.0, certenY = 1.0 - y / 221.0;
	for (int i = 0; nowAngle < (start + angle); i++){
		pointOut[i][0] = (x + r*cosf(unitAngle*(nowAngle))) / 755.0;
		pointOut[i][1] = 1.0 - (y + r*sinf(unitAngle*(nowAngle))) / 221.0;
		nowAngle += 3;
		cnt++;
	}

	glBegin(GL_TRIANGLES);
	for (int i = cnt - 1; i > 0; i--){
		if (color){
			fp << 1.0 << "," << 1.0 << "," << 1.0 << "," << certenX << "," << certenY << "," << "0.0," << std::endl;
			fp << 1.0 << "," << 1.0 << "," << 1.0 << "," << pointOut[i][0] << "," << pointOut[i][1] << "," << "0.0," << std::endl;
			fp << 1.0 << "," << 1.0 << "," << 1.0 << "," << pointOut[i - 1][0] << "," << pointOut[i - 1][1] << "," << "0.0," << std::endl;
		}
		else{
			fp << 0 << "," << 102 / 255.0 << "," << 153 / 255.0 << "," << certenX << "," << certenY << "," << "0.0," << std::endl;
			fp << 0 << "," << 102 / 255.0 << "," << 153 / 255.0 << "," << pointOut[i][0] << "," << pointOut[i][1] << "," << "0.0," << std::endl;
			fp << 0 << "," << 102 / 255.0 << "," << 153 / 255.0 << "," << pointOut[i - 1][0] << "," << pointOut[i - 1][1] << "," << "0.0," << std::endl;
		}
	}
	glEnd();
}

void drowN(void){
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
	GLfloat N[] = { 8.0 / 755.0, YUp, 0.0,
		8.0 / 755.0, yDown, 0.0,
		11.0 / 755, yDown, 0.0,
		8.0 / 755.0, YUp, 0.0,
		11.0 / 755, yDown, 0.0,
		11.0 / 755, YUp, 0.0,
		11.0 / 755, YUp, 0.0,
		11.0 / 755, 38.0 / 221, 0.0,
		29.0 / 755, yDown, 0.0,
		29.0 / 755, yDown, 0.0,
		11.0 / 755, YUp, 0.0,
		29.0 / 755, 16.0 / 221, 0.0,
		29.0 / 755, yDown, 0.0,
		29.0 / 755, YUp, 0.0,
		32.0 / 755, yDown, 0.0,
		29.0 / 755, YUp, 0.0,
		32.0 / 755, yDown, 0.0,
		32.0 / 755, YUp, 0.0
	};
	glVertexPointer(3, GL_FLOAT, 0, N);
	glDrawArrays(GL_TRIANGLES, 0, 18);
}

void drowLi(void){
	glInterleavedArrays(GL_C3F_V3F, 0, Li);
	glDrawArrays(GL_POLYGON, 0, 10);
	glDrawArrays(GL_POLYGON, 10, 15);
	//glDrawArrays(GL_POLYGON, 25, 4);
	glDrawArrays(GL_POLYGON, 25, 8);
	glDrawArrays(GL_POLYGON, 33, 4);
	glDrawArrays(GL_POLYGON, 37, 5);
	glDrawArrays(GL_POLYGON, 42, 7);
	glDrawArrays(GL_POLYGON, 49, 7);
	glDrawArrays(GL_POLYGON, 56, 6);
}

void drowZhung(void){
	glInterleavedArrays(GL_C3F_V3F, 0, Zhung);
	glDrawArrays(GL_POLYGON, 0, 8);
	glDrawArrays(GL_POLYGON, 8, 10);
	glDrawArrays(GL_POLYGON, 18, 4);
	glDrawArrays(GL_POLYGON, 22, 8);
	glDrawArrays(GL_POLYGON, 30, 8);
	glDrawArrays(GL_POLYGON, 38, 7);
	
}

void drowHsing(void){
	glInterleavedArrays(GL_C3F_V3F, 0, Hsing);
	glDrawArrays(GL_POLYGON, 0, 8);
	glDrawArrays(GL_POLYGON, 8, 10);
	glDrawArrays(GL_POLYGON, 18, 6);
	glDrawArrays(GL_POLYGON, 24, 8);
	glDrawArrays(GL_POLYGON, 32, 7);
	glDrawArrays(GL_POLYGON, 39, 9);
	glDrawArrays(GL_POLYGON, 48, 10);
	glDrawArrays(GL_POLYGON, 58, 4);
	glDrawArrays(GL_POLYGON, 62, 8);
	glDrawArrays(GL_POLYGON, 70, 8);
	glDrawArrays(GL_POLYGON, 78, 7);
	glDrawArrays(GL_POLYGON, 85, 8);
	glDrawArrays(GL_POLYGON, 93, 4);
	glDrawArrays(GL_POLYGON, 97, 6);
	glDrawArrays(GL_POLYGON, 103, 5);
	//fp << 0 << "," << 0.4 << "," << 0.6 << "," << 315 / 755.0 << "," << 1.0 - 70 / 221.0 << "0,0," << std::endl;
	
	//93-96
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 291 / 755.0 << "," << 1.0 - 81 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 294 / 755.0 << "," << 1.0 - 92 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 300 / 755.0 << "," << 1.0 - 97 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 300 / 755.0 << "," << 1.0 - 85 / 221.0 << "0,0," << std::endl;

	//97-102
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 300 / 755.0 << "," << 1.0 - 85 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 300 / 755.0 << "," << 1.0 - 97 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 312 / 755.0 << "," << 1.0 - 91 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 319 / 755.0 << "," << 1.0 - 85 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 335 / 755.0 << "," << 1.0 - 77 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 312 / 755.0 << "," << 1.0 - 82 / 221.0 << "0,0," << std::endl;

	//103-107
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 353 / 755.0 << "," << 1.0 - 73 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 355 / 755.0 << "," << 1.0 - 79 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 372 / 755.0 << "," << 1.0 - 99 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 374 / 755.0 << "," << 1.0 - 91 / 221.0 << "0,0," << std::endl;
	fp << 0 << "," << 0.4 << "," << 0.6 << "," << 374 / 755.0 << "," << 1.0 - 87 / 221.0 << "0,0," << std::endl;
}

void drowU(){
	glInterleavedArrays(GL_C3F_V3F, 0, U);
	glDrawArrays(GL_TRIANGLES, 0, 420);
}


void drowi(){
	glInterleavedArrays(GL_C3F_V3F, 0, i);
	glDrawArrays(GL_TRIANGLES, 0, 48);
}

void drowl(void){
	glInterleavedArrays(GL_C3F_V3F, 0, l);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}


void drowe(void){
	glInterleavedArrays(GL_C3F_V3F, 0, e);
	glDrawArrays(GL_TRIANGLES, 0, 660);
}

void drowH(void){
	glInterleavedArrays(GL_C3F_V3F, 0, H);
	glDrawArrays(GL_TRIANGLES, 0, 18);
}

void drowv(void){
	glInterleavedArrays(GL_C3F_V3F, 0, v);
	glDrawArrays(GL_TRIANGLES, 0, 15);
}
void drowy(void){
	glInterleavedArrays(GL_C3F_V3F, 0, y);
	glDrawArrays(GL_TRIANGLES, 0, 30);
}

void drowt(){
	glInterleavedArrays(GL_C3F_V3F, 0, t);
	glDrawArrays(GL_TRIANGLES, 0, 48);
}

void drowg(){
	glInterleavedArrays(GL_C3F_V3F, 0, g);
	glDrawArrays(GL_TRIANGLES, 0, 2184);
}

void drowo(void){
	glInterleavedArrays(GL_C3F_V3F, 0, o);
	glDrawArrays(GL_TRIANGLES, 0, 714);
}

void drowr(){
	glInterleavedArrays(GL_C3F_V3F, 0, r);
	glDrawArrays(GL_TRIANGLES, 0, 264);
}

void drown(){
	glInterleavedArrays(GL_C3F_V3F, 0, n);
	glDrawArrays(GL_TRIANGLES, 0, 1392);
}

void drowu(){
	glInterleavedArrays(GL_C3F_V3F, 0, u);
	glDrawArrays(GL_TRIANGLES, 0, 300);
}

void drowC(void){
	glInterleavedArrays(GL_C3F_V3F, 0, C);
	glDrawArrays(GL_TRIANGLES, 0, 594);
}

void drowh(){
	glInterleavedArrays(GL_C3F_V3F, 0, h);
	glDrawArrays(GL_TRIANGLES, 0, 354);
	//
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
	drowi();
	drowH();
	drowv();
	drowl();
	drowC();
	drowy();
	drowe();
	drowt();
	drowo();
	drown();
	drowr();
	drowu();
	drowh();
	drowg();
	drowU();
	drowLi();
	drowZhung();
	drowHsing();
	

	glutSwapBuffers();
	/* don't wait!
	* start processing buffered OpenGL routines
	*/
	// glFlush ();
}

void init(void)
{
	/* select clearing color 	*/
	glClearColor(1.0, 1.0, 1.0, 0.0);

	/*Open file*/
	fp.open("All pixel.txt", std::ios::out);
	fp << "Start" << std::endl;
	/* initialize viewing values  */
	glEnableClientState(GL_VERTEX_ARRAY);
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