#ifndef CHESS_H
#define CHESS_H

struct attributes
{
	char shape;
	int row;
	int col;
};

struct input
{
	int initial_row;
	int initial_col;
	int final_row;
	int final_col;
};

class piece
{
public:
	virtual void set_attrib(attributes) = 0;
	virtual attributes get_attrib() = 0;
	virtual bool movement(int , int , piece***) = 0;

};

class pawn:public piece
{
private:
	attributes attrib;

public:
	void set_attrib(attributes)override;
	attributes get_attrib()override;
	bool movement(int , int , piece***)override;
};

class rook:public piece
{
private:
	attributes attrib;

public:
	void set_attrib(attributes)override;
	attributes get_attrib()override;
	bool movement(int , int , piece***)override;
};

class knight:public piece
{
private:
	attributes attrib;

public:
	void set_attrib(attributes)override;
	attributes get_attrib()override;
	bool movement(int , int , piece***)override;
};

class bishop:public piece
{
private:
	attributes attrib;

public:
	void set_attrib(attributes)override;
	attributes get_attrib()override;
	bool movement(int , int , piece***)override;
};

class queen:public piece
{
private:
	attributes attrib;

public:
	void set_attrib(attributes)override;
	attributes get_attrib()override;
	bool movement(int , int , piece***)override;
};

class king:public piece
{
private:
	attributes attrib;

public:
	void set_attrib(attributes)override;
	attributes get_attrib()override;
	bool movement(int , int , piece***)override;
};

class chess
{
private:
	piece ***board;
	input command;

public:
	chess();
	void get_input();
	bool range();
	bool p1_allow();
	bool p2_allow();
	bool can_move();
	bool p1_check();
	bool p2_check();
	bool p1_checkmate();
	bool p2_checkmate();
	bool draw();
	void pawn_promotion();
	void move();
	void save();
	void load(int& , bool& , bool& , bool&);
	void display();
	~chess();
};
#endif