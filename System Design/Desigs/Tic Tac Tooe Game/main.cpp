#include <bits/stdc++.h>
using namespace std;

/**
 * Draw state is not included
 * Contains only X and O win states
 * 
 * Design patterns used
 * * Strategy Pattern
 * * State Pattern
 * * Factory pattern (Not used, but can be used)
 */

class Board;
class GameContext;
class Player;
class XWonState;
class OWonState;
class OTurnState;
class XTurnState;

enum Symbol {
    X,
    O,
    EMPTY
};

class Position {
    public:
    int row, col;
};

class PlayerStrategy {
    public:
    virtual Position makeMove(Board board) = 0;
    virtual Symbol getSymbol() = 0;
    // virtual string type() =0;
};

class GameState {
    public:
    virtual void next(GameContext *gameContext, Player *p1, bool hasWon) = 0;
    virtual bool isGameOver() = 0;
    virtual string type() = 0;
};

class XTurnState : public GameState{
    public:
    void next(GameContext *gameContext, Player *p1, bool hasWon);

    bool isGameOver();

    string type();
};

class OTurnState : public GameState {
    public:
    void next(GameContext *gameContext, Player *p1, bool hasWon);

    bool isGameOver();

    string type();
};

class XWonState : public GameState {
    public:
    void next(GameContext *gameContext, Player* p1, bool hasWon);

    bool isGameOver();

    string type();
};

class OWonState : public GameState {
    public:
    void next(GameContext *gameContext, Player* p1, bool hasWon);

    bool isGameOver();

    string type();
};

class GameContext {
    GameState *currentState;
    public:
    GameContext();

    void setState(GameState *state);

    void next(Player* p, bool hasWon);

    GameState* getCurrentState();

    bool isGameOver();

    string getType();
};

class HumanPlayerStrategy : public PlayerStrategy {
    string name;
    Symbol symbol;
    public:
    HumanPlayerStrategy(string n, Symbol s);

    Position makeMove(Board board);

    Symbol getSymbol();

};


class Board {
    public:
    vector<vector<int>> grid;
    int size;

    Board();
    Board(int s);

    bool isMoveValid(int row, int col);

    void makeMove(int row, int col, Symbol symbol);

    void printBoard();


};

class Player {
    PlayerStrategy *ps;

    public:
        Player(PlayerStrategy* tps);

        PlayerStrategy* getPlayerStrategy();

        Symbol getSymbol();
};


class Game {
    Board board;
    // board.size = 3;
    Player *player1 = new Player(new HumanPlayerStrategy("Player 1", X));
    Player *player2 = new Player(new HumanPlayerStrategy("Player 2", O));

    Player *currentPlayer = player1;

    GameContext gameContext;

    public:
        Game();

        void play();

        void switchPlayer();

        void checkGameState();

        void announceResult();
};


int main() {
    Game game;
    game.play();
}

void XTurnState::next(GameContext *gameContext, Player *p1, bool hasWon) {
    if(hasWon) {
        gameContext->setState(new XWonState());
    }
    else {
        gameContext->setState(new OTurnState());
    }
}

bool XTurnState::isGameOver() {
    return false;
}

string XTurnState::type() {
    return "XTurnState";
}


void OTurnState::next(GameContext *gameContext, Player *p1, bool hasWon) {
    if(hasWon) {
        gameContext->setState(new OWonState());
    }
    else {
        gameContext->setState(new XTurnState());
    }
}

bool OTurnState::isGameOver() {
    return false;
}

string OTurnState::type() {
    return "OTurnState";
}


void XWonState::next(GameContext *gameContext, Player* p1, bool hasWon) {
    // Nothing  -->  player won
}

bool XWonState::isGameOver() {
    return true;
}

string XWonState::type() {
    return "XWonState";
}


void OWonState::next(GameContext *gameContext, Player* p1, bool hasWon) {
    // Nothing player won
}

bool OWonState::isGameOver() {
    return true;
}

string OWonState::type() {
    return "OWonState";
}

GameContext::GameContext() {
    currentState = new XTurnState();
}

void GameContext::setState(GameState *state) {
    currentState = state;
}

void GameContext::next(Player* p, bool hasWon) {
    currentState->next(this, p, hasWon);
}

GameState* GameContext::getCurrentState() {
    return currentState;
}

bool GameContext::isGameOver() {
    return currentState->isGameOver();
}

string GameContext::getType() {
    return currentState->type();
}


HumanPlayerStrategy::HumanPlayerStrategy(string n, Symbol s): name(n), symbol(s) {}

