# Fractal Dragon
![curve_fractal](./result.png)

Full text on Wikipedia:
https://en.wikipedia.org/wiki/Dragon_curve

# Setup
1. Download and unzip SFML from (https://www.sfml-dev.org)
2. In Project folder create 2 directories (lib and include)
3. From SFML/lib move to Project/lib files:
   - sfml-audio.lib
   - sfml-graphics.lib
   - sfml-network.lib
   - sfml-system.lib
   - sfml-window.lib

4. Copy SFML/include/SFML to Project/include
5. Generate project file by CMake (you can use cmake-gui) or use terminal commands:
     ```sh
     Get all types of generate files
     $> cmake -G
     $> cmake -G "Your generate file type"
     ``` 
6. Move from SFML/bin Project/Debug files:
   - sfml-graphics-2.dll
   - sfml-system-2.dll
   - sfml-window-2.dll
