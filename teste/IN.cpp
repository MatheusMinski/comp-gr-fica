#include <GL/glut.h>

#include <GL/freeglut.h>

#include <stdlib.h>

#include <stdio.h>

//adicionar as formas a serem mostradas na cena

void display()

{

    /* Limpa todos os pixels da tela */

    glClear(GL_COLOR_BUFFER_BIT);

    /* Desenha um poligono colorido (retangulo) */

    glBegin(GL_POLYGON);

    glColor3f(1, 0, 0);

    glVertex3f(0.25, 0.25, 0);

    glColor3f(0, 1, 0);

    glVertex3f(0.75, 0.25, 0);

    glColor3f(0, 0, 1);

    glVertex3f(0.75, 0.75, 0);

    glVertex3f(0.25, 0.75, 0);

    glEnd();

    /*glBegin(GL_LINE_STRIP);

    glColor3f(1,0,0);

    glVertex2i(50,0);

    glVertex2i(50,80);

    glVertex2i(100,80);

    glVertex2i(100,0);



    glEnd();



     /*glBegin(GL_POINTS);

    glColor3f(1,0,0);

    glVertex2i(80,50);



    glEnd();



    */

    /*glBegin(GL_LINE_LOOP);

    glColor3f(1,0,0);

    glVertex2i(50,0);

    glVertex2i(50,80);

    glVertex2i(100,80);

    glVertex2i(100,0);



    glEnd();

    */

    glColor3f(0, 1, 1); //azul claro

    glutWireTeapot(0.8); //desenha centrado na origem

    //glutSolidSphere(0.5, 30, 10); //GLdouble radius, GLint slices (latitude), GLint stacks (longitude);

    //glutWireTeapot(0.5);

    /* Troca buffers (double-buffering) */

    glutSwapBuffers();
}

void myReshape(int winWidth, int winHeight) // reshape window

{

    int tam = winWidth < winHeight ? winWidth : winHeight;

    glViewport(0, 0, tam, tam); // reset the viewport
}

//Colocar comandos pelo teclado

void myKeyboard(unsigned char c, int x, int y)

{

    switch (c)
    {

    case 'q':

        exit(0);

        break;
    }
}

/*comandos especiais do teclado*/

void keySpecial(int key, int x, int y)
{

    printf("(%d, %d)\n", x, y);

    switch (key)
    {

    case GLUT_KEY_LEFT:

        printf("Left pressed\n");

        break;

    case GLUT_KEY_UP:

        printf("Up pressed\n");

        break;
    }

    if (glutGetModifiers() == GLUT_ACTIVE_ALT) //GLUT_ACTIVE_CTRL ou SHIFT

        printf("ALT pressed\n");
}

//imprimir as coordenadas com o clique do mouse

void myMouse(int b, int s, int x, int y)

{

    switch (b)
    {

    case GLUT_LEFT_BUTTON:

        printf("(%d, %d)\n", x, y);
    }
}

//função detecta movimento do mouse e salva coordenadas

void myMotion(int x, int y)
{

    printf("Motion: (%d, %d)\n", x, y);
}

void init()

{

    /* Define a cor de fundo (preto) */

    glClearColor(0.0, 0.0, 0.0, 0.0);

    //deixa o fundo vermelho

    //glClearColor(1.0, 0.0, 0.0, 0.0);

    /* Inicializa as Matrizes do OpenGL */

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    //glOrtho(-100, 100, -100 , 100, -100, 100);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)

{

    glutInit(&argc, argv); //inicializa

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //mostra o display como

    glutInitWindowSize(350, 350); //tamanho da janela

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Hello world!");

    init();

    glutDisplayFunc(display);

    glutReshapeFunc(myReshape);

    glutKeyboardFunc(myKeyboard);

    glutSpecialFunc(keySpecial);

    glutMouseFunc(myMouse);

    glutMotionFunc(myMotion);

    glutMainLoop();

    return 0;
}