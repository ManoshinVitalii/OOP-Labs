#include "../headers/DataMethods.h"

void DataMethods::saveData(const set<shared_ptr<NPC>>& array, const string& filename) {
    ofstream fs(filename);
    fs << array.size() << endl;
    for (auto& elem : array) 
        elem->save(fs);    
    fs << endl;
    fs.close();
}

set<shared_ptr<NPC>> DataMethods::loadData(const string& filename) {
    set<shared_ptr<NPC>> ans;
    short shtype, count, x, y;

    NpcType type;
    ifstream is(filename);
    if (!(is.good() && is.is_open())) 
        throw invalid_argument("Error opening file");
    is >> count >> shtype >> x >> y;
    type = NpcType(shtype);
    ans.insert(Factory::Create(type, x, y));     
    is.close(); 
    return ans;
}
