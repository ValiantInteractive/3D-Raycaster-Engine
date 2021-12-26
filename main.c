#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "math.h"
#include "maps.h"
#include "structs.h"
#include "raycaster.h"
#define WIDTH 1280
#define HEIGHT 720


void drawPlayer() {
    glColor3f(1, 0, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(player.posX, player.posY);
    glEnd();
}

void drawMap2D() {
    int x, y, xo, yo;

    for (y = 0; y < mapY; y++) {
        for (x = 0; x < mapX; x++) {
            if (map[y * mapX + x] == 1) {
                glColor3f(1, 1, 1);
            } else {
                glColor3f(0, 0, 0);
            }

            xo = x * mapS;
            yo = y * mapS;

            glBegin(GL_QUADS);
            glVertex2i(xo + 1, yo + 1);
            glVertex2i(xo + 1, yo + mapS - 1);
            glVertex2i(xo + mapS - 1, yo + mapS - 1);
            glVertex2i(xo + mapS - 1, yo + 2);
            glEnd();
        }
    }
}

void exitInput(unsigned char key, int x, int y) {
    if (key == 27) // Hit Escape key
    {
        glutDestroyWindow(0);
        exit(0);
    }
}

void ButtonDown(unsigned char key, int x, int y) {
    if(key == GLUT_KEY_LEFT)
        keys.left = 1;
    if(key == GLUT_KEY_RIGHT)
        keys.right = 1;
    if(key == GLUT_KEY_UP)
        keys.up = 1;
    if(key == GLUT_KEY_DOWN)
        keys.down = 1;
    glutPostRedisplay();
}

void ButtonUp(unsigned char key, int x, int y) {
    if(key == GLUT_KEY_LEFT)
        keys.left = 0;
    if(key == GLUT_KEY_RIGHT)
        keys.right = 0;
    if(key == GLUT_KEY_UP)
        keys.up = 0;
    if(key == GLUT_KEY_DOWN)
        keys.down = 0;
    glutPostRedisplay();
}

void init() {
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, 1024, 510, 0);
    player.posX = 100;
    player.posY = 100;
    player.deltaX = cosf(player.angle) * 5;
    player.deltaY = sinf(player.angle) * 5;
}

void display() {
    // Frames per second:
    frame2 = glutGet(GLUT_ELAPSED_TIME);
    fps = (frame2 - frame1);
    frame1 = glutGet(GLUT_ELAPSED_TIME);

    // Buttons:
    if (keys.left == 1) {
        player.angle += 0.1f * fps;
        player.angle = FixAng(player.angle);
        player.deltaX = cosf(degToRad(player.angle));
        player.deltaY = -sinf(degToRad(player.angle));
    }
    if (keys.right == 1) {
        player.angle -= 0.1f * fps;
        player.angle = FixAng(player.angle);
        player.deltaX = cosf(degToRad(player.angle));
        player.deltaY = -sinf(degToRad(player.angle));
    }

    int xo = 0;

    if (player.deltaX < 0)
        xo -= 20;
    else
        xo = 20;

    int yo = 0;

    if (player.deltaY < 0)
        yo -= 20;
    else
        yo = 20;

    int ipx = player.posX / 64, ipx_add_xo = (player.posX + xo) / 64, ipx_sub_xo = (player.posX - xo) / 64;
    int ipy = player.posY / 64, ipy_add_yo = (player.posY + yo) / 64, ipy_sub_yo = (player.posY - yo) / 64;

    if (keys.up == 1) {
        if(map[ipy*mapX + ipx_add_xo] == 0)
            player.posX += player.deltaX * 0.1f * fps;
        if(map[ipy_add_yo*mapX + ipx] == 0)
            player.posY += player.deltaY * 0.1f * fps;
    }
    if (keys.down == 1) {
        if(map[ipy*mapX + ipx_sub_xo] == 0)
            player.posX -= player.deltaX * 0.1f * fps;
        if(map[ipy_sub_yo*mapX + ipx] == 0)
            player.posY -= player.deltaY * 0.1f * fps;
    }
    glutPostRedisplay();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawMap2D();
    drawRays2D();
    drawPlayer();
    glutSwapBuffers();
}

void resize() {
    glutReshapeWindow(WIDTH, HEIGHT);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("3D Engine");
    init();
    glutKeyboardFunc(exitInput);
    glutSpecialFunc((void (*)(int, int, int)) ButtonDown);
    glutSpecialUpFunc((void (*)(int, int, int)) ButtonUp);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}