/***************************
4103056035 周彤 第4次作業5/15
***************************/

// Rendering_Hw.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "math.h"
#include <fstream>
#include "myArrays.cpp"

#define DRAWARRAY 1
#define DRAWELEMENTS 2
#define MULTIDRAWARRAYS 3
#define MULTIDRAWELEMENTS 4

#define angleUnit 3.1415926/180.0

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

int alpha = 0, beta = 0, gamma = 0;	//alpha X-Z, beta Y-Z, gamma X-Y
GLdouble locationX = 0.0, locationY = 0.0, locationZ = 3.0;
GLdouble eyeX = 0.0, eyeY = 0.0, eyeZ = 0.0;
GLdouble testX = 0.0, testY = 0.0, testZ = 2.0;
float jumpY[361];
float ShakingArm[21];
int shakeArm = 0;
int index[10000];

GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };

void indexArray(){
	for (int num = 0; num < 10000; num++)
		index[num] = num;
}

//void drowCircle(float x, float y, float r, int start, int angle, int color){
//	float pointOut[360][2];
//	int nowAngle = start, cnt = 0;
//	GLfloat certenX = x / 755.0, certenY = 1.0 - y / 221.0;
//	for (int i = 0; nowAngle < (start + angle); i++){
//		pointOut[i][0] = (x + r*cosf(unitAngle*(nowAngle))) / 755.0;
//		pointOut[i][1] = 1.0 - (y + r*sinf(unitAngle*(nowAngle))) / 221.0;
//		nowAngle += 3;
//		cnt++;
//	}
//	if (color)
//		glColor3f(1.0, 1.0, 1.0);
//	else
//		glColor3f(0, 0.4, 0.6);
//	glBegin(GL_TRIANGLES);
//	for (int i = cnt - 1; i > 0; i--){
//		glVertex3f(certenX, certenY, 0.0);
//		glVertex3f(pointOut[i][0], pointOut[i][1], 0.0);
//		glVertex3f(pointOut[i - 1][0], pointOut[i - 1][1], 0.0);
//	}
//	/*
//	for (int i = cnt - 1; i > 0; i--){
//	if (color){
//	fp << 1.0 << "," << 1.0 << "," << 1.0 << "," << certenX << "," << certenY << "," << "0.0," << std::endl;
//	fp << 1.0 << "," << 1.0 << "," << 1.0 << "," << pointOut[i][0] << "," << pointOut[i][1] << "," << "0.0," << std::endl;
//	fp << 1.0 << "," << 1.0 << "," << 1.0 << "," << pointOut[i - 1][0] << "," << pointOut[i - 1][1] << "," << "0.0," << std::endl;
//	}
//	else{
//	fp << 0 << "," << 102 / 255.0 << "," << 153 / 255.0 << "," << certenX << "," << certenY << "," << "0.0," << std::endl;
//	fp << 0 << "," << 102 / 255.0 << "," << 153 / 255.0 << "," << pointOut[i][0] << "," << pointOut[i][1] << "," << "0.0," << std::endl;
//	fp << 0 << "," << 102 / 255.0 << "," << 153 / 255.0 << "," << pointOut[i - 1][0] << "," << pointOut[i - 1][1] << "," << "0.0," << std::endl;
//	}
//	}*/
//	glEnd();
//}

void drowN(void){
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
	else if (nowMethod == DRAWELEMENTS){
		for (int num = 0; num < (sizeof(part) / sizeof(part[0])); num++){
			glDrawElements(GL_POLYGON, part[num], GL_UNSIGNED_INT, (index + x));
			x += part[num];
		}
	}

}

void drowZhung(void){
	int part[] = { 8, 10, 4, 8, 8, 7 };
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
		4, 7, 4, 6, 7, 5, 4, 4, 4, 6 };
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

void drowArm(){

	// Dorw Left Arm
	glPushMatrix();
	//glutSolidSphere(1.0, 20, 16);
	glPushMatrix();
	/*glTranslatef(locationX - 0.3, locationY - 0.3 + ShakingArm[20 - shakeArm], locationZ - 0.3);
	glRotatef(45, 0.0, 0.0, 1.0);
	glRotatef(45, 0.0, 1.0, 0.0);
	/***** Drow Fingers *****/
	/*glPushMatrix();
	glTranslatef(0.275, 0.035, 0.0375);
	glPushMatrix();
	glTranslatef(0.05, 0.0, -0.0125);
	glRotatef(30, 0.0, 1.0, 0.0);
	glScalef(0.05, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	glScalef(0.05, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.285, 0.035, -0.05);
	glRotatef(30, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0.072, 0.0, 0.02);
	glRotatef(300, 0.0, 1.0, 0.0);
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.285, 0.0, -0.05);
	glRotatef(30, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0.072, 0.0, 0.02);
	glRotatef(300, 0.0, 1.0, 0.0);
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.285, -0.035, -0.05);
	glRotatef(30, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0.072, 0.0, 0.02);
	glRotatef(300, 0.0, 1.0, 0.0);
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();

	/************************/

	/*glScalef(0.5, 0.1, 0.1);
	glutWireCube(1.0);
	glPopMatrix();
	//glutSolidSphere(1.0, 20, 20);

	//Drow Right Arm
	glPushMatrix();
	glTranslatef(locationX + 0.3, locationY - 0.3 + ShakingArm[shakeArm], locationZ - 0.3);
	glRotatef(325, 0.0, 0.0, 1.0);
	glRotatef(315, 0.0, 1.0, 0.0);

	/***** Drow Fingers *****/
	/*glPushMatrix();
	glTranslatef(-0.275, -0.035, 0.0375);
	glPushMatrix();
	glTranslatef(-0.05, 0.016, 0.0);
	glRotatef(330, 0.0, 0.0, 1.0);
	glScalef(0.05, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	glScalef(0.05, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.285, 0.055, -0.0375);
	glRotatef(330, 0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(-0.075, -0.018, 0.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.285, 0.055, 0.0);
	glRotatef(330, 0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(-0.075, -0.018, 0.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.285, 0.055, 0.0375);
	glRotatef(330, 0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(-0.075, -0.018, 0.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	glScalef(0.07, 0.03, 0.025);
	glutWireCube(1.0);
	glPopMatrix();
	/************************/

	/*glPushMatrix();

	glPushMatrix();

	glPopMatrix();
	glPushMatrix();

	glPopMatrix();
	glPushMatrix();

	glPopMatrix();
	glPushMatrix();

	glPopMatrix();
	glPushMatrix();

	glPopMatrix();
	glPushMatrix();
	glScalef(0.5, 0.1, 0.1);
	glutWireSphere(1.0, 20, 60);
	glPopMatrix();

	glPopMatrix();*/

	//glScalef(0.5, 0.1, 0.1);
	glutWireCube(1.0);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();
	glPopMatrix();
}

