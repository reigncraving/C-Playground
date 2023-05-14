#define FILE_PATH "./challenges/ch15/numbers.txt"
#define BUFF_SIZE 255
#define READ "r"

/*  
* @brief takes a number and returns 0 if it's event or 1 it it's odd.
*
* @param number [int number] the number to check.
* @return [Int]
*/
int is_even_number(int number);

int even_or_odd_file_lines(const char filepath[]);

int main(void);