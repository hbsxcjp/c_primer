#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void c10_1() {
    vector<int> vi{2, 3, 5, 7, 8, 3, 5, 5};
    int ct = count(vi.begin(), vi.end(), 5);
    cout << ct << endl;
}

void c10_2() {
    list<string> vi{"abc", "xyz", "chen", "chen"};
    int ct = count(vi.begin(), vi.end(), "abc");
    cout << ct << endl;
}

void c10_3() {
    vector<int> vi{2, 3, 5, 7, 28, 3, 5, 5};
    int sum = accumulate(vi.begin(), vi.end(), 0);
    cout << sum << endl;
}

void c10_4() {
    vector<double> vi{2, 3, 5, 7, 28.5, 3, 5.3, 5};
    double sum = accumulate(vi.cbegin(), vi.cend(), 0.0);
    cout << sum << endl;
}

void c10_5() {
    // vector<string> vs{"abc", "xyz"};
    vector<const char *> vs{"abc", "xyz"};
    list<const char *> ls{"abc", "xyzq"};
    bool res;
    res = equal(vs.cbegin(), vs.cend(), ls.cbegin());
    cout << res << endl;
}

void c10_6() {
    vector<int> vec;
    // vec.reserve(10);
    // cout << vec.size();
    fill_n(back_inserter(vec), 10, 0);
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void c10_9() {
    vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                         "over", "the",   "slow", "red", "turtle"};
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    for (auto &s : words)
        cout << s << " ";
    cout << endl;
}

bool fiveUp(const string s) { return s.size() >= 5; }

void c10_13() {
    vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                         "over", "the",   "slow", "red", "turtle"};
    auto end_fiveUp = partition(words.begin(), words.end(), fiveUp);
    for (auto beg = words.begin(); beg != end_fiveUp; ++beg)
        cout << *beg << " ";
    cout << endl;
    for (auto end = words.end(); end != end_fiveUp; ++end_fiveUp)
        cout << *end_fiveUp << " ";
    cout << endl;
}

void c10_14() {
    auto sum = [](int x, int y) { return x + y; };
    cout << sum(3, 9) << endl;
    int a = 9;
    auto add = [a](int b) { return a + b; };
    cout << add(8) << endl;
}

void c10_20() {
    vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                         "over", "the",   "slow", "red", "turtle"};
    int cnt = count_if(words.begin(), words.end(),
                       [](string s) -> int { return s.size() >= 6; });
    cout << cnt << endl;
}

void c10_21() {
    int c = 16;
    auto dec = [&c]() -> bool {
        cout << c << " ";
        return c > 0 ? c-- : 0;
    };
    while (c > 0) {
        dec();
    }
    cout << endl;
    dec();
}

void c10_27() {
    list<int> ls;
    vector<int> vi{1, 3, 5, 7, 9, 1, 2, 3, 4, 5};
    sort(vi.begin(), vi.end());
    auto e = unique(vi.begin(), vi.end());
    vi.erase(e, vi.end());
    unique_copy(vi.cbegin(), vi.cend(), inserter(ls, ls.begin()));
    for (auto i : ls) {
        cout << i << " ";
    }
}

void c10_28() {
    list<int> ls1 = {10}, ls2 = {10}, ls3 = {10};
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    copy(vi.cbegin(), vi.cend(), back_inserter(ls2));
    for (auto i : ls2) {
        cout << i << " ";
    }
    cout << endl;
    copy(vi.cbegin(), vi.cend(),
         inserter(ls1, ls1.begin())); //  插入后，迭代器递增1
    for (auto i : ls1) {
        cout << i << " ";
    }
    cout << endl;
    copy(vi.cbegin(), vi.cend(), front_inserter(ls3));
    for (auto i : ls3) {
        cout << i << " ";
    }
}

void c10_29() {
    ifstream ifs{"infile.txt"};
    istream_iterator<string> in_iter(ifs), eof;
    vector<string> vs(in_iter, eof); // 从流迭代器构造向量
    ostream_iterator<string> out_iter(cout, " _ ");
    copy(vs.begin(), vs.end(), out_iter); // 拷入输出流迭代器
}

void c10_30() {
    istream_iterator<int> in(cin), eof;
    vector<int> vi(in, eof);
    sort(vi.begin(), vi.end());
    ostream_iterator<int> out(cout, " ");
    // copy(vi.cbegin(), vi.cend(), out);
    unique_copy(vi.cbegin(), vi.cend(), out); // c10_31
}

void c10_33(string iname, string oname1, string oname2) {
    ifstream ifs(iname);
    ofstream o1(oname1), o2(oname2);
    istream_iterator<int> iit(ifs), eof;
    ostream_iterator<int> oit1(o1, " "), oit2(o2, "\n");
    vector<int> vi(iit, eof);
    for (auto i : vi) {
        cout << i << " ";
        if (i % 2)
            *oit1++ = i;
        else
            *oit2++ = i;
    }
}

void c10_34() {
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    ostream_iterator<int> oi(cout, " ");
    // copy(vi.crbegin(), vi.crend(), oi);
    for (auto it = vi.end() - 1; it != vi.begin(); --it) { // c10_35
        cout << *it << " ";
    }
    cout << *(vi.begin());
}

void c10_36() {
    list<int> li{1, 2, 3, 4, 5, 0, 6, 7, 8, 9};
    auto i0 = find(li.crbegin(), li.crend(), 0);
    for (auto it = i0.base(); it != li.cend(); ++it) {
        cout << *it << " ";
    }
}

void c10_37() {
    vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> li(vi.crend() - 8, vi.crend() - 3);
    for (auto i : li) {
        cout << i << " ";
    }
}

void elimDups2(list<string> &words) {
    words.sort();
    words.unique();
}

void c10_42() {
    list<string> words{"the",  "quick", "red",  "fox", "jumps",
                       "over", "the",   "slow", "red", "turtle"};
    elimDups2(words);
    words.sort(isShorter);
    for (auto &s : words)
        cout << s << " ";
    cout << endl;
}

int main(int argc, char const *argv[]) {
    // c10_1();
    // c10_2();
    // c10_3();
    // c10_4();
    // c10_5();
    // c10_6();
    c10_9();
    // c10_13();
    // c10_14();
    // c10_20();
    // c10_21();
    // c10_27();
    // c10_28();
    // c10_29();
    // c10_30();
    // c10_33("infile.txt", "out1.txt", "out2.txt");
    // c10_34();
    // c10_36();
    // c10_37();
    c10_42();

    return 0;
}