void jump(){
	eyeY = jumpY[jumpT];
	locationY = jumpY[jumpT];
	glutPostRedisplay();
	jumpT++;
	if (jumpT >= 361){
		jumpT = 0;
		glutIdleFunc(NULL);
	}
}
void stepLeft(){
	eyeX -= 0.1;
	locationX -= 0.1;
	glutPostRedisplay();
}
void stepRight(){
	eyeX += 0.1;
	locationX += 0.1;
	glutPostRedisplay();
}
void stepForward(){
	eyeZ -= 0.1;
	locationZ -= 0.1;
	glutPostRedisplay();
}
void stepBackward(){
	eyeZ += 0.1;
	locationZ += 0.1;
	glutPostRedisplay();
}

void initJumpY(){
	for (int i = 0; i < 180; i++)
		jumpY[i] = 9.8 / 2.0 * (0.0025*(i + 1)) * (0.0025 * (i + 1));
	for (int i = 180; i < 361; i++)
		jumpY[i] = 9.8 / 2.0 * (0.0025*(360 - i)) * (0.0025 * (360 - i));
}
void initShakeArm(){
	for (int i = 0; i < 5; i++){
		ShakingArm[i] = sin(angleUnit*i * 5) * 0.25;
		ShakingArm[10 - i] = sin(angleUnit*i * 5) * 0.25;
		ShakingArm[i + 10] = 0 - sin(angleUnit*i * 5) * 0.25;
		ShakingArm[20 - i] = 0 - sin(angleUnit*i * 5) * 0.25;
	}
	ShakingArm[5] = sin(angleUnit * 25) * 0.25;
	ShakingArm[15] = 0 - sin(angleUnit * 25) * 0.25;

}
void init(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 100.0 };
	GLfloat black_emission[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 0.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.0, 0.0, 0.1, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, black_emission);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	initJumpY();
	initShakeArm();
	indexArray();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();             /* clear the matrix */
	/* viewing transformation  */
	gluLookAt(locationX, locationY, locationZ, eyeX, eyeY, eyeZ, 0.0, 2.0, 0.0);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	drowArm();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_DEPTH_TEST);

	glPushMatrix();
	//繞著軸轉

	glRotatef(gamma, 0, 0, 1.0);

	//繞著自身轉
	glTranslatef(locationX, locationY, locationZ);
	glRotatef(beta, 1.0, 0, 0);
	glRotatef(alpha, 0, 1.0, 0);
	glTranslatef((0 - locationX), (0 - locationY), (0 - locationZ));

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
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
	glPopMatrix();

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.2, 0.2, -0.2, 0.2, 0.3, 4.0);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			gamma += 5;
			if (gamma > 360)
				gamma -= 360;
			glutPostRedisplay();
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN) {
			alpha += 5;
			if (alpha > 360)
				alpha -= 360;
			glutPostRedisplay();
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			beta += 5;
			if (beta > 360)
				beta -= 360;
			glutPostRedisplay();
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
	case 'a':
		stepLeft();
		shakeArm += 1;
		if (shakeArm > 20)
			shakeArm -= 20;
		break;
	case 'd':
		stepRight();
		shakeArm += 1;
		if (shakeArm > 20)
			shakeArm -= 20;
		break;
	case 'w':
		stepForward();
		shakeArm += 1;
		if (shakeArm > 20)
			shakeArm -= 20;
		break;
	case 's':
		stepBackward();
		shakeArm += 1;
		if (shakeArm > 20)
			shakeArm -= 20;
		break;
	case 'i':
		testZ -= 0.1;
		std::cout << "X:" << testX << "\tY:" << testY << "\tZ:" << testZ << std::endl;
		glutPostRedisplay();
		break;
	case 'k':
		testZ += 0.1;
		std::cout << "X:" << testX << "\tY:" << testY << "\tZ:" << testZ << std::endl;
		glutPostRedisplay();
		break;
	case 'j':
		testX -= 0.1;
		std::cout << "X:" << testX << "\tY:" << testY << "\tZ:" << testZ << std::endl;
		glutPostRedisplay();
		break;
	case 'l':
		testX += 0.1;
		std::cout << "X:" << testX << "\tY:" << testY << "\tZ:" << testZ << std::endl;
		glutPostRedisplay();
		break;
	case 'o':
		testY -= 0.1;
		std::cout << "X:" << testX << "\tY:" << testY << "\tZ:" << testZ << std::endl;
		glutPostRedisplay();
		break;
	case 'u':
		testY += 0.1;
		std::cout << "X:" << testX << "\tY:" << testY << "\tZ:" << testZ << std::endl;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

