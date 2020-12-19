#include "pch.h"
#include "LoadBase.h"
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

std::istream& operator>>(std::istream& stream, NodeBase& nb)
{
	int k, size_z;
	stream >> k >> size_z;
	nb.ordered_rooms.resize(size_z);
	for (int i = 0; i < size_z; ++i) {
		int t;
		stream >> t;
		for (int p = 0; p < t; ++p) {
			int key, value;
			stream >> key >> value;
			nb.ordered_rooms[i].ord_rooms[key] = (TypeRooms)value;
		}
	}
	nb.TypeEntry = (Argument)k;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const NodeBase& nb)
{
	stream << (int)nb.TypeEntry <<" "<< nb.ordered_rooms.size();
	for (int i = 0; i < (int)nb.ordered_rooms.size(); ++i) {
		stream << " " << nb.ordered_rooms[i].ord_rooms.size();
		for (auto& c : nb.ordered_rooms[i].ord_rooms) {
			stream << " " << c.first << " " << (int)c.second;
		}
	}
	return stream;
}

LoadBase::LoadBase() {
	std::ifstream istream("base.txt");
	std::string str;
	std::getline(istream, str);
	while (str.size()>0) {
		std::stringstream ss(str);
		std::string s;
		ss >> s;
		login_base.push_back(move(s));
		std::string_view sv(login_base.back());
		ss >> s;
		login_password[sv] = s;

		NodeBase nb;
		ss >> nb;
		all_db[sv] = std::move(nb);


		std::getline(istream, str);
	}
	istream.close();
}

LoadBase::~LoadBase()
{
	std::ofstream ostream("base.txt");
	auto it = all_db.begin();
	for (auto& l : login_password) {
		ostream << l.first << " " << l.second << " " << it->second << std::endl;
		it++;
	}
	ostream.close();
}

bool LoadBase::Insert(std::string& login, std::string& password)
{
	for (auto& l : login) {
		if (!((l <= 'z' && l >= 'a') || (l <= 'Z' && l >= 'A') || (l >= '0' && l <= '9'))) {
			return false;
		}
	}
	for (auto& p : password) {
		if (!(p <= '{' && p >= '!'))
			return false;
	}
	if (login_password.count(login)) {
		return false;
	}
	if (!(login.size() > 4 && password.size() > 4)) {
		return false;
	}
	login_base.push_back(login);
	std::string_view sv(login_base.back());
	login_password[sv] = password;
	all_db[sv] = { Argument::CLIENT };
	return true;
}

bool LoadBase::Insert_hotel(std::string& login, std::string& password)
{
	login_base.push_back(login);
	std::string_view sv(login_base.back());
	login_password[sv] = password;
	all_db[sv] = { Argument::HOTEL };
	return true;
}

bool LoadBase::possinshotel(std::string& name_hotel)
{
	if (login_password.count(name_hotel)) {
		return false;
	}
	return true;
}

bool LoadBase::Exist(std::string& login, std::string& password)
{
	return login_password.at(login) == password;
}

NodeBase* LoadBase::GetNode(std::string login)
{
	return &all_db[login];
}
