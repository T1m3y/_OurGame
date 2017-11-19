#pragma once
#include "Entity.h"

class EntityContainerBase
{
private:

public:

	

};

class EntityRefBase
{
	//virtual Entity& operator*() = 0;
	virtual EntityContainerBase& getContainer() = 0;
	virtual EntityContainerBase::Iterator getIterator() = 0;
};

template<typename Container>
class EntityContainer : EntityContainerBase
{
private:
	Container container;

public:
	typedef decltype(declval<Container>().begin()) Iterator;

	EntityContainerTemplate() : container(Container)
	{

	}

	class EntityRef : EntityRefBase
	{
	private:

	public:
	};

};


