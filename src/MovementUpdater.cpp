//
// Created by Alexandre Sejournant on 18/06/2016.
//

#include <vector>
#include "MovementUpdater.hpp"

MovementUpdater::MovementUpdater()
{
}

MovementUpdater::~MovementUpdater()
{
}

void    MovementUpdater::addEntity(Object *newObject)
{
    _objectList.push_back(newObject);
}

void    MovementUpdater::updatePosition()
{
    for (std::vector<Object *>::iterator i = _objectList.begin(); i != _objectList.end(); ++i)
    {
        Object *tmp = *i;
        tmp->updatePosition();
    }
}