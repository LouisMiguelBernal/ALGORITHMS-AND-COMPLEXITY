// Louis Miguel H. Bernal | BCS 32

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate total distance between delivery points

double totalDistance(const vector<pair<int, int>>& points) {
    double total = 0.0; // Initialize total distance
    for (size_t i = 1; i < points.size(); ++i) {
        // Calculate the distance between consecutive points using the Euclidean distance formula
        // d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
        double d = sqrt(pow(points[i].first - points[i-1].first, 2) + 
                        pow(points[i].second - points[i-1].second, 2));
        total += d; // Accumulate the distance
    }
    return total; // Return total distance
}

// Function to calculate the sum of the first N natural numbers

int sumOfNaturalNumbers(int N) {
    // Use the formula S = N(N + 1) / 2 to compute the sum of the first N natural numbers
    // This calculation is done in constant time O(1)
    return (N * (N + 1)) / 2; 
}

int main() {
    // Define delivery points in a 2D space
    vector<pair<int, int>> deliveryPoints = {{0, 0}, {3, 4}, {6, 8}, {10, 10}};
    int N = deliveryPoints.size(); // Get the number of points

    double distance = totalDistance(deliveryPoints); // Calculate total distance
    int sum = sumOfNaturalNumbers(N); // Calculate sum of first N natural numbers

    // Output the results
    cout << "Total distance traveled: " << distance << endl;
    cout << "Sum of the first " << N << " natural numbers: " << sum << endl;

    return 0; // End of program
}
