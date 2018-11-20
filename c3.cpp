#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::toupper;
using std::vector;

void c3_2() {
  string s;
  while (cin >> s) { // getline(cin, s)
    cout << s << endl;
  }
}

void c3_4() {
  string s, t;
  while (cin >> s >> t) { // getline(cin, s)
    if (s == t) {
      cout << "same str" << endl;
    } else if (s > t) {
      cout << s << endl;
    } else {
      cout << t << endl;
    }
    if (s.size() == t.size()) {
      cout << "length is equal" << endl;
    } else if (s.size() < t.size()) {
      cout << t << endl;
    } else {
      cout << s << endl;
    }
  }
}

void c3_5() {
  string s, t;
  while (cin >> t) { // getline(cin, s)
    s += t;
    cout << t << " ";
  }
  cout << s << endl;
}

void c3_6() {
  string s, t;
  while (cin >> s) { // getline(cin, s)
    for (auto &c : s) {
      c = 'X';
    }
    cout << s << endl;
  }
}

void c3_10() {
  string s, t;
  while (getline(cin, s)) { // cin >> s
    t = "";
    for (auto c : s) {
      if (!ispunct(c)) {
        t += c;
      }
    }
    cout << t << endl;
  }
}

void c3_14() {
  int i;
  vector<int> vi;
  while (cin >> i) {
    vi.push_back(i);
  }
  for (auto c : vi) {
    cout << c << " ";
  }
}

void c3_15() {
  string s;
  vector<string> vs;
  while (cin >> s) { // getline(cin, s)
    vs.push_back(s);
  }
  for (auto s : vs) {
    cout << s << "_";
  }
}

void c3_16() {
  vector<int> v1;              // 空，长度0
  vector<int> v2(10);          // 0，长度10
  vector<int> v3(10, 42);      // 42，长度10
  vector<int> v4{10};          // 10，长度1
  vector<int> v5{10, 42};      // 10，42，长度2
  vector<string> v6{10};       // 空字符串，长度10
  vector<string> v7{10, "hi"}; // “hi”，长度10

  if (v1.empty()) {
    cout << "v1 is empty." << endl;
  }
  for (auto i : v2) {
    cout << i << " ";
  }
  cout << endl;
  for (auto i : v3) {
    cout << i << " ";
  }
  cout << endl;
  for (auto i : v4) {
    cout << i << " ";
  }
  cout << endl;
  for (auto i : v5) {
    cout << i << " ";
  }
  cout << endl;
  for (auto s : v6) {
    cout << s << "_";
  }
  cout << endl;
  for (auto s : v7) {
    cout << s << "_";
  }
  cout << endl;
}

void c3_17() {
  string s;
  vector<string> vs;
  while (cin >> s) { // getline(cin, s)
    vs.push_back(s);
  }
  for (auto &s : vs) {
    for (auto &c : s) {
      c = toupper(c);
    }
  }
  for (auto s : vs) {
    cout << s << endl;
  }
}

void c3_19() {
  vector<int> v1 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> v2(10, 42);
  vector<int> v3 = v2;
  vector<int> v4(v1);
  vector<vector<int>> v;
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);
  for (auto vv : v) {
    for (auto i : vv) {
      cout << i << " ";
    }
    cout << endl;
  }
}

void c3_20() {
  int i;
  vector<int> vi;
  while (cin >> i) {
    vi.push_back(i);
  }
  decltype(vi.size()) j, k;
  for (j = 0, k = vi.size(); j < k - 1; j += 2) {
    cout << vi[j] + vi[j + 1] << " ";
  }
  cout << endl;
  for (j = 0, k = vi.size() - 1; j < k; j++, k--) {
    cout << vi[j] + vi[k] << " ";
  }
}

