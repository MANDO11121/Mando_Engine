#pragma once
#include <iostream>

#if	1
#define MLOG(x)	std::cout<<x<<std::endl;
#define MERROR(x)	std::cerr<<x<<std::endl;
#else
#define MLOG(x)
#define MERROR(x)
#endif