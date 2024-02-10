
# Kastel Game

## Introduction

Kastel is a console-based game developed in C++ designed to provide an engaging and strategic gameplay experience. Players compete by collecting carts and scoring points, with various game modes adding depth and complexity to the game. The game also features a leaderboard system to track high scores and encourage competition.

## Features

- Support for 2, 3, 4, 5 and 6-player games.
- Various game modes including Normar and Hard versions.
- Command-line interface for game interaction.
- Leaderboard functionality to track high scores.

## Requirements

- C++ Compiler (C++11 or later recommended)
- Standard C++ libraries

## Compilation and Running

To compile the game, you can use any C++ compiler that supports C++11 or later. For example, if you're using g++, you can compile the game using the following command:

```
g++ -o kastel kastel.cpp
```

To run the game, simply execute the compiled binary:

```
./kastel
```

## Game Mechanics

- **Players:** The game supports multiple players, each represented with a unique set of attributes including name, carts, a list for tracking, and points.
- **Carts:** Players collect carts as part of the gameplay, which are essential for scoring points and advancing in the game.
- **Points:** Points are awarded based on the carts collected and the completion of various objectives within the game. The game features different point thresholds for normal and hard game modes.
- **Leaderboard:** Scores are recorded in a leaderboard file (`Leaderboard.txt`), allowing players to track their performance and compete for the highest scores.

## Gameplay

1. At the start, players are initialized and enter their names.
2. Players then proceed to collect carts through a series of rounds, with each round offering opportunities to gain or lose carts.
3. Points are calculated based on the carts collected and specific game events.
4. The game continues until a predefined end condition is met (e.g., a certain number of rounds or points).
5. Final scores are displayed, and high scores are recorded in the leaderboard.

## Additional Features

- Color-coded console output enhances the user interface, making gameplay more intuitive and engaging.
- A random number generator is used to ensure the dynamic and unpredictable allocation of carts.
- Players can attempt to beat their previous scores or compete against others for a position on the leaderboard.


## Contributing

Contributions to the Quoridor game project are welcome. Please feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is open source and available under the [MIT License](LICENSE).

## Acknowledgments

- Inspired by the original Kastel game.
- Thanks to all contributors and players.
