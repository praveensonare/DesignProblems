Running The Project from Terminal
1. Go to PaperScissorRock directory
2. Execute command "run.sh" script file.
   Example : >> sh run.sh

Description:
Each GAME has
    
- Display: CLI for user to provide Input (for choosing Rock, Paper or Scissor) and Displaying various output such as -
   Game Result
   Summary
   Brief about recently played games.

- 2 Players : User and Computer, before playing a match they must have one of rock, paper or scissor. 
    User has to choose one object with the help of Selection Menu
    Computer will choose random object.
       

OOPS Description:
Each object rock, paper and scissor are derived from are from Interface PlayObject.
Player will have one of these object.
Player is derived from interface IPlayer.
ComputerPlayer is derived from class Player, since it holds additional property of choosing random object. 
(Although, Computer can also be a Player and It needs a simple check for making random object selection, 
 but I prefer derived class)
While playing match object's of Human Player and Computer are compared.


Attaching a small video clip for demonstration. 
