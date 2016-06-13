//
// Created by Alexandre Sejournant on 08/06/2016.
//

//  Basic entity template, most things will inherit from this

#ifndef DUNJONEER_IENTITY_HPP
#define DUNJONEER_IENTITY_HPP

#include <customMacro.h>

class IEntity
{
public:
    virtual         ~IEntity()  {}

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

#endif //!DUNJONEER_IENTITY_HPP
