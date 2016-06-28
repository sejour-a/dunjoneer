//
// Created by Alexandre Sejournant on 09/06/2016.
//

#include <iostream>

#include <Object.hpp>

#include <debug.hh>
#include <colors.hh>

Object::Object(Settings *config)
{
    if (DBG >= DEBUG_2)
        std::cerr << CYAN << ">Creating new object" << COLOR_RESET << std::endl;

    _type               =   (const std::string &) "NONE";
    _name               =   (const std::string &) "nameless";
    _position           =   t_vec3df(0, 0, 0);
    _acceleration       =   t_vec3df(0, 0, 0);
    _config             =   config;
    _speed              =   0.1f;
    _node               =   0;
}

Object::~Object()
{
    if  (_node) _node->drop();
}

//SETTERS

void    Object::setPos      (const  t_vec3df    &newPos)    {   _position       =   newPos;     }
void    Object::setAcc      (const  t_vec3df    &newAcc)    {   _acceleration   =   newAcc;     }
void    Object::setSpeed    (const  float       &newSpeed)  {   _speed          =   newSpeed;   }
void    Object::setName     (const  std::string &newName)   {   _name           =   newName;    }

//GETTERS

const   t_vec3df    &Object::getPos()   const   {   return  _position;      }
const   t_vec3df    &Object::getAcc()   const   {   return  _acceleration;  }
const   float       &Object::getSpeed() const   {   return  _speed;         }
const   std::string &Object::getType()  const   {   return  _type;          }
const   std::string &Object::getName()  const   {   return  _name;          }

//SYSTEM

void    Object::updatePosition()
{
    _position += (_acceleration * _speed);

    if  (_node)
        _node->setPosition(_position);
}
