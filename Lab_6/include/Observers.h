#pragma once
#include "NPC.h"

class TextObserver : public ObserverFight {
    private:
        TextObserver() {};
    public:
        static shared_ptr<ObserverFight> get();
        void on_fight(const shared_ptr<NPC>& attacker, const shared_ptr<NPC>& defender, bool win) override;
};

class FileObserver : public ObserverFight {
    private:
        string NPCname(const NpcType& type);
        ofstream fs;
        FileObserver() {};
    public:
        static shared_ptr<ObserverFight> get();
        void on_fight(const shared_ptr<NPC>& attacker, const shared_ptr<NPC>& defender, bool win) override;
};
