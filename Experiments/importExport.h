
#pragma once

#ifdef EXPERIMENTS_PROJ
#define impexExp __declspec(dllexport)
#else
#define impexExp __declspec(dllimport)
#endif