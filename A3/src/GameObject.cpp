#include "Main.h"


GameObject::GameObject()
{
	x = y = 0;
	height = 152;
	width = 90;
}


GameObject::~GameObject()
{
}

void GameObject::Draw()
{
	img.draw(x, y);
}

ofImage* GameObject::GetImage()
{
	return &img;
}