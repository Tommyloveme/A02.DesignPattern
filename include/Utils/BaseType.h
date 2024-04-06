#ifndef BASE_TYPE_HEADER
#define BASE_TYPE_HEADER

struct xy_vect {
    double x;
    double y;
};

enum CHUCK_ID {
    CHUCK_MIN = 0,
    CHUCK_1,
    CHUCK_2,
    CHUCK_BOTH,
    CHUCK_MAX
};

enum STATE {
    INITIATION,
    START_LOT,
    START_WAFER,
    START_IMAGE,
    terminate
};

#endif // BASE_TYPE_HEADER