#ifndef MODEL_H
#define MODEL_H
#include "staminabar.h"
#include "gameover.h"
#include "player.h"
#include "cat.h"
#include "copycat.h"
#include "disposalbin.h"

typedef struct {
    Player player;
    Cat cats[CATS];
    CopyCat copycat;
    DisposalBin disposal;
    Terminal terminals[5];
    GameOver endScr;
    StaminaBar stamBar;
}Model;

#endif
