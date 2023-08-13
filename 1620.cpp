// complete
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
  map<string, int> dict_name_num; //map의 경우 python의 dictionary와 같이 첫번째 자료로 두번째 자료 탐색 가능 탐색시 log(n)의 시간복잡도 보장
  vector<string> dict_num_name;   //vector로 index를 통하여 상수시간으로 탐색가능

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