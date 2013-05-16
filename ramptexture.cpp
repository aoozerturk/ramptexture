#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define windowSizeX 1024
#define windowSizeY 768
void resize(int width, int height)
{
     glViewport(0, 0, width, height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0, width, 0, height);
     glMatrixMode(GL_MODELVIEW);
}


static void display(void)
{
       static int a=0;
       static int b=0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor (1.0, 1.0, 1.0, 0.0);
    for(a=0;a<256;a++) {
                       for(b=0;b<256;b++) {
    glColor3f(a/(float)256,(a+b)/(float)512,b/(float)512);
    glBegin (GL_LINES);
     glVertex2i(400+b,windowSizeY-100-a);
     glVertex2i(401+b,windowSizeY-100-a);
     glEnd();
     
     glColor3f(pow(a/(float)256,0.5),pow((a+b)/(float)512,2),pow(b/(float)512,2));
     glBegin (GL_LINES);
     glVertex2i(100+b,windowSizeY-400-a);
     glVertex2i(101+b,windowSizeY-400-a);
     glEnd();
     
     glColor3f(pow(a/(float)256,2),pow((a+b)/(float)512,0.5),pow(b/(float)512,2));
     glBegin (GL_LINES);
     glVertex2i(400+b,windowSizeY-400-a);
     glVertex2i(401+b,windowSizeY-400-a);
     glEnd();
     
     glColor3f(pow(a/(float)256,2),pow((a+b)/(float)512,2),pow(b/(float)512,0.5));
     glBegin (GL_LINES);
     glVertex2i(700+b,windowSizeY-400-a);
     glVertex2i(701+b,windowSizeY-400-a);
     glEnd();}}
     
     glutSwapBuffers();
}


static void idle(void)
{
    glutPostRedisplay();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(windowSizeX,windowSizeY);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Ramp Texture");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glClearColor(1,1,1,1);
    glutMainLoop();

    return EXIT_SUCCESS;
    
}

    

