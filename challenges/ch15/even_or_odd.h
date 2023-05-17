#define FILE_PATH "./challenges/ch15/numbers.txt"
#define BUFF_SIZE 255
#define READ "r"
#define ODD "odd"
#define EVEN "even"
#define PRIME "prime"

/*  
* @brief takes a number and returns 0 if it's event or 1 it it's odd.
*
* @param number [int number] the number to check.
* @return [Int]
*/
int is_even_number(int number);

/*  
* @brief takes a number and returns 0 if it's prime or 1 it it's not.
*
* @param number [int number] the number to check.
* @return [Int]
*/
int is_prime(int number);

int even_odd_or_prime(const char filepath[]);

int main(void);
