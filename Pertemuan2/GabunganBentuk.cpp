#include <GL/glut.h>
#include <math.h>   
#include <cstdlib>

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glLineWidth(2.0f);
        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.01f,  0.22f, 0.0f);
            glVertex3f(0.01f, -0.18f, 0.0f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glPointSize(5.0f);
        glTranslatef(0.34f, 0.36f, 0.0f);

        glBegin(GL_POINTS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.24f, 0.26f, 0.0f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.48f, 0.52f, 0.0f);

        glBegin(GL_TRIANGLE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f);  glVertex3f(-0.06f, -0.04f, 0.0f);
            glColor3f(0.0f, 1.0f, 0.0f);  glVertex3f( 0.14f, -0.04f, 0.0f);
            glColor3f(0.0f, 0.0f, 1.0f);  glVertex3f(-0.06f,  0.04f, 0.0f);
            glColor3f(1.0f, 1.0f, 0.0f);  glVertex3f( 0.16f,  0.06f, 0.0f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        const double PI = 3.1415926535898;
        const int circle_points = 98;

        glBegin(GL_LINE_LOOP);
            glColor3f(1.0f, 1.0f, 1.0f);
            for (int i = 0; i < circle_points; i++) {
                double angle = 2.0 * PI * i / circle_points;
                glVertex2f((float)cos(angle) * 0.95f, (float)sin(angle) * 0.95f);
            }
        glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Stack");

    glutDisplayFunc(RenderScene);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}