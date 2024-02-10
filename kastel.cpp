#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

#define numberCarts 90
#define red "\033[;31m"
#define green "\033[;32m"
#define magenta "\033[;35m"
#define endcolor "\033[0m\n"  // normal color (white)
#define point_normal_game 150
#define point_hard_game 100
#define address_lb "Leaderboard.txt"


struct player 
{
    string name = "";
    int carts[3] = {0};
    int list[6] = {0};
    int point = 0;
};
player player1, player2, player3, player4, player5, player6;


bool comp(int a, int b)
{
    return (a < b);
}


int generate_random_number(int a, int b)
{
    srand(time(0));
    return rand() % (b-a+1) + a;
} 


void del_array_element(int* array, int index, int size)
{
    for (int i = index; i < size; i++)
        array[index] = array[index+1];
}


void get_cart_first_game(int* carts, int* arr, int* number_carts)
{
    int random;
    for (int i = 0; i < 3; i++)
    {
        random = generate_random_number(0, *number_carts);
        arr[i] = carts[random];
        
        del_array_element(carts, random, *number_carts);
        *number_carts -= 1;
    }
}


void color_text(int color_number)  // 0 for red, 1 for green, 2 for magenta
{
    if (color_number == 0)
        cout << red;
    if (color_number == 1)
        cout << green;
    if (color_number == 2)
        cout << magenta;
}


void show_hand_carts(int* carts, string name)
{ 
    cout << name << " Carts :  " << endl;

    // first row
    color_text(carts[0] / 100);
    cout << "_______" << "\t\t";
    color_text(carts[1] / 100);
    cout << "_______\t\t";
    color_text(carts[2] / 100);
    cout << "_______" << endl;

    // second row
    color_text(carts[0] / 100);
    cout << "|     |\t\t";
    color_text(carts[1] / 100);
    cout << "|     |\t\t";
    color_text(carts[2] / 100);
    cout << "|     |" << endl;

    // third row
    color_text(carts[0] / 100);
    if (carts[0] % 100 < 10)
        cout << "|  " << carts[0]%100 << "  |\t\t";
    else
        cout << "|  " << carts[0]%100 << " |\t\t";
    color_text(carts[1] / 100);
    if (carts[1] % 100 < 10)
        cout << "|  " << carts[1]%100 << "  |\t\t";
    else
        cout << "|  " << carts[1]%100 << " |\t\t";
    color_text(carts[2] / 100);
    if (carts[2] % 100 < 10)
        cout << "|  " << carts[2]%100 << "  |" << endl;
    else
        cout << "|  " << carts[2]%100 << " |\t\t" << endl;

    // fourth row
    color_text(carts[0] / 100);
    cout << "|_____|\t\t";
    color_text(carts[1] / 100);
    cout << "|_____|\t\t";
    color_text(carts[2] / 100);
    cout << "|_____|" << endcolor << endl;
    
    cout << "*****************************************" << endl << endl;
}


void show_list_carts(int number)  // show festival carts all players
{
    int * lists[6] = {&player1.list[0], &player2.list[0], &player3.list[0], &player4.list[0], &player5.list[0], &player6.list[0]};
    string names[6] = {player1.name, player2.name, player3.name, player4.name, player5.name, player6.name};
    for (int i = 0; i < number; i++)
    {
        cout << names[i] << " Festival :  " << endl;
        int* list = lists[i];
        
        // first row
        color_text(list[0] / 100);
        cout << "_______\t\t";
        color_text(list[1] / 100);
        cout << "_______\t\t";
        color_text(list[2] / 100);
        cout << "_______\t\t";
        color_text(list[3] / 100);
        cout << "_______\t\t";
        color_text(list[4] / 100);
        cout << "_______\t\t";
        color_text(list[5] / 100);
        cout << "_______" << endl;

        // second row
        color_text(list[0] / 100);
        cout << "|     |\t\t";
        color_text(list[1] / 100);
        cout << "|     |\t\t";
        color_text(list[2] / 100);
        cout << "|     |\t\t";
        color_text(list[3] / 100);
        cout << "|     |\t\t";
        color_text(list[4] / 100);
        cout << "|     |\t\t";
        color_text(list[5] / 100);
        cout << "|     |" << endl;

        // third row
        color_text(list[0] / 100);
        if (list[0] % 100 < 10)
            cout << "|  " << list[0]%100 << "  |\t\t";
        else
            cout << "|  " << list[0]%100 << " |\t\t";
        color_text(list[1] / 100);
        if (list[1] % 100 < 10)
            cout << "|  " << list[1]%100 << "  |\t\t";
        else
            cout << "|  " << list[1]%100 << " |\t\t";
        color_text(list[2] / 100);
        if (list[2] % 100 < 10)
            cout << "|  " << list[2]%100 << "  |\t\t";
        else
            cout << "|  " << list[2]%100 << " |\t\t";
        color_text(list[3] / 100);
        if (list[3] % 100 < 10)
            cout << "|  " << list[3]%100 << "  |\t\t";
        else
            cout << "|  " << list[3]%100 << " |\t\t";
        color_text(list[4] / 100);
        if (list[4] % 100 < 10)
            cout << "|  " << list[4]%100 << "  |\t\t";
        else
            cout << "|  " << list[4]%100 << " |\t\t";
        color_text(list[5] / 100);
        if (list[5] % 100 < 10)
            cout << "|  " << list[5]%100 << "  |\t\t" << endl;
        else
            cout << "|  " << list[5]%100 << " |\t\t" << endl;

        // fourth row
        color_text(list[0] / 100);
        cout << "|_____|\t\t";
        color_text(list[1] / 100);
        cout << "|_____|\t\t";
        color_text(list[2] / 100);
        cout << "|_____|\t\t";
        color_text(list[3] / 100);
        cout << "|_____|\t\t";
        color_text(list[4] / 100);
        cout << "|_____|\t\t";
        color_text(list[5] / 100);
        cout << "|_____|\t\t" << endcolor << endl;
            
        cout << "*****************************************************************************************" << endl;
    }
}


