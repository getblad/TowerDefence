#include <string>
#include <utility>
#include <algorithm>
#include "game_elements.h"


Game_tile::Game_tile(const field_type fieldType, const float patency, const resource_type resourceType,
                     std::string owner, float playerInfluence , int towerLevel , float productionRate ) : fieldType(
        fieldType), patency(patency), resourceType(resourceType), owner(std::move(owner)), player_influence(
        playerInfluence), tower_level(towerLevel), production_rate(productionRate) {}



const std::string &Game_tile::getOwner() const {
    return owner;
}

void Game_tile::setOwner(const std::string &owner) {
    Game_tile::owner = owner;
}

float Game_tile::getPlayerInfluence() const {
    return player_influence;
}

void Game_tile::setPlayerInfluence(float playerInfluence) {
    player_influence = playerInfluence;
}

int Game_tile::getTowerLevel() const {
    return tower_level;
}

void Game_tile::setTowerLevel(int towerLevel) {
    tower_level = towerLevel;
}

float Game_tile::getProductionRate() const {
    return production_rate;
}

void Game_tile::setProductionRate(float productionRate) {
    production_rate = productionRate;
}

field_type Game_tile::getFieldType() const {
    return fieldType;
}

float Game_tile::getPatency() const {
    return patency;
}

resource_type Game_tile::getResourceType() const {
    return resourceType;
}

Game_field *Game_field::instance = nullptr;
Game_field::Game_field( const std::vector<std::vector<Game_tile>> &tiles,const std::vector<fraction> &fractions,
                       const std::vector<player> &players) : tiles(tiles),fractions(fractions), players(players) {}

Game_field *Game_field::get_field(int player_number, int fraction_number, int rows, int cols ) {
    if (instance == nullptr) {
        instance = generate_field(player_number, fraction_number, rows, cols );
        return instance;
    } else {
        return instance;
    }

}
using namespace std;
Game_field *Game_field::generate_field(int player_number, int fraction_number, int rows, int cols ){
    if(instance != nullptr){
        delete instance;
        instance = nullptr;
    }
    vector<player> players;
    vector<fraction> fractions;
    vector<std::vector<Game_tile>> tiles(rows);
    for (int i = 0; i < fraction_number; i++){
        UUID uuid;
        UuidCreate(&uuid);
        string name;
        cout << "write fraction " << i+1 << " name: ";
        cin >> name;
        cout << endl;
        fractions.push_back(*new fraction(name, uuid));
    }
    for (int i = 0; i < player_number; i++){
        UUID uuid;
        int fraction;
        UuidCreate(&uuid);
        string name;
        cout << "write player " << i+1 << " name: ";
        cin >> name;
        cout << endl;
        cout << "type fraction number: ";
        cin >> (fraction);
        fraction--;
        cout << endl;
        players.push_back(*new player(name, uuid, fractions[fraction].getFractionId()));
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            tiles[i].emplace_back(field_type(random(0, 3)), random(0, 100),
                                  resource_type(random(0, 4)));
        }
    }
    instance = new Game_field(tiles, fractions, players);
    return instance;
}

std::vector<std::vector<int>> Game_field::get_tiles_count(const std::string& players_name) {
    std::vector<std::vector<int>> result;
    int i, j = 0;
    for (const auto & tileRow : tiles){

        for (const auto & tile : tileRow){
            if(tile.getOwner() == players_name){
                result.emplace_back(std::vector<int>{i,j});
            }
            j++;
        }
        i++;
    }
    return result;

}

std::vector<UUID> Game_field::get_players(const string &fraction_name) {
    std::vector<UUID> result;
    auto fraction = std::find_if(fractions.begin(), fractions.end(), [fraction_name](const class fraction& fract){return fract.getName() == fraction_name ;} );
    for(const auto& player:players){
        if(player.getFractionId() == fraction->getFractionId()){
            result.emplace_back(player.getPlayerId());
        }
    }
    return result;
}


