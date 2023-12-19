#pragma once
#include "Knight.h"
#include "Pegasus.h"
#include "Dragon.h"
#include "Factory.h"

class DataMethods {
    public:
        static void saveData(const set<shared_ptr<NPC>>& array, const string& filename);
        static set<shared_ptr<NPC>> loadData(const string& filename);
};
