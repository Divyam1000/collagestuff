#include <iostream>
using namespace std;

const int NUM_CANDIDATES = 5;

class Candidate {
public:
    int candidateNumber;
    int votes;

    Candidate() {
        candidateNumber = 0;
        votes = 0;
    }
};

int main() {
    Candidate candidates[NUM_CANDIDATES];
    int spoiltBallotCount = 0;
    int ballot;

    cout << "Enter the ballots (Enter -1 to stop):" << endl;

    while (true) {
        cin >> ballot;

        if (ballot == -1) {
            break;
        }

        if (ballot >= 1 && ballot <= NUM_CANDIDATES) {
            candidates[ballot - 1].votes++;
        } else {
            spoiltBallotCount++;
        }
    }

    cout << "\nVote count for each candidate:" << endl;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        cout << "Candidate " << i + 1 << ": " << candidates[i].votes << " votes" << endl;
    }

    cout << "Spoilt Ballots: " << spoiltBallotCount << endl;

    return 0;
}
