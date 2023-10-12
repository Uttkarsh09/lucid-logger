#include "logger.hpp"

Logger* Logger::logger_= nullptr;

Logger *Logger::GetInstance(const string file_name){
	if(logger_ == nullptr){
		logger_ = new Logger(file_name);
	}
	return logger_;
}

void Logger::deleteInstance(){
	fprintf(fptr, "~~~ Log File Closed ~~~");
	fclose(fptr);
	delete logger_;
	fptr = nullptr;
	logger_ = nullptr;
}


string Logger::getLogLevelName(LogLevel level){
	switch(level){
		case LogLevel::OFF: return "OFF";
		case LogLevel::CRITICAL: return "CRITICAL";
		case LogLevel::ERROR: return "ERROR";
		case LogLevel::WARNING: return "WARNING";
		case LogLevel::INFO: return "INFO";
		case LogLevel::DEBUG: return "DEBUG";
		case LogLevel::ALL: return "ALL";
		default: return "can't happen";
	}
}

void Logger::logIt(LogLevel level, const char * format, ...){
	if(logLevel < level) return;
	
	string levelName = getLogLevelName(level);
	va_list args;

	va_start(args, format);
	fprintf(fptr, "%-9s: ", levelName.c_str());

	vfprintf(fptr, format, args);
	fprintf(fptr, "\n");
	va_end(args);
}

void Logger::setLogLevel(LogLevel level){
	logLevel = level;
}
