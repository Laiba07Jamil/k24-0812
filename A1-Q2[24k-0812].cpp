#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Robot {
private:
    string name;
    int hitCount;

public:
    Robot() : name(""), hitCount(0) {}        
    Robot(string robotName) : name(robotName), hitCount(0) {} 

    void hitBall(int &ballX, int &ballY, const string &direction) {
        if (direction == "up") ballY++;
        else if (direction == "down") ballY--;
        else if (direction == "right") ballX++;
        else if (direction == "left") ballX--;
        else return;  // Ignore invalid input
        hitCount++;
    }

    int getHitCount() { return hitCount; }
    string getName() { return name; }
};

class Ball {
private: 
    int x, y;

public:
    Ball() : x(0), y(0) {}

    int getX() { return x; }
    int getY() { return y; }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};

class Goal {
private:
    const int goalX = 3;
    const int goalY = 3;

public:
    bool isGoalReached(int ballX, int ballY) const { 
        return (goalX == ballX && goalY == ballY);
    }
};

class Team {
private:
    string name;
    Robot *robot;

public:
    
    Team() : name(""), robot(nullptr) {} 
    Team(string teamName, Robot *teamRobot) : name(teamName), robot(teamRobot) {}

    string getName() { return name; }

    ~Team() { robot = nullptr; }
};

class Game {
private:
    Team teamOne;
    Team teamTwo;
    Ball ball;
    Goal goal;

public:
    Game(Team t1, Team t2) : teamOne(t1), teamTwo(t2) {} 

    void startGame() {
        cout << "\nGame Started!\n";
        play(&teamOne);
        ball = Ball(); 
        play(&teamTwo);
        declareWinner();
    }

    void play(Team *team) {
        cout << "\n" << team->getName() << " is playing...\n";
        
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            string direction;
            cout << "Ball Position: (" << ball.getX() << ", " << ball.getY() << ") | Move (up, down, left, right): ";
            cin >> direction;
            transform(direction.begin(), direction.end(), direction.begin(), ::tolower);

            int prevX = ball.getX(), prevY = ball.getY();
            team->robot->hitBall(prevX, prevY, direction);
            ball.move(prevX - ball.getX(), prevY - ball.getY());
        }

        cout << team->getName() << " reached the goal in " << team->robot->getHitCount() << " hits.\n";
    }

    void declareWinner() {
        cout << "\nGame Over!\n";
        int hitsOne = teamOne.robot->getHitCount();
        int hitsTwo = teamTwo.robot->getHitCount();

        if (hitsOne < hitsTwo) {
            cout << teamOne.getName() << " wins with " << hitsOne << " hits.\n";
        } else if (hitsTwo < hitsOne) {
            cout << teamTwo.getName() << " wins with " << hitsTwo << " hits.\n";
        } else {
            cout << "It's a tie. Both teams took " << hitsOne << " hits.\n";
        }
    }
};

int main() {
    int userChoice;
    
    while (true) {
        cout << "\nFootball Game Simulation\n";
        cout << "1. Start Game\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            string robotOneName, robotTwoName, teamOneName, teamTwoName;
            cin.ignore();

            cout << "\nTeam 1 - Enter Robot Name: ";
            getline(cin, robotOneName);
            cout << "Enter Team Name: ";
            getline(cin, teamOneName);

            cout << "\nTeam 2 - Enter Robot Name: ";
            getline(cin, robotTwoName);
            cout << "Enter Team Name: ";
            getline(cin, teamTwoName);

            Robot robot1(robotOneName);
            Robot robot2(robotTwoName);

            Team team1(teamOneName, &robot1);
            Team team2(teamTwoName, &robot2);

            Game game(team1, team2);
            game.startGame();
        } 
        else if (userChoice == 2) {
            cout << "Exiting the game...\n";
            return 0;
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

