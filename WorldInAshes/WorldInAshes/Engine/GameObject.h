#pragma once
//An object that exists in the world
#include"ComponentStore.h"

class GameObject
{
public:
	GameObject();
	virtual void Initialise() = 0;
	virtual void Update(float dt) = 0;
	void SetComponentStore(ComponentStore* componentStore);
protected:
	std::string tag;
	ComponentStore* m_componentStore;
};