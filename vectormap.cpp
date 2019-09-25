#include <iostream>
#include <map>

using namespace std;
int main ()
{

    std::map< std::string, std::map<std::string, std::string> > primaryMap;
    std::map<std::string, std::string> innerMap;

    //parse list into store into the map --

    innerMap.insert(std::make_pair("key2", "value2"));
    primaryMap.insert(std::make_pair("key", innerMap));

    std::cout<<primaryMap["key"]["key2"]<<endl;


    // check if the data is there in tha map
    //iterate through list 

    list<string>::iterator it;
    dbList *head = dbListMain;
    dbList *temp = dbListMain;

    while(temp->m_next != NULL){
      //check for temp->key in the map
      if(primaryMap.find(temp->db_GUID) != primaryMap.end()){
        //db_GUID found

      }else{
        //db_GUID not found

      }

    }

    
    
    for( = var in collection)
    {
      /* code */
    }
    

//   std::pair<std::map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( std::pair<char,int>('z',500) );
//   if (ret.second==false) {
//     std::cout << "element 'z' already existed";
//     std::cout << " with a value of " << ret.first->second << '\n';
//   }


//   // showing contents:
//   std::cout << "mymap contains:\n";
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

  return 0;
}