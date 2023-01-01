/*
     implemented by : Yousry Essam
     linked in  link : https://www.linkedin.com/in/yousryessam/ 
*/
#include<map>
#include<set>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
set<int>accept;
char alpha1, alpha2;
map<int, pair<int, int>>DFA;// <state number ,< alpha1 go to , alpha2 go to  >
int nodesNumber, finalNodesNumber, initialState;
int DFA_path(string s)
{
    int cur_node = initialState;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == alpha1) cur_node = DFA[cur_node].first;
        else cur_node = DFA[cur_node].second;
    }
    return cur_node;
}
bool is_Accept(int node)
{
    for (auto i : accept) if (node == i) return 1;
    return 0;
}
bool AcceptedString(string str)
{
    for (int i = 0; i < str.size(); i++)
        if (str[i] != alpha1 && str[i] != alpha2)
            return 0;
    return 1;
}
void printLine() { cout << "--------------------------------------------------------------------\n\a"; }
int main()
{
    printLine();
    cout << "Please enter number of nodes in your DFA: \n";
    cin >> nodesNumber;
    printLine();
    cout << "Please enter two input alphabetical OF DFA :\n";
    cin >> alpha1 >> alpha2;
    printLine();
    cout << "Nodes ( States ) created  and it equal = \n";
    for (int i = 1; i <= nodesNumber; i++)
    {
        DFA[i];
        cout << i;
        (i == nodesNumber) ? cout << '\n' : cout << ' ';
    }
    printLine();
    cout << "What is the initial state in this DFA :\n";
    cin >> initialState;
    printLine();
    cout << "What is the number of final states in this DFA :\n";
    cin >> finalNodesNumber;
    printLine();
    for (int i = 0; i < finalNodesNumber; i++)
    {
        cout << "Please enter " << i + 1 << " final state : " << endl;
        int finalState; cin >> finalState;
        if (finalState <= nodesNumber) accept.insert(finalState);
    }
    printLine();
    for (int i = 1; i <= nodesNumber; i++)
    {
        int n1, n2;
        cout << "Node " << i << " at alphabet " << alpha1 << " = ";
        cin >> n1;
        cout << "Node " << i << " at alphabet " << alpha2 << " = ";
        cin >> n2;
        printLine();
        DFA[i].first = n1;
        DFA[i].second = n2;
    }
    vector<int>deadState;
    for (auto i : DFA)
    {
        if (i.second.first == i.second.second && i.second.first == i.first && accept.find(i.first) == accept.end())
            deadState.push_back(i.first);
    }
    if (deadState.size() > 0)
    {
        cout << "Number of dead states = " << deadState.size() << '\n';
        cout << "Dead State are : ";
        for (auto i : deadState)
        {
            cout << i << ' ';
        }
        cout << '\n';
        printLine();
    }
    else
    {
        cout << "There is not dead state in the DFA.\n";
        printLine();
    }
    while (true)
    {
        cout << "Do you want to enter string !?\nEnter y or Y for yes or enter anything to Exit\n";
        char coun; cin >> coun;
        if (coun != 'y' && coun != 'Y') break;
        printLine();
        cout << "Please enter a String :\n";
        string s; cin >> s;
        if (!AcceptedString(s))
        {
            cout << "This invaled string\n";
            printLine();
            continue;
        }
        if (is_Accept(DFA_path(s))) cout << "The string : " << s << " is Accepted one.\n";
        else cout << "The string : " << s << " is Rejected one.\n";
        printLine();
    }
    printLine();
    return 0;
}