#include "Main.h"

Render::Render()
{
}


Render::~Render()
{
}

void Render::Draw(GameObject* obj)
{
	obj->GetImage()->draw(obj->x, obj->y);

	//code for modifying the pixels of an image
	//used for adding effect

	//ofPixels p = obj->GetImage()->getPixels();
	//int w = p.getWidth();
	//int h = p.getHeight();
	//for(int i=0; i < w; i++)
	//	for (int j = 0; j < h; j++)
	//	{
	//		ofColor c = p.getColor(i, j);
	//		c.r = 0;
	//		p.setColor(i, j, c);
	//	}
	//ofImage temp;
	//temp.setFromPixels(p);
	//temp.draw(obj->x, obj->y);
}