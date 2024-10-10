#include <iostream>
using namespace std;

// Function to perform the Tower of Hanoi
void towerOfHanoi(int N, char source, char destination, char buffer) {
    // Base case: If there's only one package, move it directly
    if (N == 1) {
        cout << "Move package 1 from " << source << " to " << destination << endl;
        return;
    }
    
    // Move N-1 packages from source to buffer
    towerOfHanoi(N - 1, source, buffer, destination);
    
    // Move the last package from source to destination
    cout << "Move package " << N << " from " << source << " to " << destination << endl;
    
    // Move the N-1 packages from buffer to destination
    towerOfHanoi(N - 1, buffer, destination, source);
}

// Main function
int main() {
    int N;
    cout << "Enter the number of packages: ";
    cin >> N;
    
    cout << "Sequence of moves to transfer " << N << " packages:\n";
    towerOfHanoi(N, 'A', 'C', 'B');  // A, B and C are names of rods
    
    // The total number of moves required
    cout << "Total number of moves: " << (1 << N) - 1 << endl; // 2^N - 1
    return 0;
}
