/*
Eduardo Murillo
Arcade Game Simulator 
Final Version
*/

#include <fstream>
#include "RenderWindow.h"
#include "Textures.h"
#include "Entity.h"
#include "Space.h"
#include "Laser.h"
#include "Asteroids.h"
#include "Scores.h"
#include "Number.h"
#include "Enemies.h"

using namespace std;

bool isRunning = true;

//counters
int timer;
int currentScore;
int x; //counter
int leaderBoardY;
int t; //counter
int p = 0;//counter
int f = 0;
int j = 0;
int counterGameOver;
int ghostCounter; 

RenderWindow window;
Textures playOption;
Textures LeaderBoardOption;
Textures Game1Option;
Textures Game2Option;
Textures Game3Option;
Textures backButton;
Textures pauseButton;
Textures goBackButton;
Textures keepPlayingButton;
Textures pauseMenu;
TTF_Font* Font;
SDL_Color white = { 255,255,255 };
SDL_Color black = { 0,0,0 };



Textures background1;
Textures background2;
Textures background3;
Textures losingScreen;

Textures submitButton;
Textures clearButton;
Textures nextButton;
bool nextNum = false;
Number Num;
int numSpot;

Space SpaceShip;
Laser laser;
Space SpaceHub;
Asteroids asteroid1;
Asteroids asteroid2;
Asteroids asteroid3;
Asteroids asteroid4;
Asteroids asteroid5;
Asteroids asteroid6;
Asteroids asteroid7;
Asteroids asteroid8;
Asteroids asteroid9;
bool shipHit = false;
bool lose = false;

Textures house;
Enemies ghost1;
Enemies ghost2;
Enemies ghost3;
Enemies ghost4;
Enemies ghost5;
Enemies ghost6;
Enemies ghost7;
Enemies ghost8;


fstream ScoreList;

vector<Score> scores(11);
string name;
int game;
int score;
char nameChar;
string userName;

const int windowX = RenderWindow::WindowX;
const int windowY = RenderWindow::WindowY;
bool mainMenu = true;
bool play = false;
bool leaderBoard = false;
bool coveringSign = false;
bool collectingNumber = true;
bool game1 = false;
bool game2 = false;
bool game3 = false;
bool pause = false;
bool shoot = false;
string userInput;
string userGuess;

vector<string>messages(10);




void init() {
    TTF_Init();

    //loading in all textures at beginning of run
  
    window.init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowX, windowY, 0);
    playOption.texture = playOption.createTexture("OutsideFolder/PlayButton.png", 100, (windowY / 2 - 150), 600, 125);
    LeaderBoardOption.texture = LeaderBoardOption.createTexture("OutsideFolder/LeaderBoardButton.png", 100, (windowY / 2), 600, 125);
    pauseMenu.texture = pauseMenu.createTexture("OutsideFolder/pauseMenu.png", 200, windowY - 525, 425, 325);
    keepPlayingButton.texture = keepPlayingButton.createTexture("OutsideFolder/noButton.png", (static_cast<int>(pauseMenu.getxPos()) + 50), (static_cast<int>(pauseMenu.getyPos()) + pauseMenu.getSrcHeight()) - 75, 125, 50);
    goBackButton.texture = goBackButton.createTexture("OutsideFolder/yesButton.png", (static_cast<int>(pauseMenu.getxPos()) + 250), (static_cast<int>(pauseMenu.getyPos()) + pauseMenu.getSrcHeight()) - 75, 125, 50);
    losingScreen.texture = losingScreen.createTexture("OutsideFolder/losingScreen.png", 0, 0, windowX, windowY);

    Font = TTF_OpenFont("OutsideFolder/PixelFont.ttf", 25);

    Game1Option.texture = Game1Option.createTexture("OutsideFolder/numberGuessGame.png", 50, (windowY / 3 - 125), 700, 100);
    Game2Option.texture = Game2Option.createTexture("OutsideFolder/spaceGameOption.png", 50, (windowY / 3 + 15), 700, 100);
    Game3Option.texture = Game3Option.createTexture("OutsideFolder/ghostShooterGame.png", 50, (windowY / 3 + 150), 700, 100);
    backButton.texture = backButton.createTexture("OutsideFolder/backButton.png", 10, 10, 100, 25);
    pauseButton.texture = pauseButton.createTexture("OutsideFolder/makeshiftPause.png", 10, 10, 100, 50);


    background1.texture = background1.createBackground("gameOne/pinkBackground.png");
    background2.texture = background2.createBackground("SpaceGame/spaceBackground.png");
    background3.texture = background3.createBackground("TargetShooter/grass2.png");

    clearButton.texture = clearButton.createTexture("gameOne/clearButton.png", 600, 450, 100, 50);
    submitButton.texture = submitButton.createTexture("gameOne/submitButton.png", 600, 500, 100, 50);
    nextButton.texture = nextButton.createTexture("gameOne/nextButton.png", 600, 550, 100, 50);
    messages[1] = "Guess the number";
    messages[2] = "The number is:";
    messages[3] = "You guessed:";
    messages[4] = "You guessed wrong";
    messages[5] = "You guessed correct";
    messages[6] = "Out of bounds";
    messages[7] = "You Lose!";

