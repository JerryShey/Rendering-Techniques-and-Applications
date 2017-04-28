/***************************
4103056035 周彤 第3次作業4/26
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
int jumpT = 0;
bool flag = false;

float angleX = 0.0, angleY = 0.0, angleZ = 0.0;
GLdouble eyeX = 0.0, eyeY = 0.0, eyeZ = 0.0;
float jumpY[361];
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
	int part[] = { 5, 8, 5, 8, 8, 6, 6, 5, 5, 5, 5, 9, 4, 4, 4, 6, 3,
		4, 7, 4, 6, 7, 5, 4, 4, 4, 6};
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

void initJumpY(){
	for (int i = 0; i < 180; i++)
		jumpY[i] = 0 - 9.8 / 2.0 * (0.0025*(i + 1)) * (0.0025 * (i + 1));
	for (int i = 180; i < 361; i++)
		jumpY[i] = 0 - 9.8 / 2.0 * (0.0025*(360 - i)) * (0.0025 * (360 - i));
}

void rotatedFunc(int value){
	if (rotateType == YAXIS){
		angleY += 1;
		if (angleY > 360)	angleY -= 360;
		glutPostRedisplay();
		value++;
		if (value < 90)
			glutTimerFunc(10, rotatedFunc, value);
	}
	else if (rotateType == XAXIS){
		angleX += 2;
		if (angleX > 360)	angleX -= 360;
		glutPostRedisplay();
	}
	else{
		angleZ += 2;
		if (angleZ > 360)	angleZ -= 360;
		glutPostRedisplay();
	}
}

void jump(){
	eyeY = jumpY[jumpT];
	glutPostRedisplay();
	jumpT++;
	if (jumpT >= 361){
		jumpT = 0;
		glutIdleFunc(NULL);
	}
}

void backward(){
	if (turnRun == posX)
		eyeX -= 0.1;
	else if (turnRun == negX)
		eyeX += 0.1;
	else if (turnRun == posZ)
		eyeZ -= 0.1;
	else if (turnRun == negZ)
		eyeZ += 0.1;

	glutPostRedisplay();
}

void forward(){
	if (turnRun == posX){
		eyeX += 0.1;
	}
		
	else if (turnRun == negX){
		eyeX -= 0.1;
	}
	else if (turnRun == posZ){
		eyeZ += 0.1;
	}
		
	else if (turnRun == negZ){
		eyeZ -= 0.1;
	}
		
	glutPostRedisplay();
}

void turnLeft(int value){
	if (turnRun == posX)
		eyeZ -= 0.1;
	else if (turnRun == negX)
		eyeZ += 0.1;
	else if (turnRun == posZ)
		eyeX -= 0.1;
	else
		eyeX += 0.1;
	glutPostRedisplay();
}

void turnRight(int value){
	if (turnRun == posX)
		eyeZ += 0.1;
	else if (turnRun == negX)
		eyeZ -= 0.1;
	else if (turnRun == posZ)
		eyeX += 0.1;
	else
		eyeX -= 0.1;
	glutPostRedisplay();
}

void display(void)
{
	/* clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//走路用
	glTranslatef(eyeX, eyeY, eyeZ);

	glPushMatrix();

	// 轉頭(隨著三個軸心轉)
	glTranslatef(eyeX, eyeY, eyeZ-2.0);
	glRotatef(angleX, 1.0, 0, 0);
	glRotatef(angleY, 0, 1.0, 0);
	glRotatef(angleZ, 0, 0, 1.0);
	glTranslatef((0-eyeX), (0-eyeY), (2.0-eyeZ));

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
	
	gluLookAt(1.0, 0.0, 1.0, 0.0, 0.0, 2.0, 0.0, 1.0, 0.0);

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
	initJumpY();
	indexArray();

	std::cout << "Dear TA:\n"
		<< "\tIf you click mouse's middle button, it will rotate 90 degrees.\n"
		<< "\tBut if you click left or right buton, it will rotate 2 degrees one time.\n"
		<< "\tNow, I can't forward or backward.\n"
		<< "\t\t\t\t\t\t\tThanks";
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			rotateType = ZAXIS;
			rotatedFunc(0);
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN) {
			rotateType = YAXIS;
			rotatedFunc(0);
			/*if (rotateType == YAXIS){
				rotateType = 0;
				glutIdleFunc(NULL);
			}
			else {
				rotateType = YAXIS;
				rotatedFunc(0);
				//glutIdleFunc(rotatedFunc);
			}*/
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			rotateType = XAXIS;
			rotatedFunc(0);
		}
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 32:	//space
		glutIdleFunc(jump);
		break;
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
		forward();
		break;
	case 'a':
		turnLeft(0);
		break;
	case 'd':
		turnRight(0);
		break;
	case 's':
		backward();
		break;
	case 'b':
		if (flag)
			glCullFace(GL_BACK);
		else
			glCullFace(GL_FRONT_AND_BACK);
		flag = !flag;
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

