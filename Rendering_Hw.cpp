/***************************
4103056035 周彤 第2次作業4/11
***************************/

// Rendering_Hw.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "math.h"
#include <fstream>
#include "myArrays.cpp"

#define unitAngle 3.1415926/180.0

#define DRAWARRAY 1
#define DRAWELEMENTS 2
#define MULTIDRAWARRAYS 3
#define MULTIDRAWELEMENTS 4

#define XAXIS 1
#define YAXIS 2
#define ZAXIS 3

#define negZ 1
#define negX 2
#define posZ 3
#define posX 4

int turnRun = negZ;
int lookAngle = 0;
int nowMethod = 1;
int rotateType = 0;

float angle = 0.0;
GLdouble eyeX = 0.0, eyeY = 0.0, eyeZ = 0.0, lookX = 0.0, lookY = 0.0, lookZ = -1.0;
int index[10000];

static double limitFPS = 1.0 / 60.0;

std::fstream fp;

void indexArray(){
	for (int num = 0; num < 10000; num++)
		index[num] = num;
}

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
	if (color)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0, 0.4, 0.6);
	glBegin(GL_TRIANGLES);
	for (int i = cnt - 1; i > 0; i--){
		glVertex3f(certenX, certenY, 0.0);
		glVertex3f(pointOut[i][0] , pointOut[i][1], 0.0);
		glVertex3f(pointOut[i-1][0], pointOut[i-1][1], 0.0);
	}
	/*
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
	}*/
	glEnd();
}

void drowN(void){
	glColor3f(0, 102.0 / 255.0, 153.0 / 255.0);
	glInterleavedArrays(GL_C3F_V3F, 0, N);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 18);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, index);
	
}

void drowGou(void){
	int part[] = { 9, 8, 9, 5, 4, 5, 9, 7, 9, 9, 4, 8, 6, 4, 8 };
	int x = 0;
	glInterleavedArrays(GL_C3F_V3F, 0, Gou);
	if (nowMethod == DRAWARRAY){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawArrays(GL_POLYGON, x, part[num]);
			x += part[num];
		}
	}
	else if (nowMethod == DRAWELEMENTS){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawElements(GL_POLYGON, part[num], GL_UNSIGNED_INT, (index + x));
			x += part[num];
		}
	}
}

void drowLi(void){
	int part[] = { 10, 15, 8, 4, 5, 7, 7, 6 };
	int x = 0;
	glInterleavedArrays(GL_C3F_V3F, 0, Li);
	if (nowMethod == DRAWARRAY){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawArrays(GL_POLYGON, x, part[num]);
			x += part[num];
		}
	}
	else if(nowMethod == DRAWELEMENTS){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawElements(GL_POLYGON, part[num], GL_UNSIGNED_INT, (index + x));
			x += part[num];
		}
	}

}

void drowZhung(void){
	int part[] = {8, 10, 4, 8, 8, 7};
	int x = 0;

	glInterleavedArrays(GL_C3F_V3F, 0, Zhung);
	if (nowMethod == DRAWARRAY){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawArrays(GL_POLYGON, x, part[num]);
			x += part[num];
		}
	}
	else if (nowMethod == DRAWELEMENTS){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawElements(GL_POLYGON, part[num], GL_UNSIGNED_INT, (index + x));
			x += part[num];
		}
	}
	
}

void drowHsing(void){
	int part[] = { 8, 10, 6, 8, 7, 9, 10, 4, 8, 8, 7, 8, 4, 6, 5 };
	int x = 0;
	glInterleavedArrays(GL_C3F_V3F, 0, Hsing);
	if (nowMethod == DRAWARRAY){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawArrays(GL_POLYGON, x, part[num]);
			x += part[num];
		}
	}
	else if (nowMethod == DRAWELEMENTS){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawElements(GL_POLYGON, part[num], GL_UNSIGNED_INT, (index + x));
			x += part[num];
		}
	}
	
	//fp << 0 << "," << 0.4 << "," << 0.6 << "," << 315 / 755.0 << "," << 1.0 - 70 / 221.0 << "0,0," << std::endl;
	
	
}

