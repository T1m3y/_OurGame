#pragma once
#include<map>
#include<cstdint>
#include<memory>
#include<algorithm>
#include<vector>
#include<list>


class MapElem;
template<typename Cont> class MapElemRef;

class GameMap
{
private:
	typedef std::list<MapElem> MapPosContainer;
	typedef std::vector<MapPosContainer> Map1DContainer;
	typedef std::vector<Map1DContainer> Map2DContainer;			

	Map2DContainer& map;

	typedef decltype(map.size()) Index;
public:
	GameMap(Index sizeX, Index sizeY) : map(Map2DContainer(sizeX, Map1DContainer(sizeY, MapPosContainer())))
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
class MapElem
{
private:
	enum MapElemType;
	MapElemType type;

protected:
	//typedef sf::Vector2i Position_t;
	typedef sf::Vector2f Position_t;
	Position_t mapPos;

public:

	enum MapElemType
	{
		Unit,
		Building,
		Environment
	};

	MapElem(MapElemType type, Position_t pos)
	{
		this->type = type;
		mapPos = pos;
	}
};