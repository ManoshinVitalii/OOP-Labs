#pragma once
#include "Knight.h"
#include "Pegasus.h"
#include "Dragon.h"
#include "Observers.h"

class Factory {
    public:
        static shared_ptr<NPC> Create(const NpcType& type, int x, int y);
};
