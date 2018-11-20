#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;

istream &c8_1(istream &is) {
    auto old_state = is.rdstate();
    string s;
    while (is >> s) {
        cout << s;
    }
    // is.setstate(old_state);
    return is;
}

void readfile(string fname) {
    ifstream infile(fname);
    ofstream outfile("out_"+fname, ofstream::app);
    string s;
    vector<string> vs;
    while (getline(infile, s)) { //  (infile >> s) { //
        vs.push_back(s);
    }

    for (auto s : vs) {
        outfile << s << "\n";
    }
}

void c8_9() {
    istringstream iss("chen jian ping");
    c8_1(iss);
}

void c8_10(string fname) {
    ifstream infile(fname);
    //ofstream outfile("out_"+fname, ofstream::app);
    string s, word;
    vector<string> vs;
    istringstream iss;

    while (getline(infile, s)) { //  (infile >> s) { //
        vs.push_back(s);
    }
    for (auto s: vs) {
        // istringstream iss(s);
        iss.clear();
        iss.str(s);
        while (iss >> word) {
            cout << word << endl;
        }
    }

}

int main(int argc, char const *argv[]) {
    // c8_1(cin);

    string s;
    for (int i = 0; i < argc; ++i) {
        s = argv[i];
        cout << s << endl;
    }
    //readfile(argv[1]); //"infile.txt"

    //c8_9();
    c8_10("infile.txt");

    return 0;
}