//
// Created by Admin on 4/29/2023.
//

#include "player.h"
#include <utility>

const std::string &player::getNickname() const {
    return nickname;
}

void player::setNickname(const std::string &nickname) {
    player::nickname = nickname;
}

const UUID &player::getPlayerId() const {
    return player_id;
}

const UUID &player::getFractionId() const {
    return fraction_id;
}

player::player(std::string &nickname, UUID &playerId, UUID &fractionId) : nickname(std::move(
        nickname)), player_id(playerId), fraction_id(fractionId) {}

player::player(std::string nickname, const UUID &playerId, const UUID &fractionId) : nickname(std::move(nickname)),
                                                                                            player_id(playerId),
                                                                                            fraction_id(fractionId) {}

const std::string &fraction::getName() const {
    return name;
}

const UUID &fraction::getFractionId() const {
    return fraction_id;
}

void fraction::setName(const std::string &name) {
    fraction::name = name;
}

fraction::fraction(std::string name, const UUID &fractionId) : name(std::move(name)), fraction_id(fractionId) {}
