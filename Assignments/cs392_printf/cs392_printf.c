
//Susmitha Shailesh
//I pledge my honor that I have abided by the Stevens Honor System.

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int cs392_printf(const char * format, ...){

	va_list args;
	va_start(args, format);
	static char nums[] = "0123456789";
	int str_len = 0;
	 
	//iterative over “format” and find specifiers
	while (*format != '\0') {

		// get the first argument with va_arg
		// the following is an example of handling integer format “%d”

		if(*format == '%'){
			format ++;

			if(*format == 0)
				break;
					
			if(*format == 'd'){
				int arg_int = va_arg(args, int); 
				// this helps you get the argument corresponding to “%d”
				
				int temp = arg_int;
				char print_string[50]; 
				char* str_pointer;

				if(temp = 0){
					putchar('0');
					str_len = str_len + 1;
				}
				else{

					//handle negative numbers
					if(arg_int < 0){
						putchar('-');
						temp = (arg_int * (-1));
					}
					else{
						temp = arg_int;
					}

					str_pointer = &print_string[49];
					*str_pointer = '\0';

					//add each int as a char to a string
					while(temp != 0){
						int dig = temp%10;
						*--str_pointer = nums[dig];
						str_len = str_len + 1;
						temp = temp/10;
					}

					fputs(str_pointer, stdout);
				}
			}

			//you check for other formats
			//handling string format "%s"
			if(*format == 's'){
				char* print_string = va_arg(args, char*);
				str_len = str_len + strlen(print_string);
				fputs(print_string, stdout);
			}

			//handling character format "%c"
			if(*format == 'c'){
				char print_char = va_arg(args, int);
				str_len = str_len + 1;
				putchar(print_char);
			}
		}
		else{
			//print any other char
			str_len = str_len + 1;
			putchar(*format);
		}

		++format;
	}
	//return and end parsing arguments
	return str_len;
	va_end(args);

}
