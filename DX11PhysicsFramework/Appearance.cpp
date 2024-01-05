#include "Appearance.h"

Appearance::Appearance(Geometry geometry, Material material) : _geometry(geometry), _material(material)
{
	_textureRV = nullptr;
}

Appearance::~Appearance()
{
	_textureRV = nullptr;
	_geometry.indexBuffer = nullptr;
	_geometry.vertexBuffer = nullptr;
}