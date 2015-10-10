#include <iostream> // cin, cout
#include <map>
#include <sstream>
#include <string>
#include <utility> 

using namespace std;

map<int, map <int, int> > graph;

void addValue(int v1, int v2, int value)
{   
    map<int, map <int, int> >::iterator graphIterator;
   map <int, int> tempMap;
   map <int, int>::iterator AdjcList;
	graphIterator = graph.find(v1);
	if (graphIterator == graph.end()){
  	  tempMap[v2] = value;
      graph[v1] = tempMap; 
    }else {
	  AdjcList = graphIterator->second.find(v2);
	
	  if (AdjcList == graphIterator->second.end())
	  	graphIterator->second[v2] = value;
	  else if (AdjcList->second >= value)
	  	graphIterator->second[v2] = value;
	}
}

void createGraph(istream& input)
{
   string temp;
   while (getline(input, temp)) {
      istringstream sin(temp);
      int vertix1, vertix2, value;
      sin >> vertix1 >> vertix2 >> value;
      addValue(vertix1, vertix2, value);
      addValue(vertix2, vertix1, value);
   }
}

int main () {

   createGraph(cin);
   map<int, map <int, int> >::iterator it;
   cout<< "Graph" << endl;
   for( it=graph.begin(); it != graph.end(); ++it){
      cout << it->first << " " << endl;
      map <int, int>::iterator it2;
      for( it2=it->second.begin(); it2 != it->second.end(); ++it2)
         cout << " " << it2->first << " " << it2->second << endl;
   
}
   return 0;
}
