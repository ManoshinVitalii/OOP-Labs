#include "../headers/Factory.h"

shared_ptr<NPC> Factory::Create(const NpcType& type, int x, int y) {
    shared_ptr<NPC> ans;
    if(type == KnightType) 
        ans = make_shared<Knight>(x, y); 
    if(type == PegasusType) 
        ans = make_shared<Pegasus>(x, y); 
    if(type == DragonType) 
        ans = make_shared<Dragon>(x, y);  
    if(!ans)
        throw invalid_argument("Unknown type of NPC:");
    else {
        ans->subscribe(TextObserver::get());
        ans->subscribe(FileObserver::get());
    }

    return ans;
}
