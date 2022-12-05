#include "DataCache.h"
#include "Logger.h"
#include <sstream>

using namespace AnthroGDP;

DataCache::DataCache()
{
}

DataCache::~DataCache()
{
}

template<typename T>
nlohmann::json* DataCache::SearchCache(T searchValue) {


	std::stringstream searchStream; 
	searchStream << searchValue;
	std::string searchString;
	searchStream >> searchString;
	
	


}
