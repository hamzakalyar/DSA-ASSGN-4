#include "LinkedList.h"
#include <fstream>
#include <sstream>
using namespace std;

void processFile(LinkedList& pq, const string& filename) 
{
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) 
    {
        istringstream iss(line);
        string category;
        string fullName;

        
        iss >> category;
        getline(iss, fullName);

        
        Person person(category, fullName);
        pq.iAM(person);  
    }
}

int main() 
{
    LinkedList pq;

    string filename = "people.txt";  
    processFile(pq, filename);

    cout << "Priority Queue after reading from file:" << std::endl;
    pq.traverse();

    return 0;
}
