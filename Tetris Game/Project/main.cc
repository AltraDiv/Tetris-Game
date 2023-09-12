#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <random>
#include "board.h"
#include "player.h"
#include "jblock.h"
#include "lblock.h"
#include "zblock.h"
#include "oblock.h"
#include "iblock.h"
#include "tblock.h"
#include "sblock.h"
#include "textdisplay.h"
#include "graphicaldisplay.h"
#include "window.h"
#include "subject.h"
#include <exception>

using namespace std;


void spawnNxtBlock(Player *plr, const char block_type) {
    if (block_type == 'J') {
        JBlock *blk = new JBlock();
        plr->addNxtBlk(blk);
    }
    else if (block_type == 'T') {
        TBlock *blk = new TBlock();
        plr->addNxtBlk(blk);
    }
    else if (block_type == 'O') {
        OBlock *blk = new OBlock();
        plr->addNxtBlk(blk);
    }
    else if (block_type == 'Z') {
        ZBlock *blk = new ZBlock();
        plr->addNxtBlk(blk);
    }
    else if (block_type == 'S') {
        SBlock *blk = new SBlock();
        plr->addNxtBlk(blk);
    }
    else if (block_type == 'I') {
        IBlock *blk = new IBlock();
        plr->addNxtBlk(blk);
    }
    else if (block_type == 'L') {
        LBlock *blk = new LBlock();
        plr->addNxtBlk(blk);
    }
}

void spawnBlock(Player *plr, const char block_type) {
    if (block_type == 'J') {
        JBlock *blk = new JBlock();
        plr->addBlock(blk);
    }
    else if (block_type == 'T') {
        TBlock *blk = new TBlock();
         plr->addBlock(blk);
    }
    else if (block_type == 'O') {
        OBlock *blk = new OBlock();
         plr->addBlock(blk);
    }
    else if (block_type == 'Z') {
        ZBlock *blk = new ZBlock();
        plr->addBlock(blk);
    }
    else if (block_type == 'S') {
        SBlock *blk = new SBlock();
        plr->addBlock(blk);
    }
    else if (block_type == 'I') {

        IBlock *blk = new IBlock();
         plr->addBlock(blk);
    }
    else if (block_type == 'L') {
        LBlock *blk = new LBlock();
        plr->addBlock(blk);
    }
}
//level 1
char level_1(){
    //random_device rd;
    //uniform_int_distribution<int> dist(1,12);
    int val = 1 + (rand()%12);
    if(val == 1){
        return 'S';
    }
    else if (val == 2){
        return 'Z';
    }
    else if(val == 3 || val == 4){
        return 'I';
    }
    else if(val == 5 || val == 6){
        return 'J';
    }
    else if(val == 7 || val == 8){
        return 'L';
    }
    else if(val == 9 || val == 10){
        return 'O';
    }
    else {
        return 'T';
    }
}

//level 2: equal probability of every block
char level_2(){
    char blocks[7] = {'I', 'J', 'L', 'O', 'S', 'Z', 'T'};
    //random_device rd;
    //uniform_int_distribution<int> dist(0,6);
    int val = 1 + (rand()%7);
    return blocks[val-1];
}
//level 3
char level_3(){
    //random_device rd;
    //uniform_int_distribution<int> dist(1,9);
    int val = 1 + (rand()%9);
    if(val == 1 || val == 2){
        return 'S';
    }
    else if(val == 3 || val == 4){
        return 'Z';
    }
    else if(val == 5){
        return 'I';
    }
    else if(val == 6){
        return 'J';
    }
    else if(val == 7){
        return 'L';
    }
    else if(val == 8){
        return 'O';
    }
    else {
        return 'T';
    }
}


// Since different systems will have different way to clear terminal
void clear() {
    //system("clear");
}

void errorMsg() {
    cout << "Invalid Input, please try again." << endl;
}

void showRules() {
    cout << "<|---------| Rules |---------|>" << endl;
    cout << "This is a two player game similar to tetris." << endl;
    cout << "There are different levels that you get choose for your "<< endl;
    cout << "difficulty as a player. Throughout the game there will appear blocks for each player, your goal is to beat the other player." << endl;
    cout << "There are commands as, right, left, down, drop, cw, ccw." << endl;
    cout << "Enter in anything to go back to the main menu." << endl;
    string blah;
    cin >> blah;
    clear();
}
void moveRight(Board *brd) {
    clear();
    brd->removeOldPos();
    brd->getBlock()->moveRight();
    brd->addBlock();
}

