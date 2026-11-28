#include "GameOverScreen.h"
#include <fstream>
#include <vector>
#include <utility>
#include <string>

// File used for saving scores. One line per player: "<name> <score>"
// Relative path: the file is created in the folder the game runs from.
static const char* HIGHSCORE_FILE = "highscores.txt";

GameOverScreen::GameOverScreen()
    : finalScore(0),
      playAgainClicked(false),
      leaderboardClicked(false),
      playAgainButton({0, 0, 220, 55}),
      leaderboardButton({0, 0, 220, 55}) {}
      // Real button positions are set in Draw(), because the window
      // may not exist yet when this constructor runs.

void GameOverScreen::SetFinalScore(int score)
{
    finalScore = score;
}

void GameOverScreen::SaveHighScore(const std::string& username)
{
    if (username.empty()) return;

    // 1. Read all existing entries
    std::vector<std::pair<std::string, int>> entries;
    std::ifstream in(HIGHSCORE_FILE);
    std::string line;
    while (std::getline(in, line))
    {
        if (!line.empty() && line.back() == '\r') line.pop_back();  // Windows line ending

        size_t pos = line.rfind(' ');       // score is the LAST token, so names can have spaces
        if (pos == std::string::npos) continue;  // skip broken lines

        try
        {
            entries.push_back({line.substr(0, pos), std::stoi(line.substr(pos + 1))});
        }
        catch (...) { continue; }           // score was not a number, skip the line
    }
    in.close();

    // 2. Find this player
    bool found = false;
    bool changed = false;
    for (auto& e : entries)
    {
        if (e.first == username)
        {
            found = true;
            if (finalScore > e.second)      // only update if strictly higher
            {
                e.second = finalScore;
                changed = true;
            }
            break;
        }
    }

    // 3. New player: add an entry
    if (!found)
    {
        entries.push_back({username, finalScore});
        changed = true;
    }

    // 4. Rewrite the file only if something changed
    if (!changed) return;

    std::ofstream out(HIGHSCORE_FILE, std::ios::trunc);
    for (const auto& e : entries)
        out << e.first << " " << e.second << "\n";
}

void GameOverScreen::Draw()
{
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    // Position the buttons (centered, under the score)
    playAgainButton.x   = sw / 2.0f - playAgainButton.width / 2.0f;
    playAgainButton.y   = sh / 2.0f + 20;
    leaderboardButton.x = sw / 2.0f - leaderboardButton.width / 2.0f;
    leaderboardButton.y = playAgainButton.y + playAgainButton.height + 20;

    // Dark overlay over the game
    DrawRectangle(0, 0, sw, sh, Fade(BLACK, 0.75f));

    // Title
    const char* title = "GAME OVER";
    int titleSize = 60;
    DrawText(title, sw / 2 - MeasureText(title, titleSize) / 2, sh / 2 - 160, titleSize, RED);

    // Final score
    const char* scoreText = TextFormat("Final Score: %d", finalScore);
    int scoreSize = 30;
    DrawText(scoreText, sw / 2 - MeasureText(scoreText, scoreSize) / 2, sh / 2 - 70, scoreSize, WHITE);

    // Mouse state
    Vector2 mouse = GetMousePosition();
    bool click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    bool overPlay = CheckCollisionPointRec(mouse, playAgainButton);
    bool overBoard = CheckCollisionPointRec(mouse, leaderboardButton);

    // Play Again button
    DrawRectangleRec(playAgainButton, overPlay ? GREEN : DARKGREEN);
    DrawRectangleLinesEx(playAgainButton, 2, WHITE);
    const char* t1 = "Play Again";
    DrawText(t1,
             (int)(playAgainButton.x + playAgainButton.width / 2 - MeasureText(t1, 24) / 2),
             (int)(playAgainButton.y + playAgainButton.height / 2 - 12), 24, WHITE);

    // Leaderboard button
    DrawRectangleRec(leaderboardButton, overBoard ? SKYBLUE : DARKBLUE);
    DrawRectangleLinesEx(leaderboardButton, 2, WHITE);
    const char* t2 = "Leaderboard";
    DrawText(t2,
             (int)(leaderboardButton.x + leaderboardButton.width / 2 - MeasureText(t2, 24) / 2),
             (int)(leaderboardButton.y + leaderboardButton.height / 2 - 12), 24, WHITE);

    // Set the flags (Game reads them, then calls ResetButtons)
    if (click && overPlay)  playAgainClicked = true;
    if (click && overBoard) leaderboardClicked = true;
}

bool GameOverScreen::IsPlayAgainClicked() const   { return playAgainClicked; }
bool GameOverScreen::IsLeaderboardClicked() const { return leaderboardClicked; }

void GameOverScreen::ResetButtons()
{
    playAgainClicked = false;
    leaderboardClicked = false;
}