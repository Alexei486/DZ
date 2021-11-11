#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <any>
//nvi

/*
class freebie
{
public:
    void freebies()
    {
        if (!neighbor_notebook()) { return false };
        int current_speed = speed();
    }
    virtual ~freebie() {}
private:
    virtual bool neighbor_notebook() const = 0;
    virtual int speed() const = 0;
};
class matan : public freebie
{
public:
    bool neighbor_notebook() const { return true; }
    int speed() const { return 5; }
    int mem = neighbor_notebook() * speed();
};

class physics : public freebie
{
public:
    bool neighbor_notebook() const { return false; }
    int speed() const { return 8; }
    int mem = neighbor_notebook() * speed();
};

int main()
{
    matan a;
    physics b;
    std::cout << a.speed() << std::endl;
    std::cout << b.speed() << std::endl;
    return 0;
}
*/


//mixin


template<typename D>
class freebie
{
public:
    void do_it()
    {
        if (!static_cast<D*>(this)->neighbor_notebook())
        {
            return 0;
        }
     int current_speed = static_cast<D*>(this)->speed();
    }

};
class matan : public freebie<matan>
{
public:
    bool neighbor_notebook() const { return true; }
    int speed() const { return 5; }
    int mem = speed() * neighbor_notebook();
};
class computer_science : public freebie<computer_science>
{
public:
    bool neighbor_notebook() const { return false; }
    int speed() const { return 8; }
    int mem = speed() * neighbor_notebook();
};


int main()
{
    matan a;
    computer_science b;
    std::cout << a.mem << std::endl;
    std::cout << b.mem << std::endl;
    return 0;
}