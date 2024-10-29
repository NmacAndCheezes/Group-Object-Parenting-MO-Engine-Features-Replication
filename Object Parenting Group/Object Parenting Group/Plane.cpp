#include "Plane.h"
#include "AGameObjectManager.h"
#include "PrimitiveRenderer.h"

void Plane::initialize(TexturePtr tex)
{
	PrimitiveRenderer* pr = new PrimitiveRenderer(PLANE, tex);
	attachComponent(pr);
}

Plane::Plane() : Cube(TexturePtr())
{
}

Plane::Plane(TexturePtr tex) : Cube(tex)
{
	initialize(tex);
}

void Plane::update()
{
	AGameObject::update();
}

Plane::~Plane()
{
}
