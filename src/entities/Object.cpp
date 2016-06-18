//
// Created by Alexandre Sejournant on 09/06/2016.
//

#include <iostream>

#include <Object.hpp>

#include <debug.hh>
#include <colors.hh>

Object::Object(t_irrDevice *newDevice)
{
    if (DBG >= DEBUG_1)
        std::cerr << CYAN << ">Creating new object" << COLOR_RESET << std::endl;

    _type               =   "NONE";
    _name               =   "nameless";

    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Setting object device" << COLOR_RESET;
    _device             =   newDevice;
    if (DBG >= DEBUG_2)
    {
        if (_device != 0)
            std::cerr << GREEN << "\t==Success==" << COLOR_RESET << std::endl;
        else
        {
            std::cerr << RED << "\t==FAIL==" << COLOR_RESET << std::endl;
            exit(1);
        }
    }

    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Getting scene manager" << COLOR_RESET;
    _sceneManager       =   _device->getSceneManager();
    if (DBG >= DEBUG_2)
    {
        if  (_sceneManager != 0)
            std::cerr << GREEN << "\t==Success==" << COLOR_RESET << std::endl;
        else
        {
            std::cerr << RED << "\t==FAIL==" << COLOR_RESET << std::endl;
            exit(2);
        }
    }

    _positionVector     =   t_vec3df(0, 0, 0);
    _accelerationVector =   t_vec3df(0, 0, 0);
    _movementSpeed      =   .0f;
    _standingAnimation  =   0;
    _walkingAnimation   =   0;
}

Object::~Object()
{
    /////////////////////////
    //STANDING ANIMATION DROP
    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Dropping " << object_details << YELLOW << " standing animation mesh" << COLOR_RESET;

    if      (_standingAnimation)
    {
        _standingAnimation->drop();
        if (DBG >= DEBUG_2)
            std::cerr << GREEN << "\t==Success==" << COLOR_RESET << std::endl <<std::endl;
    }
    else if (DBG >= DEBUG_2)
        std::cerr << GREEN << "\t==Success==" << YELLOW << "\t(No standing animation mesh to drop)" << COLOR_RESET << std::endl;

    ////////////////////////
    //WALKING ANIMATION DROP
    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Dropping " << object_details << YELLOW << " walking animation mesh" << COLOR_RESET;

    if      (_walkingAnimation)
    {
        _walkingAnimation->drop();
        if (DBG >= DEBUG_2)
            std::cerr << GREEN << "==Success==" << COLOR_RESET << std::endl;
    }
    else if (DBG >= DEBUG_2)
        std::cerr << GREEN << "\t==Success==" << YELLOW << "\t(No walking animation mesh to drop)" << COLOR_RESET << std::endl;
}

//SETTERS

void    Object::setPos      (const  t_vec3df    &newPos)
{
    if  (newPos != t_vec3df(0, 0, 0))
    {
        if (DBG >= DEBUG_3)
        {
            std::cerr << YELLOW << ">Setting " << object_details << YELLOW << " position" << COLOR_RESET << std::endl;
            std::cerr << YELLOW << "\t>Old position : " << position_vector << COLOR_RESET << std::endl;
            std::cerr << YELLOW << "\t>New position : " << CYAN << newPos.X << ";" << newPos.Y << ";" << newPos.Z << COLOR_RESET << std::endl << std::endl;
        }

        _positionVector = newPos;
    }
    else
    {
        if (DBG >= DEBUG_3)
        {
            std::cerr << YELLOW << ">Setting " << object_details << YELLOW << " position to 0;0;0" << COLOR_RESET << std::endl;
            std::cerr << YELLOW << "\t>Old position : " << position_vector << COLOR_RESET << std::endl << std::endl;
        }

        _positionVector = t_vec3df(0, 0, 0);
    }
}

void    Object::setAcc      (const  t_vec3df    &newAcc)
{
    if  (newAcc != t_vec3df(0, 0, 0))
    {
        if (DBG >= DEBUG_3)
        {
            std::cerr << YELLOW << ">Setting " << object_details << YELLOW << " acceleration" << COLOR_RESET << std::endl;
            std::cerr << YELLOW << "\t>Old acceleration : " << BLUE << acceleration_vector << COLOR_RESET << std::endl;
            std::cerr << YELLOW << "\t>New acceleration : " << CYAN << newAcc.X << ";" << newAcc.Y << ";" << newAcc.Z << COLOR_RESET << std::endl << std::endl;
        }

        _accelerationVector = newAcc;
    }
    else
    {
        if (DBG >= DEBUG_3)
        {
            std::cerr << YELLOW << ">Setting " << object_details << YELLOW << " acceleration to 0;0;0" << COLOR_RESET << std::endl;
            std::cerr << YELLOW << "\t>Old acceleration : " << acceleration_vector << COLOR_RESET << std::endl << std::endl;
        }

        _accelerationVector = t_vec3df(0, 0, 0);
    }
}

void    Object::setSpeed    (const  float       &newSpeed)
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Setting " << object_details << YELLOW << " speed" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>Old speed : " << BLUE << _movementSpeed << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>New speed : " << CYAN << newSpeed << COLOR_RESET << std::endl << std::endl;;
    }

    _movementSpeed      =   newSpeed;
}

void    Object::setName     (const  std::string &newName)
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Setting " << object_details << YELLOW << " name" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>Old name : " << BLUE << _name << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>New name : " << CYAN << newName << COLOR_RESET << std::endl << std::endl;;
    }

    _name               =   newName;
}

//GETTERS

const   t_vec3df    &Object::getPos()   const
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Getting " << object_details << YELLOW << " position" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>Position : " << position_vector << COLOR_RESET << std::endl << std::endl;;
    }

    return _positionVector;
}

const   t_vec3df    &Object::getAcc()   const
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Getting " << object_details << YELLOW << " acceleration" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>Acceleration : " << acceleration_vector << COLOR_RESET << std::endl << std::endl;;
    }

    return  _accelerationVector;
}

const   float       &Object::getSpeed() const
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Getting " << object_details << YELLOW << " speed" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>Speed : " << CYAN << _movementSpeed << COLOR_RESET << std::endl << std::endl;;
    }

    return  _movementSpeed;
}

const   std::string &Object::getType()  const
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Getting " << object_details << YELLOW << " type" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>Type : " << CYAN << _type << COLOR_RESET << std::endl << std::endl;;
    }

    return  _type;
}

const   std::string &Object::getName()  const
{
    if  (DBG >= DEBUG_3)
    {
        std::cerr << YELLOW << ">Getting " << object_details << YELLOW << " name" << COLOR_RESET << std::endl;
        std::cerr << YELLOW << "\t>Name : " << CYAN << _name << COLOR_RESET << std::endl << std::endl;;
    }

    return  _name;
}