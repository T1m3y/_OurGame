#pragma once
#include<map>
#include<cstdint>
#include<memory>
#include<algorithm>
#include<vector>
#include<list>
#include"Entity.h"


class MapEntity;
template<typename Cont> class MapElemRef;

class GameMap
{
private:
	typedef std::list<MapEntity> MapPosContainer;
	typedef std::vector<MapPosContainer> Map1DContainer;
	typedef std::vector<Map1DContainer> Map2DContainer;			

	Map2DContainer map;

	typedef decltype(map.size()) Index;
public:
	typedef sf::Vector2f Position_t;

	GameMap(Index sizeX, Index sizeY) : map(Map2DContainer(sizeX, Map1DContainer(sizeY, MapPosContainer())))
	{
		
	}
	
	void insertEntity(MapEntity& ent)
	{

	}

	void removeEntity(MapEntity& ent)
	{

	}


};

////References an Object inside a "Cont"-container
//template<typename Cont>
//class MapElemRef
//{
//private:
//	//Container Holding the MapElem
//	std::weak_ptr<Cont> cont;
//	std::iterator it;
//
//public:
//	MapElemRef(std::shared_ptr<Cont>& containerPtr, std::iterator& it)
//	{
//		cont = containerPtr;
//		this->it = it;
//	}
//
//	auto get()
//	{
//		return *it;
//	}
//};
//
//template<typename Cont>
//MapElemRef<Cont> makeMapElemRef(Cont container, Index index)
//{
//	return MapElemRef<Cont>(container, index);
//}

//all classes whose objects need to be inside GameMap need to derive from this
class MapEntity : Entity
{
private:
	enum MapEntityType;
	MapEntityType type;
	std::weak_ptr<GameMap> map;

protected:
	GameMap::Position_t mapPos;

public:

	~MapEntity()
	{
		(*map)
	}

	enum MapEntityType
	{
		Unit,
		Building,
		Environment
	};

	MapEntity(std::weak_ptr<GameMap> map, MapEntityType type, GameMap::Position_t pos)
	{
		this->type = type;
		mapPos = pos;
	}


};