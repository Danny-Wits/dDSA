#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class State;
State *currentState;
class State
{
public:
    char state;
    string name;
    unordered_map<char, State *> linked_states;
    State(string name, char state = 'a') : state(state), name(name) {};

    void addState(char c, State *state)
    {
        linked_states[c] = state;
    }
    void addAllStates(unordered_map<char, State *> states)
    {
        for (auto &statePair : states)
        {
            linked_states.insert(statePair);
        }
    }
    void receive(char state)
    {
        this->state = state;
    }
    void sendTo(State *s)
    {
        s->receive(state);
    }
    void compute()
    {
        for (auto statePair : linked_states)
        {
            if (statePair.first == state)
            {
                sendTo(statePair.second);
                currentState = statePair.second;
                break;
            }
        }
    }
    string getStates()
    {
        string s = "[ ";
        for (auto &statePair : linked_states)
        {
            s += string(1, statePair.first) + ":" + statePair.second->name + ",";
        }
        s = s.substr(0, s.size() - 1) + "]";
        return s;
    }
    void print()
    {
        cout << name << " State: " << state << "  Linked States : " << getStates() << "\n";
    }
};

void printAll(vector<State> &v)
{
    cout << "[\n";
    for (auto &i : v)
    {
        i.print();
    }
    cout << "]\n";
}
int main()
{
    string s = "aabacaabbbccabc";
    vector<State> automata;
    State s4("final");
    State s3("s3");
    State s2("s2");
    State s1("start");
    s4.addAllStates({{'a', &s4}, {'b', &s4}, {'c', &s4}});
    s3.addAllStates({{'a', &s2}, {'b', &s1}, {'c', &s4}});
    s2.addAllStates({{'a', &s2}, {'b', &s3}, {'c', &s1}});
    s1.addAllStates({{'a', &s2}, {'b', &s1}, {'c', &s1}});
    s1.print();
    automata.push_back(s1);
    automata.push_back(s2);
    automata.push_back(s3);
    automata.push_back(s4);
    currentState = &s1;
    char _;
    for (char c : s)
    {
        currentState->receive(c);
        // cout << "Current : ";
        // currentState->print();
        // printAll(automata);
        currentState->compute();
        cout << "\nCurrent : ";
        currentState->print();
        // scanf("%c", &_);
    }
    if (currentState == &s4)
    {
        cout << "Pattern was found";
    }
    else
    {
        cout << "Pattern was not found";
    }

    return 0;
}