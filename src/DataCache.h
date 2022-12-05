#pragma once
#include<map>
#include<string>
#include "../include/jsoncpp/json.hpp"

namespace AnthroGDP {

	class DataCache {

		std::map<std::string, nlohmann::json*> Cache;

		DataCache();
		~DataCache();

		void CacheJSONObject();
		void DeCacheJSONObject();


		template<typename T>
		nlohmann::json* SearchCache(T searchValue);

	};

}
