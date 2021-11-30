#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#define MAX_SIZE 10
using namespace std;

class MultiState
{
    char states[MAX_SIZE];
    int length, state;

public:
    MultiState() : state(-1), length(0) {}
    MultiState(char *states, int length) : state(0), length(length)
    {
        memcpy(this->states, states, sizeof(char) * length);
    }
    MultiState(const char *states, int length) : state(0), length(length)
    {
        memcpy(this->states, states, sizeof(char) * length);
    }

    MultiState &setState(int state)
    {
        this->state = state;

        return *this;
    }

    friend ostream &operator<<(ostream &, MultiState &);
};
ostream &operator<<(ostream &os, MultiState &ms)
{
    os << ms.states[ms.state];
    return os;
}

typedef MultiState ms;

void sleep(long long int millis)
{
    std::this_thread::sleep_for(chrono::milliseconds(millis));
}

int main()
{
    bool state = false;

    while (1)
    {
        system("clear");

        cout << ms(" R", 2).setState(state) << ms(" O", 2).setState(state) << ms(" F", 2).setState(state) << ms(" L", 2).setState(state) << ms(" :", 2).setState(state);
        cout << ms(" R", 2).setState(state) << ms(" O", 2).setState(state) << ms(" F", 2).setState(state) << ms(" L", 2).setState(state) << ms(" :", 2).setState(state);
        cout << "LOL:";
        cout << ms("R ", 2).setState(state) << ms("O ", 2).setState(state) << ms("F ", 2).setState(state) << ms("L ", 2).setState(state) << ms(": ", 2).setState(state);
        cout << ms("R ", 2).setState(state) << ms("O ", 2).setState(state) << ms("F ", 2).setState(state) << ms("L ", 2).setState(state) << '\n';
        cout << "           A\n";
        cout << "  " << ms(" L", 2).setState(state) << "    /--------\n";
        cout << " LOL====      []\\\n";
        cout << "  " << ms("L ", 2).setState(state) << "    \\         \\\n";
        cout << "        \\_________]\n";
        cout << "            I    I\n";
        cout << "       ------------/\n";

        state = !state;

        sleep(100);
    }

    return 0;
}