//
// Created by Alexandre Sejournant on 18/06/2016.
//

#ifndef DUNJONEER_ENTITYLIST_HPP
#define DUNJONEER_ENTITYLIST_HPP

#include <Object.hpp>

#include <vector>

class   EntityList
{
private:
    std::vector<Object *> _objectList;

public:
    EntityList();
    ~EntityList();

    void    addEntity(Object *newObject);
    void    updatePosition();
};

#endif //DUNJONEER_ENTITYLIST_HPP

