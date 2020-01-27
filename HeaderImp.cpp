#include <iostream>
#include <fstream>
#include <windows.h>
#include "Chess.h"

using namespace std;

void pawn::set_attrib(attributes temp)
{
	attrib = temp;
}

attributes pawn::get_attrib()
{
	return attrib;
}

bool pawn::movement(int final_row , int final_col , piece ***board)
{
	bool move = false;
	int temp_row;
	int temp_col;


	if (attrib.shape == 'p')
	{
		//initial case
		temp_row = attrib.row - 2;
		temp_col = attrib.col;

		if (final_row == temp_row && final_col == temp_col && attrib.row == 6)
		{
			move = true;

			if (board [attrib.row - 1][attrib.col]->get_attrib().shape != '-')
				return false;

			if (board [attrib.row - 2][attrib.col]->get_attrib().shape != '-')
				return false;
		}

		//case1
		temp_row = attrib.row - 1;
		temp_col = attrib.col;

		if (final_row == temp_row && final_col == temp_col)
		{
			move = true;

			if (board[final_row][final_col]->get_attrib().shape != '-')
				return false;
		}

		//case2
		temp_row = attrib.row - 1;
		temp_col = attrib.col - 1;

		if (final_row == temp_row && final_col == temp_col)
		{
			if (board[final_row][final_col]->get_attrib().shape >= 'A' &&
				board[final_row][final_col]->get_attrib().shape <= 'Z')
				move = true;
		}

		//case3
		temp_row = attrib.row - 1;
		temp_col = attrib.col + 1;

		if (final_row == temp_row && final_col == temp_col)
		{
			if (board[final_row][final_col]->get_attrib().shape >= 'A' &&
				board[final_row][final_col]->get_attrib().shape <= 'Z')
				move = true;
		}
	}

	else if (attrib.shape == 'P')
	{

		//initial case
		temp_row = attrib.row + 2;
		temp_col = attrib.col;

		if (final_row == temp_row && final_col == temp_col && attrib.row == 1)
		{
			move = true;

			if (board [attrib.row + 1][attrib.col]->get_attrib().shape != '-')
				return false;

			if (board [attrib.row + 2][attrib.col]->get_attrib().shape != '-')
				return false;
		}

		//case1
		temp_row = attrib.row + 1;
		temp_col = attrib.col;

		if (final_row == temp_row && final_col == temp_col)
		{
			move = true;

			if (board[final_row][final_col]->get_attrib().shape != '-')
				return false;
		}

		//case2
		temp_row = attrib.row + 1;
		temp_col = attrib.col - 1;

		if (final_row == temp_row && final_col == temp_col)
		{
			if (board[final_row][final_col]->get_attrib().shape >= 'a' &&
				board[final_row][final_col]->get_attrib().shape <= 'z')
				move = true;
		}

		//case3
		temp_row = attrib.row + 1;
		temp_col = attrib.col + 1;

		if (final_row == temp_row && final_col == temp_col)
		{
			if (board[final_row][final_col]->get_attrib().shape >= 'a' &&
				board[final_row][final_col]->get_attrib().shape <= 'z')
				move = true;
		}
	}

	return move;
}

void rook::set_attrib(attributes temp)
{
	attrib = temp;
}

attributes rook::get_attrib()
{
	return attrib;
}

bool rook::movement(int final_row , int final_col , piece ***board)
{
	bool move = false;
	int temp_row;
	int temp_col;

	//case1
	for (int i = 0; i < 8; i++)
	{
		temp_row = attrib.row;
		temp_col = i;
		if (temp_row == final_row && temp_col == final_col)
		{
			move = true;

			if (final_col < attrib.col)
			{
				for (int j = final_col + 1; j < attrib.col; j++)
				{
					if (board[attrib.row][j]->get_attrib().shape != '-')
						return false;
				}
			}

			else if (final_col > attrib.col)
			{
				for (int j = final_col - 1; j > attrib.col; j--)
				{
					if (board[attrib.row][j]->get_attrib().shape != '-')
						return false;
				}
			}
		}
	}

	//case2
	for (int i = 0; i < 8; i++)
	{
		temp_row = i;
		temp_col = attrib.col;
		if (temp_row == final_row && temp_col == final_col)
		{
			move = true;

			if (final_row < attrib.row)
			{
				for (int j = final_row + 1; j < attrib.row; j++)
				{
					if (board[j][attrib.col]->get_attrib().shape != '-')
						return false;
				}
			}
			else if (final_row > attrib.row)
			{
				for (int j = final_row - 1; j > attrib.row; j--)
				{
					if (board[j][attrib.col]->get_attrib().shape != '-')
						return false;
				}
			}
		}
	}

	return move;
}

