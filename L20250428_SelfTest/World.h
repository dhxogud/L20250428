#pragma once
#include <string>

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();
	void Tick();
	void Load(const std::string fileName);
};