Position HumanPlayerStrategy::makeMove(Board board) {
    while (1) {
        Position pos;
        cout << "Enter row: ";
        cin >> pos.row;;
        cout << "Enter column: ";
        cin >> pos.col;

        if (board.isMoveValid(pos.row, pos.col)) {
            return pos;
        }
        else {
            cout << "Move is Invalid\n";
            cout << "Choose the Move again\n";
        }
    }
    
}

Symbol HumanPlayerStrategy::getSymbol() {
    return symbol;
}

Board::Board() {};
Board::Board(int s) : size(s) {
    grid.resize(size, vector<int>(size, EMPTY));
}

bool Board::isMoveValid(int row, int col) {
    return row >= 0 && row < size && col >= 0 && col < size && grid[row][col] == EMPTY;
}

void Board::makeMove(int row, int col, Symbol symbol) {
    if (isMoveValid(row, col)) {
        grid[row][col] = symbol;
    }
}

void Board::printBoard() {
    for (int i=0;i< size;i++) {
        for (int j =0 ;j<size;j++) {
            switch(grid[i][j]) {
                case X: cout << "  X  ";
                break;
                case O: cout << "  O  ";
                break;
                case EMPTY: cout << "  _  ";
                break;
            }
        }
        cout << endl << endl;
    }
}


Player::Player(PlayerStrategy* tps) : ps(tps) {}

PlayerStrategy* Player::getPlayerStrategy() {
    return ps;
}

Symbol Player::getSymbol() {
    return ps->getSymbol();
}


Game::Game() : board(3) {}

void Game::play() {

    cout << "......... Start Tic Tac Toe Game ..........\n\n";

    do {
        cout << "Enter position (row, col) for symbol: " << ((currentPlayer->getSymbol() == X)? "X" : "O" )<< endl;
        Position pos = currentPlayer->getPlayerStrategy()->makeMove(board);
        board.makeMove(pos.row, pos.col, currentPlayer->getSymbol());
        board.printBoard();
        checkGameState();
        switchPlayer();
    } while (!gameContext.isGameOver());
    announceResult();

}

void Game::switchPlayer() {
    if (currentPlayer == player1) {
        currentPlayer = player2;
    }
    else {
        currentPlayer = player1;
    }
}

void Game::checkGameState() {
    // gameContext.checkGameState
    // Below is to check Win probablity in row
    bool isWon = false;
    for (int i=0;i<board.size;i++) {
        
        if (board.grid[i][0] == EMPTY) break;
        isWon = true;
        for (int j=1;j<board.size;j++) {
            if (board.grid[i][j] != board.grid[i][j-1]) {
                isWon = false;
                break;
            }
        }
    }
    if (isWon) {
        gameContext.next(currentPlayer, true);
        return;
    }
    else {
        gameContext.next(currentPlayer, false);
    }

    isWon =  false;
    for (int i=0;i<board.size;i++) { // column
        
        if (board.grid[0][i] == EMPTY) break;
        isWon = true;
        for (int j=1;j<board.size;j++) { // row
            if (board.grid[j][i] != board.grid[j-1][i]) {
                isWon = false;
                break;
            }
            isWon = true;
        }
    }
    if (isWon) {
        gameContext.next(currentPlayer, true);
        return;
    }
    else {
        gameContext.next(currentPlayer, false);
    }
    
    // check in diagnol1
    
    if (board.grid[0][0]== EMPTY) {
        gameContext.next(currentPlayer, false); 
    }
    else {
        isWon = true;
        for (int i=1;i<board.size;i++) {
            if(board.grid[i][i] != board.grid[i-1][i-1]) {
                isWon = false;
                break;
            }
        }
        if (isWon) {
            gameContext.next(currentPlayer, true);
            return;
        }
        else {
            gameContext.next(currentPlayer, false);
        }
    }

    // Check for diagnol 2
    int inc = 0;
    int dec = board.size -1;
    if (board.grid[inc][dec]== EMPTY) {
        gameContext.next(currentPlayer, false); 
    }
    else {
        inc++;
        dec--;
        isWon = true;
        while (inc < board.size && dec >= 0) {
            if (board.grid[inc][dec] != board.grid[inc-1][dec+1]) {
                isWon = false;
                break;
            }
            inc++; dec--;
        }
        if (isWon) {
            gameContext.next(currentPlayer, true);
            return;
        }
        else {
            gameContext.next(currentPlayer, false);
            
        }
    }

    // CHeck is all Cells filled


}

void Game::announceResult() {
    // GameState *state = gameContext.getCurrentState();
    cout << "------------------------------------------------------------------\n";

    if (gameContext.getType() == "XWonState") {
        cout << "X won\n";
    }
    else if (gameContext.getType() == "OWonState") {
        cout << "O won\n";
    }
    else {
        cout << "Draw.......\n";
    }

    cout << "------------------------------------------------------------------\n";
}