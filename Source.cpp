#include "LinkedList.h"
#include <fstream>
#include <sstream>

void processFile(LinkedList& pq, const std::string& filename) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string category;
        std::string fullName;

        // Read category and full name
        iss >> category;
        std::getline(iss, fullName);

        // Create a Person object and insert into the queue based on priority
        Person person(category, fullName);
        pq.iAM(person);  // Insert at the appropriate position based on priority
    }
}

int main() {
    LinkedList pq;

    // Read from file and enqueue data
    std::string filename = "people.txt";  // Text file with people data
    processFile(pq, filename);

    // Display the priority queue
    std::cout << "Priority Queue after reading from file:" << std::endl;
    pq.traverse();

    

    return 0;
}
