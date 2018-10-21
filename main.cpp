#include <iostream>
#include <GL\gl.h>
#include <GL\glu.h>
#include <C:\My Files\GLUT\glutdlls36\glut.h>
#include "Player.h"
#include "Ball.h"
#include "Constants.hpp"

Player* bottomPlayer = new Player(300);
Player* topPlayer = new Player(300);
Ball* ball;

using namespace std;

void specialHandler(int key, int x, int y)
{
   switch(key)
   {
       case GLUT_KEY_LEFT:
        {
            bottomPlayer->moveLeft(30);
            glutPostRedisplay();
            break;
        }
        case GLUT_KEY_RIGHT:
        {
            bottomPlayer->moveRight(30);
            glutPostRedisplay();
            break;
        }
   }
}

void keyboardHandler(unsigned char key, int x, int y)
{
    switch(toupper(key))
    {
        case 'A':
        {
            topPlayer->moveLeft(20);
            glutPostRedisplay();
            break;
        }
        case 'D':
        {
            topPlayer->moveRight(20);
            glutPostRedisplay();
            break;
        }
        case 32: //spacebar
        {
            ball = new Ball(bottomPlayer->getLeftX() , bottomPlayer->getRightY() -1, bottomPlayer, topPlayer);
            break;
        }
    }
}

void printScore(Player* topPlayer, Player* bottomPlayer)
{
    system("cls");
    cout << "Top player : Bottom player \n";
    cout << "\n" << topPlayer->getScore() << " : " << bottomPlayer->getScore();
}

void checkIsScore()
{
    if (ball->getY() > Constants::WindowHeight)
    {
        topPlayer->setScore(topPlayer->getScore() + 1);
        printScore(topPlayer, bottomPlayer);
        delete ball;
        ball = NULL;
    }
    else if (ball->getY() < 0)
    {
        bottomPlayer->setScore(bottomPlayer->getScore() + 1);
        printScore(topPlayer, bottomPlayer);
        delete ball;
        ball = NULL;
    }
}

void displayScene()
{
    glBegin(GL_LINES);
            glColor3f(0, 1, 0);
            glVertex2i(topPlayer->getLeftX(), topPlayer->getLeftY());
            glVertex2i(topPlayer->getRightX(), topPlayer->getRightY());
            glColor3f(1, 0, 0);
            glVertex2i(bottomPlayer->getLeftX(), bottomPlayer->getLeftY());
            glVertex2i(bottomPlayer->getRightX(), bottomPlayer->getRightY());
    glEnd();
    if (ball)
    {
        glPointSize(50);
        glBegin(GL_POINTS);
                glColor3f(0, 0, 1);
                glVertex2i(ball->getX(), ball->getY());
                ball->moveBall(1);
                checkIsScore();
        glutPostRedisplay();
        glEnd();
    }
        glFlush();
}

void displayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glLineWidth(33);
    displayScene();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(Constants::WindowWidth, Constants::WindowHeight);
    glutCreateWindow("Ping - Pong");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, Constants::WindowWidth, Constants::WindowHeight, 0, -1, 1);
    topPlayer->setLeftY(1);
    topPlayer->setRightY(1);
    bottomPlayer->setLeftY(Constants::WindowHeight - 1);
    bottomPlayer->setRightY(Constants::WindowHeight - 1);
    glutKeyboardFunc(keyboardHandler);
    glutSpecialFunc(specialHandler);
    glutDisplayFunc(displayFunc);
    glutMainLoop();
    return 0;
}
