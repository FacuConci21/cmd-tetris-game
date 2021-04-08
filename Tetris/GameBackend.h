#pragma once

#include <fstream>
#include <iomanip>

#include "ISlots.h"
#include "json.hpp"
#include "utils.h"


using json = nlohmann::json;


#ifndef GAMEBACKEND_H
#define GAMEBACKEND_H

class GameBackend
{
	ISlot slot;
	json jsonSlotSchema;

public:
	GameBackend(ISlot _slot) : slot(_slot) {};

	~GameBackend() {};

	int SaveGame();
};

#endif // !GAMEBACKEND_H
