#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    ifstream file("DATA/kolkata_west_bengal_dijkstra_routes.csv");

    if (!file.is_open()) {
        cout << "Failed to open CSV file" << endl;
        return 1;
    }

    unordered_map<string, int> stationId;

    int nextId = 0;
    string line;

    // Skip header
    getline(file, line);

    while (getline(file, line)) {

        string station1;
        string station2;
        string distance;

        stringstream ss(line);

        getline(ss, station1, ',');
        getline(ss, station2, ',');
        getline(ss, distance, ',');

        if (stationId.find(station1) == stationId.end()) {
            stationId[station1] = nextId++;
        }

        if (stationId.find(station2) == stationId.end()) {
            stationId[station2] = nextId++;
        }
    }

    file.close();

    for (auto x : stationId) {
        cout << x.first << " -> " << x.second << endl;
    }

    return 0;
}