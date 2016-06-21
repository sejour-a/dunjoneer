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

    _type               =   (const std::string &) "NONE";
    _name               =   (const std::string &) "nameless";

    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Setting object device" << COLOR_RESET;
    _device             =   newDevice;
    if (DBG >= DEBUG_2)
    {
        if (_device != 0)
            std::cerr << GREEN << "\t\t\t==Success==" << COLOR_RESET << std::endl;
        else
        {
            std::cerr << RED << "\t\t\t==Failure==" << COLOR_RESET << std::endl;
            exit(1);
        }
    }

    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Getting scene manager" << COLOR_RESET;
    _sceneManager       =   _device->getSceneManager();
    if (DBG >= DEBUG_2)
    {
        if  (_sceneManager != 0)
            std::cerr << GREEN << "\t\t\t==Success==" << COLOR_RESET << std::endl;
        else
        {
            std::cerr << RED << "\t\t\t==Failure==" << COLOR_RESET << std::endl;
            exit(2);
        }
    }

    _positionVector         =   t_vec3df(0, 0, 0);
    _accelerationVector     =   t_vec3df(0, 0, 0);
    _movementSpeed          =   0.01f;
    _standingAnimation      =   0;
    _standingAnimationNode  =   0;
    _walkingAnimation       =   0;
    _walkingAnimationNode   =   0;
    _node                   =   0;
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
            std::cerr << GREEN << "\t\t\t==Success==" << COLOR_RESET << std::endl <<std::endl;
    }
    else if (DBG >= DEBUG_2)
        std::cerr << GREEN << "\t\t\t==Success==" << YELLOW << "\t(No standing animation mesh to drop)" << COLOR_RESET << std::endl;

    ////////////////////////
    //WALKING ANIMATION DROP
    if (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Dropping " << object_details << YELLOW << " walking animation mesh" << COLOR_RESET;

    if      (_walkingAnimation)
    {
        _walkingAnimation->drop();
        if (DBG >= DEBUG_2)
            std::cerr << GREEN << "\t\t==Success==" << COLOR_RESET << std::endl;
    }
    else if (DBG >= DEBUG_2)
        std::cerr << GREEN << "\t\t\t==Success==" << YELLOW << "\t(No walking animation mesh to drop)" << COLOR_RESET << std::endl;
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

void    Object::setCurrentNode  (const  std::string &nodeName)
{
            if  (nodeName == "standing" )   _node   =   _standingAnimationNode  ;
    else    if  (nodeName == "walking"  )   _node   =   _walkingAnimationNode   ;
}

//GETTERS

const   t_vec3df    &Object::getPos()   const   {   return  _positionVector;        }
const   t_vec3df    &Object::getAcc()   const   {   return  _accelerationVector;    }
const   float       &Object::getSpeed() const   {   return  _movementSpeed;         }
const   std::string &Object::getType()  const   {   return  _type;                  }
const   std::string &Object::getName()  const   {   return  _name;                  }

//SYSTEM

void    Object::updatePosition()
{
    if  (DBG >= DEBUG_3)
        std::cerr << YELLOW << ">Updated " << _name << " position" << COLOR_RESET << std::endl << std::endl;

    _positionVector += (_accelerationVector * _movementSpeed);
    _node->setPosition(_positionVector);
}

void    Object::loadStandingMesh(const std::string &modelName)
{
    if  (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Loading mesh\t\t" << MAGENTA << modelName << COLOR_RESET << std::endl;
    _standingAnimation = _sceneManager->getMesh(std::string("./media/" + modelName + ".ms3d").c_str());
    _standingAnimationNode = _sceneManager->addAnimatedMeshSceneNode(_standingAnimation);

    if  (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Configuring model\t" << MAGENTA << modelName << COLOR_RESET << std::endl;
    _standingAnimationNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _standingAnimationNode->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
    _standingAnimationNode->setMaterialFlag(irr::video::EMF_ANTI_ALIASING, true);
    _standingAnimationNode->setMaterialFlag(irr::video::EMF_BILINEAR_FILTER, false);
    _standingAnimationNode->setMaterialFlag(irr::video::EMF_TRILINEAR_FILTER, true);

    if  (DBG >= DEBUG_2)
        std::cerr << YELLOW << ">Loading texture\t" << MAGENTA << modelName << COLOR_RESET << std::endl << std::endl;
    _standingAnimationNode->setMaterialTexture(0, _sceneManager->getVideoDriver()->getTexture(std::string("./media/" + modelName + ".png").c_str()));
}