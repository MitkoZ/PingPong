#ifndef PLAYER_H
#define PLAYER_H
#include <GL\gl.h>
#include <GL\glu.h>
#include <C:\My Files\GLUT\glutdlls36\glut.h>

class Player
{
    public:
        Player(GLint playerLength);
        virtual ~Player();
        void setLeftX(GLint value);
        void setRightX(GLint value);
        void setLeftY(GLint value);
        void setRightY(GLint value);
        GLint getLeftX();
        GLint getLeftY();
        GLint getRightX();
        GLint getRightY();
        int getScore();
        void setScore(int score);
        GLint getPlayerLength();
        void moveLeft(GLint value);
        void moveRight(GLint value);
    protected:

     private:
          GLint leftX, leftY, rightX, rightY;
          GLint PlayerLength;
          int score;
};

#endif // PLAYER_H
