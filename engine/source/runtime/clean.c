#include <stdio.h>


#include "../../include/config.h"
#include "../../include/engine.h"

int cleanupEngine() {
	cleanObjects();
	cleanFonts();
	cleanTexture();
}