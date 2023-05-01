//
// Created by Admin on 4/29/2023.
//

#ifndef TOWERDEFENCE_PLAYER_H
#define TOWERDEFENCE_PLAYER_H
#include <iostream>
#include <windows.h>

class player {
private:
    std::string nickname;
    const UUID player_id;
public:
    player(std::string nickname, const UUID &playerId, const UUID &fractionId);

private:
    const UUID fraction_id;
public:
    player(std::string &nickname, UUID &playerId, UUID &fractionId);
    [[nodiscard]] const std::string &getNickname() const;

    [[nodiscard]] const UUID &getPlayerId() const;

    [[nodiscard]] const UUID &getFractionId() const;

    void setNickname(const std::string &nickname);
};

class fraction{
private:
    std::string name;
public:
    void setName(const std::string &name);

private:
    const UUID fraction_id;
public:
    fraction(std::string name, const UUID &fractionId);

public:
    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] const UUID &getFractionId() const;
};

#endif //TOWERDEFENCE_PLAYER_H
