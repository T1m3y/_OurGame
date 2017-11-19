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
	typedef MapEntity* MapEntityRef;
	typedef std::list<MapEntityRef> MapPosContainer;
	typedef std::vector<MapPosContainer> Map1DContainer;
	typedef std::vector<Map1DContainer> Map2DContainer;		

	Map2DContainer map;

	typedef decltype(map.size()) Index;

public:
	typedef sf::Vector2f Position_t;

	GameMap(Index sizeX, Index sizeY) : map(Map2DContainer(sizeX, Map1DContainer(sizeY, MapPosContainer())))
	{
		
	}
	
	void insertEntity(MapEntityRef ent)
	{

	}

	void removeEntity(MapEntity& ent)
	{

	}
};



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