# Guess the Number Game (C++)

A simple console-based Guess the **Number Game** developed in C++.  
The computer randomly selects a number within a user-defined range, and the player tries to guess it with hints provided after each attempt.


# Features

-  Random number generation
-  User-defined minimum and maximum range
-  Input validation for range
-  "Too High" and  "Too Low" hints
-  Attempts counter
-  Score calculation based on number of attempts
-  Play multiple rounds using menu


# Technologies Used

- C++
- Standard Library
  - `<iostream>`
  - `<cstdlib>`
  - `<ctime>`


# How to Run

## Compile

```bash
g++ guess_number.cpp -o guess_number
```

## Run

```bash
./guess_number
```

*For Windows (MinGW):*

```bash
g++ guess_number.cpp -o guess_number.exe
guess_number.exe
```


# How to Play

1. Run the program.
2. Select Play Game.
3. Enter the minimum and maximum range.
4. The computer randomly chooses a secret number.
5. Keep guessing until you find the correct number.
6. The program gives hints:
   - Too Low!
   - Too High!
7. After guessing correctly, your:
   - Number of attempts
   - Final score
   are displayed.



# Score Calculation

Initial score starts from 100.

For every wrong attempt:

```text
Score = 100 - (Attempts - 1) × 10
```

Minimum score is 10.

### Example

| Attempts | Score |
|----------|------:|
| 1 | 100 |
| 2 | 90 |
| 3 | 80 |
| 4 | 70 |
| 5 | 60 |
| 10 or more | 10 |

---

# Project Structure

```
Guess-Number-Game/
│
├── guess_number.cpp
└── README.md
```



# Sample Output

```
=============================
     GUESS NUMBER GAME
=============================
1. Play Game
2. Exit

Enter Choice: 1

Enter Minimum Range: 1
Enter Maximum Range: 50

I have selected a number between 1 and 50.

Enter your guess: 25
Too Low!

Enter your guess: 40
Too High!

Enter your guess: 33

Correct!!

Number = 33
Attempts = 3
Score = 80/100
```



# Future Improvements

- Difficulty Levels (Easy, Medium, Hard)
- Limited number of attempts
- High score system
- Save scores to a file
- Multiplayer mode
- Time-based scoring
- Better input validation

---

# Author

Ashish Prajapati

If you like this project, don't forget to ⭐ star the repository.
