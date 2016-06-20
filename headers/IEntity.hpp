//
// Created by Alexandre Sejournant on 08/06/2016.
//

//  Basic entity template, most things will inherit from this

#ifndef DUNJONEER_IENTITY_HPP
#define DUNJONEER_IENTITY_HPP

#include <irrlicht.h>
#include <string>

#include <customMacro.hh>

class IEntity
{
public:
    virtual         ~IEntity()  {}

    ///////////
    //SETTERS////////////////////////////////////////////////////////////////////////////////
    virtual void    setPos      (   const   t_vec3df        &newPos     )   =   0;//DEFAULT//
    virtual void    setAcc      (   const   t_vec3df        &newAcc     )   =   0;//DEFAULT//
    virtual void    setSpeed    (   const   float           &newSpeed   )   =   0;//DEFAULT//
    virtual void    setName     (   const   std::string     &newName    )   =   0;//DEFAULT//
    /////////////////////////////////////////////////////////////////////////////////////////

    ///////////
    //GETTERS////////////////////////////////////////////////////////////
    virtual t_vec3df    const   &getPos     ()  const   =   0;//DEFAULT//
    virtual t_vec3df    const   &getAcc     ()  const   =   0;//DEFAULT//
    virtual float       const   &getSpeed   ()  const   =   0;//DEFAULT//
    virtual std::string const   &getType    ()  const   =   0;//DEFAULT//
    virtual std::string const   &getName    ()  const   =   0;//DEFAULT//
    /////////////////////////////////////////////////////////////////////

    //////////
    //SYSTEM////////////////////////////////////////////////////////////////////////////////
    virtual void    updatePosition      (                               )   =   0;//SYSTEM//
    virtual void    loadStandingMesh    (const  std::string &fileName   )   =   0;//SYSTEM//
    ////////////////////////////////////////////////////////////////////////////////////////
};

#endif //!DUNJONEER_IENTITY_HPP