void moveLeft(Board *brd) {
    clear();
    brd->removeOldPos();
    brd->getBlock()->moveLeft();
    brd->addBlock();
}

void moveDown(Board *brd) {
    clear();
    brd->removeOldPos();
    brd->getBlock()->moveDown();
    brd->addBlock();
}

void rotate(Board *brd) {
    clear();
    brd->removeOldPos();
    brd->getBlock()->rotate();
    brd->addBlock();
}

void counterRotate(Board *brd) {
    clear();
    brd->removeOldPos();
    brd->getBlock()->counterRotate();
    brd->addBlock();
}

void printDisplay(Player *p1, Player *p2, Xwindow *wind, bool enable_window) {
    Subject subj;
    TextDisplay *td = new TextDisplay(p1, p2);
    subj.attach(td);
    if (enable_window){
        GraphicalDisplay *gd = new GraphicalDisplay(p1, p2, wind);
        subj.attach(gd);
    }
    subj.notifyObservers();
}

string read_lvl_file(string file_name){
    string player_in;
    string temp_in;
    ifstream input_file;

    input_file.open(file_name);
    while(input_file >> temp_in){
        player_in += temp_in;
    }
    remove(player_in.begin(), player_in.end(), ' ');
    return player_in;
}

int main(int argc, const char *argv[]) {
// -- Main Menu --
    int menu_command = 0;
    bool enable_window = true;
    while (menu_command != 1)
    {
        //system("clear");
        cout << "<|---------| WELCOME TO BIQUADRIS |---------|>" << endl;
        cout << "1) Type 1 to Start" << endl;
        cout << "2) Type 2 for the rules" << endl;
        cout << "3) Type 3 to Quit" << endl;
        cout << "4) Type 4 to Disable Graphics" << endl;
        while (1) {
            if (cin >> menu_command) {
                break;
            }
            errorMsg();
            cin.clear();
            cin.ignore();
        }
        if (menu_command == 2) {
            showRules();
        }
        if (menu_command == 3) {
            exit(3);
        }
        if (menu_command == 4) {
            enable_window = false;
        }
        else {
            errorMsg();
        }

    }
// -- Main Menu end --

// -- Game Set up ---

    bool chosen_level = false;
    int level = 0;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-startlevel") == 0){
            istringstream iss{argv[i+1]};
            iss >> level;
            chosen_level = true;
        }
    }
    clear();

    if(!chosen_level){
        cout << "Player 1, pick your level: " << endl;
        cout << "Level 0: Easy" << endl;
        cout << "Level 1: Medium" << endl;
        cout << "Level 2: Hard" << endl;
        cout << "Level 3: Difficult" << endl;
        cin >> level;
    }
    string player1_in;

    string file_name = "biquadris_sequence1.txt";

    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-scriptfile1") == 0){
            file_name = argv[i+1];
        }
    }
    
    Board *b1 = new Board();
    Player *p1 = new Player(b1, level, 0);
    clear();

    if(!chosen_level){
        cout << "Player 2, pick your level: " << endl;
        cout << "Level 0: Easy" << endl;
        cout << "Level 1: Medium" << endl;
        cout << "Level 2: Hard" << endl;
        cout << "Level 3: Difficult" << endl;
        cin >> level;
    }

    string player2_in;

    string file_name2 = "biquadris_sequence2.txt";

    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-scriptfile2") == 0){
            file_name2 = argv[i+1];
        }
    }
    
    clear();
    Board *b2 = new Board();
    Player *p2 = new Player(b2, level, 0); 
    //read in seed
    int seed;
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-seed") == 0){
            istringstream iss{argv[i+1]};
            iss >> seed;
        }
    }
    srand(seed);
    bool lost = false;
    string command;
    int turn_count = 0;
    bool debug = true;

    int player1_in_len;
    int player2_in_len ;

    //counters for when the string runs out, then restart from 0
    int i = 0;
    int j = 0;
    Xwindow *window;
    if (enable_window) {
        window = new Xwindow(500, 500);
    }
