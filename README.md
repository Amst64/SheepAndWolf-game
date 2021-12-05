# SheepAndWolf-game
A repository to SheepAndWolf game (C++ and SDL), source code.

Execute the game :
- Im using SDL, so you have to download the development libraries (link : https://www.libsdl.org/download-2.0.php, in Development Libraries section) and the development librairies for SDL_image (link :https://www.libsdl.org/projects/SDL_image/, in Development Libraries section)
- Put the SDL libraries on SEYADOUMOUGAMMADOU_Askar_projet_final directory
- Compile, you can compile with cmake
- Copy the media folder on the directory where there is the build
- Execute the build with three arguments (respectively number of sheep, number of wolf, the time of the game in second) exemple : .\SDL_final 5 2 10 , in this case the game launch   with 5 sheeps, 2 wolve and the game last 10 seconds.

How to play :
- You are the shepherd and you can move with the arrow keys (you must hold the key)
- You have to protect the sheeps from the wolve
- The wolve are scared of the shepherd dog
- The shepherd dog circle around the shepherd
- The sheeps can give birth to another sheep if a male sheep and a female sheep meet
