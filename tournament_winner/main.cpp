/**
 * A team receives 3 points if it wins and 0 if it loses.
 * Sample Input
 * competitions = [
 *  ["HTML", "C#"],
 *  ["C#", "Python"],
 *  ["Python", "HTML"],
 * ]
 * results = [0, 0, 1]
 * 
 * Sample Output
 * "Python"
 * C# beats HTML, Python beats C#, and Python beats HTML
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int HOME_TEAM_WON = 1;

void updateScores(string team, int points, unordered_map<string, int>& scores) {
    // if the winning team is not registered in the hash table, create an element and initialize it to zero
    // later it will be summed their points
    // otherwise, just add the new points to the current points
    if (scores.find(team) == scores.end())
        scores[team] = 0;

    scores[team] += points;
}

string tournamentWinner(vector<vector<string>>& competitions,
                        vector<int>& results) {
    // Write your code here.
    // O(n) time | O(k) space
    // where n is the number of competitions and k is the number of teams that won at least once
    string currentBestTeam = "";
    unordered_map<string, int> scores = {{currentBestTeam, 0}};

    for (int i = 0; i < competitions.size(); i++) {
        auto result = results[i];
        auto competition = competitions[i];
        auto homeTeam = competition[0];
        auto awayTeam = competition[1];

        auto winningTeam = result == HOME_TEAM_WON ? homeTeam : awayTeam;

        updateScores(winningTeam, 3, scores);

        if (scores[winningTeam] > scores[currentBestTeam]) {
            currentBestTeam = winningTeam;
        }
    }
    
    return currentBestTeam;
}

int main () {
    vector<vector<string>> competitions = {
          {"HTML", "C#"}, {"C#", "Python"}, {"Python", "HTML"}
          };
    vector<int> results = {0, 0, 1};

    string output = tournamentWinner(competitions, results);

    cout << output << endl;
}