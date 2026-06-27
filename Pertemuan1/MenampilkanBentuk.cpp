#include <GL/glut.h>

void MenampilkanBentuk() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9f, 0.7f);
        glVertex2f(-0.7f, 0.88f);
        glVertex2f(-0.5f, 0.7f);
        glVertex2f(-0.28f, 0.9f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2f, 0.9f);
        glVertex2f( 0.12f, 0.89f);
        glVertex2f( 0.1f, 0.6f);
        glVertex2f(-0.18f, 0.6f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.55f, 0.75f);
        glVertex2f(0.45f, 0.60f);
        glVertex2f(0.55f, 0.55f);
        glVertex2f(0.65f, 0.60f);
        glVertex2f(0.70f, 0.75f);
        glVertex2f(0.65f, 0.90f);
        glVertex2f(0.55f, 0.95f);
        glVertex2f(0.45f, 0.90f);
        glVertex2f(0.40f, 0.75f);
        glVertex2f(0.45f, 0.60f);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.9f, 0.1f);
        glVertex2f(-0.8f, -0.2f);
        glVertex2f(-0.7f, 0.1f);
        glVertex2f(-0.6f, -0.2f);
        glVertex2f(-0.5f, 0.1f);
        glVertex2f(-0.38f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.1f);
        glVertex2f( 0.2f, 0.1f);
        glVertex2f( 0.2f, -0.2f);
        glVertex2f(-0.1f, -0.21f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.4f,  0.1f);
        glVertex2f(0.4f, -0.2f);
        glVertex2f(0.55f,  0.15f);
        glVertex2f(0.55f, -0.15f);
        glVertex2f(0.7f,  0.1f);
        glVertex2f(0.7f, -0.2f);
        glVertex2f(0.85f,  0.15f);
        glVertex2f(0.85f, -0.15f);
    glEnd();

    glRectf(-0.30f, -0.70f, -0.12f, -0.52f);
    glRectf(-0.10f, -0.70f,  0.08f, -0.52f);
    glRectf( 0.10f, -0.70f,  0.28f, -0.52f);
    glRectf(-0.20f, -0.50f, -0.02f, -0.32f);
    glRectf( 0.03f, -0.50f,  0.18f, -0.32f);
    
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Adefritz Einar Sinaga - 24060124140186");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(MenampilkanBentuk);
    glutMainLoop();
    return 0;
}