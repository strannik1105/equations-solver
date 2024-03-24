#ifndef CMD_C
#define CMD_C


enum ParseStatus
{
    SUCCESS,
    TOO_LOW_ARGS,
    TOO_MANY_ARGS,
    INCORRECT_ARGS
};

typedef struct
{
    enum ParseStatus status;
    void* equation;
} CMDParseResult;

CMDParseResult* make_cmd_parse_result(enum ParseStatus status, void* equation);
CMDParseResult* parse_cmd(int argc, char *argv[]);

// print error message and stop program if status not SUCCESS
void raise_from_result(CMDParseResult* result);

#endif