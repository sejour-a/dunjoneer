//
// Created by Alexandre Sejournant on 09/06/2016.
//

#ifndef DUNJONEER_OBJECT_HPP
#define DUNJONEER_OBJECT_HPP

#include <IEntity.hpp>
#include <Settings.hpp>

class Object : public IEntity
{
private:
    Object();   //Illegal call

protected:
    //SETTINGS
    Settings        *_config;

    //ID stuff
    std::string     _type;
    std::string     _name;

    //POSITION SYSTEM
    t_vec3df        _position;
    t_vec3df        _acceleration;
    float           _speed;

    //OBJECT CLASS REQUIREMENTS
    t_mesh          *_walk;
    t_mesh          *_stand;
    t_node          *_node;

public:
                    Object(Settings *config);
    virtual         ~Object();

    ///////////
    //SETTERS////////////////////////////////////////////////////////////////////////////
    virtual void    setPos          (   const   t_vec3df        &newPos     );//DEFAULT//
    virtual void    setAcc          (   const   t_vec3df        &newAcc     );//DEFAULT//
    virtual void    setSpeed        (   const   float           &newSpeed   );//DEFAULT//
    virtual void    setName         (   const   std::string     &newName    );//DEFAULT//
    /////////////////////////////////////////////////////////////////////////////////////

    ///////////
    //GETTERS////////////////////////////////////////////////////
    virtual t_vec3df    const   &getPos     ()  const;//DEFAULT//
    virtual t_vec3df    const   &getAcc     ()  const;//DEFAULT//
    virtual float       const   &getSpeed   ()  const;//DEFAULT//
    virtual std::string const   &getType    ()  const;//DEFAULT//
    virtual std::string const   &getName    ()  const;//DEFAULT//
    /////////////////////////////////////////////////////////////

    //////////
    //SYSTEM/////////////////////////////////////
    virtual void    updatePosition  ();//SYSTEM//
    /////////////////////////////////////////////
};

#endif //DUNJONEER_OBJECT_HPP
