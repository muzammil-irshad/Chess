#include <iostream>
#include <fstream>
#include <windows.h>
#include "Chess.h"

using namespace std;

int main()
{
	chess game;
	int ans;

	int turn = 1;
	bool check_mate1 = false;
	bool check_mate2 = false;
	bool tie = false;


	cout << "\t1.Reload Game" << endl;
	cout << "\t2.Start New Game" << endl;
	cout << "\t3.exit" << endl << endl;
	cout << "Note : To exit at any point set all values to -1" << endl << endl;

	cout << "\tAnswer : ";
	cin >> ans;
	cout << endl;

	if (ans == 1)
		game.load(turn , check_mate1  , check_mate2 , tie);
	

	else if (ans == 2)
	{
		ofstream out;
		out.open("chess.txt");
		out.clear();
		out.close();
	}

	else
	{
		exit(1);
	}

	while (!check_mate1 && !check_mate2 && !tie)
	{
		game.display();

		switch (turn)
		{
		case 1:
			do
			{
				cout << "Player 1 : " << endl;

				game.get_input();

				cout << endl << endl;

				if (!game.range() || !game.p1_allow())
					cout << "Illegal move" << endl;

				else if (!game.can_move())
					cout << "You can't move the chessmen to the desire location" << endl;

				else if (game.p1_check())
					cout << "Your king is in check be aware" << endl;

				else if (game.p1_checkmate())
					break;


				cout << endl;

			}while (!game.range() || !game.p1_allow() || !game.can_move() || game.p1_check());


			game.pawn_promotion();

			game.save();

			game.move();

			if (game.p1_checkmate())
				check_mate1 = true;

			if (game.draw())
				tie = true;

			turn = 2;
			break;

		case 2:
			do
			{
				cout << "Player 2 : " << endl;

				game.get_input();

				cout << endl << endl;

				if (!game.p2_allow() || !game.range())
					cout << "Illegal move" << endl;

				else if (!game.can_move())
					cout << "You can't move the chessmen to the desire location" << endl;

				else if (game.p2_check())
					cout << "Your king is in check be aware" << endl;

				else if (game.p2_checkmate())
					break;


				cout << endl;

			}while (!game.range() || !game.p2_allow() || !game.can_move() || game.p2_check());


			game.pawn_promotion();

			game.save();

			game.move();

			if (game.p1_checkmate())
				check_mate1 = true;

			if (game.draw())
				tie = true;

			turn = 1;
			break;
		}

	}

	if (check_mate1)
		cout << "Player 2 wins!!!" << endl;

	else if (check_mate2)
		cout << "Player 1 wins!!!" << endl;

	else
		cout << "It's a draw" << endl;

	system("pause");
	return 0;
}