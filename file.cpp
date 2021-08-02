#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "olcConsoleGameEngine.h"

class OneLoneCoder_Asteroids : public olcConsoleGameEngine{
    public:
    OneLoneCoder_Asteroids()
    {
        m_sAppName = L"Asteroids";
    }
    private:
    struct sSpaceObject{
        float x;
        float y;
        float dx;
        float dy;
        int nSize;
    };

    vector<sSpaceObject> vecAsteroids;
    

    protected:

    virtual bool OnUserCreate()
    {
        vecAsteroids.push_back({20.0f, 20.0f, 8.0f, -6.0f, (int)16});
        for(auto &a : vecAsteroids)
        {
            a.x += a.dx * fElaspseTime;
        }
         

        return true;
    }

    virtual bool OnUSerUpdate(float fElapsedTime)
    {
        Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, 0);
        return true;
    }

};

int main()
{
    OneLoneCoder_Asteroids game;
    game.ConstructConsole(160, 100, 8, 8);
    game.Start();
    return 0;
}