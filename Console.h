#pragma once
#include <iostream>
#include <string>

class Console
{
public:

	Console();
	~Console();

public:

	void Info(const char* text);
	void Err(const char* text);
};


