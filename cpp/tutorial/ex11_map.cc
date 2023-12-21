#include <iostream>
#include <map>

using namespace std;
#if 0
int main() {
  map<string, int> M;

  M["Top"] = 1;
  M["Coder"] = 2;
  M["SRM"] = 10;

  int x = M["Top"] + M["Coder"];
  cout << "x = " << x << endl;

  cout << "Traversing map M:" << endl;
  for(const auto& element : M) {
    cout << "   " << element.first << " => "<< element.second << endl;
  }

  if (M.find("SRM") != M.end()) {
    cout << "Found and erase it" << endl;
    M.erase("SRM");
  }

  map<string, int>::iterator found;
  found = M.find("Nothing");
  if (found != M.end()) {
    M.erase(found);
  }
  for (const auto& element : M) {
    cout << "   " << element.first << " => "<< element.second << endl;
  }

  return 0;
}
#endif

int main() {
  // Initializer list invovles creating and move the temporary object
  // of each key-value pair into the map.
  // std::map<std::string, int> M = {
  //   {"Top", 1},
  //   {"Coder", 2},
  //   {"SRM", 10}
  // };
  // The emplace function is used to insert elements into the map in-place,
  // without creating temporary objects
  map<string, int> M;

  M.emplace("Top", 1);
  M.emplace("Coder", 2);
  M.emplace("SRM", 3);

  int x = M["Top"] + M["Coder"];
  cout << "x = " << x << endl;

  cout << "Traversing map M:" << endl;
  for (const auto& [key, value] : M) {
    cout << "   " << key << " => " << value << endl;
  }

  if (auto found = M.find("SRM"); found != M.end()) {
    cout << "Found and erase it" << endl;
    M.erase(found);
  }

  if (auto found = M.find("Nothing"); found != M.end()) {
    M.erase(found);
  }

  for (const auto& [key, value] : M) {
    cout << "   " << key << " => " << value << endl;
  }

  return 0;
}
