#pragma once
class Physics
{
public:

	Physics();
	~Physics();

	void Move(GameObject* obj, int targetX);

	int GroundLevel(int x);
};

