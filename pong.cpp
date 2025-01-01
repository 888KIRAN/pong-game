
////////////////////
//topspeed3x = 10.0;
//topspeed3y = -10.0;
////////////////////


#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

//daire
#define M_PI 3.1415926
#define radius 15
#define value1 160

float ballx = 500.0;
float bally = 450.0;

int cx = radius;
int cy = radius;

float ww = 1000.0;
float wh = 900.0;

float speed1 = 0.0;
float speed2 = 0.0;
float topspeed3x = 0.0;
float topspeed3y = 0.0;

float direction1 = 0.0;
float direction2 = 0.0;

//bir dizi tanımla ve raketlerin konumuna göre top yön değiştirsin

void drawScene(void)
{
	float red = 1.0;
	float green = 1.0;
	float blue = 0.0;
    char text[8] = "DEDELER";
	int counter = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, green, blue); 
	glRasterPos2f(468.5, 450); 

	while (counter <= 10) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[counter]); 
		counter++;
	}
	

	
	glColor3f(red, green, blue);

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0.8 + direction1,0.0,0.0);// one point 
	glVertex3f(190.0 + direction1,0.0,0.0);// two point 
	glVertex3f(190.0 + direction1,20.0,0.0);// there point 
	glVertex3f(0.8 + direction1,20.0,0.0);// four point 

	glEnd();
	glFlush();

    red = 1.0;
    green = 1.0;
	blue = 0.0;

	glColor3f(red, green, blue);

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0.8 + direction2, 900, 0.0);// one point 
	glVertex3f(190.0 + direction2, 900, 0.0);// two point 
	glVertex3f(190.0 + direction2, 880.0, 0.0);// there point 
	glVertex3f(0.8 + direction2, 880.0, 0.0);// four point 

	glEnd();
	glFlush();

	red = 1.0;
	green = 0.0;
	blue = 0.0;

	glColor3f(red, green, blue);

	glBegin(GL_POLYGON); 
	for (int i = 0; i < value1; ++i) 
	{
		float angle = 2.0f * M_PI * float(i) / float(value1); 
		float x = radius * cos(angle); 
		float y = radius * sin(angle); 
		glVertex2f((cx + x) + ballx,(cy + y) + bally); 
	}

	glEnd();
	glFlush();

}

void update(int value) 
{
	direction1 += speed1;
	direction2 += speed2;
	ballx += topspeed3x;
	bally += topspeed3y;

	if (direction1 < 0) direction1 = 0;
	if (direction1 + 190 > ww) direction1 = ww - 190;

	if (direction2 < 0) direction2 = 0;
	if (direction2 + 190 > ww) direction2 = ww - 190;


	if ((880.0 >= (bally + radius) && 190.0 + direction2 >= (ballx + radius) && (ballx + radius) >= 0.8 + direction2) && 0 <= (bally + radius) || (20.0 >= (bally + radius) && 190.0 + direction1 >= (ballx + radius) && (ballx + radius) >= 0.8 + direction1) && 0 <= (bally + radius))//3 saat uraştım aq
	{
		//engel
		// X eksenindeki sınır kontrolü
		if (ballx - radius < -20.0 || ballx + radius > ww -20.0) {
			topspeed3x = -topspeed3x; // X yönünü değiştir
		}
		                    //alt                         //üst
		// Y eksenindeki sınır kontrolü
		if (bally - radius < 10 || bally + radius > wh - 40) {
			topspeed3y = -topspeed3y; // Y yönünü değiştir
		}
	}
	else
	{
		//sebest
		// X eksenindeki sınır kontrolü
		if (ballx - radius < -20 || ballx + radius > ww - 20) {
			topspeed3x = -topspeed3x; // X yönünü değiştir
		}

		 //Y eksenindeki sınır kontrolü
		if (bally - radius < -20 || bally + radius > wh - 20) {
			topspeed3y = -topspeed3y; // Y yönünü değiştir
		}
	}
	

	////raket olunca
	//if (!((160.0 + direction2 >= bally && 880.0 >= bally) || (160.0 + direction1 >= bally && 20.0 >= bally)))
	//{
	//	if (ballx < 160.0) ballx = 160.0;
	//	if (ballx + radius * 2 > (ww - 160.0)) ballx = (ww - 160.0) - radius * 2;

	//	if (bally < 20.0) bally = 20.0;
	//	if (bally + radius * 2 > (wh - 20.0)) bally = (wh - 20.0) - radius * 2;

	//}
	//
	//else
	//{
	//	//engel olmadan
	//	if (ballx < 0) ballx = 0;
	//	if (ballx + radius * 2 > (ww - 0)) ballx = (ww - 0) - radius * 2;

	//	if (bally < 0) bally = 0;
	//	if (bally + radius * 2 > (wh - 0)) bally = (wh - 0) - radius * 2;

	//}
	

	glutPostRedisplay();
	glutTimerFunc(6, update, 0); //165 FPS 
}
void ball_direction() 
{

	// Başlangıç yönü ve hızı
	topspeed3x = 5.0; // Sağdan sola
	topspeed3y = 5.0; // Yukarıdan aşağıya

  glutPostRedisplay();

}

void keyInput(unsigned char key, int x, int y) 
{
	switch (key) {
	case 27:
		exit(0);
	case 'd'://AYNI AN
	case 'D':
		speed1 = 5.0;
		break;
	case 'a'://AYNI AN
	case 'A':
		speed1 = -5.0;
		break;
	default:
		break;
	}

}

void keyInput2(int key, int x, int y) 
{
	switch (key) {
	case GLUT_KEY_LEFT:
		speed2 = -5.0;
		break;
	case GLUT_KEY_RIGHT:
		speed2 = 5.0;
		break;
	default:
		break;
	}
}
void setup(void)
{
	glClearColor(0.0, 0.0,0.0, 0.0);
}

void myReshape(GLsizei w, GLsizei h)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	//	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	ww = w;
	wh = h;
}
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	ww = w;
	wh = h;
	printf("\n w=%u - h=%u", w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, ww, 0.0, wh, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	ww = w;
	wh = h;
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1000, 900);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("pong");

	glutDisplayFunc(drawScene);
	ball_direction();
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(keyInput2);
	//bunlar top hareket

	/*glutKeyboardFunc(topharaketkey1);
	glutSpecialFunc(topharaketkey2);*/

	glutTimerFunc(6, update, 0);

	setup();
	glutMainLoop();

}
