#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Determines the result of a single round
string playRound(string playerMove, string computerMove) {
    if (playerMove == computerMove) return "Draw";
    if ((playerMove == "Rock" && computerMove == "Scissors") ||
        (playerMove == "Paper" && computerMove == "Rock") ||
        (playerMove == "Scissors" && computerMove == "Paper")) {
        return "Player Wins";
    }
    return "Computer Wins";
}

int main() {
    srand(time(0));
    string options[] = {"Rock", "Paper", "Scissors"};
    
    // Using predefined player moves for a live demo
    string playerMoves[] = {"Rock", "Paper", "Scissors", "Rock", "Paper"};
    vector<string> compMoves;
    vector<string> results;
    
    int wins = 0, losses = 0, draws = 0;
    int nRounds = 5;

    for (int i = 0; i < nRounds; i++) {
        string cMove = options[rand() % 3];
        string pMove = playerMoves[i];
        string res = playRound(pMove, cMove);
        
        compMoves.push_back(cMove);
        results.push_back(res);

        if (res == "Player Wins") wins++;
        else if (res == "Computer Wins") losses++;
        else draws++;
    }

    // Print summary table
    cout << left << setw(10) << "Round" << setw(15) << "Player Move" 
         << setw(20) << "Computer Move" << "Result\n";
    cout << string(55, '-') << "\n";
    
    for (int i = 0; i < nRounds; i++) {
        cout << left << setw(10) << ("Round " + to_string(i + 1))
             << setw(15) << playerMoves[i] 
             << setw(20) << compMoves[i] 
             << results[i] << "\n";
    }

    double winPercentage = (static_cast<double>(wins) / nRounds) * 100.0;
    
    cout << "\nFinal Summary (after " << nRounds << " rounds)\n";
    cout << "Wins: " << wins << " | Losses: " << losses 
         << " | Draws: " << draws << " | Win % = " 
         << fixed << setprecision(1) << winPercentage << "%\n";

    return 0;
}