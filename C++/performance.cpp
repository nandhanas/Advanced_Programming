#include "BST.h"
#include <chrono>  // time
#include <algorithm> //generate random numbers
#include <map>
#include <unordered_map>
#include <fstream>
using namespace std::chrono;

template<typename key_type, typename value_type>
void BST<key_type,value_type>::performance_BST (vector<key_type> &values){
  auto random = []() -> key_type { return rand() % 10000;};
  generate(values.begin(), values.end(), random);
  for(auto i=values.begin(); i!=values.end();i++) {
    insertNode(pair<key_type,value_type>{*i,*i});
  }
};

template<typename key_type, typename value_type>
void BST<key_type,value_type>::lookup_time_BST (vector<key_type> &values, ofstream &file)
{
  auto start = high_resolution_clock::now();
  for(auto i=values.begin(); i!=values.end();i++) {
    if(findNode(*i) == end()){
      cout<<"Not found";
    }
    else {
      continue;
    }
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  file << "Time taken for "<<values.size()<<" elements :"<< duration.count() << " microseconds" << endl;
}

/**
 *  Templated function to insert random values into a map
 *  @param m map to which values are to be inserted
 *  @param values a vector of random value to be inserted into the given map
 */

template<typename map_key, typename map_value>
void performance_map(map<map_key,map_value> &m, vector<map_key> &values){
  auto random = []() -> map_key { return rand() % 10000;};
  generate(values.begin(), values.end(), random);
  for(auto i=values.begin(); i!=values.end();i++) {
    m.insert({*i,*i});
  }
};

/**
 *  Templated function to insert random values into an unordered map
 *  @param um unordered map to which values are to be inserted
 *  @param values a vector of random value to be inserted into the given unordered map
 */

template<typename map_key, typename map_value>
void performance_map(unordered_map<map_key,map_value> &um, vector<map_key> &values){
  auto random = []() -> map_key { return rand() % 10000;};
  generate(values.begin(), values.end(), random);
  for(auto i=values.begin(); i!=values.end();i++) {
    um.insert({*i,*i});
  }
};

/**
 *  Templated function to estimate the time taken to find a value from the given map
 *  @param m map to which values are to be inserted
 *  @param values a vector of random value to be inserted into the given map
 */

template<typename map_key, typename map_value>
void lookup_time_map(map<map_key,map_value> &m, vector<map_key> &values, ofstream &file) {

  auto start = high_resolution_clock::now();
  for(auto i=values.begin(); i!=values.end();i++) {
    m.find(*i);
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  file << "Time taken for "<<values.size()<<" elements :"<< duration.count() << " microseconds" << endl;
};

/**
 *  Templated function to estimate the time taken to find a value from the given unordered map
 *  @param um unordered map to which values are to be inserted
 *  @param values a vector of random value to be inserted into the given unordered map
 */

template<typename map_key, typename map_value>
void lookup_time_map(unordered_map<map_key,map_value> &um, vector<map_key> &values, ofstream &file) {

  auto start = high_resolution_clock::now();
  for(auto i=values.begin(); i!=values.end();i++) {
    um.find(*i);
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  file << "Time taken for "<<values.size()<<" elements :"<< duration.count() << " microseconds" << endl;
};

int main() {

  ofstream file;
  file.open("benchmark.txt");
  BST<int,int> b1{};
  file<<"Int BST before balancing"<<endl;
  for(int i=1;i<6;i++){
    vector<int> values(2000*i);
    b1.performance_BST(values);
    b1.lookup_time_BST(values,file);
  }
  file<<endl;

  b1.balanceTree();

  file<<"Int BST after balancing"<<endl;
  for(int i=1;i<6;i++){
    vector<int> values(2000*i);
    b1.lookup_time_BST(values,file);
  }
  file<<endl;

  BST<double,double> b2{};
  file<<"Double BST before balancing"<<endl;
  for(int i=1;i<6;i++){
    vector<double> values(2000*i);
    b2.performance_BST(values);
    b2.lookup_time_BST(values,file);
  }
  file<<endl;

  b2.balanceTree();

  file<<"Double BST after balancing"<<endl;
  for(int i=1;i<6;i++){
    vector<double> values(2000*i);
    b2.lookup_time_BST(values,file);
  }
  file<<endl;

  map<int,int> m1;
  file<<"Int Map"<<endl;
  for(int i=1;i<6;i++) {
    vector<int> values(2000*i);
    performance_map(m1,values);
    lookup_time_map(m1,values,file);
  }
  file<<endl;

  unordered_map<int,int> um1;
  file<<"Int Unordered Map"<<endl;
  for(int i=1;i<6;i++) {
    vector<int> values(2000*i);
    performance_map(um1,values);
    lookup_time_map(um1,values,file);
  }
  file<<endl;

  map<double,double> m2;
  file<<"Double Map"<<endl;
  for(int i=1;i<6;i++) {
    vector<double> values(2000*i);
    performance_map(m2,values);
    lookup_time_map(m2,values,file);
  }
  file<<endl;

  unordered_map<double,double> um2;
  file<<"Unordered Double Map"<<endl;
  for(int i=1;i<6;i++) {
    vector<double> values(2000*i);
    performance_map(um2,values);
    lookup_time_map(um2,values,file);
  }
  file<<endl;
  file.close();
}