void drowDa(void){
	int part[] = { 9, 8, 7, 6, 5, 6, 7, 5 };
	int x = 0;
	glInterleavedArrays(GL_C3F_V3F, 0, Da);
	if (nowMethod == DRAWARRAY){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawArrays(GL_POLYGON, x, part[num]);
			x += part[num];
		}
	}
	else if (nowMethod == DRAWELEMENTS){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawElements(GL_POLYGON, part[num], GL_UNSIGNED_INT, (index + x));
			x += part[num];
		}
	}
}

void drowSh(void){
	int part[] = { 5, 8, 5, 8, 8, 6, 6, 5, 5, 5, 5, 9 };
	int x = 0;
	glInterleavedArrays(GL_C3F_V3F, 0, Sh);
	if (nowMethod == DRAWARRAY){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawArrays(GL_POLYGON, x, part[num]);
			x += part[num];
		}
	}
	else if (nowMethod == DRAWELEMENTS){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawElements(GL_POLYGON, part[num], GL_UNSIGNED_INT, (index + x));
			x += part[num];
		}
	}
	
	



	//fp << 0 << "," << 0.4 << "," << 0.6 << "," << 515 / 755.0 << "," << 1.0 - 35 / 221.0 << "0,0," << std::endl;
}

void drowa(){
	
	glInterleavedArrays(GL_C3F_V3F, 0, a);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 156);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 156, GL_UNSIGNED_INT, index);
}

void drows(){
	
	glInterleavedArrays(GL_C3F_V3F, 0, s);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 144);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 144, GL_UNSIGNED_INT, index);
}

void drowU(void){
	glInterleavedArrays(GL_C3F_V3F, 0, U);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 420);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 420, GL_UNSIGNED_INT, index);
}

void drowi(){
	glInterleavedArrays(GL_C3F_V3F, 0, i);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 48);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, index);
}

void drowl(void){
	glInterleavedArrays(GL_C3F_V3F, 0, l);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 6);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, index);
}

void drowe(void){
	glInterleavedArrays(GL_C3F_V3F, 0, e);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 660);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 660, GL_UNSIGNED_INT, index);
}

void drowH(void){
	glInterleavedArrays(GL_C3F_V3F, 0, H);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 18);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, index);
}

void drowv(void){
	glInterleavedArrays(GL_C3F_V3F, 0, v);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 15);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 15, GL_UNSIGNED_INT, index);
}

void drowy(void){
	glInterleavedArrays(GL_C3F_V3F, 0, y);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 30);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, index);
}

void drowt(){
	glInterleavedArrays(GL_C3F_V3F, 0, t);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 48);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, index);
}

void drowg(){
	glInterleavedArrays(GL_C3F_V3F, 0, g);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 2184);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 2184, GL_UNSIGNED_INT, index);
}

void drowo(void){
	glInterleavedArrays(GL_C3F_V3F, 0, o);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 714);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 714, GL_UNSIGNED_INT, index);
}

void drowr(){
	glInterleavedArrays(GL_C3F_V3F, 0, r);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 264);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 264, GL_UNSIGNED_INT, index);;
}

void drown(){
	glInterleavedArrays(GL_C3F_V3F, 0, n);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 1392);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 1392, GL_UNSIGNED_INT, index);
}

void drowu(){
	glInterleavedArrays(GL_C3F_V3F, 0, u);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 300);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 300, GL_UNSIGNED_INT, index);
}

void drowC(void){
	glInterleavedArrays(GL_C3F_V3F, 0, C);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 594);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 594, GL_UNSIGNED_INT, index);
}

