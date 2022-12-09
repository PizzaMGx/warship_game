Battleship War Game

--IMPORTANT-- This project is running using the Linux file system as well as the clear command on the console

Instructions on How to play:

1 - Navigation 
    You can navigate in the program by typing the corresponding number for every option
        1 Login: You can login with your credentials once you registered your account
        2 Register: register your account 
        3 Project Info: Will prompt some info about the project
        4 Exit: Quits the program
    Once you logued In a new menu will show
        1 logout: Returns to the previous screen 
        2 Play: Plays the actual game
        3 Score: Shows the total amount of ships sinked
        4 Exit: Quits the program 

2 - Login and registration 
    You can register your user and password in the data.txt file trough the register function in the manu, A txt file with your username will be saved in the score folder 
    Then you can login using your credentials 

3 - Play and score 
    The play and score functions will be unlocked after a successful login.
    For playing you need to enter the coordenates for a 10x10 matrix divided by a comma ie: 2,6
    Each time you enter a coordenate it will be added to te tries variable, and if you get a ship position correctly it will add 1 to your score
    The game will end when you get all the ships or input the "s" letter for surrender in wich case will end the game, show you the position of the remainig ships and prompt the tries and current score for that game
    Will also add the score to your total score in the file inside the score folder
