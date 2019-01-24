#include "Ball.h"
#include <GL\gl.h>
#include <GL\glu.h>
#include <C:\My Files\GLUT\glutdlls36\glut.h>
#include <Player.h>
#include "../Constants.hpp"
#include <iostream>

using namespace std;

Ball::Ball(GLint x, GLint y, Player* bottomPlayer, Player* topPlayer)
{
    this->x = x;
    this->y = y;
    this->bottomPlayer = bottomPlayer;
    this->topPlayer = topPlayer;
    this->moveDirectionEnum = FromBottomToLeft;
}

Ball::~Ball()
{
}

GLint Ball::getX()
{
    return this->x;
}

GLint Ball::getY()
{
    return this->y;
}

GLint Ball::getStartPosition()
{
    return bottomPlayer->getLeftX() + bottomPlayer->getPlayerLength() / 2;
}

void Ball::setX(GLint value)
{
    this->x = value;
}

void Ball::setY(GLint value)
{
    this->y = value;
}

bool Ball::isHitBottomPlayer()
{
    if (this->getX() >= bottomPlayer->getLeftX() && this->getX() <= bottomPlayer->getRightX()
        && this->getY() >= bottomPlayer->getLeftY()) // doesn't really matter if you use getLeftY() or getRightY()
    {
        return true;
    }

    return false;
}

bool Ball::isHitTopPlayer()
{
    if (this->getY() <= 0 && topPlayer->getLeftX() <= this->getX() && topPlayer->getRightX() >= this->getX())
    {
        return true;
    }

    return false;
}

void Ball::checkIsPlayerHit()
{
    if (isHitBottomPlayer())
    {
        moveDirectionEnum = FromBottomToLeft;
    }
    else if (isHitTopPlayer())
    {
        moveDirectionEnum = FromTopToRight;
    }
}

void Ball::checkIsHitWall()
{
    bool leftBoundaries = this->getY() > 0 && this->getY() < Constants::WindowHeight;
    if (leftBoundaries)
    {
        if (this->getX() <= 0 && this->getY() > 0) // hit left wall
        {
            moveDirectionEnum = FromLeftToTop;
        }
    }
}

void Ball::moveFromBottomToLeft(GLint value)
{
    setX(getX() - value);
    setY(getY() - value);
}

void Ball::moveFromTopToRight(GLint value)
{
    setX(getX() + value);
    setY(getY() + value);
}

void Ball::moveFromLeftToTop(GLint value)
{
    setX(getX() + value);
    setY(getY() - value);
}

void Ball::moveBall(GLint value)
{
    checkIsPlayerHit();
    checkIsHitWall();

    switch (moveDirectionEnum)
    {
        case FromBottomToLeft:
        {
            moveFromBottomToLeft(value);
            break;
        }
        case FromTopToRight:
        {
            moveFromTopToRight(value);
            break;
        }
        case FromLeftToTop:
        {
            moveFromLeftToTop(value);
            break;
        }
    }
}
