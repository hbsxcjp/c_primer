#include <array>
using std::array;

#include <deque>
using std::deque;

#include <stack>
using std::stack;

#include <forward_list>
using std::forward_list;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <iterator>
using std::begin;
using std::end;

#include <list>
using std::list;

#include <string>
using std::string;

#include <vector>
using std::vector;

list<deque<int>> ldi;

using vi_iter = vector<int>::iterator;
bool find_int(vi_iter ia, vi_iter ib, int v) {
    while (ia != ib) {
        if (*ia == v)
            return true;
        ++ia;
    }
    return false;
}

void c9_4() {
    vector<int> vi{3, 4, 5, 67, 7, 43, 89};
    bool b;
    b = find_int(vi.begin() + 3, vi.end(), 17);
    cout << b << endl;
}

int find_iter(vi_iter ia, vi_iter ib, int v) {
    while (ia != ib) {
        if (*ia == v)
            return *ia;
        ++ia;
    }
    cout << "Not find!" << endl;
    return -1;
}

void c9_5() {
    vector<int> vi{3, 4, 5, 67, 7, 43, 89};
    int ib;
    ib = find_iter(vi.begin() + 3, vi.end(), 17);
    cout << ib << endl;
}

void c9_11() {
    vector<vector<string>> vvs;
    vector<string> vs1;
    vector<string> vs2{"abc", "def", "ghij"};
    vector<string> vs3(vs2);
    vector<string> vs4 = vs3;
    vector<string> vs5(vs4.begin(), vs4.end());
    vector<string> vs6(5);
    vector<string> vs7(6, "Hi");
    vvs.push_back(vs1);
    vvs.push_back(vs2);
    vvs.push_back(vs3);
    vvs.push_back(vs4);
    vvs.push_back(vs5);
    vvs.push_back(vs6);
    vvs.push_back(vs7);
    int i = 0;
    for (auto vs : vvs) {
        cout << "vs" << ++i << ": ";
        for (auto s : vs) {
            cout << s << "_";
        }
        cout << "\n";
    }
}

void c9_13() {
    // list<int> li{2, 3, 5, 6, 7, 8};
    vector<int> li{2, 3, 5, 6, 7, 8};
    vector<double> vd(li.begin(), li.end());
    for (auto s : vd) {
        cout << s << "_";
    }
    cout << "\n";
}

void c9_14() {
    list<char *> lc;
    char cs[] = "abc";
    char cs2[] = "xyz";
    lc.push_back(cs);
    lc.push_back(cs2);
    vector<string> vs;
    vs.assign(lc.begin(), lc.end());
    for (auto s : vs) {
        cout << s << "_";
    }
    cout << "\n";
}

void c9_15() {
    vector<int> vi1{1, 3, 5, 7, 9};
    vector<int> vi2{1, 3, 5, 7, 8};
    if (vi1 < vi2)
        cout << "vi1 is small.";
    else
        cout << "vi2 is small.";
}

string c9_16() {
    list<int> li{1, 3, 5, 7};
    vector<int> vi{1, 3, 5, 7, 8};
    int i = li.size(), j = vi.size();
    int k = i < j ? i : j;
    list<int>::iterator liit = li.begin();
    vector<int>::iterator viit = vi.begin();
    for (int i = 0; i < k; ++i) {
        if (*liit < *viit)
            return "li is small.";
        else if (*liit > *viit)
            return "vi is small.";
        ++liit;
        ++viit;
    }
    if (i < j)
        return "li is small.";
    else if (i > j)
        return "vi is small.";
    else
        return "vi == li.";
}

void c9_18() {
    deque<string> ds; // list<string> ds; // c9_19
    string s;
    while (getline(cin, s)) {
        ds.push_back(s);
    }
    for (auto s : ds) {
        cout << s << "\n";
    }
}

void c9_20() {
    deque<int> di1, di2;
    list<int> li{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : li) {
        if (i % 2)
            di1.push_back(i);
        else
            di2.push_back(i);
    }
    cout << "di1: ";
    for (auto s : di1) {
        cout << s << " ";
    }
    cout << "\ndi2: ";
    for (auto s : di2) {
        cout << s << " ";
    }
}

void c9_24() {
    vector<int> vi{897, 2, 3, 5};
    cout << vi.at(0) << " ";
    cout << vi[0] << " ";
    cout << vi.front() << " ";
    cout << vi.back() << " ";
    cout << *vi.begin() << " ";
    cout << *(vi.end() - 2) << " ";
}

void c9_26() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vi;
    list<int> li;
    int *beg = begin(ia);
    while (beg != end(ia)) {
        vi.push_back(*beg);
        li.push_back(*beg);
        ++beg;
    }
    auto it = vi.begin();
    while (it != vi.end()) {
        if (*it % 2 == 0)
            it = vi.erase(it);
        else
            ++it;
    }
    auto lit = li.begin();
    while (lit != li.end()) {
        if (*lit % 2)
            lit = li.erase(lit);
        else
            ++lit;
    }
    cout << "vi: ";
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << "\nli: ";
    for (auto i : li) {
        cout << i << " ";
    }
}

void c9_29() {
    vector<int> vi(25, 1);
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
    vi.resize(100, -1);
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
    vi.resize(10);
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
}

void c9_34() {
    vector<int> vi{0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            ++iter; // += 2;
        }
        ++iter;
    }
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
}

