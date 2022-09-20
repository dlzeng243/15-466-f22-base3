#  Invisible Three Threes

Edit: There seems to be no equivalent wait() function in [Windows](https://stackoverflow.com/questions/18013950/error-sys-wait-h-no-such-file-or-directory), so this can only be ran on Linux and MacOS.

STARTING WITH GAME 2 AS BASE CODE. All models were made in blender by me, and all audio files were generated randomly from https://jfxr.frozenfractal.com.

Author: Daniel Zeng (dlzeng)

Design: It's Connect 4 but with 3 players trying to get 3 in a row. And now it's invisible (with sounds to help out)!

Screen Shot:

![Screen Shot](screenshot.png)

How To Play:

Use W, A, S, D to move around the camera. Mouse motion rotates the camera and escape to ungrab the mouse. Use the left and right arrows to move between columns and space bar to place a coin in the column. The ordering of the colors go RGB, RGB, RGB, etc.The coins are now invisible, and you must use your memory to remember the locations of the coins. If you happen to forget, you can place a coin in any column and use the resulting sounds to determine what the coins in that column are. Finally, the goal is to get three in a row first :).

This game was built with [NEST](NEST.md).
