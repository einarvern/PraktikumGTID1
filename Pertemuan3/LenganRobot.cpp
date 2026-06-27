#include <GL/glut.h>
#include <cstdlib>

static int shoulder = 0, elbow = 0, wrist = 0;
static int finger1 = 0, finger2 = 0, finger3 = 0, thumb = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(int baseRot) {
    float seg = 0.36f;
    glPushMatrix();
        glRotatef((GLfloat)baseRot, 0.0, 0.0, 1.0);
        glTranslatef(seg / 2.0f, 0.0, 0.0);
        glPushMatrix();
            glScalef(seg, 0.19f, 0.19f);
            glutWireCube(1.0);
        glPopMatrix();
        
        glTranslatef(seg / 2.0f, 0.0, 0.0);
        glRotatef((GLfloat)(baseRot / 2), 0.0, 0.0, 1.0);
        glTranslatef(seg / 2.0f, 0.0, 0.0);
        glPushMatrix();
            glScalef(seg, 0.17f, 0.17f);
            glutWireCube(1.0);
        glPopMatrix();
        
        glTranslatef(seg / 2.0f, 0.0, 0.0);
        glPushMatrix();
            glScalef(seg * 0.7f, 0.14f, 0.14f);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef(2.0, 0.42, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef(2.0, 0.42, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);

    glPushMatrix();
        glScalef(0.72f, 0.88f, 0.36f);
        glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.36f, 0.0, 0.0);

    glPushMatrix();
        glTranslatef(0.0, 0.31f, 0.0);
        drawFinger(finger1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, 0.11f, 0.0);
        drawFinger(finger2);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, -0.09f, 0.0);
        drawFinger(finger3);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, -0.29f, 0.0);
        glPushMatrix();
            glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);
            glTranslatef(0.21f, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.29f, 0.16f, 0.16f);
                glutWireCube(1.0);
            glPopMatrix();
            glTranslatef(0.23f, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.21f, 0.14f, 0.14f);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.19f, -0.51f, 0.0);
        glRotatef(-30.0f, 0.0, 0.0, 1.0);
        glRotatef((GLfloat)thumb, 0.0, 0.0, 1.0);
        glTranslatef(0.21f, 0.0, 0.0);
        glPushMatrix();
            glScalef(0.41f, 0.21f, 0.21f);
            glutWireCube(1.0);
        glPopMatrix();
        glTranslatef(0.27f, 0.0, 0.0);
        glPushMatrix();
            glScalef(0.29f, 0.16f, 0.16f);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5 + 360) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5 + 360) % 360; break;
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5 + 360) % 360; break;
        case 'f': finger1 = (finger1 + 5) % 90; break;
        case 'F': finger1 = (finger1 - 5 + 90) % 90; break;
        case 'g': finger2 = (finger2 + 5) % 90; break;
        case 'G': finger2 = (finger2 - 5 + 90) % 90; break;
        case 'h': finger3 = (finger3 + 5) % 90; break;
        case 'H': finger3 = (finger3 - 5 + 90) % 90; break;
        case 't': thumb = (thumb + 5) % 90; break;
        case 'T': thumb = (thumb - 5 + 90) % 90; break;
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan Robot");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}