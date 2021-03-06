//
// Created by Alexandre Sejournant on 18/06/2016.
//

#include <iostream>

#include <EntityList.hpp>

#include <debug.hh>
#include <colors.hh>

EntityList::EntityList()
{
}

EntityList::~EntityList()
{
}

void    EntityList::addEntity(Object *newObject)
{
    if (DBG >= DEBUG_3)
        std::cerr << YELLOW << ">Adding " << CYAN << newObject->getName() << YELLOW << " to entity list" << COLOR_RESET << std::endl << std::endl;

    _objectList.push_back(newObject);
}

void    EntityList::updatePosition()
{
    for (std::vector<Object *>::iterator i = _objectList.begin(); i != _objectList.end(); ++i)
    {
        Object *tmp = *i;
        tmp->updatePosition();
    }
}