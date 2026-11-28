
#pragma once
#include "raylib.h"
#include <string>
#include <vector>

struct Score
{
    std::string playerName;
    int points;
};

class LeaderBoard
{
private:
    std::vector<Score> scores;

public:
    void addScore(std::string &playerName, int points); // Add a new player's score

    void sortScores(); // Bubble Sorting scores from highest to lowest

    void draw() const; // To Draw leaderboard on screen

    std::vector<Score> &getScores() const; // To return all scores
    void clearScores();                    // Clear all scores
};