void knight::set_attrib(attributes temp)
{
	attrib = temp;
}

attributes knight::get_attrib()
{
	return attrib;
}

bool knight::movement(int final_row , int final_col , piece ***board)
{
	bool move = false;
	int temp_row;
	int temp_col;

	//case1
	temp_row = attrib.row - 2;
	if ((final_row == temp_row && final_col == attrib.col - 1) || (final_row == temp_row && final_col == attrib.col + 1))
	{
		move = true;
	}

	//case2
	temp_row = attrib.row + 2;
	if ((final_row == temp_row && final_col == attrib.col - 1) || (final_row == temp_row && final_col == attrib.col + 1))
	{
		move = true;
	}

	//case3
	temp_col = attrib.col - 2;
	if ((final_row == attrib.row - 1 && final_col == temp_col) || (final_row == attrib.row + 1 && final_col == temp_col))
	{
		move = true;
	}

	//case4
	temp_col = attrib.col + 2;
	if ((final_row == attrib.row - 1 && final_col == temp_col) || (final_row == attrib.row + 1 && final_col == temp_col))
	{
		move = true;
	}

	return move;
}

void bishop::set_attrib(attributes temp)
{
	attrib = temp;
}

attributes bishop::get_attrib()
{
	return attrib;
}

bool bishop::movement(int final_row , int final_col , piece ***board)
{
	bool move = false;
	int temp_row;
	int temp_col;

	//case1
	for (temp_row = attrib.row + 1, temp_col = attrib.col + 1; temp_row < 8 && temp_col < 8; temp_row++, temp_col++)
	{
		if (final_row == temp_row && final_col == temp_col)
		{
			move = true;

			for (int i = attrib.row + 1, j = attrib.col + 1; i < final_row && j < final_col; i++, j++)
			{
				if (board[i][j]->get_attrib().shape != '-')
					return false;
			}
		}
	}

	//case2
	for (temp_row = attrib.row - 1, temp_col = attrib.col - 1; temp_row > -1 && temp_col > -1; temp_row--, temp_col--)
	{
		if (final_row == temp_row && final_col == temp_col)
		{
			move = true;

			for (int i = attrib.row - 1, j = attrib.col - 1; i > final_row && j > final_col; i--, j--)
			{
				if (board[i][j]->get_attrib().shape != '-')
					return false;
			}
		}
	}

	//case3
	for (temp_row = attrib.row - 1, temp_col = attrib.col + 1; temp_row > -1 && temp_col < 8; temp_row--, temp_col++)
	{
		if (final_row == temp_row && final_col == temp_col)
		{
			move = true;

			for (int i = attrib.row - 1, j = attrib.col + 1; i > final_row && j < final_col; i--, j++)
			{
				if (board[i][j]->get_attrib().shape != '-')
					return false;
			}
		}
	}

	//case4
	for (temp_row = attrib.row + 1, temp_col = attrib.col - 1; temp_row < 8 && temp_col > -1; temp_row++, temp_col--)
	{
		if (final_row == temp_row && final_col == temp_col)
		{
			move = true;

			for (int i = attrib.row + 1, j = attrib.col - 1; i < final_row && j > final_col; i++, j--)
			{
				if (board[i][j]->get_attrib().shape != '-')
					return false;
			}
		}
	}

	return move;
}

void queen::set_attrib(attributes temp)
{
	attrib = temp;
}

attributes queen::get_attrib()
{
	return attrib;
}

bool queen::movement(int final_row , int final_col , piece ***board)
{
	attributes temp;
	rook obj1;
	bishop obj2;

	temp.row = attrib.row;
	temp.col = attrib.col;
	temp.shape = attrib.shape;

	obj1.set_attrib(temp);
	obj2.set_attrib(temp);

	return (obj1.movement(final_row , final_col , board) ||
		obj2.movement(final_row , final_col , board));
}

