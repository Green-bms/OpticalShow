#ifndef continents_h
#define continents_h

#include <Arduino.h>

static const uint8_t PROGMEM
    continents[][8] =
    {
  {   // 0: North America (Tile 1)
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B00001000,
      B00000000,
      B00000000,
      },

 {   // 1: South America (Tile 1)
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B11110111,
      B11111111,
      B11111111,
      },

{   // 2: Europe (Tile 2)
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111000,
      B11111111,
      B11100000,
      B10000000,
      },

{   // 3: Africa (Tile 3)
      B11111000,
      B11111111,
      B11111111,
      B11111000,
      B11111100,
      B11111111,
      B11111111,
      B11111111,
      },

{   // 4: Asia (Tile 2)
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000111,
      B00000000,
      B00011111,
      B01111111,
      },

{   // 5: Asia (Tile 3)
      B00000111,
      B00000000,
      B00000000,
      B00000111,
      B00000011,
      B00000000,
      B00000000,
      B00000000,
      },

{   // 6: Asia (Tile 4)
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11111111,
      B11110000,
      B00000000,
      B00000000,
      },

{   // 7: Oceania (Tile 4)
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00000000,
      B00001111,
      B11111111,
      B11111111,
      },


    };


#endif