void drowh(){
	glInterleavedArrays(GL_C3F_V3F, 0, h);
	if (nowMethod == DRAWARRAY)	glDrawArrays(GL_TRIANGLES, 0, 354);
	else if (nowMethod == DRAWELEMENTS)	glDrawElements(GL_TRIANGLES, 354, GL_UNSIGNED_INT, index);
	//
}

void rotatedFunc(){
	angle += 0.1;
	if (angle > 360)	angle -= 360;
	glutPostRedisplay();
}

void forward(int value){
	if (turnRun == posX){
		eyeX += 0.01;
		lookX = eyeX + 1.0;
	}
		
	else if (turnRun == negX){
		eyeX -= 0.01;
		lookX = eyeX - 1.0;
	}
	else if (turnRun == posZ){
		eyeZ += 0.01;
		lookZ = eyeZ + 1.0;
	}
		
	else if (turnRun == negZ){
		eyeZ -= 0.01;
		lookZ = eyeZ - 1.0;
	}
		
	glutPostRedisplay();
}

void turnLeft(int value){

	turnRun += 1;
	if (turnRun > 4) turnRun -= 4;

	lookAngle -= 1;
	if (lookAngle < 0) lookAngle += 360;

	lookZ = eyeZ + cos(lookAngle*unitAngle);
	lookX = eyeX + sin(lookAngle*unitAngle);

	glutPostRedisplay();
	if (lookAngle % 90)
		glutTimerFunc(10, turnLeft, 1);
}

void turnRight(int value){

	turnRun -= 1;
	if (turnRun == 0) turnRun += 4;

	lookAngle += 1;
	if (lookAngle > 360) lookAngle -= 360;

	lookZ = eyeZ + cos(lookAngle*unitAngle);
	lookX = eyeX + sin(lookAngle*unitAngle);

	glutPostRedisplay();
	if (lookAngle % 90)
		glutTimerFunc(10, turnRight, 1);
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

	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, 0.0, 1.0, 0.0);
	glPushMatrix();

	glTranslatef(0.5, 0.5, 0.0);
	switch (rotateType)
	{
	case XAXIS:
		glRotatef(angle, 0.5, 0, 0);
		break;
	case YAXIS:
		glRotatef(angle, 0, 0.5, 0);
		break;
	case ZAXIS:
		glRotatef(angle, 0, 0, 1.0);
		break;
	default:
		break;
	}
	if (angle == 360)
		angle = 0;
	
	glTranslatef(-0.5, -0.5, 0.0);

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
	drowa();
	drows();
	drowGou();
	drowLi();
	drowZhung();
	drowHsing();
	drowDa();
	drowSh();

	

	glPopMatrix();
	
	
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
	//fp.open("All pixel.txt", std::ios::out);
	//fp << "Start" << std::endl;
	/* initialize viewing values  */
	glEnableClientState(GL_VERTEX_ARRAY);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	indexArray();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			if (rotateType == ZAXIS){
				rotateType = 0;
				glutIdleFunc(NULL);
			}
			else{
				rotateType = ZAXIS;
				glutIdleFunc(rotatedFunc);
			}
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN) {
			if (rotateType == YAXIS){
				rotateType = 0;
				glutIdleFunc(NULL);
			}
			else {
				rotateType = YAXIS;
				glutIdleFunc(rotatedFunc);
			}
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			if (rotateType == XAXIS){
				rotateType = 0;
				glutIdleFunc(NULL);
			}
			else {
				rotateType = XAXIS;
				glutIdleFunc(rotatedFunc);
			}
		}
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 49:	// 49 = '1'
		nowMethod = DRAWARRAY;
		break;
	case 50:
		nowMethod = DRAWELEMENTS;
		break;
	case 51:
		nowMethod = MULTIDRAWARRAYS;
		break;
	case 52:
		nowMethod = MULTIDRAWELEMENTS;
		break;
	case 'w':
		forward(0);
		break;
	case 'a':
		turnLeft(0);
		break;
	case 'd':
		turnRight(0);
		break;
	case 's':
		break;
	case 27:
		exit(0);
		break;
	}
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
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

