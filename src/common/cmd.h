#ifndef CMD_C
#define CMD_C


enum ParseStatus
{
    CMD_SUCCESS,
    CMD_TOO_FEW_ARGS,
    CMD_TOO_MANY_ARGS,
    CMD_INCORRECT_ARGS
};

typedef struct
{
    enum ParseStatus status;
    void* equation;
} CMDParseResult;

//constructor
CMDParseResult* make_cmd_parse_result(enum ParseStatus status, void* equation);
//parse command line args
CMDParseResult* parse_cmd(int argc, char *argv[]);
// print error message and stop program if status not SUCCESS
void raise_from_result(CMDParseResult* result);

#endif