void king::set_attrib(attributes temp)
{
	attrib = temp;
}

attributes king::get_attrib()
{
	return attrib;
}

bool king::movement(int final_row , int final_col , piece ***board)
{
	int temp_row;
	int temp_col;

	//case1
	temp_row = attrib.row;
	temp_col = attrib.col + 1;

	if (temp_row == final_row && temp_col == final_col)
	{
		return true;
	}

	//case2
	temp_row = attrib.row;
	temp_col = attrib.col - 1;

	if (temp_row == final_row && temp_col == final_col)
	{
		return true;
	}

	//case3
	temp_row = attrib.row + 1;
	temp_col = attrib.col;

	if (temp_row == final_row && temp_col == final_col)
	{
		return true;
	}

	//case4
	temp_row = attrib.row - 1;
	temp_col = attrib.col;

	if (temp_row == final_row && temp_col == final_col)
	{
		return true;
	}

	//case5
	temp_row = attrib.row - 1;
	temp_col = attrib.col - 1;

	if (temp_row == final_row && temp_col == final_col)
	{
		return true;
	}

	//case6
	temp_row = attrib.row - 1;
	temp_col = attrib.col + 1;

	if (temp_row == final_row && temp_col == final_col)
	{
		return true;
	}

	//case7
	temp_row = attrib.row + 1;
	temp_col = attrib.col - 1;

	if (temp_row == final_row && temp_col == final_col)
	{
		return true;
	}

	//case8
	temp_row = attrib.row + 1;
	temp_col = attrib.col + 1;

	if (temp_row == final_row && temp_col == final_col)
	{
		return true;
	}

	return false;
}

chess::chess()
{
	board = new piece**[8];
	for (int i = 0; i < 8; i++)
	{
		board[i] = new piece*[8];
	}


	attributes temp;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 0)
			{	
				temp.row = i;

				board[i][j] = new rook;

				temp.col = j;
				temp.shape = 'R';

				board[i][j]->set_attrib(temp);

				board[i][++j] =new knight;

				temp.col = j;
				temp.shape = 'N';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new bishop;

				temp.col = j;
				temp.shape = 'B';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new queen;

				temp.col = j;
				temp.shape = 'Q';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new king;

				temp.col = j;
				temp.shape = 'K';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new bishop;

				temp.col = j;
				temp.shape = 'B';

				board[i][j]->set_attrib(temp);

				board[i][++j] =new knight;

				temp.col = j;
				temp.shape = 'N';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new rook;

				temp.col = j;
				temp.shape = 'R';

				board[i][j]->set_attrib(temp);
			}

			else if (i == 1)
			{
				temp.row = i;
				temp.shape = 'P';
				while (j < 8)
				{
					board[i][j] = new pawn;

					temp.col = j;

					board[i][j]->set_attrib(temp);

					j++;
				}
			}

			else if (i == 6)
			{
				temp.row = i;
				temp.shape = 'p';
				while (j < 8)
				{
					board[i][j] = new pawn;

					temp.col = j;

					board[i][j]->set_attrib(temp);

					j++;
				}
			}

			else if (i == 7)
			{
				temp.row = i;

				board[i][j] = new rook;

				temp.col = j;
				temp.shape = 'r';

				board[i][j]->set_attrib(temp);

				board[i][++j] =new knight;

				temp.col = j;
				temp.shape = 'n';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new bishop;

				temp.col = j;
				temp.shape = 'b';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new queen;

				temp.col = j;
				temp.shape = 'q';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new king;

				temp.col = j;
				temp.shape = 'k';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new bishop;

				temp.col = j;
				temp.shape = 'b';

				board[i][j]->set_attrib(temp);

				board[i][++j] =new knight;

				temp.col = j;
				temp.shape = 'n';

				board[i][j]->set_attrib(temp);

				board[i][++j] = new rook;

				temp.col = j;
				temp.shape = 'r';

				board[i][j]->set_attrib(temp);;
			}

			else
			{
				temp.row = i;
				temp.col = j;
				temp.shape = '-';
				board[i][j] = new pawn;
				board[i][j]->set_attrib(temp);
			}
		}
	}
}

