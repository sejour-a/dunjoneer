//
// Created by Alexandre Sejournant on 09/06/2016.
//

#include <debug.h>
#include <colors.h>

#include <Object.hpp>

#include <iostream>

Object::Object(t_irrDevice *newDevice)
{
    if (DBG >= DEBUG_1)
        std::cerr << YELLOW << ">Creating new object" << COLOR_RESET << std::endl;

    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">" << COLOR_RESET << std::endl;
    _device             =   newDevice;
    if (DBG >= DEBUG_2)
        std::cerr << GREEN << "==Success==" << COLOR_RESET << std::endl;

    _sceneManager       =   _device->getSceneManager();
    _positionVector     =   t_vec3df(0, 0, 0);
    _accelerationVector =   t_vec3df(0, 0, 0);
    _movementSpeed      =   .0f;
    _standingAnimation  =   0;
    _walkingAnimation   =   0;
}

Object::~Object()
{
    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Dropping object standing animation mesh" << COLOR_RESET << std::endl;

    if      (_standingAnimation)
    {
        _standingAnimation->drop();
        if (DBG >= DEBUG_2)
            std::cerr << GREEN << "==Success==" << COLOR_RESET << std::endl;
    }
    else if (DBG >= DEBUG_2)
        std::cerr << YELLOW << "==No standing animation mesh to drop==" << COLOR_RESET << std::endl;

    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Dropping object walking animation mesh" << COLOR_RESET << std::endl;

    if      (_walkingAnimation)
    {
        _walkingAnimation->drop();
        if (DBG >= DEBUG_2)
            std::cerr << GREEN << "==Success==" << COLOR_RESET << std::endl;
    }
    else if (DBG >= DEBUG_2)
        std::cerr << YELLOW << "==No walking animation mesh to drop==" << COLOR_RESET << std::endl;
}

//SETTERS

void    Object::setPos      (const  t_vec3df    &newPos)
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Setting nameless object position" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>Old position : " << _positionVector.X << "/" << _positionVector.Y << "/" << _positionVector.Z << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>New position : " << newPos.X << "/" << newPos.Y << "/" << newPos.Z << COLOR_RESET << std::endl;
    }

    _positionVector     =   newPos;

    if  (DBG >= DEBUG_3)
        std::cerr << GREEN << "==Success==" << COLOR_RESET << std::endl;
}

void    Object::setAcc      (const  t_vec3df    &newAcc)
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Setting nameless object acceleration" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>Old acceleration : " << _accelerationVector.X << "/" << _accelerationVector.Y << "/" << _accelerationVector.Z << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>New acceleration : " << newAcc.X << "/" << newAcc.Y << "/" << newAcc.Z << COLOR_RESET << std::endl;
    }

    _accelerationVector =   newAcc;

    if  (DBG >= DEBUG_3)
        std::cerr << GREEN << "==Success==" << COLOR_RESET << std::endl;
}

void    Object::setSpeed    (const  float       &newSpeed)
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Setting nameless object speed" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>Old speed : " << _movementSpeed << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>New speed : " << newSpeed << COLOR_RESET << std::endl;
    }

    _movementSpeed      =   newSpeed;

    if  (DBG >= DEBUG_3)
        std::cerr << GREEN << "==Success==" << COLOR_RESET << std::endl;
}

//GETTERS

const   t_vec3df    &Object::getPos()   const
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Getting nameless object position" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>Position : " << _positionVector.X << "/" << _positionVector.Y << "/" << _positionVector.Z << COLOR_RESET << std::endl;
    }

    return _positionVector;
}

const   t_vec3df    &Object::getAcc()   const
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Getting nameless object acceleration" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>Acceleration : " << _accelerationVector.X << "/" << _accelerationVector.Y << "/" << _accelerationVector.Z << COLOR_RESET << std::endl;
    }

    return  _accelerationVector;
}

const   float       &Object::getSpeed() const
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Getting nameless object speed" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << ">>Speed : " << _movementSpeed << COLOR_RESET << std::endl;
    }

    return  _movementSpeed;
}