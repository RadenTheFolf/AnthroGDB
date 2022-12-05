#pragma once
#include <string>
#include <map>

const int CACHE_SIZE = 32;

class SimpleDB
{
	std::map<std::string, std::string> writeThroughCache;
	std::map<std::string, std::string> readThroughCache;


	SimpleDB();
	~SimpleDB();





};