void chess::get_input()
{
	cout << "\tinitial_row : ";
	cin >> command.initial_row;
	cout << "\tinitial_col : ";
	cin >> command.initial_col;
	cout << "\tfinal_row : ";
	cin >> command.final_row;
	cout << "\tfinal_col : ";
	cin >> command.final_col;

	if (command.initial_row == -1 && command.initial_col == -1 && command.final_row == -1 && command.final_col == -1)
		exit(1);
}

bool chess::range()
{
	if (command.initial_row < 0 || command.initial_col < 0 || command.final_row < 0 || command.final_col < 0)
		return false;

	if (command.initial_row > 7 || command.initial_col > 7 || command.final_row > 7 || command.final_col > 7)
		return false;

	return true;
}

bool chess::p1_allow()
{
	if ((board[command.initial_row][command.initial_col]->get_attrib().shape <= 'a' ||
		board[command.initial_row][command.initial_col]->get_attrib().shape >= 'z'))
		return false;

	if (board[command.final_row][command.final_col]->get_attrib().shape >= 'a' &&
		board[command.final_row][command.final_col]->get_attrib().shape <= 'z')
		return false;

	return true;
}


bool chess::p2_allow()
{
	if ((board[command.initial_row][command.initial_col]->get_attrib().shape <= 'A' ||
		board[command.initial_row][command.initial_col]->get_attrib().shape >= 'Z'))
		return false;

	if (board[command.final_row][command.final_col]->get_attrib().shape >= 'A' &&
		board[command.final_row][command.final_col]->get_attrib().shape <= 'Z')
		return false;

	return true;
}

bool chess::can_move()
{
	return board[command.initial_row][command.initial_col]->movement(command.final_row , command.final_col , board);
}

bool chess::p1_check()
{
	int row;
	int col;

	char initial_shape;
	char final_shape;

	initial_shape = board[command.initial_row][command.initial_col]->get_attrib().shape;
	final_shape = board[command.final_row][command.final_col]->get_attrib().shape;

	move();


	bool found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape == 'k')
			{
				row = i;
				col = j;
				found = true;
			}
		}
	}

	bool check = false;
	for(int i = 0; i < 8 && !check; i++)
	{
		for (int j = 0; j < 8 && !check; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				check = board[i][j]->movement(row , col , board);
			}
		}
	}

	attributes temp;

	delete board[command.initial_row][command.initial_col];
	delete board[command.final_row][command.final_col];

	temp.row = command.initial_row;
	temp.col = command.initial_col;
	temp.shape = initial_shape;

	if (initial_shape == 'p' || initial_shape == 'P')
	{
		board[command.initial_row][command.initial_col] = new pawn;
		board[command.initial_row][command.initial_col]->set_attrib(temp);

	}

	else if (initial_shape == 'r' || initial_shape == 'R')
	{
		board[command.initial_row][command.initial_col] = new rook;
		board[command.initial_row][command.initial_col]->set_attrib(temp);

	}

	else if (initial_shape == 'n' || initial_shape == 'N')
	{
		board[command.initial_row][command.initial_col] = new knight;
		board[command.initial_row][command.initial_col]->set_attrib(temp);

	}

	else if (initial_shape == 'b' || initial_shape == 'B')
	{
		board[command.initial_row][command.initial_col] = new bishop;
		board[command.initial_row][command.initial_col]->set_attrib(temp);

	}

	else if (initial_shape == 'q' || initial_shape == 'Q')
	{
		board[command.initial_row][command.initial_col] = new queen;
		board[command.initial_row][command.initial_col]->set_attrib(temp);
	}

	else if (initial_shape == 'k' || initial_shape == 'K')
	{
		board[command.initial_row][command.initial_col] = new king;
		board[command.initial_row][command.initial_col]->set_attrib(temp);
	}



	temp.row = command.final_row;
	temp.col = command.final_col;
	temp.shape = final_shape;

	if (final_shape == 'p' || final_shape == 'P' || final_shape == '-')
	{
		board[command.final_row][command.final_col] = new pawn;
		board[command.final_row][command.final_col]->set_attrib(temp);

	}

	else if (final_shape == 'r' || final_shape == 'R')
	{
		board[command.final_row][command.final_col] = new rook;
		board[command.final_row][command.final_col]->set_attrib(temp);

	}

	else if (final_shape == 'n' || final_shape == 'N')
	{
		board[command.final_row][command.final_col] = new knight;
		board[command.final_row][command.final_col]->set_attrib(temp);

	}

	else if (final_shape == 'b' || final_shape == 'B')
	{
		board[command.final_row][command.final_col] = new bishop;
		board[command.final_row][command.final_col]->set_attrib(temp);

	}

	else if (final_shape == 'q' || final_shape == 'Q')
	{
		board[command.final_row][command.final_col] = new queen;
		board[command.final_row][command.final_col]->set_attrib(temp);
	}

	else if (final_shape == 'k' || final_shape == 'K')
	{
		board[command.final_row][command.final_col] = new king;
		board[command.final_row][command.final_col]->set_attrib(temp);
	}

	return check;
}

