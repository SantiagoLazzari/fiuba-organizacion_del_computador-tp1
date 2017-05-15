#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "argv_parser.h"
#include "base64.h"

option_t options = { STDIN_FILENO, STDOUT_FILENO, false };

char encode_table[64] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3',
  '4', '5', '6', '7', '8', '9', '+', '/'
};

char PADDING_SYMBOL = '=';

int main(int argc, char** argv) {

    parse_options(argc, argv, &options);

    base64_encode(
        options.input_file_descriptor,
        options.output_file_descriptor
    );

    close_files(&options);
    return 0;
}
