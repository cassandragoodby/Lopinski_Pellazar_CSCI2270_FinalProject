#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    for(int i = 0; i < 12; i++)
    {
        TeamTable[i] = NULL;
    }
}

HashTable::~HashTable()
{

}

void HashTable::initializer(string data)
{
    int length, index;
    string name, team;

    PlayerElem *player = new PlayerElem();

    index = 0;
    length = data.find(", ");
    player->GP = stoi(data.substr(0,length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->GS = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->TOTM = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->MAVG = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->FG = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->FGA = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->FGP = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->TFG = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->TFGA = stoi(data.substr(index, length));

    index += length + 1;

    length = data.substr(index).find(", ");
    player->TFGP = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->FT = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->FTA = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->FTP = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->OFF = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->DEF = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->TOTR = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->RAVG = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->PF = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->FO = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->A = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->TO = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->BLK = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->STL = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->PTS = stoi(data.substr(index, length));
    index += length + 1;

    length = data.substr(index).find(", ");
    player->PAVG = stoi(data.substr(index, length));
    index += length + 1;

    insertPlayer(player);
}

void HashTable::insertPlayer(PlayerElem *player)
{
    int index = hashTeams(player->team);

    if(index == -1) cout << "Please assign " << player->name << " to one of the listed teams" << endl;
    else if(TeamTable[index] == NULL) TeamTable[index] = player;
    else
    {
        PlayerElem *temp = TeamTable[index];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = player;
        player->previous = temp;
    }
}

void HashTable::insertNewPlayer(string team, string name)
{
    PlayerElem *player = new PlayerElem();
    player->name = name;
    player->team = team;

    insertPlayer(player);
}

void HashTable::removePlayer(string name)
{
    for(int index = 0; index < TeamSize; index++)
    {
        PlayerElem *temp = TeamTable[index];
        while(temp)
        {
            if(temp->name == name)
            {
                if(temp->previous)  temp->previous->next = temp->next;
                if(temp->next)  temp->next->previous = temp->previous;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }
    cout << "Player not found" << endl;
}

void HashTable::getIndivStats(string name)
{
    for(int index = 0; index < TeamSize; index++)
    {
        PlayerElem *temp = TeamTable[index];
        while(temp)
        {
            if(temp->name == name)
            {
                cout << "Name: " << temp->name << endl;
                cout << "Team: " << temp->team << endl;
                cout << "Games Played: " << temp->GP << endl;
                cout << "Games Started: " << temp->GS << endl;
                cout << "Total Minutes Played: " << temp->TOTM << endl;
                cout << "Average Minutes Played Per Game: " << temp->MAVG << endl;
                cout << "Field Goals: " << temp->FG << endl;
                cout << "Attempted Field Goals Per Game: " << temp->FGA << endl;
                cout << "Field Goal Percentage: " << temp->FGP * 100 << "%" << endl;
                cout << "Three Pointers Made: " << temp->TFG << endl;
                cout << "Attempted Three Pointers Per Game: " << temp->TFGA << endl;
                cout << "Three Pointer Percentage: " << temp->TFGP << endl;
                cout << "Free Throws Made: " << temp->FT << endl;
                cout << "Attempted Free Throws Per Game: " << temp->FTA << endl;
                cout << "Free Throw Percentage: " << temp->FTP * 100 << "%" << endl;
                cout << "Offensive Rebounds: " << temp->OFF << endl;
                cout << "Defensive Rebounds: " << temp->DEF << endl;
                cout << "Total Rebounds: " << temp->TOTR << endl;
                cout << "Average Rebounds Per Game: " << temp->RAVG << endl;
                cout << "Personal Fouls: " << temp->PF << endl;
                cout << "Foul Outs: " << temp->FO << endl;
                cout << "Assists: " << temp->A << endl;
                cout << "Turnovers: " << temp->TO << endl;
                cout << "Blocks: " << temp->BLK << endl;
                cout << "Steals: " << temp->STL << endl;
                cout << "Total Points: " << temp->PTS << endl;
                cout << "Average Points Per Game: " << temp->PAVG << endl;
                return;
            }
            temp = temp->next;
        }
    }
    cout << "Player not found" << endl;
}


void HashTable::getTeamStats(string team)
{
    int index = hashTeams(team);

    if(TeamTable[index] == NULL || index == -1) cout << "No information found for that team" << endl;
    else
    {
        int i = 0;
        int TOTM, FG, FGA, FGP, TFG, TFGA, TFGP, FT, FTA, FTP, OFF, DEF, TOTR, RAVG, PF, FO, A, TO, BLK, STL, PTS, PAVG = 0;
        PlayerElem *player = TeamTable[index];
        while(player)
        {
            TOTM += player->TOTM;
            FG += player->FG;
            FGA += player->FGA;
            FGP += player->FGP;
            TFG += player->TFG;
            TFGA += player->TFGA;
            TFGP += player->TFGP;
            FT += player->FT;
            FTA += player->FTA;
            FTP += player->FTP;
            OFF += player->OFF;
            DEF += player->DEF;
            TOTR += player->TOTR;
            RAVG += player->RAVG;
            PF += player->PF;
            FO += player->FO;
            A += player->A;
            TO += player->TO;
            BLK += player->BLK;
            STL += player->STL;
            PTS += player->PTS;
            PAVG += player->PAVG;

            i++;
            player = player->next;
        }
        cout << "Games Played: " << player->GP/i << endl;
        cout << "Games Started: " << player->GS/i << endl;
        cout << "Total Minutes Played: " << player->TOTM/i << endl;
        cout << "Average Minutes Played Per Game: " << player->MAVG/i << endl;
        cout << "Field Goals: " << player->FG/i << endl;
        cout << "Attempted Field Goals: " << player->FGA/i << endl;
        cout << "Field Goal Percentage: " << player->FGP/i * 100 << "%" << endl;
        cout << "Three Pointers Made: " << player->TFG << endl;
        cout << "Attempted Three Pointers: " << player->TFGA/i << endl;
        cout << "Three Pointer Percentage: " << player->TFGP/i << endl;
        cout << "Free Throws Made: " << player->FT/i << endl;
        cout << "Attempted Free Throws: " << player->FTA/i << endl;
        cout << "Free Throw Percentage: " << player->FTP/i * 100 << "%" << endl;
        cout << "Offensive Rebounds: " << player->OFF/i << endl;
        cout << "Defensive Rebounds: " << player->DEF/i << endl;
        cout << "Total Rebounds: " << player->TOTR/i << endl;
        cout << "Average Rebounds Per Game: " << player->RAVG/i << endl;
        cout << "Personal Fouls: " << player->PF/i << endl;
        cout << "Foul Outs: " << player->FO/i << endl;
        cout << "Assists: " << player->A/i << endl;
        cout << "Turnovers: " << player->TO/i << endl;
        cout << "Blocks: " << player->BLK/i << endl;
        cout << "Steals: " << player->STL/i << endl;
        cout << "Total Points: " << player->PTS/i << endl;
        cout << "Average Points Per Game: " << player->PAVG/i << endl;
        return;
    }
}

void HashTable::getIndivRankings(string team, int key)
{
    int index = hashTeams(team);

    int first, second, third, hold, hold2 = 0;
    string fname, sname, tname, hname, hname2;

    if(TeamTable[index] == NULL || index == -1) cout << "No information found for that team" << endl;
    else
    {
        PlayerElem *player = TeamTable[index];

        if(key == 1)        //Key = Total Points
        {
            while(player)
            {
                if(player->PTS > first)
                {
                    hold = first;
                    hname = fname;
                    first = player->PTS;
                    fname = player->name;

                    if(hold > second)
                    {
                        hold2 = second;
                        hname2 = sname;
                        second = hold;
                        sname = hname;

                        if(hold2 > third)
                        {
                            third = hold2;
                            tname = hname2;
                        }
                    }
                    else if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->PTS > second)
                {
                    hold = second;
                    hname = sname;
                    second = player->PTS;
                    sname = player->name;

                    if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->PTS > third)
                {
                    third = player->PTS;
                    tname = player->name;
                }
            }
        }

        else if(key == 2)   //Key = Free Throws Made
        {
            while(player)
            {
                if(player->FT > first)
                {
                    hold = first;
                    hname = fname;
                    first = player->FT;
                    fname = player->name;

                    if(hold > second)
                    {
                        hold2 = second;
                        hname2 = sname;
                        second = hold;
                        sname = hname;

                        if(hold2 > third)
                        {
                            third = hold2;
                            tname = hname2;
                        }
                    }
                    else if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->FT > second)
                {
                    hold = second;
                    hname = sname;
                    second = player->FT;
                    sname = player->name;

                    if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->FT > third)
                {
                    third = player->FT;
                    tname = player->name;
                }
            }
        }

        else if(key == 3)   //Key = Three Pointers Made
        {
            while(player)
            {
                if(player->TFG > first)
                {
                    hold = first;
                    hname = fname;
                    first = player->TFG;
                    fname = player->name;

                    if(hold > second)
                    {
                        hold2 = second;
                        hname2 = sname;
                        second = hold;
                        sname = hname;

                        if(hold2 > third)
                        {
                            third = hold2;
                            tname = hname2;
                        }
                    }
                    else if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->TFG > second)
                {
                    hold = second;
                    hname = sname;
                    second = player->TFG;
                    sname = player->name;

                    if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->TFG > third)
                {
                    third = player->TFG;
                    tname = player->name;
                }
            }
        }

        else if(key == 4)   //Key = Total Rebounds
        {
            while(player)
            {
                if(player->PTS > first)
                {
                    hold = first;
                    hname = fname;
                    first = player->PTS;
                    fname = player->name;

                    if(hold > second)
                    {
                        hold2 = second;
                        hname2 = sname;
                        second = hold;
                        sname = hname;

                        if(hold2 > third)
                        {
                            third = hold2;
                            tname = hname2;
                        }
                    }
                    else if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->PTS > second)
                {
                    hold = second;
                    hname = sname;
                    second = player->PTS;
                    sname = player->name;

                    if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->PTS > third)
                {
                    third = player->PTS;
                    tname = player->name;
                }
            }
        }

        else if(key == 5)   //Key = Blocks
        {
            while(player)
            {
                if(player->PTS > first)
                {
                    hold = first;
                    hname = fname;
                    first = player->PTS;
                    fname = player->name;

                    if(hold > second)
                    {
                        hold2 = second;
                        hname2 = sname;
                        second = hold;
                        sname = hname;

                        if(hold2 > third)
                        {
                            third = hold2;
                            tname = hname2;
                        }
                    }
                    else if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->PTS > second)
                {
                    hold = second;
                    hname = sname;
                    second = player->PTS;
                    sname = player->name;

                    if(hold > third)
                    {
                        third = hold;
                        tname = hname;
                    }
                }
                else if(player->PTS > third)
                {
                    third = player->PTS;
                    tname = player->name;
                }
            }
        }
        else
        {
            cout << "Please enter a valid statistic option" << endl;
            return;
        }
        cout << "1st: " << fname << ": " << first << endl;
        cout << "2nd: " << sname << ": " << second << endl;
        cout << "3rd: " << tname << ": " << third << endl;
    }
}

void HashTable::getTeamRankings(int key)
{
    for(int i = 0; i < TeamSize; i++)
    {
        cout << "/nFrom " << TeamTable[i]->team << endl;
        getIndivRankings(TeamTable[i]->team, key);
    }
}

void HashTable::updateIndivStats(PlayerElem *updater)
{
    int index = hashTeams(updater->team);

    if(TeamTable[index] == NULL || index == -1) cout << "Player not found" << endl;
    else
    {
        PlayerElem *player = TeamTable[index];
        while(player)
        {
            if(player->name == updater->name)
            {
                player->GP += updater->GP;
                player->GS += updater->GS;
                player->TOTM += updater->TOTM;
                player->MAVG = player->TOTM/player->GP;
                player->FG += updater->FG;
                player->FGA += updater->FGA;
                player->FGP = player->FG/player->FGA;
                player->TFG += updater->TFG;
                player->TFGA += updater->TFGA;
                player->TFGP = player->TFG/player->TFGA;
                player->FT += updater->FT;
                player->FTA += updater->FTA;
                player->FTP = player->FT/player->FTA;
                player->OFF += updater->OFF;
                player->DEF += updater->DEF;
                player->TOTR += updater->TOTR;
                player->RAVG = player->TOTR/player->GP;
                player->PF += updater->PF;
                player->FO += updater->FO;
                player->A += updater->A;
                player->TO += updater->TO;
                player->BLK += updater->BLK;
                player->STL += updater->STL;
                player->PTS += updater->PTS;
                player->PAVG = player->PTS/player->GP;
                cout << "Successfully updated stats for " << player->name << endl;
                return;
            }
            player = player->next;
        }
    }
    cout << "Player not found" << endl;
}

void HashTable::startNewSeason()
{
    PlayerElem *temp;
    PlayerElem *temp_next;

    for(int i = 0; i < TeamSize; i++)
    {
        if(TeamTable[i])
        {
            temp = TeamTable[i];
            while(temp)
            {
                temp_next = temp->next;
                delete temp;
                temp = temp_next;
            }
            TeamTable[i] = NULL;
        }
    }
}

int HashTable::hashTeams(string x)
{
    if(x == "Arizona") return 0;
    else if(x == "Arizona State") return 1;
    else if(x == "California") return 2;
    else if(x == "Colorado") return 3;
    return -1;
}