bool chess::p2_check()
{
	int row;
	int col;

	char initial_shape;
	char final_shape;

	initial_shape = board[command.initial_row][command.initial_col]->get_attrib().shape;
	final_shape = board[command.final_row][command.final_col]->get_attrib().shape;

	move();

	bool found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j] != nullptr && board[i][j]->get_attrib().shape == 'K')
			{
				row = i;
				col = j;
				found = true;
			}
		}
	}

	bool check = false;
	for(int i = 0; i < 8 && !check; i++)
	{
		for (int j = 0; j < 8 && !check; j++)
		{
			if (board[i][j] != nullptr && board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				check = board[i][j]->movement(row , col , board);
			}
		}
	}

	attributes temp;

	delete board[command.initial_row][command.initial_col];
	delete board[command.final_row][command.final_col];

	temp.row = command.initial_row;
	temp.col = command.initial_col;
	temp.shape = initial_shape;

	if (initial_shape == 'p' || initial_shape == 'P')
	{
		board[command.initial_row][command.initial_col] = new pawn;
		board[command.initial_row][command.initial_col]->set_attrib(temp);

	}

	else if (initial_shape == 'r' || initial_shape == 'R')
	{
		board[command.initial_row][command.initial_col] = new rook;
		board[command.initial_row][command.initial_col]->set_attrib(temp);

	}

	else if (initial_shape == 'n' || initial_shape == 'N')
	{
		board[command.initial_row][command.initial_col] = new knight;
		board[command.initial_row][command.initial_col]->set_attrib(temp);

	}

	else if (initial_shape == 'b' || initial_shape == 'B')
	{
		board[command.initial_row][command.initial_col] = new bishop;
		board[command.initial_row][command.initial_col]->set_attrib(temp);

	}

	else if (initial_shape == 'q' || initial_shape == 'Q')
	{
		board[command.initial_row][command.initial_col] = new queen;
		board[command.initial_row][command.initial_col]->set_attrib(temp);
	}

	else if (initial_shape == 'k' || initial_shape == 'K')
	{
		board[command.initial_row][command.initial_col] = new king;
		board[command.initial_row][command.initial_col]->set_attrib(temp);
	}



	temp.row = command.final_row;
	temp.col = command.final_col;
	temp.shape = final_shape;

	if (final_shape == 'p' || final_shape == 'P' || final_shape == '-')
	{
		board[command.final_row][command.final_col] = new pawn;
		board[command.final_row][command.final_col]->set_attrib(temp);

	}

	else if (final_shape == 'r' || final_shape == 'R')
	{
		board[command.final_row][command.final_col] = new rook;
		board[command.final_row][command.final_col]->set_attrib(temp);

	}

	else if (final_shape == 'n' || final_shape == 'N')
	{
		board[command.final_row][command.final_col] = new knight;
		board[command.final_row][command.final_col]->set_attrib(temp);

	}

	else if (final_shape == 'b' || final_shape == 'B')
	{
		board[command.final_row][command.final_col] = new bishop;
		board[command.final_row][command.final_col]->set_attrib(temp);

	}

	else if (final_shape == 'q' || final_shape == 'Q')
	{
		board[command.final_row][command.final_col] = new queen;
		board[command.final_row][command.final_col]->set_attrib(temp);
	}

	else if (final_shape == 'k' || final_shape == 'K')
	{
		board[command.final_row][command.final_col] = new king;
		board[command.final_row][command.final_col]->set_attrib(temp);
	}

	return check;
}

