#ifndef GAME_H
#define GAME_H

class Game : public Engine
{
public:
    Game();
    bool initialize();
    void runLoop();
    bool shutDown();
    void setWinDim(int width, int height);
    void startGame();

    enum GameState
    {
        EStart,
        EGameplay,
        EPause
    };

    enum Globals
    {
        GPlayerSpeed,
    };

    void addActor(Actor *actor);
    void removeActor(Actor *actor);

    void addSprite(SpriteComponent *sprite);
    void removeSprite(SpriteComponent *sprite);

    void addBG(BGComponent *bg);
    void removeBG(BGComponent *bg);

    void addTilemap(class TilemapComponent *tilemap);
    void removeTilemap(class TilemapComponent *tilemap);

    void addMouseInComp(class MouseInComponent *mic);
    void removeMouseInComp(class MouseInComponent *mic);

    class Player *getPlayer();
    class Enemy *getEnemy();

    void addEnvironment(class Object *object);
    void removeEnvironment(class Object *object);
    std::vector<class Object *> &getEnvironment();

    Texture *getTexture(const std::string &filename);
    Camera *getCamera() { return mCamera; }
    class WebsockClient *getWebsocket() { return mWebSocket; }

    static int WIN_WIDTH;
    static int WIN_HEIGHT;
    static glm::vec2 WIN_RES;
    static glm::vec2 MOUSE_POS;

    void setValue(std::string key, std::string value);
    std::string getValue(Globals key);

    void callUIRPC(std::string command);

    void mouseClicked(float x, float y);
    void changeMouseClicked(class MouseInComponent *mic);

private:
    void processInput();
    void updateGame() override;
    void generateOutput() override;

    void loadData();
    void unloadData();

    void loadNetwork(int pid, char *name);

    bool loadShaders();
    bool loadSpriteShader();
    bool loadBGShader();

    GameState mState;
    bool mConnected;

    std::vector<Actor *> mActors;
    std::vector<Actor *> mPendingActors;
    bool mUpdatingActors;

    std::vector<SpriteComponent *> mSprites;
    std::unordered_map<std::string, Texture *> mTextures;
    Camera *mCamera;

    class WebsockClient *mWebSocket;

    // shaders
    Shader *mSpriteShader;
    Shader *mBGShader;

    // game specific
    class Player *mPlayer;
    class Enemy *mEnemy;
    class GameLevel *mLevel;
    class Space *mSpace;

    bool mLeft;

    std::vector<class BGComponent *> mBackgrounds;

    class TilemapComponent *mTilemap;

    std::vector<class Object *> mEnvironment;

    std::vector<class MouseInComponent *> mMouseInComponents;
    class MouseInComponent *mCurrentMouseInComp;

    std::map<Globals, std::string> mDataStore;

    class Utils *mUtils;
};

#endif