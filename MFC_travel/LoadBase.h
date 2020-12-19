#pragma once
#include "pch.h"
#include "MFC_travel.h"
#include <map>
#include <string>
#include <list>
#include <string_view>
#include <vector>
#include "hotel.h"
enum struct Argument {
	DEFFAULT,
	CLIENT,
	HOTEL,
	ADMIN
};
struct OrderedInfo {
	/*int nums_hotel = 0;
	int count_rooms = 0;*/
	//int , typeRooms
	std::map<int, TypeRooms> ord_rooms;
	//TODO::переделать на map
};
struct NodeBase {
	Argument TypeEntry = Argument::DEFFAULT;
	std::vector<OrderedInfo> ordered_rooms;
};
std::istream& operator >>(std::istream& stream, NodeBase& nb);
std::ostream& operator <<(std::ostream& stream,const NodeBase& nb);
class LoadBase {
public:
	LoadBase();

	~LoadBase();

	bool Insert(std::string& login, std::string& password);

	bool Insert_hotel(std::string& login, std::string& password);

	bool possinshotel(std::string& name_hotel);

	bool Exist(std::string& login, std::string& password);

	NodeBase* GetNode(std::string login);
	std::map<std::string_view, NodeBase> all_db;
private:
	std::list<std::string> login_base;
	std::map<std::string_view, std::string> login_password;

};


inline std::string to_string(const CString& cst)
{
	return CT2A(cst.GetString());
}