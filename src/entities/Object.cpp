//
// Created by Alexandre Sejournant on 09/06/2016.
//

#include "debug.h"
#include "colors.h"

#include "Object.hpp"

#include <iostream>

Object::Object(t_irrDevice *newDevice)
{
    _device             =   newDevice;
    _sceneManager       =   _device->getSceneManager();
    _positionVector     =   t_vec3df(0, 0, 0);
    _accelerationVector =   t_vec3df(0, 0, 0);
    _movementSpeed      =   .0f;
    _standingAnimation  =   0;
    _walkingAnimation   =   0;
}

Object::~Object()
{
    _standingAnimation->drop();
    _walkingAnimation->drop();
}

//SETTERS

void    Object::setPos      (const  t_vec3df    &newPos)
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Setting nameless object position" << std::endl;
        std::cerr << ">>Old position : " << _positionVector.X << "/" << _positionVector.Y << "/" << _positionVector.Z << std::endl;
        std::cerr << ">>New position : " << newPos.X << "/" << newPos.Y << "/" << newPos.Z << std::endl;
    }

    _positionVector     =   newPos;

    if  (DBG >= DEBUG_3)
        std::cerr << GREEN << "==Success==" << std::endl << COLOR_RESET;
}

void    Object::setAcc      (const  t_vec3df    &newAcc)
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Setting nameless object acceleration" << std::endl;
        std::cerr << ">>Old acceleration : " << _accelerationVector.X << "/" << _accelerationVector.Y << "/" << _accelerationVector.Z << std::endl;
        std::cerr << ">>New acceleration : " << newAcc.X << "/" << newAcc.Y << "/" << newAcc.Z << std::endl;
    }

    _accelerationVector =   newAcc;

    if  (DBG >= DEBUG_3)
        std::cerr << GREEN << "==Success==" << std::endl << COLOR_RESET;
}

void    Object::setSpeed    (const  float       &newSpeed)
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Setting nameless object speed" << std::endl;
        std::cerr << ">>Old speed : " << _movementSpeed << std::endl;
        std::cerr << ">>New speed : " << newSpeed << std::endl;
    }

    _movementSpeed      =   newSpeed;

    if  (DBG >= DEBUG_3)
        std::cerr << GREEN << "==Success==" << std::endl << COLOR_RESET;
}