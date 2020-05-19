#include "Board.h"
#include <iostream>

Board::Board()
{

}

void Board::printBoard(Player player1)
    {
        for(unsigned int i=0; i< BOARD_HEIGHT ; i++)
        {
            for(unsigned int j=0; j< BOARD_WIDTH; j++)
            {
                if(j == player1._snakeBody.at(0).first && i == player1._snakeBody.at(0).second)
                {
                    std::cout<< "S";
                }
                else if(j ==_foodXcord && i == _foodYcord)
                {
                    std::cout<< "X";
                }
                else
                {
                    std::cout << this->_board[i][j];
                }
            }
            std::cout << std::endl;
        }
    }

void Board::makeFrame()
    {
        for(unsigned int i=0; i < BOARD_HEIGHT ; i++)
        {
            _board[i][0] = '|';
            _board[i][BOARD_WIDTH-1] = '|';
        }

        for(unsigned int j=0; j < BOARD_WIDTH ; j++)
        {
            _board[0][j] = '-';
            _board[BOARD_HEIGHT-1][j] = '-';
        }
        _board[0][0] = '+';
        _board[0][BOARD_WIDTH - 1] = '+';
        _board[BOARD_HEIGHT - 1][BOARD_WIDTH - 1] = '+';
        _board[BOARD_HEIGHT - 1][0] = '+';
    }

void Board::initializeBoard(Player player1)
    {
        for(unsigned int i=0; i< BOARD_HEIGHT ; i++)
            for(unsigned int j=0; j< BOARD_WIDTH; j++)
            {
                {
                    _board[i][j] = '.';
                }
            }
        makeFrame();
    }

void Board::generateFood(Player player1)
{
    do
    {
        this->_foodXcord = ( std::rand() % 17 ) + 1;
        this->_foodYcord = ( std::rand() % 7 ) + 1;
    }while(this->_foodXcord == player1._snakeBody.front().first && this->_foodYcord == player1._snakeBody.front().second);

}

void Board::checkIfPlayerAteFood(Player player1)
{
    if(_foodXcord == player1._snakeBody.front().first && _foodYcord == player1._snakeBody.front().second)
    {
        player1.addNewSnakePart();
        player1._points += 1;
        this->generateFood(player1);
    }
}
