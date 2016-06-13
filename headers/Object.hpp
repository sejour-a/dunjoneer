//
// Created by Alexandre Sejournant on 09/06/2016.
//

#ifndef DUNJONEER_OBJECT_HPP
#define DUNJONEER_OBJECT_HPP

#include <IEntity.hpp>

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
    virtual         ~Object();

    ///////////
    //SETTERS////////////////////////////////////////////////////////////////////////
    virtual void    setPos      (   const   t_vec3df        &newPos     );//DEFAULT//
    virtual void    setAcc      (   const   t_vec3df        &newAcc     );//DEFAULT//
    virtual void    setSpeed    (   const   float           &newSpeed   );//DEFAULT//
    /////////////////////////////////////////////////////////////////////////////////

    ///////////
    //GETTERS////////////////////////////////////////////////
    virtual t_vec3df    const   &getPos()   const;//DEFAULT//
    virtual t_vec3df    const   &getAcc()   const;//DEFAULT//
    virtual float       const   &getSpeed() const;//DEFAULT//
    /////////////////////////////////////////////////////////
};

#endif //DUNJONEER_OBJECT_HPP
