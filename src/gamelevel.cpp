#include "headers/gamepch.h"

GameLevel::GameLevel(Game *game) : mGame(game)
{
}

GameLevel::~GameLevel()
{
    for (auto obj : mObjects)
    {
        delete obj;
    }
}

void GameLevel::load(const char *file, unsigned int levelWidth, unsigned int levelHeight)
{
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData;
    unsigned int tileCode;

    if (fstream)
    {
        while (std::getline(fstream, line))
        {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;

            while (sstream >> tileCode)
            {
                row.push_back(tileCode);
            }

            tileData.push_back(row);
        }

        if (tileData.size() > 0)
        {
            this->init(tileData, levelWidth, levelHeight);
        }
    }
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight)
{
    unsigned int height = tileData.size();
    unsigned int width = tileData[0].size();

    float unit_width = levelWidth / static_cast<float>(width), unit_height = levelHeight / height;

    float scale = .1f;
    float offset = .3f;

    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            if (tileData[y][x] == 1)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);
                new Object(mGame, this, pos, scale, TYPE::TYPE_1);
            }
            else if (tileData[y][x] == 2)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);
                new Object(mGame, this, pos, scale, TYPE::TYPE_2);
            }
            else if (tileData[y][x] == 3)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);
                new Object(mGame, this, pos, scale, TYPE::TYPE_3);
            }
            else if (tileData[y][x] == 4)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);
                new Object(mGame, this, pos, scale, TYPE::TYPE_4);
            }
            else if (tileData[y][x] == 5)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);
                new Object(mGame, this, pos, scale, TYPE::TYPE_5);
            }
            else if (tileData[y][x] == 6)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);
                new Object(mGame, this, pos, scale, TYPE::TYPE_6);
            }
            else if (tileData[y][x] == 7)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);
                new Object(mGame, this, pos, scale, TYPE::TYPE_7);
            }
            else if (tileData[y][x] == 8)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);
                new Object(mGame, this, pos, scale, TYPE::TYPE_8);
            }
            else if (tileData[y][x] == 9)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);

                new Object(mGame, this, pos, scale, TYPE::TYPE_9);
            }
            else if (tileData[y][x] == 10)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);

                new Object(mGame, this, pos, scale, TYPE::TYPE_10);
            }
            else if (tileData[y][x] == 11)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);

                new Object(mGame, this, pos, scale, TYPE::TYPE_11);
            }
            else if (tileData[y][x] == 12)
            {
                // glm::vec2 pos(scale * x - 1.f, scale * y - 1.f);
                glm::vec2 pos(scale * x - offset, scale * y - offset);

                glm::vec2 size(unit_width, unit_height);

                new Object(mGame, this, pos, scale, TYPE::TYPE_12);
            }
        }
    }
}

void GameLevel::addObject(Object *object)
{
    mObjects.push_back(object);
}

void GameLevel::removeObject(Object *object)
{
    auto iter = std::find(mObjects.begin(), mObjects.end(), object);
    if (iter != mObjects.end())
    {
        mObjects.erase(iter);
    }
}