bool correct_name(string name)  // check player name is correct
{
    char n;

    if (name == player1.name || name == player2.name || name == player3.name || 
        name == player4.name || name == player5.name || name == player6.name)
    {
        cout << "This Name Is Repetitious..." << endl;
        return false;
    }

    if (name.length() <= 20)
    {
        for (int i = 0; i < int(name.length()); i++)
        {
            n = name[i];
            if (!((n <= 90 && n >= 65) || (n <= 122 && n >= 97) || (n <= 57 && n >= 48) || (n == 95)))
            {
                cout << "Name Must Include [(a-z), (A-Z), (0-9), (_)]" << endl;
                return false;
            }
        }
        return true;
    }

    cout << "Name Must Include Maximume 20 Character..." << endl;
    return false;
}


string get_name(int number)
{
    string name;
    do {
        cout << "What's Your Name Player " << number << ":  ";
        cin >> name;
    } while (!correct_name(name));
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    return name;
}


void unify(int* list)  // chceck don't exist repetition carts in player festival
{
    for (int i = 0; i < 5; i++)
    {
        if (list[i] != 0)
        {
            for (int j = i+1; j < 6; j++)
                if (list[i] == list[j])
                    list[j] = 0;
        }
    }
}


bool end_game(int* list, int number_carts, int* cart_pl)  // check carts is player festival equal to 6
{
    if (number_carts == 0 && cart_pl[0] == 0 && cart_pl[1] == 0 && cart_pl[2] == 0)  // finished cart
        return true;
    
    for (int i = 0; i < 6; i++)  // complete a festival
        if (list[i] == 0)
            return false;

    return true;
}


void get_new_cart(int* number_carts, int* carts, int* carts_pl, int index)  // take a new cart after every movement
{
    int random;
    if (*number_carts == 0)
        carts_pl[index] = 0;

    else
    {
        random = generate_random_number(0, *number_carts);
        carts_pl[index] = carts[random];

        del_array_element(carts, random, *number_carts);
        *number_carts -= 1;
    }
}


bool check_correct_move(int number, int pl1, int pl2, string name)  // check player input for move is correct
{
    string names[6] = {player1.name, player2.name, player3.name, player4.name, player5.name, player6.name};
    if (pl1 <= 3 && pl1 >= 1 && pl2 <= 6 && pl2 >= 1)
        for (int i = 0; i < number; i++)
            if (names[i] == name)
                return true;

    return false;
}


int calc_point(int* list)
{
    int sum = 1, plus = 0;
    for (int i = 0; i < 6; i++)
    {
        if (list[i] != 0)
        {
            if (list[i] / 100 == 0)
                sum *= 2;
            else if (list[i] / 100 == 1)
                sum *= 3;
            else if (list[i] / 100 == 2)
                sum *= 5;
        }
    }
    if (sum % 2 != 0 || sum % 3 != 0 || sum % 5 != 0)
        return 0;

    for (int i = 0; i < 6; i++)
        plus += list[i] % 100;

    return plus;
}


int move(int* number_carts, int* carts, int* carts_pl, int* list, int pl1, int pl2)
{
    list[pl2-1] = carts_pl[pl1-1];
    unify(list);
    get_new_cart(number_carts, carts, carts_pl, pl1-1);

    if (end_game(list, *number_carts, carts_pl))
        return 1;

    return 0;
}


