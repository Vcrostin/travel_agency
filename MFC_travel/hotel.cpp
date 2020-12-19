#include "pch.h"
#include "hotel.h"



std::ostream& operator<<(std::ostream& stream,const Hotel& ht)
{
	stream << ht.Name << " " << std::to_string(ht.Rooms.size()) << " ";
	for (int i = 0; i < (int)ht.Rooms.size(); ++i) {
		stream << (int)ht.Rooms[i] << " ";
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, Hotel& ht)
{
	stream >> ht.Name;
	int k;
	stream >> k;
	int p;
	for (int i = 0; i < k; ++i) {
		stream >> p;
		ht.Rooms.push_back((TypeRooms)p);
	}
	return stream;
}

Hotels::Hotels()
{
	Update();
}

Hotels::~Hotels()
{
	std::ofstream ostream("hotel_base.txt");
	for (auto& ah : all_hotels) {
		ostream << ah << "\n";
	}
	ostream.close();
}

//сохранить перед update
void Hotels::Update()
{
	all_hotels.clear();
	st.clear();
	std::ifstream stream("hotel_base.txt");
	std::string str;
	std::getline(stream, str);
	while (str.size() > 0) {
		Hotel element;
		std::stringstream ss(str);
		ss >> element;
		st.insert(element.Name);
		all_hotels.push_back(std::move(element));
		std::getline(stream, str);
	}
	stream.close();
}

void Hotels::Save()
{
	std::ofstream ostream("hotel_base.txt");
	for (auto& ah : all_hotels) {
		ostream << ah << "\n";
	}
	ostream.close();
}

bool Hotels::AddHotel(std::string& str, int size)
{
	if (st.count(str)==0) {
		st.insert(str);
		Hotel ht = { str, std::vector<TypeRooms>(size,TypeRooms::AVAILABLE) };
		all_hotels.push_back(std::move(ht));
		return true;
	}
	return false;
}

