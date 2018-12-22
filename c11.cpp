#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void c11_4(string ifname, string ofname)
{
    ifstream ifs{ifname};
    ofstream ofs{ofname};
    map<string, size_t> word_count;
    string word;
    while (ifs >> word)
    {
        for(auto &c: word)
            c = tolower(c);
        if (!isalnum(word.back()))
            word.pop_back();
            //word.erase(word.size() - 1); //同上
        ++word_count[word];
    }
    for (const auto &w : word_count)
        ofs << w.first << " __ " << w.second
            << ((w.second > 1) ? "times" : "time") << endl;
}

void c11_7(){
    map<string, vector<string>> family;
    vector<string> firstname{"chen", "li"};
    vector<string> childname{"jianping", "sibei", "xiaodan"};
    for(const auto fname: firstname){
        family.insert({fname, childname});
    }
    family.insert({"xu", {}});
    family["xu"].push_back("taoying");
    family["chen"].push_back("jianlan");
    for(const auto fm:family){
        cout << fm.first << ':' << endl;
        for (const auto cn: fm.second){
            cout << fm.first << '.' << cn << endl;
        }
        cout << endl;
    }
}
int main(int argc, char const *argv[])
{
    //c11_4("englishtext.txt", "word_count.txt");
    c11_7();
    return 0;
}