int movement(int number, int* number_carts, int* carts, int* carts_pl, string name_pl)
{
    int pl1 = 0, pl2 = 0;
    string name;

    system("clear");
    show_hand_carts(carts_pl, name_pl);
    show_list_carts(number);

    do {
        cout << "Enter Your Move : (#Cart #Festival #name [1 2 mohammad]) ";
        cin >> pl1 >> pl2 >> name;
    } while ((!check_correct_move(number, pl1, pl2, name)) && carts_pl[pl1] != 0);

    if (name == player1.name)
        return move(number_carts, carts, carts_pl, &player1.list[0], pl1, pl2);
    else if (name == player2.name)
        return move(number_carts, carts, carts_pl, &player2.list[0], pl1, pl2);
    else if (name == player3.name)
        return move(number_carts, carts, carts_pl, &player3.list[0], pl1, pl2);
    else if (name == player4.name)
        return move(number_carts, carts, carts_pl, &player4.list[0], pl1, pl2);
    else if (name == player5.name)
        return move(number_carts, carts, carts_pl, &player5.list[0], pl1, pl2);
    else if (name == player6.name)
        return move(number_carts, carts, carts_pl, &player6.list[0], pl1, pl2);

    return 0;
}


bool playAgain()
{
    string answer;

    cout << "Are You Want Play Again? (y/n) :  ";
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if (answer == "yes" || answer == "y")
        return true;
    
    return false;
}


void add_to_lb(int score, string name)
// add new names and their scores in leaderboard , update the scores names befor exist in leaderboard
{
    string name1;
    int score1, score2 = score;
    int i = 0;
    bool cond = true;
    string names[100];
    int scores[100];
    
    ifstream lb1 (address_lb);
    if (!lb1.is_open())
        cout << "This address Not Exist" << endl;

    while(lb1 >> name1 >> score1)  // read names and scores in leaderboard
    {
        if (name == name1)
        {
            score1 += score;
            score = score1;
            cond = false;
        }
        names[i] = name1;
        scores[i++] = score1;
    }
    if (cond)
    {
        names[i] = name;
        scores[i++] = score;
    }
    lb1.close();

    ofstream lb2 (address_lb);  // write names and scores in leaderboard
    for (int k = 0; k < i; k++)
        lb2 << names[k] << "\t" << scores[k] << "\n";
    
    lb2.close();

    cout << "You Got " << score2 << " Points !!!" << endl;
    cout << "Your Point Is : " << score << endl;
}


