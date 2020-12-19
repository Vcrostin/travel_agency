#pragma once
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

enum class TypeRooms{
	AVAILABLE,
	ORDERED,
	FULL,
	BUY_AVAILABLE,
	BOUGHT
};
struct Hotel {
	std::string Name;
	std::vector<TypeRooms> Rooms;
};
std::ostream& operator<<(std::ostream& stream,const Hotel& ht);
std::istream& operator>>(std::istream& stream, Hotel& ht);
struct Hotels {
	Hotels();
	~Hotels();
	void Update();
	void Save();
	bool AddHotel(std::string& str, int size);
	//void Reserve_Room(Task& t);
	std::vector<Hotel> all_hotels;
	std::set<std::string> st;
};