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
	typedef sf::Vector2f Position;

	GameMap(Index sizeX, Index sizeY) : map(Map2DContainer(sizeX, Map1DContainer(sizeY, MapPosContainer())))
	{
		
	}

	void insertEntity(MapEntityRef ent)
	{
		map.at(ent->getPosition.x).at(ent->getPosition.y).emplace_front(ent);
	}

	void removeEntity(MapEntityRef ent)
	{
		auto begin = map.at(ent->getPosition.x).at(ent->getPosition.y).begin;
		auto end = map.at(ent->getPosition.x).at(ent->getPosition.y).end;

		auto entIt = std::find(begin, end, ent);
		map.at(ent->getPosition.x).at(ent->getPosition.y).erase(entIt);
	}
};



class MapEntity : Entity
{
private:
	enum MapEntityType;
	MapEntityType type;
	std::weak_ptr<GameMap> map;

protected:
	GameMap::Position mapPos;

public:

	~MapEntity()
	{
		(*map);
	}

	enum MapEntityType
	{
		Environment,
		Unit,
		City,
		Ressource,
	};

	MapEntity(std::weak_ptr<GameMap> map, MapEntityType type, GameMap::Position pos)
	{
		this->type = type;
		mapPos = pos;
	}

	GameMap::Position getPosition()
	{
		return mapPos;
	}

	MapEntityType getType()
	{
		return type;
	}

};