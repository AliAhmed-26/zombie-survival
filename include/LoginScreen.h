#pragma once
#include<string>

class LoginScreen
{
private:
    std::string username;
    std::string password;
    bool usernameActive,passwordActive;
    bool loginSuccessful,registrationSuccessful;
    bool isLoginMode;
public:
    // COntructor
    LoginScreen();

    // HANDLE THE USERNAME AND PASSWORD INPUT
    void handleInput();

    // DRAW THE LOGINSCREEN
    void draw() const;

    // CHECKS WHETHER USNENAME ANS PASSWORD ARE CORRECT OR NOT
    bool validateLogin() const;

    // FOR REGISTRING NEW USER
    bool registerUser();

    // CHECKS WHETHER USER LODDEG IN OR NOT
    bool isLoginSuccessful() const;

    // CHECKS WHETHER THE USER IS REGISTERED OR NOT
    bool isRegistrationSuccessful() const;

    // RETURN THE LOGGEDIN USERNAME
    std::string getLoggedInUsername() const;

};