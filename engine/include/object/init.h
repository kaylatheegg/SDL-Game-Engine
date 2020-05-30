#pragma once
#define INIT_OBJECT_ENGINE_H

void initObject();

#include "object.h"

object** objects;

static size_t objectSize;
static size_t rectSize;