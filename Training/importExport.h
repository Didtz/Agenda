
#pragma once

#ifdef TRAINING_PROJ
#define impex __declspec(dllexport)
#else
#define impex __declspec(dllimport)
#endif