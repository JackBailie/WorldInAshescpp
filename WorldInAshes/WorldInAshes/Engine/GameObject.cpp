#include"GameObject.h"

GameObject::GameObject()
{
}

void GameObject::SetComponentStore(ComponentStore* componentStore)
{
	m_componentStore = componentStore;
}
