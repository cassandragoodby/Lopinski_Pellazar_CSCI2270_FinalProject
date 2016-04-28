#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct PlayerElem{
	std::string name;
	std::string team;
	int GP, GS, TOTM, FG, TFG, FT, OFF, DEF, TOTR, PF, FO, A, TO, BLK, STL, PTS;
	float MAVG, FGA, FGP, TFGA, TFGP, FTA, FTP, RAVG, PAVG;

    /*
    Games Played (GP)
    Games Started (GS)
    Total Minutes (TOTM)
    Average Minutes per game (MAVG)
    Field Goals Made (FG)
    Field Goal Average (FGA)
    Field Goal Percentage (FGP)
    Three Pointers Made (TFG)
    Three Pointer Average (TFGA)
    Three Pointer Percentage (TFGP)
    Free Throws Made (FT)
    Free Throw Average (FTA)
    Free Throw Percentage (FTP)
    Offensive Rebounds (OFF)
    Defensive Rebounds (DEF)
    Total Rebounds (TOTR)
    Average Rebounds per game (RAVG)
    Personal Fouls (PF)
    Foul Outs (FO)
    Assists (A)
    Turnovers (TO)
    Blocks (BLK)
    Steals (STL)
    Points (PTS)
    Average Points per Game (PAVG)
    */

	PlayerElem *next;
    PlayerElem *previous;

	PlayerElem()
	{
        GP = 0;
        GS = 0;
        TOTM = 0;
        MAVG = 0;
        FG = 0;
        FGA = 0;
        FGP = 0;
        TFG = 0;
        TFGA = 0;
        TFGP = 0;
        FT = 0;
        FTA = 0;
        FTP = 0;
        OFF = 0;
        DEF = 0;
        TOTR = 0;
        RAVG = 0;
        PF = 0;
        FO = 0;
        A = 0;
        TO = 0;
        BLK = 0;
        STL = 0;
        PTS = 0;
        PAVG = 0;

		next = NULL;
		previous = NULL;
	};

	PlayerElem(std::string in_name, std::string in_team, int in_GP, int in_GS, int in_TOTM, float in_MAVG, int in_FG, float in_FGA, float in_FGP, int in_TFG, float in_TFGA, float in_TFGP, int in_FT, float in_FTA, float in_FTP, int in_OFF, int in_DEF, int in_TOTR, float in_RAVG, int in_PF, int in_FO, int in_A, int in_TO, int in_BLK, int in_STL, int in_PTS, float in_PAVG)
	{
		name = in_name;
		team = in_team;
        GP = in_GP;
        GS = in_GS;
        TOTM = in_TOTM;
        MAVG = in_MAVG;
        FG = in_FG;
        FGA = in_FGA;
        FGP = in_FGP;
        TFG = in_TFG;
        TFGA = in_TFGA;
        TFGP = in_TFGP;
        FT = in_FT;
        FTA = in_FTA;
        FTP = in_FTP;
        OFF = in_OFF;
        DEF = in_DEF;
        TOTR = in_TOTR;
        RAVG = in_RAVG;
        PF = in_PF;
        FO = in_FO;
        A = in_A;
        TO = in_TO;
        BLK = in_BLK;
        STL = in_STL;
        PTS = in_PTS;
        PAVG = in_PAVG;

		next = NULL;
		previous = NULL;
	}
};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void initializer(std::string data);
        void insertPlayer(PlayerElem *player);
        void insertNewPlayer(std::string team, std::string name);
		void removePlayer(std::string name);
		void getIndivStats(std::string name);
		void getTeamStats(std::string team);
        void getIndivRankings(std::string team, int key);
        void getTeamRankings(int key);
		void updateIndivStats(PlayerElem *updater);
        void startNewSeason();

	private:
        int hashTeams(std::string x);
		int TeamSize = 4;
		PlayerElem *TeamTable[4];

};

#endif // HASHTABLE_H
