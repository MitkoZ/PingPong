#ifndef BALL_H
#define BALL_H
#include <GL\gl.h>
#include <GL\glu.h>
#include <C:\My Files\GLUT\glutdlls36\glut.h>
#include <Player.h>

class Ball
{
    public:
        Ball(GLint x, GLint y, Player* bottomPlayer, Player* topPlayer);
        virtual ~Ball();
        GLint getX(), getY(), getStartPosition();
        void setX(GLint value), setY(GLint value), moveBall(GLint value);
    protected:

    private:
        GLint x, y;
        bool isHitTopPlayer();
        bool isHitBottomPlayer();
        void checkIsPlayerHit();
        void checkIsHitWall();
        Player* bottomPlayer;
        Player* topPlayer;
        enum MoveDirectionEnum
        {
            FromBottomToLeft,
            FromTopToRight,
            FromLeftToTop
        };
        MoveDirectionEnum moveDirectionEnum;
        void moveFromBottomToLeft(GLint value);
        void moveFromTopToRight(GLint value);
        void moveFromLeftToTop(GLint value);
};

#endif // BALL_H