int main()
{
    string gameType, name, answer;
    int number_carts = 89, numberPlayer, maxx = 0;

    int copy_carts[numberCarts] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
    101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
    201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215,
    201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215};
    int carts[numberCarts];

    while (true)
    {
        system("clear");

        cout << "Hello To The Kasel's Game ..." << endl;

        do {
            cout << "Select Game Type (Normal , Hard , Leaderboard) :  ";
            cin >> gameType;
            transform(gameType.begin(), gameType.end(), gameType.begin(), ::tolower);
        } while (!(gameType == "n" || gameType == "h" || gameType == "normal" || gameType == "hard" || 
                gameType == "leaderboard" || gameType == "lb"));
        
        if (gameType == "n" || gameType == "h" || gameType == "normal" || gameType == "hard")
        {
            do {
                cout << "Select Number Of Players (2-6) :  ";
                cin >> numberPlayer;
            } while (!(numberPlayer <= 6 && numberPlayer >= 2));

            // empty all players name
            player1.name = "";
            player2.name = "";
            player3.name = "";
            player4.name = "";
            player5.name = "";
            player6.name = "";
            
            // reset zero all players point
            player1.point = 0;
            player2.point = 0;
            player3.point = 0;
            player4.point = 0;
            player5.point = 0;
            player6.point = 0;

            player1.name = get_name(1);
            player2.name = get_name(2);
            if (numberPlayer > 2)
                player3.name = get_name(3);
            if (numberPlayer > 3)
                player4.name = get_name(4);
            if (numberPlayer > 4)
                player5.name = get_name(5);
            if (numberPlayer > 5)
                player6.name = get_name(6);

            while (true)
            {
                number_carts = 89;
                maxx = 0;
                copy(begin(copy_carts), end(copy_carts), begin(carts));

                get_cart_first_game(&carts[0], &player1.carts[0], &number_carts);
                get_cart_first_game(&carts[0], &player2.carts[0], &number_carts);
                if (numberPlayer > 2)
                    get_cart_first_game(&carts[0], &player3.carts[0], &number_carts);
                if (numberPlayer > 3)
                    get_cart_first_game(&carts[0], &player4.carts[0], &number_carts);
                if (numberPlayer > 4)
                    get_cart_first_game(&carts[0], &player5.carts[0], &number_carts);
                if (numberPlayer > 5)
                    get_cart_first_game(&carts[0], &player6.carts[0], &number_carts);
                
                for (int i = 0; i < 6; i++)  // reset zero all carts in festival
                {
                    player1.list[i] = 0;
                    player2.list[i] = 0;
                    player3.list[i] = 0;
                    player4.list[i] = 0;
                    player5.list[i] = 0;
                    player6.list[i] = 0;
                }

                while (true)
                {
                    if (movement(numberPlayer, &number_carts, &carts[0], &player1.carts[0], player1.name))
                        break;
                    if (movement(numberPlayer, &number_carts, &carts[0], &player2.carts[0], player2.name))
                        break;
                    if (numberPlayer > 2 && movement(numberPlayer, &number_carts, &carts[0], &player3.carts[0], player3.name))
                        break;
                    if (numberPlayer > 3 && movement(numberPlayer, &number_carts, &carts[0], &player4.carts[0], player4.name))
                        break;
                    if (numberPlayer > 4 && movement(numberPlayer, &number_carts, &carts[0], &player5.carts[0], player5.name))
                        break;
                    if (numberPlayer > 5 && movement(numberPlayer, &number_carts, &carts[0], &player6.carts[0], player6.name))
                        break;
                }

                // calculates point of al players end of every round
                player1.point += calc_point(&player1.list[0]);
                player2.point += calc_point(&player2.list[0]);
                if (numberPlayer > 2)
                    player3.point += calc_point(&player3.list[0]);
                if (numberPlayer > 3)
                    player4.point += calc_point(&player4.list[0]);
                if (numberPlayer > 4)
                    player5.point += calc_point(&player5.list[0]);
                if (numberPlayer > 5)
                    player6.point += calc_point(&player6.list[0]);

                int* max_arr[6] = {&player1.point, &player2.point, &player3.point, &player4.point, &player5.point, &player6.point};
                maxx = max({player1.point, player2.point, player3.point, player4.point, player5.point, player6.point}, comp);  // calc max point

                if (gameType == "hard" || gameType == "h")  // in hard game, reset to zero point of all player expect max point
                    for (int i = 0; i < 6; i++)
                        if (maxx != *max_arr[i])
                            max_arr[i] = 0;
                        
                system("clear");
                show_list_carts(numberPlayer);
                cout << "Player 1 Point : " << player1.point << endl;
                cout << "Player 2 Point : " << player2.point << endl;
                if (numberPlayer > 2)
                    cout << "Player 3 Point : " << player3.point << endl;
                if (numberPlayer > 3)
                    cout << "Player 4 Point : " << player4.point << endl;
                if (numberPlayer > 4)
                    cout << "Player 5 Point : " << player5.point << endl;
                if (numberPlayer > 5) 
                    cout << "Player 6 Point : " << player6.point << endl;

                if ((gameType == "hard" || gameType == "h") && maxx >= point_hard_game)
                    break;
                else if ((gameType == "normal" || gameType == "n") && maxx >= point_normal_game)
                    break;

                cout << "Are You Ready For Next Round (enter any things):  ";
                cin >> answer;
            }

            // show winner game
            int players_point[6] = {player1.point, player2.point, player3.point, player4.point, player5.point, player6.point};
            string players_name[6] = {player1.name, player2.name, player3.name, player4.name, player5.name, player6.name};

            for (int i = 0; i < 6; i++)
                if (players_point[i] == maxx)
                {
                    cout << "Winner This Game Is :  " << players_name[i] << endl;

                    if (gameType == "hard" || gameType == "h")
                        add_to_lb(2*players_point[i], players_name[i]);
                    else
                        add_to_lb(players_point[i], players_name[i]);

                }
            
            if (!playAgain())
                break;
        }

        else
        {
            string name1;
            int score;

            system("clear");
            cout << "Name" << "\t\t\t" << "Score" << endl << endl;
            ifstream lb (address_lb);
            if (!lb.is_open())  // check address leaderboard file
                cout << "This address Not Exist" << endl;

            while(lb >> name1 >> score)  // show names and scores in leaderboard
                if (name1.length() < 8)
                    cout << name1 << "\t\t\t" << score << endl;
                else if (name1.length() < 16)
                    cout << name1 << "\t\t" << score << endl;
                else
                    cout << name1 << "\t" << score << endl;

            lb.close();
            
            cout << endl << "---------------------------------------------" << endl;
            if (!playAgain())
                break;
        }
    }

    return 0;
}

