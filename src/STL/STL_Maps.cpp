 /*Ordered Map (std::map)*/
/*Stores key-value pairs in sorted order by key (ascending by default).
Internally implemented as a balanced binary search tree (usually a Red-Black tree).*/


#include<iostream>
#include<map>
#include<cstring>
using namespace std;

int main()
{
    map<string, string> fruits;
    fruits.insert(pair<string, string>("strawberry", "die Erdbeere"));
    fruits.insert(pair<string, string>("ornage", "die orange, die Apfelsine"));
    fruits.insert(pair<string, string>("Apple", "die Apfel"));
    fruits.insert(pair<string, string>("Banana", "die Banana"));
    
    for(auto pair: fruits)
        cout<<pair.first<<"-"<<pair.second<<endl;
    system("pause>0");
}


/*Unordered Map (std::unordered_map)
Defined in: <unordered_map>

Stores key-value pairs in no particular order (unordered).

Internally implemented as a hash table. */

#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

int main()
{
    unordered_map<string, string> fruits_unordered;
    fruits_unordered.insert({"strawberry", "die Erdbeere"});
    fruits_unordered.insert({"ornage", "die orange, die Apfelsine"});
    fruits_unordered.insert({"Apple", "die Apfel"});
    fruits_unordered.insert({"Banana", "die Banana"});
    
    for (auto &pair : fruits_unordered)
        cout<<pair.first<<"-"<<pair.second<<endl;
    system("pause>0");
}