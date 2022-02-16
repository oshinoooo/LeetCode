#include <iostream>
#include <memory>

using namespace std;

class task
{
public:
    task(string name) : name(name) {}

    string getTaskName()
    {
        return name;
    }

private:
    string name;
};

class module
{
public:
    module(string name) : name(name) {}

    void getTask(task& t)
    {

    }

    void process()
    {
        cout << this << " processing..." << endl;
    }

private:
    string name;
    mutex mux;
};



int main()
{
    cout << "------------------" << endl;
    for (int i = 0; i < 20; ++i)
    {
        string tmp = "task no: ";
        tmp.push_back(i);

    }

    module m1("stage1");
    module m2("stage2");
    module m3("stage3");
    module m4("stage4");
    module m5("stage5");
    cout << "------------------" << endl;
    return 0;
}