void c9_38() {
    vector<int> ivec;
    cout << "size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

    for (vector<int>::size_type ix = 0; ix != 20; ++ix) {
        ivec.push_back(ix);
        cout << "size: " << ivec.size() << " capacity: " << ivec.capacity()
             << endl;
    }

    ivec.reserve(50);
    while (ivec.size() != ivec.capacity()) {
        ivec.push_back(0);
    }
    cout << "size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

    ivec.push_back(42);
    cout << "size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;
}

void c9_41() {
    vector<char> vc{'a', 'b', 'c', 'o', 'k'};
    char ac[100];
    int i = 0;
    for (auto c : vc) {
        ac[i] = c;
        ++i;
    }
    ac[i] = 0;
    string s(ac);
    cout << s << endl;
}

void c9_42() {
    char ac[200];
    char c;
    int i = 0;
    while (cin >> c) {
        ac[i] = c;
        ++i;
    }
    ac[i] = 0;

    string s(ac);
    cout << s << endl;
}

void c9_43(string s, string oldVal, string newVal) {
    auto beg = s.begin();
    auto sz = oldVal.size();
    auto nsz = newVal.size();
    cout << s << " | " << oldVal << " | " << newVal << endl;
    while (beg != s.end()) {
        if (s.substr(beg - s.begin(), sz) == oldVal) {
            auto sbeg = s.erase(beg, beg + sz); // 保留指向被删元素之后的迭代器
            auto diff = sbeg - s.begin();
            s.insert(sbeg, newVal.cbegin(), newVal.cend());
            beg = s.begin() + diff + nsz;
        } else {
            ++beg;
        }
    }
    cout << s << endl;
}

void c9_44(string s, string oldVal, string newVal) {
    auto beg = s.begin();
    auto sz = oldVal.size();
    auto nsz = newVal.size();
    cout << s << " | " << oldVal << " | " << newVal << endl;
    while (beg != s.end()) {
        auto diff = beg - s.begin();
        if (s.substr(diff, sz) == oldVal) {
            s.replace(diff, sz, newVal);
            beg = s.begin() + diff + nsz;
        } else {
            ++beg;
        }
    }
    cout << s << endl;
}

string getName(string name, string pre, string last) {
    pre = pre + " ";
    name.insert(name.begin(), pre.cbegin(),
                pre.cend()); // 使用beg迭代器，编译通不过
    name.append(" " + last);
    return name;
}

string getName2(string name, string pre, string last) {
    name.insert(0, pre + " ");
    name.insert(name.size(), " " + last);
    return name;
}

void c9_47() {
    string s("ab2c3d7R4E6");
    string numbers("0123456789"),
        alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string::size_type pos = 0;
    while ((pos = s.find_first_not_of(alpha, pos)) != string::npos) {
        //((pos = s.find_first_of(numbers, pos)) != string::npos) {
        cout << "find number at index: " << pos << " element is " << s[pos]
             << endl;
        ++pos;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
        // ((pos = s.find_first_of(alpha, pos)) != string::npos) {
        cout << "find alpha at index: " << pos << " element is " << s[pos]
             << endl;
        ++pos;
    }
    cout << numbers.find(s) << endl; // cout << string::npos;
}

void c9_49(const string filename) {
    string ascender("bdfhklt"), descender("gjpqy");
    ifstream input(filename);
    int max = 0;
    string word, curword;
    vector<string> vs;
    while (input >> word) {
        // cout << word << endl;
        if (word.find_first_of(ascender) == string::npos &&
            word.find_first_of(descender) == string::npos &&
            word.size() > max) {
            max = word.size();
            curword = word;
            vs.push_back(word);
        };
    }
    for (auto s : vs) {
        cout << s << "\n";
    }
    cout << "\nmax: " << curword << " length: " << max;
}

void c9_50() {
    vector<string> vs{"2", "3", "5", "42"};
    vector<string> vs2{"2.5", "3.1", "5.2", "42.0"};
    int sum = 0;
    double sum2 = 0;
    for (auto s : vs)
        sum += stoi(s);
    cout << "sum: " << sum << endl;
    for (auto s : vs2)
        sum2 += stod(s);
    cout << "sum2: " << sum2 << endl;
}

void c9_52() {
    string s("4(3(12)5)6");
    istringstream is(s);
    char c;
    stack<char> st, rest;
    while (is >> c) {
        if (c == ')') {
            c = st.top();
            while (c != '(') {
                cout << c << " ";
                st.pop();
                c = st.top();
            }
        } else
            st.push(c);
    }
    while (!st.empty()) {
        c = st.top();
        cout << c << " ";
        st.pop();
    }
}

int main(int argc, char const *argv[]) {
    // c9_4();
    // c9_5();
    // c9_11();
    // c9_13();
    // c9_14();
    // c9_15();
    // cout << c9_16();
    // c9_18();
    // c9_20();
    // c9_24();
    // c9_26();
    // c9_29();
    // c9_34();
    // c9_38();
    // c9_41();
    // c9_42();
    // c9_43("tho thru abctho xyzthoru", "tho", "though");
    // c9_44("tho thru abctho xyzthoru", "tho", "though");
    // cout << getName("Chen", "Mr.", "Jian Ping");
    // c9_47();
    // c9_49("c8.cpp");
    // c9_50();
    c9_52();

    return 0;
}