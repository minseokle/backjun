// uncomplete
#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int dic_num, qes_num;
  cin >> dic_num >> qes_num;
  map<string, int> dict_name_num;
  vector<string> dict_num_name;

  for (int i = 0; i < dic_num; i++) {
    string name;
    cin >> name;
    dict_name_num.insert(make_pair(name, i));
    dict_num_name.push_back(name);
  }

  for (int i = 0; i < qes_num; i++) {
    string name;
    cin >> name;
    if ('0' <= name[0] && name[0] <= '9') {
      std::cout << dict_num_name[stoi(name) - 1] << '\n';
    } else {
      std::cout << dict_name_num.at(name)+1 << '\n';
    }
  }
}