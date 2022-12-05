#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <direct.h>

namespace AnthroGDP::Logger {

	enum LOG_LEVEL
	{
		LOG,
		LOG_ERROR,
		LOG_WARNING
	};

	template<typename T> 
	void Log(LOG_LEVEL level, T message, bool saveToFile) {
		std::stringstream messageStream;
		messageStream << message;
		std::string messageString;
		messageString = messageStream.str();

		std::string prepend = "";
		std::string apend = "\n";
		std::string logType = "";

		time_t rawtime;
		struct tm* timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
		std::string date(buffer);
		strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
		std::string timeStamp(buffer);

		switch (level)
		{
		case AnthroGDP::Logger::LOG:
			prepend = "\033[1;37m";
			apend = "\033[0m\n";
			logType = "Log";
			break;

		case AnthroGDP::Logger::LOG_ERROR:
			prepend = "\033[1;31m";
			apend = "\033[0m\n";
			logType = "Error";
			break;

		case AnthroGDP::Logger::LOG_WARNING:
			prepend = "\033[1;33m";
			apend = "\033[0m\n";
			logType = "Warning";
			break;

		default:
			break;
		}

		std::cout << prepend << "[ " << logType << " ]( " << date << " | " << timeStamp << " ) : " << messageString << apend;

		if (saveToFile) {

			
			std::string fileName = "logs/" + date + ".txt";
			_mkdir("logs");
			std::ofstream logFile;
			logFile.open(fileName.c_str(), std::ios::app);
			if (!logFile.is_open()) return;
			logFile << "[ " << logType << " ]( " << date << " | " << timeStamp << " ) : " << messageString << "\n";
		}
	}
	
	

}