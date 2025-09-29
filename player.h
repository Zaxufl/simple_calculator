#ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>

class Player
{
private:
    int *data;

public:
    Player(int);
    Player(const Player &);
    ~Player();
    void set_data(int d) { *data = d; };
    void show_data() { qInfo() << *data << '\n'; };
};

#endif // PLAYER_H