bool chess::p1_checkmate()
{
	int row;
	int col;

	bool found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape == 'k')
			{
				row = i;
				col = j;
				found = true;
			}
		}
	}

	int counter = 0;

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (board[i][j]->movement(row , col , board))
				{
					found = true;
					counter++;
				}

			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (row >= 0 && row <= 7 && col + 1 >= 0 && col + 1 <= 7 &&
					board[row][col + 1]->get_attrib().shape >= 'A' &&
					board[row][col + 1]->get_attrib().shape <= 'Z' &&
					board[i][j]->movement(row , col + 1 , board))
				{
					found = true;
					counter++;
				}			
			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (row >= 0 && row <= 7 && col - 1 >= 0 && col - 1 <= 7 &&
					board[row][col - 1]->get_attrib().shape >= 'A' &&
					board[row][col - 1]->get_attrib().shape <= 'Z' &&
					board[i][j]->movement(row , col - 1 , board))
				{
					found = true;
					counter++;
				}			
			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (row + 1 >= 0 && row + 1 <= 7 && col >= 0 && col <= 7 &&
					board[row + 1][col]->get_attrib().shape >= 'A' &&
					board[row + 1][col]->get_attrib().shape <= 'Z' &&
					board[i][j]->movement(row + 1 , col , board))
				{
					found = true;
					counter++;
				}

			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (row - 1  >= 0 && row - 1 <= 7 && col >= 0 && col <= 7 &&
					board[row - 1][col]->get_attrib().shape >= 'A' &&
					board[row - 1][col]->get_attrib().shape <= 'Z' &&
					board[i][j]->movement(row - 1 , col , board))
				{
					found = true;
					counter++;
				}

			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (row - 1 >= 0 && row - 1 <= 7 && col - 1 >= 0 && col - 1 <= 7 &&
					board[row - 1][col - 1]->get_attrib().shape >= 'A' &&
					board[row - 1][col - 1]->get_attrib().shape <= 'Z' &&
					board[i][j]->movement(row - 1 , col - 1 , board))
				{
					found = true;
					counter++;
				}		
			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (row + 1 >= 0 && row + 1 <= 7 && col + 1 >= 0 && col + 1 <= 7 &&
					board[row + 1][col + 1]->get_attrib().shape >= 'A' &&
					board[row + 1][col + 1]->get_attrib().shape <= 'Z' &&
					board[i][j]->movement(row + 1 , col + 1 , board))
				{
					found = true;
					counter++;
				}	
			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if ( board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (row - 1 >= 0 && row - 1 <= 7 && col + 1 >= 0 && col + 1 <= 7 &&
					board[row - 1][col + 1]->get_attrib().shape >= 'A' &&
					board[row -1][col + 1]->get_attrib().shape <= 'Z' &&
					board[i][j]->movement(row - 1 , col + 1 , board))
				{
					found = true;
					counter++;
				}

			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
			{
				if (row + 1 >= 0 && row + 1 <= 7 && col - 1 >= 0 && col - 1 <= 7 &&
					board[row + 1][col - 1]->get_attrib().shape >= 'A' &&
					board[row + 1][col - 1]->get_attrib().shape <= 'Z' &&
					board[i][j]->movement(row + 1 , col - 1 , board))
				{
					found = true;
					counter++;
				}
			}
		}
	}


	if (counter == 9)
		return true;

	return false;

}

