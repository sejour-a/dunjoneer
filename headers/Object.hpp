//
// Created by Alexandre Sejournant on 09/06/2016.
//

#ifndef DUNJONEER_OBJECT_HPP
#define DUNJONEER_OBJECT_HPP

#include "IEntity.hpp"

class Object : public IEntity
{
private:
    Object();   //Illegal call

protected:
    //IRRLICHT UTILITIES
    t_irrDevice     *_device;
    t_sManager      *_sceneManager;

    //POSITION SYSTEM
    t_vec3df        _positionVector;
    t_vec3df        _accelerationVector;
    float           _movementSpeed;

    //OBJECT CLASS REQUIREMENTS
    t_mesh          *_standingAnimation;
    t_mesh          *_walkingAnimation;

public:
                    Object(t_irrDevice *newDevice);

                    ~Object();

    ///////////
    //SETTERS////////////////////////////////////////////////////////////////////////////////
    virtual void    setPos      (   const   t_vec3df        &newPos     )   =   0;//DEFAULT//
    virtual void    setAcc      (   const   t_vec3df        &newAcc     )   =   0;//DEFAULT//
    virtual void    setSpeed    (   const   float           &newSpeed   )   =   0;//DEFAULT//
    /////////////////////////////////////////////////////////////////////////////////////////

    ///////////
    //GETTERS////////////////////////////////////////////////////////
    virtual t_vec3df    const   &getPos()   const   =   0;//DEFAULT//
    virtual t_vec3df    const   &getAcc()   const   =   0;//DEFAULT//
    virtual float       const   &getSpeed() const   =   0;//DEFAULT//
    /////////////////////////////////////////////////////////////////
};

#endif //DUNJONEER_OBJECT_HPP
