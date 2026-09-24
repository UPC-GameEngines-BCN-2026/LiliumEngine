#pragma once

#include "imgui.h"
#include <cstdio>
#include <iostream>
#include <cstdarg>
#include <string>
#include <vector>

#define LOG(format, ...) Console::GetInstance().Log(__FILE__, __LINE__, format, ##__VA_ARGS__) 

class Console 
{
public:

	static Console& GetInstance();

	void Log(const char file[], int line, const char* format, ...);

	void Clear();

	void Draw();

	bool AutoScroll = true;

	bool Open = true;

private:

	std::vector<std::string> entries;
};