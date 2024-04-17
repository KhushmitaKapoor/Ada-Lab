#include <iostream>

void moveDisk(int disk, char source, char destination) {
    std::cout << "Move disk " << disk << " from " << source << " to " << destination << std::endl;
}

void towersOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    if (numDisks == 1) {
        moveDisk(1, source, destination);
        return;
    }

    towersOfHanoi(numDisks - 1, source, destination, auxiliary);
    moveDisk(numDisks, source, destination);
    towersOfHanoi(numDisks - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    towersOfHanoi(numDisks, 'A', 'B', 'C');
    
    return 0;
}