void c3_21() {
  vector<int> v1;              // 空，长度0
  vector<int> v2(10);          // 0，长度10
  vector<int> v3(10, 42);      // 42，长度10
  vector<int> v4{10};          // 10，长度1
  vector<int> v5{10, 42};      // 10，42，长度2
  vector<string> v6{10};       // 空字符串，长度10
  vector<string> v7{10, "hi"}; // “hi”，长度10

  if (v1.begin() == v1.end()) {
    cout << "v1 is empty." << endl;
  }
  for (auto i = v2.cbegin(); i != v2.cend(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
  for (auto i = v3.cbegin(); i != v3.cend(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
  for (auto i = v4.cbegin(); i != v4.cend(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
  for (auto i = v5.cbegin(); i != v5.cend(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
  for (auto s = v6.cbegin(); s != v6.cend(); ++s) {
    cout << *s << "_";
  }
  cout << endl;
  for (auto s = v7.cbegin(); s != v7.cend(); ++s) {
    cout << *s << "_";
  }
  cout << endl;
}

void c3_22() {
  string s;
  vector<string> vs;
  while (cin >> s) { // getline(cin, s)
    vs.push_back(s);
  }
  for (auto si = vs.begin(); si != vs.end(); ++si) {
    for (auto c = si->begin(); c != si->end();
         ++c) { // si是迭代器，因此使用->符号
      *c = toupper(*c);
    }
  }
  for (auto s : vs) {
    cout << s << endl;
  }
}

void c3_23() {
  vector<int> vi;
  for (int i = 1; i < 10; i += 1) {
    vi.push_back(i);
  }
  for (auto it = vi.begin(); it != vi.end(); ++it) {
    *it *= 2;
  }
  for (auto it = vi.begin(); it != vi.end(); ++it) {
    cout << *it << " ";
  }
}

void c3_24() {
  vector<int> vi;
  for (int i = 1; i < 500; i++) {
    vi.push_back(i);
  }
  for (auto it = vi.begin(); it != vi.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  for (auto it = vi.begin(); it != vi.end(); ++it) {
    if ((it + 1) != vi.end())
      cout << *it + *(++it) << " ";
  }
  cout << endl;
  for (auto it = vi.begin(), ie = vi.end() - 1; it != ie; ++it, --ie) {
    cout << *it + *ie << " ";
  }
}

void c3_25() {
  vector<unsigned> grade = {42, 65, 95, 100, 39, 67, 95,
                            76, 88, 76, 83,  92, 76, 93};
  vector<unsigned> scores(11, 0); // 成绩段，每10分一段
  auto st = scores.begin();
  for (auto gt = grade.cbegin(); gt != grade.end(); ++gt) {
    cout << *gt << " ";
    *(st + *gt / 10) += 1;
  }
  cout << endl;
  for (auto s = scores.begin(); s != scores.end(); ++s) {
    cout << *s << " ";
  }
}

void c3_31() {
  const int sz = 10;
  int arr[sz] = {};
  int arr2[sz];
  for (int i = 0; i < sz; i++) {
    arr[i] = i;
  }
  for (int i = 0; i < sz; i++) {
    arr2[i] = arr[i];
  }
  for (int i = 0; i < sz; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  vector<int> vi;
  for (int i = 0; i < sz; i++) {
    vi.push_back(i);
  }
  vector<int> vi2 = vi;
  for (auto i : vi2) {
    cout << i << " ";
  }
  cout << endl;
}

void c3_41() {
  int ai[10] = {2, 4, 5, 7, 8};
  int ai2[10];
  vector<int> vi(begin(ai), end(ai));
  for (auto i : vi) {
    cout << i << " ";
  }
  cout << endl;

  for (int i = 0; i < vi.size(); i++) {
    ai2[i] = vi[i];
  }
  for (int i = 0; i < 10; i++) {
    cout << ai2[i] << " ";
  }
}

int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
void c3_43() {
  // 迭代模式
  for (int(&p)[4] : ia) {
    for (int q : p) {
      cout << q << " ";
    }
    cout << endl;
  }
  cout << endl;

  // 下标模式
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cout << ia[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // 指针模式
  for (int(*p)[4] = ia; p != ia + 3; p++) {
    for (int *q = *p; q != *p + 4; q++) {
      cout << *q << " ";
    }
    cout << endl;
  }
}

using ia_4 = int[4];
void c3_44() {
  // 迭代模式
  for (ia_4 &p : ia) {
    for (int q : p) {
      cout << q << " ";
    }
    cout << endl;
  }
  cout << endl;

  // 指针模式
  for (ia_4 *p = ia; p != ia + 3; p++) {
    for (int *q = *p; q != *p + 4; q++) {
      cout << *q << " ";
    }
    cout << endl;
  }
}

void c3_45() {
  // 迭代模式
  for (auto &p : ia) {
    for (auto q : p) {
      cout << q << " ";
    }
    cout << endl;
  }
}

int main() {
  // c3_2();
  // c3_4();
  // c3_5();
  // c3_6();
  // c3_10();
  // c3_14();
  // c3_15();
  // c3_16();
  // c3_17();
  // c3_19();
  // c3_20();
  // c3_20();
  // c3_21();
  // c3_22();
  // c3_23();
  // c3_24();
  // c3_25();
  // c3_31();
  // c3_41();
  // c3_43();
  // c3_44();
  c3_45();

  return 0;
}