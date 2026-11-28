#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <string>
#include "raylib.h"

//  Shown when the player's health reaches zero. It displays the
//  final score, saves the player's highest score to a file, and
//  offers two buttons: Play Again and Leaderboard.
//
//  It does NOT restart the game or open the leaderboard itself.
//  It only reports which button was clicked; the Game class acts on it.
//
//  How Game will use it:
//      screen.SetFinalScore(score);
//      screen.SaveHighScore(username);          // once, when the game ends
//      screen.Draw();                           // every frame while game over
//      if (screen.IsPlayAgainClicked())   { ResetGame(); screen.ResetButtons(); }
//      if (screen.IsLeaderboardClicked()) { OpenLeaderboard(); screen.ResetButtons(); }

class GameOverScreen
{
private:
    int finalScore;               // score shown on the screen
    bool playAgainClicked;        // true after Play Again is clicked
    bool leaderboardClicked;      // true after Leaderboard is clicked

    Rectangle playAgainButton;    // position and size of Play Again
    Rectangle leaderboardButton;  // position and size of Leaderboard

public:
    // Constructor: score = 0, both flags false, buttons positioned
    GameOverScreen();

    // Receive the final score from Game
    void SetFinalScore(int score);

    // Save or update this player's highest score in the file.
    // Only overwrites an existing entry if the new score is higher.
    void SaveHighScore(const std::string& username);

    // Draws the screen and checks mouse clicks on the buttons.
    // Not const: it updates the button flags.
    void Draw();

    // Button checks (read by Game)
    bool IsPlayAgainClicked() const;
    bool IsLeaderboardClicked() const;

    // Set both button flags back to false
    void ResetButtons();
};

#endif // GAMEOVERSCREEN_H