bool chess::p2_checkmate()
{
	int row;
	int col;

	bool found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape == 'K')
			{
				row = i;
				col = j;
				found = true;
			}
		}
	}

	int counter = 0;

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (board[i][j]->movement(row , col , board))
				{
					found = true;
					counter++;
				}

			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (row >= 0 && row <= 7 && col + 1 >= 0 && col + 1 <= 7 &&
					board[row][col + 1]->get_attrib().shape >= 'a' &&
					board[row][col + 1]->get_attrib().shape <= 'z' &&
					board[i][j]->movement(row , col + 1 , board))
				{
					found = true;
					counter++;
				}			
			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (row >= 0 && row <= 7 && col - 1 >= 0 && col - 1 <= 7 &&
					board[row][col - 1]->get_attrib().shape >= 'a' &&
					board[row][col - 1]->get_attrib().shape <= 'z' &&
					board[i][j]->movement(row , col - 1 , board))
				{
					found = true;
					counter++;
				}			
			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (row + 1 >= 0 && row + 1 <= 7 && col >= 0 && col <= 7 &&
					board[row + 1][col]->get_attrib().shape >= 'a' &&
					board[row + 1][col]->get_attrib().shape <= 'z' &&
					board[i][j]->movement(row + 1 , col , board))
				{
					found = true;
					counter++;
				}

			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (row - 1  >= 0 && row - 1 <= 7 && col >= 0 && col <= 7 &&
					board[row - 1][col]->get_attrib().shape >= 'a' &&
					board[row - 1][col]->get_attrib().shape <= 'z' &&
					board[i][j]->movement(row - 1 , col , board))
				{
					found = true;
					counter++;
				}

			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (row - 1 >= 0 && row - 1 <= 7 && col - 1 >= 0 && col - 1 <= 7 &&
					board[row - 1][col - 1]->get_attrib().shape >= 'a' &&
					board[row - 1][col - 1]->get_attrib().shape <= 'z' &&
					board[i][j]->movement(row - 1 , col - 1 , board))
				{
					found = true;
					counter++;
				}		
			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (row + 1 >= 0 && row + 1 <= 7 && col + 1 >= 0 && col + 1 <= 7 &&
					board[row + 1][col + 1]->get_attrib().shape >= 'a' &&
					board[row + 1][col + 1]->get_attrib().shape <= 'z' &&
					board[i][j]->movement(row + 1 , col + 1 , board))
				{
					found = true;
					counter++;
				}	
			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if ( board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (row - 1 >= 0 && row - 1 <= 7 && col + 1 >= 0 && col + 1 <= 7 &&
					board[row - 1][col + 1]->get_attrib().shape >= 'a' &&
					board[row -1][col + 1]->get_attrib().shape <= 'z' &&
					board[i][j]->movement(row - 1 , col + 1 , board))
				{
					found = true;
					counter++;
				}

			}
		}
	}

	found = false;
	for(int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
			{
				if (row + 1 >= 0 && row + 1 <= 7 && col - 1 >= 0 && col - 1 <= 7 &&
					board[row + 1][col - 1]->get_attrib().shape >= 'a' &&
					board[row + 1][col - 1]->get_attrib().shape <= 'z' &&
					board[i][j]->movement(row + 1 , col - 1 , board))
				{
					found = true;
					counter++;
				}
			}
		}
	}


	if (counter == 9)
		return true;

	return false;
}

bool chess::draw()
{
	int counter1 = 0;
	int counter2 = 0;
	for(int i = 0; i < 8; i++)
	{
		for (int j = 8; j < 8; j++)
		{
			if (board[i][j]->get_attrib().shape >= 'a' && board[i][j]->get_attrib().shape <= 'z')
				counter1++;

			else if (board[i][j]->get_attrib().shape >= 'A' && board[i][j]->get_attrib().shape <= 'Z')
				counter2++;
		}
	}

	if (counter1 == 1 && counter2 == 1)
		return true;

	return false;
}

