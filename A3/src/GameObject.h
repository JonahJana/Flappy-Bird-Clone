#pragma once
class GameObject
{
protected:	//make img protected so child classes can use it
	ofImage img;
public:
	int x;
	int y;

	//Physics
	//needed for jump/fall
	bool jump;
	int y0;
	float t;
	int height;
	int width;


	GameObject();
	~GameObject();

	//virtual functions are expected to be modified by child class
	//any call will result in child class to be executed
	virtual void Draw();
	virtual ofImage* GetImage();
};

