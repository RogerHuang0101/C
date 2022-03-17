#Project Overview:

This project is a soccer game. It can be played by two players at the same time. Users can control their individual player with their own key.
Player 1 (Brown) use w, a, s, d to control its movement. Player 2 (Red) use i, j, k, l to control its movement. 
They should carry the ball to touch their own goal net to score. Every time we score, the ball will disappear and generate a new one in a random place.
The first to reach 3 points will win the game. Notice that there're obstacles inside the field. Once the ball hit the obstacles, the ball will disappear and generate another one in the random place. 

#Key challenge:

There are some key problems in this project.
1. The player is hard to push and carry the ball
-> Solve it by adjusting the shape of the player to make it better carrying the ball. Also makes the ball much smaller.
2. Goal net is hard to touch in the corner.
-> Solve it by increasing the size of the net, makes it bigger to attach to the ball.
3. It's too easy to score without obstacles.
-> Add an additional cells on the way to goal, will kill the ball if hit it.

#How to install and run:

1. Download the whole project by git clone.
2. Open the folder: cd my_project/
3. Make the project: make
4. Use the enviro to launch the localhost: enviro
5. Type http://localhost in the website to launch the game.

#How to use the project:

1. This game is a duoplayer game, find another friend to play with you"
2. Player 1 (Brown) use w, a, s, d to control its movement. Player 2 (Red) use i, j, k, l to control its movement. 
3. First one reach 3 points win the game.

#All sources:

1. virus: https://github.com/klavinslab/enviro/tree/master/examples/virus
2. enviro: https://github.com/klavinslab/enviro
