#include <GL\gl.h>
#include <GL\glu.h>
#include <C:\My Files\GLUT\glutdlls36\glut.h>
#include "Player.h"
#include "../Constants.hpp"

Player::Player(GLint playerLength)
{
    this->leftX = 0;
    this->leftY = 0;
    this->rightX = 0;
    this->rightY = 0;
    this->PlayerLength = playerLength;
    this->leftX = (Constants::WindowWidth / 2) - (PlayerLength / 2);
    this->rightX = (Constants::WindowWidth / 2) + (PlayerLength / 2);
    this->score = 0;
}

Player::~Player()
{
}

void Player::setLeftX(GLint value)
{
    this->leftX = value;
}

void Player::setRightX(GLint value)
{
    this->rightX = value;
}

void Player::setLeftY(GLint value)
{
    this->leftY = value;
}

void Player::setRightY(GLint value)
{
    this->rightY = value;
}

GLint Player::getLeftX()
{
    return Player::leftX;
}

GLint Player::getLeftY()
{
    return Player::leftY;
}

GLint Player::getRightX()
{
    return Player::rightX;
}

GLint Player::getRightY()
{
    return Player::rightY;
}

GLint Player::getPlayerLength()
{
    return Player::PlayerLength;
}

void Player::moveLeft(GLint value)
{
    int newLeftXValue = getLeftX() - value;
    if (newLeftXValue >= 0)
    {
        setLeftX(newLeftXValue);
        setRightX(getRightX() - value);
    }
    else // left end of the screen reached
    {
        setLeftX(0);
    }
}

void Player::moveRight(GLint value)
{
    int newRightXValue = getRightX() + value;
    if (newRightXValue <= Constants::WindowWidth)
    {
        setLeftX(getLeftX() + value);
        setRightX(newRightXValue);
    }
    else // right end of the screen reached
    {
        setRightX(Constants::WindowWidth);
    }
}

int Player::getScore()
{
    return this->score;
}

void Player::setScore(int score)
{
    this->score = score;
}
