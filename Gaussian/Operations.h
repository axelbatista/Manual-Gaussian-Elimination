#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int n; int m;

//function objects used here when it would just be smarter to have a general function from which we can specify the operation to be done by a function object. Works though.
auto add = [](float coefficientOne, float coefficientTwo, int first, int second, std::vector < std::vector < float >> &original) mutable {
    for (int i = 0; i < m; i++) {
        original[second][i] = ((original[second][i] * coefficientTwo) + (original[first][i] * coefficientOne));
    }
};

auto subtract = [](float coefficientOne, float coefficientTwo, int first, int second, std::vector<std::vector<float>>& original) mutable {
    for (int i = 0; i < m; i++) {
        original[second][i] = ((original[second][i] * coefficientTwo) - (original[first][i] * coefficientOne));
    }
};

std::unordered_map<std::string, int> map = {
        {"first", 1},
        {"second", 2},
        {"third", 3},                                   //checking upon which row to do operations on.
        {"fourth", 4},
        {"fifth", 5},
        {"sixth", 6}
};

enum which {
    impossible,
    uno,
    dos,
    tres,
    quatro,
    cinco,
    seis
};

void doOperation() {
    std::cout << "How many rows? ";
    std::cin >> n;
    std::cout << "\nHow many columns? ";
    std::cin >> m;
    std::cout << "\nType your matrix.\n";
    std::vector<std::vector<float>> original(n, std::vector<float>(m));        
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            std::cin >> original[j][i];
        }
    }
    std::string option;                 //string for letting us pick the row.
    while (true) {
        int first = 0; int second = 0; char operation; float coefficientOne; float coefficientTwo; int changer;
        std::cout << "\nWhich row? Or press done\n";
        std::cin >> option;
        if (option == "done") {
            return;
        }
        else {
            for (int i = 0; i < 2; i++) {                   //loop runs twice because we have to also choose which row we want to modify
                switch (map[option]) {
                case which::uno:
                    (i == 1 ? second = 0 : first = 0);
                    std::cout << "\nwhat number to multiply?\n";
                    std::cin >> (i == 0 ? coefficientOne : coefficientTwo);         //we can multiply by a number, or we can multiply by a fraction.
                    std::cout << "\nany further operation?\n";                      //that's why we have both coefficientOne and coeffiecientTwo.
                    std::cin >> changer;
                    (i == 1 ? coefficientTwo /= changer : coefficientOne /= changer);
                    break;
                case which::dos:
                    (i == 1 ? second = 1 : first = 1);
                    std::cout << "\nwhat number to multiply?\n";
                    std::cin >> (i == 0 ? coefficientOne : coefficientTwo);
                    std::cout << "\nany further operation?\n";
                    std::cin >> changer;
                    (i == 1 ? coefficientTwo /= changer : coefficientOne /= changer);
                    break;
                case which::tres:
                    (i == 1 ? second = 2 : first = 2);
                    std::cout << "\nwhat number to multiply?\n";
                    std::cin >> (i == 0 ? coefficientOne : coefficientTwo);         
                    std::cout << "\nany further operation?\n";
                    std::cin >> changer;
                    (i == 1 ? coefficientTwo /= changer : coefficientOne /= changer);
                    break;
                case which::quatro:
                    (i == 1 ? second = 3 : first = 3);
                    std::cout << "\nwhat number to multiply?\n";
                    std::cin >> (i == 0 ? coefficientOne : coefficientTwo);
                    std::cout << "\nany further operation?\n";
                    std::cin >> changer;
                    (i == 1 ? coefficientTwo /= changer : coefficientOne /= changer);
                    break;
                case which::cinco:
                    (i == 1 ? second = 4 : first = 4);
                    std::cout << "\nwhat number to multiply?\n";
                    std::cin >> (i == 0 ? coefficientOne : coefficientTwo);
                    std::cout << "\nany further operation?\n";
                    std::cin >> changer;
                    (i == 1 ? coefficientTwo /= changer : coefficientOne /= changer);
                    break;
                case which::seis:
                    (i == 1 ? second = 5 : first = 5);
                    std::cout << "\nwhat number to multiply?\n";
                    std::cin >> (i == 0 ? coefficientOne : coefficientTwo);
                    std::cout << "\nany further operation?\n";
                    std::cin >> changer;
                    (i == 1 ? coefficientTwo /= changer : coefficientOne /= changer);
                    break;
                default:
                    std::cout << "not an option\n";
                    break;
                }
                if (i == 1) continue;
                std::cout << "\nnext?\n";               //sneaky but we have the other row selected here.
                std::cin >> option;
            }
            std::cout << "\nwhich operation?\n";
            std::cin >> operation;
            if (operation == 'a') {                     //addition 
                add(coefficientOne, coefficientTwo, first, second, original);
            }
            else if (operation == 's') {               
                subtract(coefficientOne, coefficientTwo, first, second, original);          //subtraction.
            }
            std::cout << '\n';
            for (auto &row : original) {
                for (float each : row) {
                    std::cout << each << " ";
                }
                std::cout << '\n';
            }
        }
    }
}
