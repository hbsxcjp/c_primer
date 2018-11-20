#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class Person {
    friend std::ostream &print(std::ostream &, const Person &);
    friend std::istream &read(std::istream &, Person &);

  public:
    Person() = default;
    Person(const string &s) : name(s) {}
    Person(const string &sn, const string &sa) : name(sn), address(sa) {}
    string getName() const { return name; };
    string getAddress() const { return address; };

  private:
    string name;
    string address;
};

std::ostream &print(std::ostream &, const Person &);
std::istream &read(std::istream &, Person &);

std::ostream &print(std::ostream &os, const Person &per) {
    os << per.getName() << " " << per.getAddress();
    return os;
}
std::istream &read(std::istream &is, Person &per) {
    is >> per.name >> per.address;
    return is;
}

class Screen {
  public:
    friend class Window_mgr;
    // friend Window_mgr::clear(ScreenIndex); // 先后次序有问题！
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}
inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}
inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

class Window_mgr {
  public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

  private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

class Y;

class X {
    Y *y;
};

class Y {
    X x;
};

class Sales_data {
  public:
    Sales_data(string s, unsigned cnt, double price)
        : bookNo(s), units_sold(cnt), revenue(cnt * price) {
        cout << "This three args!\n";
    }
    Sales_data() : Sales_data("", 0, 0) { cout << "This none args!\n"; }
    Sales_data(string s) : Sales_data(s, 0, 0) { cout << "This one args!\n"; }
    Sales_data(std::istream &is): Sales_data() {
        double price;
        is >> bookNo >> units_sold >> price;
        revenue = units_sold * price;
        cout << "This cin args!\n";
    }

  private:
    string bookNo;
    unsigned units_sold;
    double revenue;
};

class Example {
    public:
    static constexpr double rate = 6.5;
    static constexpr int vecSize = 20;
    static vector<double> vec; //int(vecSize)
};
constexpr double Example::rate;
vector<double> Example::vec(vecSize);

int main() {
    /*
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    */
    Sales_data s1("s1", 1, 2.5);
    cout << "\n";
    Sales_data s2;
    cout << "\n";
    Sales_data s3("s3");
    cout << "\n";
    Sales_data s4(cin);

    return 0;
}