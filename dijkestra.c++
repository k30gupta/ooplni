#include <iostream> // cin, cout
#include <map>
#include <sstream>
#include <string>

using namespace std;

map<pair<int, int>, int> edgeMap;

void createGraph(istream& input)
{
   string temp;
   map<pair<int, int>, int>::iterator edgeMapIterator;

   while (getline(input, temp)) {
      istringstream sin(temp);
      int vertix1, vertix2, value;
      sin >> vertix1 >> vertix2 >> value;
      edgeMapIterator = edgeMap.find(make_pair(vertix1, vertix2));
      if (edgeMapIterator == edgeMap.end())
         edgeMap[make_pair(vertix1, vertix2)] = value;
      else
         if (edgeMapIterator->second > value)
            edgeMap[make_pair(vertix1, vertix2)] = value;
   }

}

int main () {

   createGraph(cin);
   map<pair<int, int>, int>::iterator it;
   for( it=edgeMap.begin(); it != edgeMap.end(); ++it)
      cout << it->second << endl;//(it->first)->first << (it->first)->second << 
   return 0;
}