void chess::pawn_promotion()
{
	if (board[command.initial_row][command.initial_col]->get_attrib().shape == 'p' && command.final_row == 0)
	{
		int answer;

		cout << "Your pawn has been promoted now choose the chessmen" << endl;
		cout << "1-rook" << endl;
		cout << "2-knight" << endl;
		cout << "3-bishop" << endl;
		cout << "4-queen" << endl << endl;

		cout << "answer : ";
		cin >> answer;
		cout << endl;

		attributes temp;
		temp.row = command.initial_row;
		temp.col = command.initial_col;

		if (answer == 1)
		{
			temp.shape = 'r';

			delete board[command.initial_row][command.initial_col];
			board[command.initial_row][command.initial_col] = new rook;
			board[command.initial_row][command.initial_col]->set_attrib(temp);
		}

		else if (answer == 2)
		{
			temp.shape = 'n';

			delete board[command.initial_row][command.initial_col];
			board[command.initial_row][command.initial_col] = new knight;
			board[command.initial_row][command.initial_col]->set_attrib(temp);
		}

		else if (answer == 3)
		{
			temp.shape = 'b';

			delete board[command.initial_row][command.initial_col];
			board[command.initial_row][command.initial_col] = new bishop;
			board[command.initial_row][command.initial_col]->set_attrib(temp);
		}

		else
		{
			temp.shape = 'q';

			delete board[command.initial_row][command.initial_col];
			board[command.initial_row][command.initial_col] = new queen;
			board[command.initial_row][command.initial_col]->set_attrib(temp);

		}
	}

	else if (board[command.initial_row][command.initial_col]->get_attrib().shape == 'P' && command.final_row == 7)
	{
		int answer;

		cout << "Your pawn has been promoted now choose the chessmen" << endl;
		cout << "1-rook" << endl;
		cout << "2-knight" << endl;
		cout << "3-bishop" << endl;
		cout << "4-queen" << endl << endl;

		cout << "answer : ";
		cin >> answer;
		cout << endl;

		attributes temp;
		temp.row = command.initial_row;
		temp.col = command.initial_col;

		if (answer == 1)
		{
			temp.shape = 'R';

			delete board[command.initial_row][command.initial_col];
			board[command.initial_row][command.initial_col] = new rook;
			board[command.initial_row][command.initial_col]->set_attrib(temp);
		}

		else if (answer == 2)
		{
			temp.shape = 'N';

			delete board[command.initial_row][command.initial_col];
			board[command.initial_row][command.initial_col] = new knight;
			board[command.initial_row][command.initial_col]->set_attrib(temp);
		}

		else if (answer == 3)
		{
			temp.shape = 'B';

			delete board[command.initial_row][command.initial_col];
			board[command.initial_row][command.initial_col] = new bishop;
			board[command.initial_row][command.initial_col]->set_attrib(temp);
		}

		else
		{
			temp.shape = 'Q';

			delete board[command.initial_row][command.initial_col];
			board[command.initial_row][command.initial_col] = new queen;
			board[command.initial_row][command.initial_col]->set_attrib(temp);
		}
	}
}	

void chess::move()
{
	attributes temp;
	temp.row = command.final_row;
	temp.col = command.final_col;
	temp.shape =  board[command.initial_row][command.initial_col]->get_attrib().shape;

	delete board[command.final_row][command.final_col];
	board[command.final_row][command.final_col] = board[command.initial_row][command.initial_col];

	board[command.final_row][command.final_col]->set_attrib(temp);

	temp.row = command.initial_row;
	temp.col = command.initial_col;
	temp.shape = '-';

	board[command.initial_row][command.initial_col] = new pawn;
	board[command.initial_row][command.initial_col]->set_attrib(temp);

}

void chess::save()
{
	ofstream fout;
	fout.open("chess.txt", ios::app);
	
	fout << command.initial_row << " " << command.initial_col << " " << command.final_row << " " << command.final_col << " ";

	fout.close();
}

void chess::load(int &turn , bool &check_mate1 , bool &check_mate2 , bool &tie)
{
	int counter = 0;

	ifstream fin;
	fin.open("chess.txt");

	while(!fin.eof())
	{
		
		if(fin.eof())
			break;

		fin >> command.initial_row;
		fin >> command.initial_col;
		fin >> command.final_row;
		fin >> command.final_col;

		move();

		counter++;
	}

	if (counter % 2 == 0)
		turn = 1;

	else 
		turn = 2;

	check_mate1 = p1_checkmate();
	check_mate2 = p2_checkmate();
	tie = draw();

	fin.close();
}

void chess::display()
{
	system ("cls");

	for (int i = 0; i < 8; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j]->get_attrib().shape << " ";
		}
		cout << endl;
	}
	cout << endl << "   0 1 2 3 4 5 6 7" << endl << endl;

}

chess::~chess()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete board[i][j];
		}
		delete []board[i];
	}

	delete board;
}