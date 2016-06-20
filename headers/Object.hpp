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
    //OTHER STUFF
    std::string     _type;
    std::string     _name;

    //IRRLICHT UTILITIES
    t_irrDevice     *_device;
    t_sManager      *_sceneManager;

    //POSITION SYSTEM
    t_vec3df        _positionVector;
    t_vec3df        _accelerationVector;
    float           _movementSpeed;

    //OBJECT CLASS REQUIREMENTS
    t_mesh          *_standingAnimation;
    t_node          *_standingAnimationNode;
    t_mesh          *_walkingAnimation;
    t_node          *_walkingAnimationNode;
    t_node          *_node;

public:
                    Object(t_irrDevice *newDevice);
    virtual         ~Object();

    ///////////
    //SETTERS////////////////////////////////////////////////////////////////////////////
    virtual void    setPos          (   const   t_vec3df        &newPos     );//DEFAULT//
    virtual void    setAcc          (   const   t_vec3df        &newAcc     );//DEFAULT//
    virtual void    setSpeed        (   const   float           &newSpeed   );//DEFAULT//
    virtual void    setName         (   const   std::string     &newName    );//DEFAULT//
    virtual void    setCurrentNode  (   const   std::string     &nodeName   );//DEFAULT//
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
    //SYSTEM////////////////////////////////////////////////////////////////////////
    virtual void    updatePosition      (                               );//SYSTEM//
    virtual void    loadStandingMesh    (const  std::string &fileName   );//SYSTEM//
    ////////////////////////////////////////////////////////////////////////////////
};

#endif //DUNJONEER_OBJECT_HPP
