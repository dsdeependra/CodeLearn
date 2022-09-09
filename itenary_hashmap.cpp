#include<iostream>
#include<cstring>
#include<map>

using namespace std;

void printItenary(map<string,string> data){
    //find the starting point in map, for that we need to create the reversemap
    map<string, string> reverseMap;
    map<string, string>::iterator it;

    for(it = data.begin();it != data.end();it++){
        reverseMap[it->second] = it->first;
    }
    string start;

    for(it = data.begin(); it !=data.end();it++){
        if(reverseMap.find(it->first) == reverseMap.end()){
            start = it->first;
            break;
        }
    }

    //now print the result;

    it = data.find(start);
    while(it != data.end()){
        cout<<it->first<<"-> "<<it->second<<endl;
        it = data.find(it->second);
    }    
}

int main(){
    map<string,string> data;
    data["chennai"] = "Bangalore";
    data["Bombay"] = "Delhi";
    data["Goa"] = "Chennai";
    data["Delhi"] = "Goa";

    printItenary(data);
    return 0;
}
