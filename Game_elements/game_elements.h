
#ifndef TOWERDEFENCE_GAME_ELEMENTS_H
#define TOWERDEFENCE_GAME_ELEMENTS_H

#include <vector>
#include "player.h"
#include <random>
#include <utility>
enum resource_type{wood = 0, stone, metal, gold, none};
enum field_type {tile = 0, swamp, mountain, hill};

template<typename T>
T random(T range_from, T range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

class Game_tile {
private:
    const field_type fieldType;
    const float patency;
    const resource_type resourceType;

    std::string owner;
    float player_influence;
    // 0 if no tower on tile
    int tower_level;
    float production_rate;


public:
    //TODO: move constructor
    Game_tile(const Game_tile& field):fieldType(field.fieldType), patency(field.patency), resourceType(field.resourceType), owner(field.owner), player_influence(field.player_influence), tower_level(field.tower_level), production_rate(field.production_rate){} ;
//    Game_tile( Game_tile&& tile) noexcept :fieldType(tile.fieldType), patency(tile.patency),
//    resourceType(tile.resourceType), owner(tile.owner), player_influence(tile.player_influence), tower_level(tile.tower_level), production_rate(tile.production_rate)  {
//    };
    Game_tile(Game_tile&& tile): fieldType(tile.fieldType), patency(tile.patency), resourceType(tile.resourceType), owner(std::move(tile.owner)), player_influence(tile.player_influence), tower_level(tile.tower_level), production_rate(tile.production_rate){};
    Game_tile(field_type fieldType, float patency, resource_type resourceType,
              std::string owner ="None" , float playerInfluence = 0 , int towerLevel = 0 , float productionRate = 0 );
//    Game_tile& operator=(const Game_tile& other) {
//        if (this != &other) {
//            fieldType = other.fieldType;
//            patency = other.patency;
//            resourceType = other.resourceType;
//        }
//        return *this;
//    }
//    Game_tile(Game_tile& other):fieldType(other.fieldType),patency(other.patency), resourceType(other.resourceType){};
    [[nodiscard]] field_type getFieldType() const;

    [[nodiscard]] float getPatency() const;

    [[nodiscard]] resource_type getResourceType() const;

    [[nodiscard]] const std::string &getOwner() const;

    void setOwner(const std::string &owner);

    [[nodiscard]] float getPlayerInfluence() const;

    void setPlayerInfluence(float playerInfluence);

    [[nodiscard]] int getTowerLevel() const;

    void setTowerLevel(int towerLevel);

    [[nodiscard]] float getProductionRate() const;

    void setProductionRate(float productionRate);
};

class Game_field{
private:
    Game_field(const std::vector<std::vector<Game_tile>> &tiles, const std::vector<fraction> &fractions,
               const std::vector<player> &players);

    const std::vector<std::vector<Game_tile>> tiles;
    std::vector<fraction> fractions;
    std::vector<player> players;
    static Game_field* instance;
public:

//    Game_field(const Game_field& tile) = delete;
    static Game_field* generate_field(int player_number, int fraction_number, int rows, int cols);
    static Game_field *get_field(int player_number, int fraction_number, int rows, int cols);
    std::vector<std::vector<int>> get_tiles_count(const std::string& players_name) ;
    std::vector<UUID> get_players(const std::string& fraction_name);
};

#endif //TOWERDEFENCE_GAME_ELEMENTS_H
