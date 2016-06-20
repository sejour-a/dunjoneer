//
// Created by Alexandre Sejournant on 08/06/2016.
//

#ifndef DUNJONEER_CUSTOMMACRO_HH
#define DUNJONEER_CUSTOMMACRO_HH

#define t_vec3df            irr::core::vector3df
#define t_irrDevice         irr::IrrlichtDevice
#define t_sManager          irr::scene::ISceneManager
#define t_mesh              irr::scene::IAnimatedMesh
#define t_node              irr::scene::IAnimatedMeshSceneNode
#define t_texture           irr::video::ITexture
#define object_details      CYAN << "[" << this->_name << ":" << this->_type << "]"
#define position_vector     BLUE << this->_positionVector.X << ";" << this->_positionVector.Y << ";" << this->_positionVector.Z
#define acceleration_vector BLUE << this->_accelerationVector.X << ";" << this->_accelerationVector.Y << ";" << this->_accelerationVector.Z

#endif //!DUNJONEER_CUSTOMMACRO_HH
