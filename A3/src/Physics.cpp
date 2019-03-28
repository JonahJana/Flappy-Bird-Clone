#include "Main.h"

/*
Ground Level
here are the bumps and ramps in the current map
X, Y (X is where the bump starts, Y the new ground level)
0, 660
130, 500
370, 340
610, ramp
910, 660

we can read this data from a data file so it is not hard coded

alternatively, we can raed a height map image, go through all X values (columns) and find the highest black pixel and save that as ground level 
for that X. This will be saved in an array
*/

Physics::Physics()
{
}


Physics::~Physics()
{
}

int Physics::GroundLevel(int x)
{
	int groundLevel;

	if (x < 130)
		groundLevel = 660;
	else if (x < 370)
		groundLevel = 500;
	else if (x < 600)
		groundLevel = 340;
	else if (x < 920)
		groundLevel = 340+(x-600);
	else
		groundLevel = 660;

	return groundLevel;
}

void Physics::Move(GameObject* obj, int targetX)
{
	//set ground level where the player wants to go (target x)
	//can we move forward
	int dy = GroundLevel(targetX) - (obj->y+obj->height);
	if (dy > -5) //if new level is more than 5 higher than current level, we can't move
	{
		obj->x = targetX;
		if(dy < 5)
			obj->y += dy; //follow the ramp. if difference is more than 5, we need to use the fall algorithm
	}

	int groundLevel = GroundLevel(obj->x);

	//do jump/fall
	if (obj->jump == true)
	{
		//move
		obj->y = obj->y0 - JUMP_SPEED * obj->t + 0.5 * GRAVITY * obj->t*obj->t;
		//advance time
		obj->t+= 0.2;
		//reached the ground?
		if (obj->y > groundLevel - obj->height)
		{
			obj->y = groundLevel - obj->height;
			obj->jump = false;
	 	}
	}
	else //see if we have walked off a cliff and have to fall
	{
		if (obj->y < groundLevel - obj->height)
			obj->jump = true;
	}

}