// -- Set up end --
// -- Game Start --
    
    //lvl 1:
    char p1_next_block;
    p1_next_block = level_1();

    char p2_next_block;
    p2_next_block = level_1();

    //lvl 2:
    char p1_next_block2;
    p1_next_block2 = level_2();

    char p2_next_block2;
    p2_next_block2 = level_2();

    //lvl3:
    char p1_next_block3;
    p1_next_block3 = level_3();

    char p2_next_block3;
    p2_next_block3 = level_3();

    cout << "Start Game!" << endl;
    
    while(!lost) {
        int multiplier = 1;
        if(p1->getLevel() == 4){
                p1->levelDown();
        }
        if(p2->getLevel() == 4){
                p2->levelDown();
            }
        //levels
        if(turn_count%2 == 0){
            if(p1->getLevel() == 0){
                player1_in = read_lvl_file(file_name);
                player1_in_len = player1_in.length();
                if(i == player1_in_len){
                    i = 0;
                }
                spawnBlock(p1, player1_in[i]);
                if(i+1 == player1_in_len){
                    b1->clearNxtBlock();
                    spawnNxtBlock(p1, player1_in[0]);
                }
                else{
                    b1->clearNxtBlock();
                    spawnNxtBlock(p1, player1_in[i + 1]);
                }
                ++i;
            }
            else if(p1->getLevel() == 1){
                spawnBlock(p1, p1_next_block);
                b1->clearNxtBlock();
                p1_next_block = level_1();
                spawnNxtBlock(p1, p1_next_block);
            }
            else if(p1->getLevel() == 2){
                spawnBlock(p1, p1_next_block2);
                b1->clearNxtBlock();
                p1_next_block2 = level_2();
                spawnNxtBlock(p1, p1_next_block2);
            }
            else if(p1->getLevel() == 3){ //BLOCK DOESN'T DROP ON FIRST TURN
                spawnBlock(p1, p1_next_block3);
                b1->clearNxtBlock();
                p1_next_block3 = level_3();
                spawnNxtBlock(p1, p1_next_block3);
            }
        }
        else if(turn_count%2 != 0){
            if(p2->getLevel() == 0){
                player2_in = read_lvl_file(file_name2);
                player2_in_len = player2_in.length();
                if(j == player2_in_len){
                    j = 0;
                }
                spawnBlock(p2, player2_in[j]);

                if(j+1 == player2_in_len){
                    b2->clearNxtBlock();
                    spawnNxtBlock(p2, player2_in[0]);
                }
                else{
                    b2->clearNxtBlock();
                    spawnNxtBlock(p2, player2_in[j + 1]);
                }
                ++j;
            }
            else if(p2->getLevel() == 1){
                spawnBlock(p2, p2_next_block);
                b2->clearNxtBlock();
                p2_next_block = level_1();
                spawnNxtBlock(p2, p2_next_block);
            }
            else if(p2->getLevel() == 2){
                spawnBlock(p2, p2_next_block2);
                b2->clearNxtBlock();
                p2_next_block2 = level_2();
                spawnNxtBlock(p2, p2_next_block2);
            }
            else if(p2->getLevel() == 3){//BLOCK DOESN'T DROP ON FIRST TURN
                spawnBlock(p2, p2_next_block2);
                b2->clearNxtBlock();
                p2_next_block3 = level_3();
                spawnNxtBlock(p2, p2_next_block3);
            }
        }
        if (turn_count % 2 == 0) {
            if (p1->getBoard()->checkCollision()) {
                lost = true;
                break;
            }
        }
        else {
            if (p2->getBoard()->checkCollision()) {
                lost = true;
                break;
            }
        }
        
        clear();
        printDisplay(p1, p2, window, enable_window);
        bool turn_over = false;
        while (command != "drop" && !turn_over) {
            cin >> command;
            istringstream iss{command};
            if (iss >> multiplier) {
                iss >> command;
            }
            else {
                multiplier = 1;
            }
            for (int i = 0; i < multiplier; ++i) {
                if (command == "right" || command == "ri" || command == "rig" || command == "righ") {
                    if (turn_count % 2 == 0) {
                        if (!p1->getBoard()->checkCollision()) {
                            moveRight(p1->getBoard());
                            clear();
                            printDisplay(p1, p2, window, enable_window);
                        }
                    }
                    else {
                        if (!p2->getBoard()->checkCollision()) {
                            moveRight(p2->getBoard());
                            clear();
                            printDisplay(p1, p2, window, enable_window);
                        }
                    }
                }
                else if (command == "left" || command == "lef") {
                    if (turn_count % 2 == 0) {
                        if (!p1->getBoard()->checkCollision()) {
                            moveLeft(p1->getBoard());
                            clear();
                            printDisplay(p1, p2, window, enable_window);
                        }
                    }
                    else {
                        if (!p2->getBoard()->checkCollision()) {
                            moveLeft(p2->getBoard());
                            clear();
                            printDisplay(p1, p2, window, enable_window);
                        }
                    }
                }
                else if (command == "down" || command == "do" || command == "dow") {
                    if (turn_count % 2 == 0) {
                        if (!p1->getBoard()->checkCollision()) {
                            moveDown(p1->getBoard());
                            clear();
                            printDisplay(p1, p2, window, enable_window);
                        } else {
                            turn_over = true;
                        }
                    }
                    else {
                        if (!p2->getBoard()->checkCollision()) {
                            moveDown(p2->getBoard());
                            clear();
                            printDisplay(p1, p2, window, enable_window);
                        } else {
                            turn_over = true;
                        }
                    }
                }
                else if (command == "clockwise" || command == "cw") {
                    if (turn_count % 2 == 0) {
                        rotate(b1);
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        rotate(b2);
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "counter" || command == "ccw" || command == "co") {
                    if (turn_count % 2 == 0) {
                        counterRotate(b1);
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        counterRotate(b2);
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "levelup"){
                if(turn_count % 2 == 0){
                    if(p1->getLevel() + 1 < 4){
                        p1->levelUp();
                        if(p1->getLevel() == 1){
                            b1->clearNxtBlock();
                            p1_next_block = level_1();
                            spawnNxtBlock(p1, p1_next_block);
                        }
                        else if(p1->getLevel() == 2){
                            b1->clearNxtBlock();
                            p1_next_block2 = level_2();
                            spawnNxtBlock(p1, p1_next_block2);
                        }
                        else if(p1->getLevel() == 3){
                            b1->clearNxtBlock();
                            p1_next_block3 = level_3();
                            spawnNxtBlock(p1, p1_next_block3);
                        }
                    }
                }
                else{
                    if(p2->getLevel() + 1 < 4){
                        p2->levelUp();
                        if(p2->getLevel() == 1){
                            b2->clearNxtBlock();
                            p2_next_block = level_1();
                            spawnNxtBlock(p2, p2_next_block);
                        }
                        else if(p2->getLevel() == 2){
                            b2->clearNxtBlock();
                            p2_next_block2 = level_2();
                            spawnNxtBlock(p2, p2_next_block2);
                        }
                        else if(p2->getLevel() == 3){
                            b2->clearNxtBlock();
                            p2_next_block3 = level_3();
                            spawnNxtBlock(p2, p2_next_block3);
                        }
                    }
                }
                clear();
                printDisplay(p1, p2, window, enable_window);
            }
            else if (command == "leveldown"){
                if(turn_count % 2 == 0){
                    if(p1->getLevel() - 1 >= 0){
                        p1->levelDown();
                        if(p1->getLevel() == 1){
                            b1->clearNxtBlock();
                            p1_next_block = level_1();
                            spawnNxtBlock(p1, p1_next_block);
                        }
                        else if(p1->getLevel() == 2){
                            b1->clearNxtBlock();
                            p1_next_block2 = level_2();
                            spawnNxtBlock(p1, p1_next_block2);
                        }
                        else if(p1->getLevel() == 3){
                            b1->clearNxtBlock();
                            p1_next_block3 = level_3();
                            spawnNxtBlock(p1, p1_next_block3);
                        }
                        else if(p1->getLevel() == 0){
                            player1_in = read_lvl_file(file_name);
                            b1->clearNxtBlock();
                            spawnNxtBlock(p1, player1_in[0]);
                        }
                    }
                }
                else{
                    if(p2->getLevel() - 1 >= 0){
                        p2->levelDown();
                        if(p2->getLevel() == 1){
                            b2->clearNxtBlock();
                            p2_next_block = level_1();
                            spawnNxtBlock(p2, p2_next_block);
                        }
                        else if(p2->getLevel() == 2){
                            b2->clearNxtBlock();
                            p2_next_block2 = level_2();
                            spawnNxtBlock(p2, p2_next_block2);
                        }
                        else if(p2->getLevel() == 3){
                            b2->clearNxtBlock();
                            p2_next_block3 = level_3();
                            spawnNxtBlock(p2, p2_next_block3);
                        }
                        else if(p2->getLevel() == 0){
                            player2_in = read_lvl_file(file_name2);
                            b2->clearNxtBlock();
                            spawnNxtBlock(p2, player2_in[0]);
                        }
                    }
                }
                clear();
                printDisplay(p1, p2, window, enable_window);
            }
                else if (command == "debug=true") {
                    debug = true;
                }
                else if (command == "I" && debug) {
                    if (turn_count % 2 == 0) {
                        clear();
                        b1->removeOldPos();
                        spawnBlock(p1, 'I');
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        clear();
                        b2->removeOldPos();
                        spawnBlock(p2, 'I');
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "J" && debug) {
                    if (turn_count % 2 == 0) {
                        clear();
                        b1->removeOldPos();
                        spawnBlock(p1, 'I');
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        clear();
                        b2->removeOldPos();
                        spawnBlock(p2, 'J');
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "O" && debug) {
                    if (turn_count % 2 == 0) {
                        clear();
                        b1->removeOldPos();
                        spawnBlock(p1, 'O');
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        clear();
                        b2->removeOldPos();
                        spawnBlock(p2, 'O');
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "Z" && debug) {
                    if (turn_count % 2 == 0) {
                        clear();
                        b1->removeOldPos();
                        spawnBlock(p1, 'Z');
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        clear();
                        b2->removeOldPos();
                        spawnBlock(p2, 'Z');
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "S" && debug) {
                    if (turn_count % 2 == 0) {
                        clear();
                        b1->removeOldPos();
                        spawnBlock(p1, 'S');
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        clear();
                        b2->removeOldPos();
                        spawnBlock(p2, 'S');
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "T" && debug) {
                    if (turn_count % 2 == 0) {
                        clear();
                        b1->removeOldPos();
                        spawnBlock(p1, 'T');
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        clear();
                        b2->removeOldPos();
                        spawnBlock(p2, 'T');
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "L" && debug) {
                    if (turn_count % 2 == 0) {
                        clear();
                        b1->removeOldPos();
                        spawnBlock(p1, 'L');
                        printDisplay(p1, p2, window, enable_window);
                    }
                    else {
                        clear();
                        b2->removeOldPos();
                        spawnBlock(p2, 'L');
                        printDisplay(p1, p2, window, enable_window);
                    }
                }
                else if (command == "reset") {
                    int level_p1 = p1->getLevel();
                    int level_p2 = p2->getLevel();
                    delete b1;
                    delete b2;
                    delete p1;
                    delete p2;
                    Board *b1 = new Board();
                    Board *b2 = new Board();
                    Player *p1 = new Player(b1, level_p1, 0);
                    Player *p2 = new Player(b2, level_p2, 0);
                    printDisplay(p1, p2, window, enable_window);
                    break;
                }
            }
            if (turn_count % 2 == 0) {
                if (p1->getHeavy()) {
                    for (int i = 0; i < p1->getLevel(); ++i) {
                        p1->getBoard()->getBlock()->moveDown();
                    }
                }
                if(p1->getLevel() == 3){
                    p1->getBoard()->removeOldPos();
                    p1->getBoard()->getBlock()->moveDown();
                }
                p1->updateBoard();
            }
            else {
                if (p2->getHeavy()) {
                    for (int i = 0; i < p2->getLevel(); ++i) {
                        p2->getBoard()->getBlock()->moveDown();
                    }
                }
                if(p2->getLevel() == 3){
                    p2->getBoard()->removeOldPos();
                    p2->getBoard()->getBlock()->moveDown();
                }
            } 
        }
        command = "";
        if (turn_count % 2 == 0) {
            clear();
            b1->dropBlock();
            p1->updateBoard();
        } else {
            clear();
            b2->dropBlock();
            p2->updateBoard();
        }
        ++turn_count;
    }
    if (turn_count % 2 == 0) {
        cout << "Player 1 loses!" << endl;
    }
    else {
        cout << "Player 2 loses!" << endl;
    }
    delete p1;
    delete p2;
    delete b1;
    delete b2;
    delete window;
// -- Game end --
}