SpaceShip.texture = SpaceShip.createTexture(Textures::createEntityTex("SpaceGame/Spaceship.png"), static_cast<float>((windowX/2)), static_cast<float>((windowY - 250)), 100, 50);
 SpaceHub.texture = SpaceHub.createTexture(Textures::createEntityTex("SpaceGame/spaceHub.png"), static_cast<float>(0), static_cast<float>(windowY - 200), 200, windowX);
 laser.texture = laser.createTexture(Textures::createEntityTex("SpaceGame/laser.png"), (SpaceShip.getXPos() + SpaceShip.srcW / 2), SpaceShip.getYPos(), 20, 5);

 asteroid1.texture = asteroid1.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"),50, 10, 25, 25);
 asteroid2.texture = asteroid2.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"), 200, 10, 30, 30);
 asteroid3.texture = asteroid3.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"), 400, 10,20 , 20);
 asteroid4.texture = asteroid4.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"), 500, 10, 50, 50);
 asteroid5.texture = asteroid5.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"), 300, 10, 60, 60);
 asteroid6.texture = asteroid6.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"), 600, 10, 40, 40);
 asteroid7.texture = asteroid7.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"), 100, 10, 100, 100);
 asteroid8.texture = asteroid8.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"), 350, 10, 60, 60);
 asteroid9.texture = asteroid9.createTexture(Textures::createEntityTex("SpaceGame/asteroid.png"), 600, 10, 55, 55);

 house.texture = house.createTexture("TargetShooter/makeshiftHouse.png", (windowX / 2)-75, (windowY / 2)-50, 100, 100);
 ghost1.texture = ghost1.createTexture(Textures::createEntityTex("TargetShooter/ghost.png"), 10, 50, 50, 50);
 ghost2.texture = ghost2.createTexture(Textures::createEntityTex("TargetShooter/ghost.png"), 10, 550, 50, 50);
 ghost3.texture = ghost3.createTexture(Textures::createEntityTex("TargetShooter/ghost2.png"), 650, 50, 50, 50);
 ghost4.texture = ghost4.createTexture(Textures::createEntityTex("TargetShooter/ghost2.png"), 650, 550, 50, 50);
 ghost5.texture = ghost5.createTexture(Textures::createEntityTex("TargetShooter/ghost2.png"), 600, 600, 50, 50);
 ghost6.texture = ghost6.createTexture(Textures::createEntityTex("TargetShooter/ghost.png"), 100, 550, 50, 50);
 ghost7.texture = ghost7.createTexture(Textures::createEntityTex("TargetShooter/ghost2.png"), 600, 50, 50, 50);
 ghost8.texture = ghost8.createTexture(Textures::createEntityTex("TargetShooter/ghost.png"), 100, 0, 50, 50);



 ScoreList.open("ScoreList.txt");

 if (!ScoreList)
     cout << "cannot open score list";
 if(p<1){
     for(int i=0;i<10;i++){
         
     ScoreList >> name;
     ScoreList >> game;
     ScoreList >> score;
     scores[i].storeName(name);
     scores[i].storeGame(game);
     scores[i].storeScore(score);
 }
 p++;
 }
 ScoreList.close();
 scores[10].storeGame(0);

 x = 0;
 t = 0;
 currentScore = 0;
 timer = 0;
 leaderBoardY = 0;
 userInput;
 numSpot = 0;
 counterGameOver = 0;
 ghostCounter = 0;


 cout << "Before we begin, enter username for score records.\nGame will begin once enter is selected: ";
 getline(cin, userName);

}
void PauseMenu() {
    window.renderTexture(pauseMenu.texture, pauseMenu.getxPos(), pauseMenu.getyPos(), pauseMenu.getSrcHeight(), pauseMenu.getSrcWidth());
    window.renderTexture(keepPlayingButton.texture, keepPlayingButton.getxPos(), keepPlayingButton.getyPos(), keepPlayingButton.getSrcHeight(), keepPlayingButton.getSrcWidth());
    window.renderTexture(goBackButton.texture, goBackButton.getxPos(), goBackButton.getyPos(), goBackButton.getSrcHeight(), goBackButton.getSrcWidth());
}
void reset() {
    asteroid1.reset();
    asteroid2.reset();
    asteroid3.reset();
    asteroid4.reset();
    asteroid5.reset();
    asteroid6.reset();
    asteroid7.reset();
    asteroid8.reset();
    asteroid9.reset();
    timer = 0;
    t = 0;
    x = 0;
    p = 0;
    j = 0;
    f = 0;
    ghostCounter = 0;
    counterGameOver = 0;
    numSpot = 0;
    currentScore = 0;
    shipHit = false;
    lose = false;
    SpaceShip.setXPos(static_cast<float>(windowX/2));
    collectingNumber = true;
    userInput = "";
    Num.resetScore();

    ghost1.reset();
    ghost2.reset();
    ghost3.reset();
    ghost4.reset();
    ghost5.reset();
    ghost6.reset();
    ghost7.reset();
    ghost8.reset();
}
void updateScores() {
   ScoreList.open("ScoreList.txt");
    for (int i = 0; i < 10; i++) {
        ScoreList << scores[i].getName();
        ScoreList << " ";
        ScoreList << scores[i].getGameNum();
        ScoreList << " ";
        ScoreList << scores[i].getScore(); 
        ScoreList << endl;
    }
    ScoreList.close();
}
void checkScore(int score, int game) {
    if (score < scores[9].getScore()) {
        return;
    }
    else {  
            int spot=10;
            for (int i = 9; i >= 0; i--) {
                if (score > scores[i].getScore()) {
                    spot = i;
                }
            }

            
            for (int i = 9; i > (spot); i--) {
                scores[i].storeScore(scores[i-1].getScore());
                scores[i].storeGame(scores[i - 1].getGameNum());
                scores[i].storeName(scores[i - 1].getName());

              }

            scores[spot].storeName(userName);
            scores[spot].storeScore(currentScore);
            scores[spot].storeGame(game);
        
        updateScores();
    }
    
    
}
bool isCoveringSign(Textures tex) {
    int mXPos;
    int mYPos;
    int texWid = tex.getSrcWidth();
    int texHei = tex.getSrcHeight();
    int texX = static_cast<int>(tex.getxPos());
    int texY = static_cast<int>(tex.getyPos());

    SDL_GetMouseState(&mXPos, &mYPos);

    if( ((mXPos < (texX + texWid)) && (mXPos > texX)) && ((mYPos < (texY+texHei)) && (mYPos > texY) )) {
        coveringSign = true;
    }
    else
        coveringSign = false;

    return coveringSign;
}
bool coveringGhost(Enemies enemy) {
    int mXPos;
    int mYPos;
    int texWid = enemy.srcW;
    int texHei = enemy.srcH;
    int texX = static_cast<int>(enemy.getXPos());
    int texY = static_cast<int>(enemy.getYPos());

    SDL_GetMouseState(&mXPos, &mYPos);

    if (((mXPos < (texX + texWid)) && (mXPos > texX)) && ((mYPos < (texY + texHei)) && (mYPos > texY))) {
        return true;
    }
    else
        return false;
}
string toStr(int num) {
    string newNum;
    newNum = to_string(num);
    return newNum;
}
void gameLoop() {

    window.ClearRender();
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type){
        case SDL_QUIT:
        {
            isRunning = false;
            break;
        }//SDLQUIT ends
        case SDL_MOUSEBUTTONDOWN:
        {
            if (mainMenu){
                if (isCoveringSign(playOption)) {
                    mainMenu = false;
                    play = true;
                    leaderBoard = false;
                    //break;
                }
                else if (isCoveringSign(LeaderBoardOption)) {
                    mainMenu = false;
                    play = false;
                   leaderBoard = true;
                }
            } // if main menu ends

            else if (play) {
                if (isCoveringSign(backButton)) {
                    mainMenu = true;
                    play = false;
                }
                if (isCoveringSign(Game1Option)) {
                    play = false;
                    pause = false;
                    game1 = true;
                }
                if (isCoveringSign(Game2Option)) {
                    play = false;
                    pause = false;
                    game2 = true;
                }
                if (isCoveringSign(Game3Option)) {
                    play = false;
                    pause = false;
                    game3 = true;
                }
                
            }
            else if (game1) {
                if (isCoveringSign(pauseButton)) {
                    pause = true;
                }
                if (isCoveringSign(submitButton)) {
                    collectingNumber = false;
                }
                if (isCoveringSign(clearButton)) {
                    userInput = "";
                }
                if (isCoveringSign(nextButton)) {
                    nextNum = true;
                }
            }
            else if (game2) {
                if (isCoveringSign(pauseButton)) {
                    pause = true;
                }
            }
               
            else if (game3) {
                if (isCoveringSign(pauseButton)) {
                    pause = true;
                }
                if (coveringGhost(ghost1)) {
                    ghost1.isClicked(true);
                }
                if (coveringGhost(ghost2)) {
                    ghost2.isClicked(true);
                }
                if (coveringGhost(ghost3)) {
                    ghost3.isClicked(true);
                }
                if (coveringGhost(ghost4)) {
                    ghost4.isClicked(true);
                }
                if (coveringGhost(ghost5)) {
                    ghost5.isClicked(true);
                }
                if (coveringGhost(ghost6)) {
                    ghost6.isClicked(true);
                }
                if (coveringGhost(ghost7)) {
                    ghost7.isClicked(true);
                }
                if (coveringGhost(ghost8)) {
                    ghost8.isClicked(true);
                }
            }
            if (pause) {
                if (isCoveringSign(keepPlayingButton)) {
                    pause = false;
                }
                else if (isCoveringSign(goBackButton)) {
                    play = true;
                    game1 = false;
                    game2 = false;
                    game3 = false;
                }
            }
            if (lose) {
                if (isCoveringSign(backButton)) {
                game1 = false;
                game2 = false;
                game3 = false;
                pause = false;
                play = false;
                mainMenu = true;

                }
                
            }
               
            else if (leaderBoard) {
                if (isCoveringSign(backButton)) {
                    mainMenu = true;
                    leaderBoard = false;
                    play = false;
                    game1 = false;
                    game2 = false;
                    game3 = false;
                    lose = false;
                }
                
            }
        } // mouse button down ends
             
        case SDL_MOUSEBUTTONUP: {

            break; }
        case SDL_KEYDOWN:
        {
            switch (event.key.keysym.sym) {

            case SDLK_d: {
                if (game2) {
                    SpaceShip.moveXPos(0);
                }
                break;
            } //SDLK_RIGHT ends
            case SDLK_a: {
                if (game2) {
                    SpaceShip.moveXPos(1);
                }
                break;
            }//SDLK_a ends
            case SDLK_SPACE: {
                if (game2) {
                    shoot = true;
                    
                }
                break;
            }
            case (SDLK_SPACE && SDLK_d): {
                if (game2) {
                    SpaceShip.moveXPos(0);
                }
                break;
            }
            } // key switch ends
        break;

        } //SDL_KEYDOWN ends
        case SDL_KEYUP: {
            if (game2) {
                shoot = false;
               }
        }
        case SDL_TEXTINPUT: {
            userInput += event.text.text;
            SDL_StopTextInput();
        }
           
            
        }//switch ends

        
            
        
    }//while ends

    if (mainMenu) {
        reset();
        window.setRendererColor(0, 0, 205);
        window.renderTextures(playOption.texture, playOption.getxPos(),playOption.getyPos(), playOption.getSrcHeight(), playOption.getSrcWidth());
        window.renderTextures(LeaderBoardOption.texture, LeaderBoardOption.getxPos(), LeaderBoardOption.getyPos(), LeaderBoardOption.getSrcHeight(), LeaderBoardOption.getSrcWidth());
    }
    else if (play) {
        reset();
        window.setRendererColor(200, 600, 30);
        window.renderTextures(Game1Option.texture,Game1Option.getxPos(), Game1Option.getyPos(), Game1Option.getSrcHeight(), Game1Option.getSrcWidth());
        window.renderTextures(Game2Option.texture, Game2Option.getxPos(), Game2Option.getyPos(), Game2Option.getSrcHeight(), Game2Option.getSrcWidth());
        window.renderTextures(Game3Option.texture, Game3Option.getxPos(), Game3Option.getyPos(), Game3Option.getSrcHeight(), Game3Option.getSrcWidth());
        window.renderTextures(backButton.texture, backButton.getxPos(), backButton.getyPos(), backButton.getSrcHeight(), backButton.getSrcWidth());

    }
    else if (lose) {
        window.renderTexture(losingScreen.texture, losingScreen.getxPos(), losingScreen.getyPos(), losingScreen.getSrcHeight(), losingScreen.getSrcWidth());
        window.renderTextures(backButton.texture, backButton.getxPos(), backButton.getyPos(), backButton.getSrcHeight(), backButton.getSrcWidth());
        if (counterGameOver < 1) {
            checkScore(currentScore, game);
            counterGameOver++;
        }
       
    }
    else if (game1) {
        game = 1;
        window.setRendererColor(6, 130, 70);
        window.renderBackground(background1.texture);
        window.renderTexture(pauseButton.texture, pauseButton.getxPos(), pauseButton.getyPos(), pauseButton.getSrcHeight(), pauseButton.getSrcWidth());
        window.renderTexture(submitButton.texture, submitButton.getxPos(), submitButton.getyPos(), submitButton.getSrcHeight(), submitButton.getSrcWidth());
        window.renderTexture(clearButton.texture, clearButton.getxPos(), clearButton.getyPos(), clearButton.getSrcHeight(), clearButton.getSrcWidth());
        
        window.renderWordText(200, 50, messages[1].c_str(), Font, black);
        window.renderWordText(150, 100, "Between the interval", Font, black);
        window.renderWordText(150, 150, toStr(Num.getMinInterval(numSpot)).c_str(), Font, black);
        window.renderWordText((windowX/2)-25, 150, "-", Font, black);
        window.renderWordText(500, 150, toStr(Num.getMaxInterval(numSpot)).c_str(), Font, black);
        if (collectingNumber) {
            nextNum = false;

            SDL_StartTextInput();
            window.renderWordRealTime(200, 500, userInput.c_str(), Font, black);

        }
        else if (!collectingNumber) {
            if (userInput == "") {
                collectingNumber = true;
            }
            else {
                userGuess = userInput;
                //submit the into a function to check the number 

                window.renderWordText(100, 200, messages[2].c_str(), Font, black);
                window.renderWordText(500, 200, toStr(Num.getNum()).c_str(),Font, black);
                window.renderWordText(100, 250, messages[3].c_str(), Font, black);
                window.renderWordText(500, 250, userGuess.c_str(),Font, black);

                if (!Num.isTooHigh(stoi(userGuess), numSpot) && !Num.isTooLow(stoi(userGuess), numSpot)) {

                    if (Num.isHigher(stoi(userGuess))) {
                        window.renderWordText(150, 300, messages[5].c_str(),Font, black);
                        window.renderTexture(nextButton.texture, nextButton.getxPos(), nextButton.getyPos(), nextButton.getSrcHeight(), nextButton.getSrcWidth());
                        if (f < 1) {
                        currentScore = Num.getScore();
                        f++;
                        }

                    }
                    else if (!Num.isHigher(stoi(userGuess))) {
                        window.renderWordText(150, 300, messages[4].c_str(),Font, black);


                        if (t > 75) {
                            lose = true;
                        }
                        t++;

                    }
                }
                else if(Num.isTooHigh(stoi(userGuess), numSpot)||Num.isTooLow(stoi(userGuess),numSpot)){
                    window.renderWordText(150, 300, messages[6].c_str(), Font, black);
                    window.renderWordText(150, 400, messages[7].c_str(), Font, black);

                    if (t > 75) {
                        lose = true;
                    }
                    t++;

                }

                if (nextNum) {
                    userInput = "";


                    if (j < 1) {
                        numSpot += 1;
                        if (numSpot > 4) {
                            numSpot = 0;
                        }
                        j++;
                    }
                    collectingNumber = true;
                    Num.NextNumber(numSpot);
                    j = 0;
                    f = 0;
                }
            }
        }//not collcting num


        if (pause) {
            PauseMenu();
        }

    }//game ends
    else if (game2) {
        game = 2;
        window.setRendererColor(200, 10, 40);

        window.renderBackground(background2.texture);
        window.renderTexture(pauseButton.texture, pauseButton.getxPos(), pauseButton.getyPos(), pauseButton.getSrcHeight(), pauseButton.getSrcWidth());
        window.renderWordText(550, 25, "Score: ", Font,white );
        window.renderWordRealTime(700, 25, toStr(currentScore).c_str(),Font, white);

       if (pause) {
           PauseMenu();

       }
       else if(!pause){
        timer++;
        SpaceShip.updateShip();

        window.renderTextures(SpaceShip.texture, SpaceShip.getXPos(), SpaceShip.getYPos(), SpaceShip.srcH, SpaceShip.srcW);
        window.renderTextures(SpaceHub.texture, SpaceHub.getXPos(), SpaceHub.getYPos(), SpaceHub.srcH, SpaceHub.srcW);

       
        laser.updateLaser(SpaceShip.getXPos()+SpaceShip.srcW/2);
        if (shoot) {
            window.renderTextures(laser.texture, laser.getXPos(), laser.getYPos(), 20, 5);
        } 
        else if (!shoot) {
            laser.yPos = SpaceShip.getYPos() + 10;
        }

       //asteroid1
       window.renderTextures(asteroid1.texture, asteroid1.xPos, asteroid1.yPos, asteroid1.srcH, asteroid1.srcW);
       asteroid1.update(laser.getYPos(), laser.srcW,laser.getXPos());
       //asteroid2
       window.renderTextures(asteroid2.texture, asteroid2.xPos, asteroid2.yPos, asteroid2.srcH, asteroid2.srcW);
       asteroid2.update(laser.getYPos(), laser.srcW, laser.getXPos());
       if (timer > 200) {
            window.renderTextures(asteroid3.texture, asteroid3.xPos, asteroid3.yPos, asteroid3.srcH, asteroid3.srcW);
            asteroid3.update(laser.getYPos(), laser.srcW, laser.getXPos());

            window.renderTextures(asteroid4.texture, asteroid4.xPos, asteroid4.yPos, asteroid4.srcH, asteroid4.srcW);
            asteroid4.update(laser.getYPos(), laser.srcW, laser.getXPos());

            if (timer > 600) {
                window.renderTextures(asteroid5.texture, asteroid5.xPos, asteroid5.yPos, asteroid5.srcH, asteroid5.srcW);
                asteroid5.update(laser.getYPos(), laser.srcW, laser.getXPos());
                window.renderTextures(asteroid6.texture, asteroid6.xPos, asteroid6.yPos, asteroid6.srcH, asteroid6.srcW);
                asteroid6.update(laser.getYPos(), laser.srcW, laser.getXPos());

                if (timer > 1000) {
                    window.renderTextures(asteroid7.texture, asteroid7.xPos, asteroid7.yPos, asteroid7.srcH, asteroid7.srcW);
                    asteroid7.update(laser.getYPos(), laser.srcW, laser.getXPos());
                    window.renderTextures(asteroid8.texture, asteroid8.xPos, asteroid8.yPos, asteroid8.srcH, asteroid8.srcW);
                    asteroid8.update(laser.getYPos(), laser.srcW, laser.getXPos());
                    window.renderTextures(asteroid9.texture, asteroid9.xPos, asteroid9.yPos, asteroid9.srcH, asteroid9.srcW);
                    asteroid9.update(laser.getYPos(), laser.srcW, laser.getXPos());
                }
            }
       }
       //if asteroid hits spaceship
       {

       
       if (asteroid1.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH)|| asteroid2.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH)) {
           shipHit = true;
           lose = true;
       }
       if (asteroid3.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH) || asteroid4.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH)) {
           shipHit = true;
           lose = true;
       }
       if (asteroid5.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH) || asteroid6.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH)) {
           shipHit = true;
           lose = true;
       }
       if (asteroid7.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH) || asteroid8.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH)) {
           shipHit = true;
           lose = true;
       }
       if (asteroid9.hitsSpaceShip(SpaceShip.getXPos(), SpaceShip.srcW, SpaceShip.srcH) ) {
           shipHit = true;
           lose = true;
       }
       }
       //if asteroid hits spacehub
       {
           if (asteroid1.hitsSpaceHub() || asteroid2.hitsSpaceHub() || asteroid3.hitsSpaceHub() || asteroid4.hitsSpaceHub() || asteroid5.hitsSpaceHub()|| asteroid6.hitsSpaceHub() || asteroid7.hitsSpaceHub() || asteroid8.hitsSpaceHub() || asteroid9.hitsSpaceHub()) {
               f++;
               if(f>35)
                lose = true;
           }
       }

       if (!shipHit) {
        currentScore = (asteroid1.getScore() + asteroid2.getScore() + asteroid3.getScore() + asteroid4.getScore() + asteroid5.getScore()+
                       asteroid6.getScore()+asteroid7.getScore()+asteroid8.getScore()+asteroid9.getScore());
       }
       
      }


    }
    else if (game3) {
        game = 3;
        
        window.setRendererColor(50, 150, 255);
        window.renderBackground(background3.texture);
        window.renderTexture(pauseButton.texture, pauseButton.getxPos(), pauseButton.getyPos(), pauseButton.getSrcHeight(), pauseButton.getSrcWidth());
        window.renderTexture(house.texture, house.getxPos(), house.getyPos(), house.getSrcHeight(), house.getSrcWidth());
        window.renderWordText(550, 25, "Score: ",Font, black);
        window.renderWordRealTime(700, 25, toStr(currentScore).c_str(),Font, black);

        if (!pause) {
            ghostCounter++;
       
        window.renderTexture(ghost1.texture, ghost1.getXPos(), ghost1.getYPos(), ghost1.srcH, ghost1.srcW);
        ghost1.updateEnemy();
        window.renderTexture(ghost2.texture, ghost2.getXPos(), ghost2.getYPos(), ghost2.srcH, ghost2.srcW);
        ghost2.updateEnemy();
        window.renderTexture(ghost3.texture, ghost3.getXPos(), ghost3.getYPos(), ghost3.srcH, ghost3.srcW);
        ghost3.updateEnemy();
        window.renderTexture(ghost4.texture, ghost4.getXPos(), ghost4.getYPos(), ghost4.srcH, ghost4.srcW);
        ghost4.updateEnemy(); 

        if (ghostCounter > 500) {
            window.renderTexture(ghost5.texture, ghost5.getXPos(), ghost5.getYPos(), ghost5.srcH, ghost5.srcW);
            ghost5.updateEnemy();
            window.renderTexture(ghost6.texture, ghost6.getXPos(), ghost6.getYPos(), ghost6.srcH, ghost6.srcW);
            ghost6.updateEnemy();
            
            if (ghostCounter > 1400) {
                window.renderTexture(ghost7.texture, ghost7.getXPos(), ghost7.getYPos(), ghost7.srcH, ghost7.srcW);
                ghost7.updateEnemy();
                window.renderTexture(ghost8.texture, ghost8.getXPos(), ghost8.getYPos(), ghost8.srcH, ghost8.srcW);
                ghost8.updateEnemy();
            }
        }

        if (ghost1.arrivedAtHouse() || ghost2.arrivedAtHouse() || ghost3.arrivedAtHouse() || ghost4.arrivedAtHouse()) {
            lose = true;
        }
        if (ghost5.arrivedAtHouse() || ghost6.arrivedAtHouse() || ghost7.arrivedAtHouse() || ghost8.arrivedAtHouse()) { 
            lose = true;
        }
           


        if (!lose) {
            currentScore = (ghost1.getScore() + ghost2.getScore() + ghost3.getScore() + ghost4.getScore() + ghost5.getScore() + ghost6.getScore()
                + ghost7.getScore() + ghost8.getScore());
        }
        }
        


        if (pause) {
            PauseMenu();
        }

    }
    else if (leaderBoard) {
        window.setRendererColor(174, 34, 34);
        window.renderTextures(backButton.texture, backButton.getxPos(), backButton.getyPos(), backButton.getSrcHeight(), backButton.getSrcWidth());
        window.renderWordText(50, (50), "Name", Font, black);
        window.renderWordText(300, 50, "Game", Font, black);
        window.renderWordText(650, 50, "Score", Font, black);
      
        window.renderWordText(20, (100), scores[0].getName().c_str(), Font, white);
        window.renderWordText(275, (100), scores[0].getGame().c_str(), Font,white);
        window.renderWordText(650, 100, toStr(scores[0].getScore()).c_str(), Font, white);

        window.renderWordText(20, (150), scores[1].getName().c_str(), Font, white);
        window.renderWordText(275, (150), scores[1].getGame().c_str(), Font, white);
        window.renderWordText(650, 150, toStr(scores[1].getScore()).c_str(), Font, white);

        window.renderWordText(20, (200), scores[2].getName().c_str(), Font, white);
        window.renderWordText(275, (200), scores[2].getGame().c_str(), Font, white);
        window.renderWordText(650, 200, toStr(scores[2].getScore()).c_str(), Font, white);

        window.renderWordText(20, (250), scores[3].getName().c_str(), Font, white);
        window.renderWordText(275, (250), scores[3].getGame().c_str(),Font, white);
        window.renderWordText(650, 250, toStr(scores[3].getScore()).c_str(), Font, white);

        window.renderWordText(20, (300), scores[4].getName().c_str(),Font, white);
        window.renderWordText(275, (300), scores[4].getGame().c_str(), Font, white);
        window.renderWordText(650, 300, toStr(scores[4].getScore()).c_str(), Font, white);

        window.renderWordText(20, (350), scores[5].getName().c_str(), Font, white);
        window.renderWordText(275, (350), scores[5].getGame().c_str(), Font, white);
        window.renderWordText(650, 350, toStr(scores[5].getScore()).c_str(),Font, white);

        window.renderWordText(20, (400), scores[6].getName().c_str(), Font, white);
        window.renderWordText(275, (400), scores[6].getGame().c_str(), Font, white);
        window.renderWordText(650, 400, toStr(scores[6].getScore()).c_str(),Font, white);

        window.renderWordText(20, (450), scores[7].getName().c_str(), Font, white);
        window.renderWordText(275, (450), scores[7].getGame().c_str(), Font, white);
        window.renderWordText(650, 450, toStr(scores[7].getScore()).c_str(), Font, white);

        window.renderWordText(20, (500), scores[8].getName().c_str(), Font,white);
        window.renderWordText(275, (500), scores[8].getGame().c_str(), Font, white);
        window.renderWordText(650, 500, toStr(scores[8].getScore()).c_str(), Font, white);

        window.renderWordText(20, (550), scores[9].getName().c_str(), Font, white);
        window.renderWordText(275, (550), scores[9].getGame().c_str(), Font,white);
        window.renderWordText(650, 550, toStr(scores[9].getScore()).c_str(),Font, white);
        


    }
    else
        window.setRendererColor(0, 0, 0);


     

     window.display();
}

int main(int argc, char* args[]) {
    init();

    while (isRunning) {
        gameLoop();
    }
    window.End();
	

	return 0;
}